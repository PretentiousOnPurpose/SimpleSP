#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"
#define PI 3.14159 
using std::vector;
using namespace std;

namespace filter {
    vector<float> FIRLowPass(float fp, float fs, float F, int N, int phi, string window) {
        vector<float> h, t;
        float fc = (fp + fs) / 2;
        t = utils::linspace(-(N - 1) / 2, (N - 1) / 2, N);

        for (float i : t) {
            
            if ((i - phi) == 0) {
                h.push_back(2 * fc / F);
            } else {
                h.push_back(sin(2 * PI * (fc / F) * (i - phi)) / ((i - phi) * PI));
            }    
        }

        return h;
    }

}