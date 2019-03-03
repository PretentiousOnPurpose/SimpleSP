#include <iostream>
#include <vector>
#include "func.hpp"

using std::vector;
using namespace std;

int main() {

    vector<float> y, x1, x2;

    x1 = {1, 1, 1, 1, 1};
    x2 = {1, 1};

    y = conv1d(x1, x2);

    return 0;
}