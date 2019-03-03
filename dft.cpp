#include <iostream>
#include <vector>
#include <complex.h>
#include <cmath>
#include "func.hpp"
using std::vector;
using namespace std;

vector<complex<float>> dft(vector<complex<float>> & x, int N) {
    
    vector<complex<float>> y;
    y.reserve(N);

    if (x.size() < N) {
        for (int i = 0; i < (N - x.size()); i++) {
            x.push_back(0);
        }
    }

    for (int i = 0; i < N; i++) {
        y[i] = 0;
        for (int j = 0; j < N; j++) {
            y[i] += x[j] * complex<float>{cos(2 * M_PI * j * i / N), -sin(2 * M_PI * j * i / N)};
        }
    }

    return y;
}

vector<complex<float>> idft(vector<complex<float>> & x) {
    int N = x.size();

    vector<complex<float>> y;
    y.reserve(N);

    for (int i = 0; i < N; i++) {
        y[i] = 0;
        for (int j = 0; j < N; j++) {
            y[i] += x[j] * complex<float>{cos(2 * M_PI * j * i / N), sin(2 * M_PI * j * i / N)};
        }
        cout << x[i] << endl;
        y[i] /= N;
    }

    return y;
}