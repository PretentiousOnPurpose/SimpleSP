#include <iostream>
#include <complex.h>
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

    vector<complex<float>> getEvenOddTerms(vector<complex<float>> x, int b) {
        vector<complex<float>> y;
        for (int i = 0 + b; i < x.size(); i += 2) {
            y.push_back(x[i]);
        }

        return y;
    }
}