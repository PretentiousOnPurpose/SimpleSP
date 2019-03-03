#include <vector>
#include <complex.h>
using std::vector;
using namespace std;

namespace basic {
    vector<float> conv1d(vector<float>, vector<float>);
    vector<complex<float>> dft(vector<complex<float>> &, int N);
    vector<complex<float>> idft(vector<complex<float>> &);
    vector<complex<float>> dct(vector<complex<float>> &, int N);
    vector<complex<float>> idct(vector<complex<float>> &);
};

namespace utils {
    void printSeq(vector<float> &);
    void printSeq(vector<complex<float>> &);
};

namespace filters {

};

namespace image {

};