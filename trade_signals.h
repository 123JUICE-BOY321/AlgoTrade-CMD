#ifndef TRADE_SIGNALS_H
#define TRADE_SIGNALS_H

#include <string>

void generateTradeSignal(double S, double K, double T, double sigma, double r, const std::string& type, double marketPrice);

#endif
