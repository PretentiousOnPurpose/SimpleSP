#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"

using std::vector;
using namespace std;


namespace filter {
    vector<float> FIRLowPass(float fc, float gain, int N, string window) {
        vector<float> h;

        for (int i = 0; i <= N/2; i++) {
            if (i == 0) {
                h.push_back(gain * fc / M_PI);
                continue;
            }
            h.push_back(gain * sin(2 * M_PI * fc * i) / (i * M_PI));
        }

        return h;
    }
}