#include <cmath>
#include <string>
#include "black_scholes.h"

using namespace std;

double normalCDF(double x) {
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double blackScholesPrice(double S, double K, double T, double sigma, double r, const string& type) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (type == "call")
        return S * normalCDF(d1) - K * exp(-r * T) * normalCDF(d2);
    else if (type == "put")
        return K * exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
    else
        return -1.0; // invalid type (should be checked before calling)
}
