#include <iostream>
#include <vector>
#include <complex.h>
#include <cmath>
#include "dsp.hpp"
using std::vector;
using namespace std;
using namespace utils;

// LLR (Exact and Approx)W

namespace comm {

    vector<complex<float>> QAM = {{-0.7071, -0.7071}, {-0.7071, 0.7071}, {0.7071, -0.7071}, {0.7071, 0.7071}, {-0.9487, 0.9487}, {-0.9487, 0.3163}, {-0.9487, -0.9487}, {-0.9487, -0.3163}, {-0.3163, 0.9487}, {-0.3163, 0.3163}, {-0.3163, -0.9487}, {-0.3163, -0.3163}, {0.9487, 0.9487}, {0.9487, 0.3163}, {0.9487, -0.9487}, {0.9487, -0.3163}, {0.3163, 0.9487}, {0.3163, 0.3163},	{0.3163, -0.9487}, {0.3163, -0.3163}};

    vector<complex<float>> QAMMod(vector<int> data, int M, int size) {
        // Number of bits per symbol
        int bitsPerSym = log2(M);

        // Total number of QAM Symbols

        int numSyms = size / bitsPerSym;

        // Buffer for output modulated vector
        vector<complex<float>> modData(numSyms);

        // Iterating over the groups of bits (symbols)
        for (int iter_sym = 0; iter_sym < numSyms; iter_sym++) {
            // Variable representing the symbol in decimal form
            int modIdx = 0;
            // Iterating over each bit in symbol
            for (int iter_bits = 0; iter_bits < bitsPerSym; iter_bits++) {
                // Bit shifting and forming decimal symbol
                modIdx = modIdx << 1;
                modIdx ^= data[iter_sym * bitsPerSym + iter_bits];
            }
            // QAM Modulation from lookup array using symbol as index
            modIdx = (M > 4) * 4 + (M > 16) * 16 + (M > 64) * 64 + modIdx;
            
            modData[iter_sym] = QAM[modIdx];
        }

        return modData;    
    }
    
    vector<float> QAMDemod(vector<complex<float>> modData, int M, int size, int softOut, float noiseVar) {
        float dist = 1000;
        int distIdx = 0;
        float dist_tmp = 0;
        int bitsPerSym = log2(M);
        int modIdx = (M > 4) * 4 + (M > 16) * 16 + (M > 64) * 64;
            
        vector<float> demodOut(size * bitsPerSym);

        if (softOut == 0) { // Hard Output
            for (int iter_data = 0; iter_data < size; iter_data++) {
                
                // Iterating over all constellation points and finding the nearest
                // point (smallest euclidean distance)
                for (int iter_const = 0; iter_const < M; iter_const++) {
                    dist_tmp = cAbsDiffSqr(modData[iter_data], QAM[modIdx + iter_const]);   
                    if (dist_tmp <= dist) {
                        distIdx = modIdx + iter_const;
                        dist = dist_tmp;
                    } 
                }

                // Converting decimal symbol into bits
                for (int iter_bits = 0; iter_bits < bitsPerSym; iter_bits++) {
                    demodOut[iter_data * bitsPerSym + bitsPerSym - iter_bits - 1] = distIdx % 2;
                    distIdx /= 2;
                }
            }
        } else if (softOut == 1) { // Soft Output (Exact LLR)
            for (int iter_data = 0; iter_data < size; iter_data++) {
                for (int iter_bits = 0; iter_bits < bitsPerSym; iter_bits++) {
                    float lkhd0 = 0, lkhd1 = 0;
                    cout << "--- bit ---" << endl;
                    for (int iter_const = 0; iter_const < M; iter_const++) {
                        if ((iter_const >> iter_bits) % 2 == 0) {
                            lkhd0 += exp((-1 / (2 * noiseVar)) * ((QAM[modIdx + iter_const].real() - modData[iter_data].real()) * (QAM[modIdx + iter_const].real() - modData[iter_data].real()) + (QAM[modIdx + iter_const].imag() - modData[iter_data].imag()) * (QAM[modIdx + iter_const].imag() - modData[iter_data].imag())));
                            cout << "ZERO" << endl;
                        } else {
                            lkhd1 += exp((-1 / (2 * noiseVar)) * ((QAM[modIdx + iter_const].real() - modData[iter_data].real()) * (QAM[modIdx + iter_const].real() - modData[iter_data].real()) + (QAM[modIdx + iter_const].imag() - modData[iter_data].imag()) * (QAM[modIdx + iter_const].imag() - modData[iter_data].imag())));
                            cout << "ONE" << endl;
                        }
                    }
                    demodOut[iter_data * bitsPerSym + iter_bits] = log(lkhd0 / lkhd1);
                }
            }
        } else if (softOut == 2) { // Soft Output (Approx. LLR)
            for (int iter_data = 0; iter_data < size; iter_data++) {
                for (int iter_bits = 0; iter_bits < bitsPerSym; iter_bits++) {
                    float lkhd0 = 1e10, lkhd1 = 1e10, tmp1, tmp2;
                    for (int iter_const = 0; iter_const < M; iter_const++) {
                        if ((iter_const >> iter_bits) % 2 == 0) {
                            tmp1 = exp((-1 / (2 * noiseVar)) * ((QAM[modIdx + iter_const].real() - modData[iter_data].real()) * (QAM[modIdx + iter_const].real() - modData[iter_data].real()) + (QAM[modIdx + iter_const].imag() - modData[iter_data].imag()) * (QAM[modIdx + iter_const].imag() - modData[iter_data].imag())));
                            if (tmp1 < lkhd0) {
                                lkhd0 = tmp1;
                            }
                        } else {
                            tmp2 = exp((-1 / (2 * noiseVar)) * ((QAM[modIdx + iter_const].real() - modData[iter_data].real()) * (QAM[modIdx + iter_const].real() - modData[iter_data].real()) + (QAM[modIdx + iter_const].imag() - modData[iter_data].imag()) * (QAM[modIdx + iter_const].imag() - modData[iter_data].imag())));
                            if (tmp2 < lkhd1) {
                                lkhd1 = tmp2;
                            }
                        }
                    }
                    demodOut[iter_data * bitsPerSym + iter_bits] = log(lkhd0 / lkhd1);
                }
            }
        }

        return demodOut;
    }
}