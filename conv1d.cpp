#include <iostream>
#include <vector>
#include "func.hpp"

using std::vector;
using namespace std;

vector<float> conv1d(vector<float> x1, vector<float> x2) {
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
