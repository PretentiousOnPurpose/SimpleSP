#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"

using std::vector;
using namespace std;


namespace filter {
    vector<float> FIRLowPass(float fc, float gain, int N, string window) {
        vector<float> h;
        
        h.push_back(gain * fc / M_PI);

        for (int i = 1; i <= N/2; i++) {
            h.push_back(gain * sin(i * fc) / (i * M_PI));
        }

        return h;
    }
}