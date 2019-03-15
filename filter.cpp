#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"

using std::vector;
using namespace std;


namespace filter {
    vector<float> FIRLowPass(float fc, float gain, int N, string window) {
        vector<float> h, t;

        t = utils::linspace(-(float)N/2, (float)N/2, 64);

        for (float i : t) {
            if (i == 0) {
                h.push_back(gain * 2 * fc);
            } else {
                h.push_back(gain * sin(2 * M_PI * fc * i) / (i * M_PI));
            }    
        }

        return h;
    }
}