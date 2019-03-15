#include <vector>
#include <complex.h>
#include <opencv2/core/core.hpp>

using std::vector;
using namespace std;

namespace basic {
    vector<float> conv1d(vector<float>, vector<float>);
    vector<float> circConv(vector<float>, vector<float>);
    vector<complex<float>> dft(vector<complex<float>>, int);
    vector<complex<float>> idft(vector<complex<float>>);
    vector<complex<float>> fft(vector<complex<float>>, int, int = 0);
    vector<complex<float>> ifft(vector<complex<float>>, int);
    vector<complex<float>> fftCompute(vector<complex<float>> , int, int);
    vector<complex<float>> twiddle(int, int);
    vector<complex<float>> fftCombine(vector<complex<float>>, vector<complex<float>>, int, int);
};

namespace utils {
    void printSeq(vector<float>);
    void printSeq(vector<complex<float>>);

    vector<complex<float>> realToComplex(vector<float>);
    vector<float> complexToReal(vector<complex<float>>);
    vector<float> ampResponse(vector<complex<float>>);

    vector<float> linspace(float, float, float);
    vector<float> Sin(float, vector<float>, float = 1.0);
    vector<float> Cos(float, vector<float>, float = 1.0);
    
    vector<float> merge(vector<vector<float>>);

    vector<complex<float>> matMul(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> matAdd(vector<complex<float>>, vector<complex<float>>);
    vector<float> matMul(vector<float>, vector<float>);
    vector<float> matAdd(vector<float>, vector<float>);

    vector<float> zeroPadding(vector<float>, int);
    vector<complex<float>> zeroPadding(vector<complex<float>>, int);

    vector<complex<float>> getEvenOddTerms(vector<complex<float>>, int);
    float max(vector<float>);
    float max(float, float);
    float min(vector<float>);
    float min(float, float);
    float sum(vector<float>);
    int len(vector<float>);
    
};

namespace filter {
    vector<float> IIRLowPass();
    vector<float> FIRLowPass(float, float, int, string = "rect");
};


namespace image {
    cv::Mat gaussianFilter(int);
    void blur(string, int, int);
    void deblur(string, int);
};