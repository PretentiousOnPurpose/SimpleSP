#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"

using std::vector;
using namespace std;

int main() {

    vector<complex<float>> z, x1;

    x1 = {1, 1, 1, 1};

    z = basic::dft(x1, 4);

    utils::printSeq(x1);
    utils::printSeq(z);

    return 0;
}