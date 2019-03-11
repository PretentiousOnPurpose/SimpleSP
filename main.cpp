#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {
    
    vector<float> t = linspace(0, 10, 64);
    vector<float> sin12 = Sin(0.1, t);
    vector<float> cos12 = Cos(0.1, t);
    vector<float> sin20 = Sin(200, t);

    vector<vector<float>> M = {sin12, sin20, cos12};
    vector<vector<float>> M1 = {sin12, cos12};

    vector<float> x1 = merge(M1);
    vector<float> x = merge(M);


    auto Filter = filter::FIRLowPass(1.1, 1, 11);

    auto H = fft(realToComplex(Filter), 64);
    auto X = fft(realToComplex(x), 64);

    auto Y = matMul(X, H);

    auto y = ifft(Y, 64);

    printSeq(x1);
    cout << endl;
    printSeq(x);
    cout << endl;
    
    printSeq(complexToReal(y));

    return 0;
}