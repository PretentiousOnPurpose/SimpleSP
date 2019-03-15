#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {
    
    vector<float> t = linspace(0, 10, 64);
    vector<float> sin20 = Sin(200, t);

    vector<vector<float>> M = {sin20};
    vector<float> x = merge(M);

    auto Filter = filter::FIRLowPass(205, 1, 11);

    auto H = fft(realToComplex(Filter), 64);
    auto X = fft(realToComplex(x), 64);

    auto Y = matMul(X, H);

    auto y = ifft(Y, 64);
    auto y1 = circConv(x, Filter);

    cout << "\n\nMax: ";
    cout << max(y1) << endl;


    return 0;
}