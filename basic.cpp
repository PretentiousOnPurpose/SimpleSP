#include <iostream>
#include <vector>
#include <complex.h>
#include <cmath>
#include "dsp.hpp"
using std::vector;
using namespace std;

namespace basic {
    vector<float> conv1d(vector<float> & x1, vector<float> & x2) {
        int LEN_CONV_SEQ = x1.size() + x2.size() - 1;
        
        vector<float> y;
        y.reserve(LEN_CONV_SEQ);

        for (int i = 0; i < LEN_CONV_SEQ; i++) {
            y[i] = 0;
            for (int j = 0; j <= i; j++) {
                y[i] += x1[j] * x2[i - j];
            }
        }

        return y;
    }
    
    vector<complex<float>> dft(vector<complex<float>> & x, int N) {
        complex<float> tmp;
        vector<complex<float>> y;

        if (x.size() < N) {
            int tmp = x.size();
            for (int i = 0; i < (N - tmp); i++) {
                x.push_back(complex<float>{0, 0});
            }
        }

        for (int i = 0; i < N; i++) {
            tmp = complex<float>{0, 0};
            for (int j = 0; j < N; j++) {
                tmp += x[j] * complex<float>{cos(2 * M_PI * j * i / N), -sin(2 * M_PI * j * i / N)};
            }
            y.push_back(tmp);
        }
        return y;
    }

    vector<complex<float>> idft(vector<complex<float>> & x) {
        int N = x.size();
        complex<float> tmp;

        vector<complex<float>> y;

        if (x.size() < N) {
            int tmp = x.size();
            for (int i = 0; i < (N - tmp); i++) {
                x.push_back(complex<float>{0, 0});
            }
        }

        for (int i = 0; i < N; i++) {
            tmp = complex<float>{0, 0};
            for (int j = 0; j < N; j++) {
                tmp += x[j] * complex<float>{cos(2 * M_PI * j * i / N), sin(2 * M_PI * j * i / N)};
            }
            y.push_back(tmp/(complex<float>){N, 0});
        }
        return y;
    }

    vector<complex<float>> fft(vector<complex<float>> & x, int N) {
        complex<float> tmp;
        const int D = log2(N);

        vector<complex<float>> y, tmp1, tmp2;

        if (x.size() < N) {
            int tmp = x.size();
            for (int i = 0; i < (N - tmp); i++) {
                x.push_back(complex<float>{0, 0});
            }
        }

        // Even Samples 
        for (int j = 0; j < pow(2, (D-2)); j = j + 2) {
            for (int i = 0 + j; i <= pow(2, (D-2)) + j; i = i + 2) {
                tmp1 = {x[i + i * pow(2, (D-2))], x[i + i * pow(2, (D-2)) + pow(2, (D-1))]};
                tmp2 = dft(tmp1, 2);
                y.insert(end(y), begin(tmp2), end(tmp2));
            }
        }

        // Odd Samples
        for (int j = 0; j < pow(2, (D-3)); j = j + 2) {
            for (int i = 0 + j; i <= pow(2, (D-2)) + j; i = i + 2) {
                tmp1 = {x[1 + i + i * pow(2, (D-2))], x[1 + i + i * pow(2, (D-2)) + pow(2, (D-1))]};
                tmp2 = dft(tmp1, 2);
                y.insert(end(y), begin(tmp2), end(tmp2));
            }
        }
        
        // Rest D-1 Stages

        return y;   
    }

};