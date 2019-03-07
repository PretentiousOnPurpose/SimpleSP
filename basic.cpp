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
        return fftCompute(y, N);   
    }

    vector<complex<float>> fftCompute(vector<complex<float>> & x, int N) {
        vector<complex<float>> tmp1, tmp2;
        if (N == 2) {
            return dft(x, N);
        }
        tmp1 = vector<complex<float>>(x.begin() + 1, x.begin() + N/2);
        tmp2 = vector<complex<float>>(x.begin() + N/2 + 1, x.begin() + N);
        return fftCompute(tmp1 , N/2) + dot(twiddle(N), fftCompute(tmp2 , N/2));
    }

    vector<complex<float>> twiddle(int N) {
        vector<complex<float>> y;
        for (int i = 0; i < N; i++) {
            y.push_back(complex<float>(cos(2 * M_PI * i / N), sin(2 * M_PI * i / N)));
        }
        return y;
    }

};