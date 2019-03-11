#include <iostream>
#include <complex.h>
#include <fstream>
#include <vector>
#include "dsp.hpp"
using std::vector;
using namespace std;

namespace utils {
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
        for (int i = 0; i <= N; i++) {
            y.push_back(start + i * (stop - start)/(N));
        }

        return y;
    }

    vector<float> Sin(float freq, vector<float> t_samples, float gain) {
        vector<float> y;
        for (float x: t_samples) {
            y.push_back(gain * sin(2 * M_PI * freq * x));
        }

        return y;
    }

    vector<float> Cos(float freq, vector<float> t_samples, float gain) {
        vector<float> y;
        for (float x: t_samples) {
            y.push_back(gain * cos(2 * M_PI * freq * x));
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

    vector<complex<float>> getEvenOddTerms(vector<complex<float>> x, int b) {
        vector<complex<float>> y;
        for (int i = 0 + b; i < x.size(); i += 2) {
            y.push_back(x[i]);
        }

        return y;
    }

    vector<float> audioIn(string filename) {
        vector<float> y;
        string line;
        ifstream fp(filename);
        
        if (fp.is_open()) {
            while(getline(fp, line)) {
                cout << line << endl;
            }
            fp.close();
        }

        return y;
    }
}