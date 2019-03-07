#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"

using std::vector;
using namespace std;

int main() {
    vector<complex<float>> z, x1;

    // x1 = {1, 5, 3, 7, 2, 6, 4, 8};
    x1 = {2, 2, 2, 2, 1, 1, 1, 1};
    utils::printSeq(x1);

    z = basic::fft(x1, 8);

    utils::printSeq(z);

    return 0;
}