#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"

using std::vector;
using namespace std;

int main() {

    vector<complex<float>> z, x1;

    x1 = {1, 101, 1};


    z = basic::dft(x1, 8);

    utils::printSeq(z);

    return 0;
}