#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {
    
    vector<float> t = linspace(-10, 10, 500);
    vector<float> sin12 = Sin(0.5, t);
    // vector<float> sin5 = Sin(7.5, t);
    // vector<float> sin10 = Sin(10, t);
    vector<float> sin20 = Sin(20, t, 0.25);
    // vector<float> sin50 = Sin(50, t);

    vector<vector<float>> M = {sin12, sin20};

    vector<float> x = merge(M);
    // vector<float> x = sin12;

    vector<float> Filter = filter::FIRLowPass(2, 1, 11);

    auto a = fft(realToComplex(x), 64);
    auto b = fft(realToComplex(Filter), 64);
    cout << "A: ";
    printSeq(sin20);

    cout << "B: ";
    printSeq(ampResponse(b));
    

    vector<complex<float>> j = matMul(a, b);

    vector<float> y = ampResponse(fft(j, 64, 1));

    cout << "Out: ";
    printSeq(y);

    return 0;
}