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
            for (int i = 0; i < (N - x.size()); i++) {
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
            for (int i = 0; i < (N - x.size()); i++) {
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


};