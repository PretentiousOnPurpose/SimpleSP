#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"

using std::vector;
using namespace std;

int main() {

    vector<complex<float>> z, w, x1;

    x1 = {1, 101, 1};


    z = basic::dft(x1, 8);
    w = basic::idft(z);

    utils::printSeq(z);
    utils::printSeq(w);
    return 0;
}