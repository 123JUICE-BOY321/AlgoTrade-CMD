#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

#include <string>

double blackScholesPrice(double S, double K, double T, double sigma, double r, const std::string& type);

#endif
