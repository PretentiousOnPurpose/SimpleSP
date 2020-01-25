#include <iostream>
#include <cmath>
#include<vector>
#include "dsp.hpp"
#define PI 3.14159 
using std::vector;
using namespace std;
using namespace basic;

// LPF, HPF, BPF, BEF with Boxes, Raised Cosine Filtering

namespace filter {
    vector<complex<float>> applyFIRFilter(vector<complex<float>> impResponse, vector<complex<float>> data) {
        int diff = impResponse.size() - 1;
        vector<complex<float>> filterOut = conv1d(impResponse, data);

        for (int i = 0; i < diff; i++) {
            filterOut.pop_back();
        }

        return filterOut;
    }

    vector<complex<float>> FIRLowPass(float fp, float fs, float F, int N, int phi, string window) {
        vector<float> t;
        vector<complex<float>> h;
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

    vector<complex<float>> FIRHighPass(float fp, float fs, float F, int N, int phi, string window) {
        vector<float> t;
        vector<complex<float>> h;
        float fc = (fp + fs) / 2;
        t = utils::linspace(-(N - 1) / 2, (N - 1) / 2, N);

        for (float i : t) {
            
            if ((i - phi) == 0) {
                h.push_back(1 - 2 * fc / F);
            } else {
                h.push_back((1 / (PI * (i - phi))) * (sin((i - phi) * PI) - sin((i - phi) * 2 * PI * fc / F)));
            }    
        }
        return h;
    }

    vector<complex<float>> FIRBandPass(float f1, float f2, float F, int N, int phi, string window) {
        vector<float> t;
        vector<complex<float>> h;
        t = utils::linspace(-(N - 1) / 2, (N - 1) / 2, N);

        for (float i : t) {
            
            if ((i - phi) == 0) {
                h.push_back(2 * (f2 - f1) / F);
            } else {
                h.push_back((1 / (PI * (i - phi))) * (sin((i - phi) * 2 * PI * f2 / F) - sin((i - phi) * 2 * PI * f1 / F)));
            }    
        }
        return h;
    }

    vector<complex<float>> FIRBandStop(float f1, float f2, float F, int N, int phi, string window) {
        vector<float> t;
        vector<complex<float>> h;
        t = utils::linspace(-(N - 1) / 2, (N - 1) / 2, N);

        for (float i : t) {
            
            if ((i - phi) == 0) {
                h.push_back(1 - 2 * (f1 - f2) / F);
            } else {
                h.push_back((1 / (PI * (i - phi))) * (sin((i - phi) * PI) + sin((i - phi) * 2 * PI * f1 / F) - sin((i - phi) * 2 * PI * f2 / F)));
            }    
        }
        return h;
    }
}