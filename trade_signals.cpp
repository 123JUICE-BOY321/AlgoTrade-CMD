#include <iostream>
#include <string>
#include <iomanip>
#include "trade_signals.h"
#include "black_scholes.h"

using namespace std;

void generateTradeSignal(double S, double K, double T, double sigma, double r, const string& type, double marketPrice) {
    double modelPrice = blackScholesPrice(S, K, T, sigma, r, type);

    cout << fixed << setprecision(4);
    cout << "Model Price: " << modelPrice << "\n";

    const double epsilon = 0.0001;
    if (modelPrice > marketPrice + epsilon)
        cout << "Signal: BUY (option is underpriced)\n";
    else if (modelPrice + epsilon < marketPrice)
        cout << "Signal: SELL (option is overpriced)\n";
    else
        cout << "Signal: HOLD (fairly priced)\n";
}
