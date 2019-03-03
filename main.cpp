#include <iostream>
#include <vector>
#include <complex.h>
#include "func.hpp"

using std::vector;
using namespace std;

int main() {

    vector<complex<float>> z, w, x1;

    x1 = {5, 4, 3, 2};

    z = dft(x1, 4);
    w = idft(z);
    return 0;
}