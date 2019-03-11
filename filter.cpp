#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"

using std::vector;
using namespace std;


namespace filter {
    vector<float> FIRLowPass(float fc, float gain, int N, string window) {
        vector<float> h;

        for (float i = -N/2; i <= N/2; i += 0.16) {
            if (i == 0) {
                h.push_back(gain * fc / M_PI);
            } else {
                h.push_back(gain * sin(2 * M_PI * fc * i) / (i * M_PI));
            }
        }

        return h;
    }
}