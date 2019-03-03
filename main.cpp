#include <iostream>
#include <vector>
#include <complex.h>
#include "func.hpp"

using std::vector;
using namespace std;

int main() {

    vector<complex<float>> z, w, x1;

    x1 = {5, 4, 3, 2};

    z = basic::dft(x1, 4);
    w = basic::idft(z);

    utils::printSeq(w);
    return 0;
}