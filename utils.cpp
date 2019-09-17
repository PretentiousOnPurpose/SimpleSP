#include <iostream>
#include <complex.h>
#include <vector>
#include "dsp.hpp"
using std::vector;
using namespace std;

namespace utils {
    void printSeq(vector<int> x) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    void printSeq(vector<float> x) {
        cout.precision(3);
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    void printSeq(vector<complex<float>> x) {
        cout.precision(3);
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    vector<complex<float>> realToComplex(vector<float> x) {
        vector<complex<float>> y;
        for (auto i: x) {
            y.push_back(complex<float>{i, 0});
        }

        return y;
    }

    vector<float> complexToReal(vector<complex<float>> x) {
        vector<float> y;
        for (auto i: x) {
            y.push_back(i.real());
        }

        return y;
    }

    vector<float> ampResponse(vector<complex<float>> x) {
        vector<float> y;
        for (auto i: x) {
            y.push_back(sqrt(i.real() * i.real() + i.imag() * i.imag()));
        }

        return y;
    }

    vector<float> linspace(float start, float stop, float N) {
        vector<float> y;
        for (float i = 0; i < N; i++) {
            y.push_back(start + i * (stop - start)/(N-1));
        }

        return y;
    }

    vector<float> sampler(float start, float stop, float freq) {
        vector<float> y;
        for (float i = start; i <= stop; i += (1/freq)) {
            y.push_back(i);
        }

        return y;
    }

    vector<float> Sin(float freq, vector<float> t_samples) {
        vector<float> y;
        for (float x: t_samples) {
            y.push_back(sin(2 * M_PI * freq * x));
        }

        return y;
    }

    vector<float> Cos(float freq, vector<float> t_samples) {
        vector<float> y;
        for (float x: t_samples) {
            y.push_back(cos(2 * M_PI * freq * x));
        }

        return y;
    }

    vector<float> merge(vector<vector<float>> M) {
        vector<float> y;
        
        for (int i = 0; i < M[0].size(); i++) {
            float tmp = 0;
            for (int j = 0; j < M.size(); j++) {
                tmp += M[j][i];
            }
            y.push_back(tmp);
        }

        return y;

    }

    vector<complex<float>> matMul(vector<complex<float>> x1, vector<complex<float>> x2) {
        vector<complex<float>> y;
        for (int i = 0; i < x1.size(); i++) {
            y.push_back(x1[i] * x2[i]);
        }

        return y;
    }

    vector<complex<float>> matAdd(vector<complex<float>> x1, vector<complex<float>> x2) {
        vector<complex<float>> y;
        for (int i = 0; i < x1.size(); i++) {
            y.push_back(x1[i] + x2[i]);
        }

        return y;
    }

    vector<float> matMul(vector<float> x1, vector<float> x2) {
        vector<float> y;
        for (int i = 0; i < x1.size(); i++) {
            y.push_back(x1[i] * x2[i]);
        }

        return y;
    }

    vector<float> matAdd(vector<float> x1, vector<float> x2) {
        vector<float> y;
        for (int i = 0; i < x1.size(); i++) {
            y.push_back(x1[i] + x2[i]);
        }

        return y;
    }

    vector<float> zeroPadding(vector<float> x, int N) {
        for (int i = 0; i < N; i++) {
            x.push_back(0);            
        }

        return x;
    }

    vector<complex<float>> zeroPadding(vector<complex<float>> x, int N) {
        for (int i = 0; i < N; i++) {
            x.push_back(complex<float>{0, 0});            
        }

        return x;
    }


    vector<complex<float>> getEvenOddTerms(vector<complex<float>> x, int b) {
        vector<complex<float>> y;
        for (int i = 0 + b; i < x.size(); i += 2) {
            y.push_back(x[i]);
        }

        return y;
    }

    float cAbsDiffSqr(complex<float> a, complex<float> b) {
        float c = 0;
        c = (a.real() - b.real()) * (a.real() - b.real()) + (a.imag() - b.imag()) * (a.imag() - b.imag());

        return c;
    }

    float max(vector<float> x) {
        float A = 0;
        for (float i : x) {
            if (i > A) {
                A = i;
            }
        }

        return A;
    }

    float max(float x1, float x2) {
        if (x1 > x2) {
            return x1;
        }

        return x2;
    }

    float min(vector<float> x) {
        float A = x[0];
        for (float i : x) {
            if (i < A) {
                A = i;
            }
        }

        return A;
    }

    float min(float x1, float x2) {
        if (x1 < x2) {
            return x1;
        }

        return x2;
    }

    float sum(vector<float> x) {
        float A = 0;
        for (float i : x) {
            A += i;
        }

        return A;
    }

    int len(vector<float> x) {
        int A = 0;
        for (float i : x) {
            A++;
        }

        return A;
    }

    int len(vector<complex<float>> x) {
        int A = 0;
        for (complex<float> i : x) {
            A++;
        }

        return A;
    }

}