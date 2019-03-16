#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"

using std::vector;
using namespace std;

namespace filter {
    vector<float> FIRLowPass(float fp, float fs, float F, float gain, int N, string window) {
        vector<float> h, t;
        float fc = (fp + fs)/2;

        t = utils::linspace(0, N, 100);

        for (float i : t) {
            if (i == 0) {
                h.push_back(gain * 2 * fc / F);
            } else {
                h.push_back(gain * sin(2 * M_PI * fc * i / F) / (i * M_PI));
            }    
        }
        return h;
    }

    vector<float> FIRHighPass(float fp, float fs, float gain, int N, string window) {
        vector<float> h, t;
        float fc = (fp + fs)/2;

        t = utils::linspace(0, (float)N/2, N/2);

        for (float i : t) {
            if (i == 0) {
                h.push_back(1 - (gain * 2 * fc));
            } else {
                h.push_back(-gain * sin(2 * M_PI * fc * i) / (i * M_PI));
            }    
        }
        return h;
    }

    vector<float> FIRBandPass(float fp1, float fs1, float fp2, float fs2, float gain, int N, string window) {
        vector<float> h, t;

        float dF = utils::min((fp1 - fs1), (fs2 - fp2));

        float fc1 = fp1 - dF/2;
        float fc2 = fp1 + dF/2;

        t = utils::linspace(0, (float)N/2, N/2);

        for (float i : t) {
            if (i == 0) {
                h.push_back(gain * 2 * (fc2 - fc1));
            } else {
                h.push_back(gain * (sin(2 * M_PI * fc2 * i) - sin(2 * M_PI * fc1 * i)) / (i * M_PI));
            }    
        }
        return h;
    }

    vector<float> FIRBandStop(float fp1, float fs1, float fp2, float fs2, float gain, int N, string window) {
        vector<float> h, t;

        float dF = utils::min((fs1 - fp1), (fp2 - fs2));

        float fc1 = fp1 + dF/2;
        float fc2 = fp1 - dF/2;

        t = utils::linspace(0, (float)N/2, N/2);

        for (float i : t) {
            if (i == 0) {
                h.push_back(gain * 2 * (fc1 - fc2) + gain);
            } else {
                h.push_back(gain * (sin(2 * M_PI * fc1 * i) - sin(2 * M_PI * fc2 * i)) / (i * M_PI));
            }    
        }
        return h;
    }
}