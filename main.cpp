#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"

using std::vector;
using namespace std;

int main() {
    vector<complex<float>> z, x1;

    x1 = {0, 1, 2, 3, 4, 5, 6, 7};
    utils::printSeq(x1);

    z = basic::fft(x1, 8);
    utils::printSeq(z);

    z = basic::ifft(z, 8);
    utils::printSeq(z);
    
    return 0;
}