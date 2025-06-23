#include <iostream>
#include <iomanip>
#include <string>
#include "black_scholes.h"
#include "trade_signals.h"

using namespace std;

void displayMenu() {
    cout << "\n===== AlgoTrade-CMD =====\n";
    cout << "1. Black-Scholes Option Pricing\n";
    cout << "2. Generate Basic Trade Signal\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

bool isValidOptionType(const string& type) {
    return type == "call" || type == "put";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        double S, K, T, r, sigma, marketPrice;
        string type;

        switch (choice) {
            case 1:
                cout << "Enter Spot Price (S): ";
                cin >> S;
                cout << "Enter Strike Price (K): ";
                cin >> K;
                cout << "Enter Time to Maturity in Years (T): ";
                cin >> T;
                cout << "Enter Volatility (sigma, e.g. 0.2): ";
                cin >> sigma;
                cout << "Enter Risk-Free Rate (r, e.g. 0.05): ";
                cin >> r;
                cout << "Enter Option Type (call/put): ";
                cin >> type;

                if (!isValidOptionType(type)) {
                    cout << "Invalid option type entered. Please enter 'call' or 'put'.\n";
                    break;
                }

                if (S <= 0 || K <= 0 || T <= 0 || sigma <= 0) {
                    cout << "Inputs must be positive values.\n";
                    break;
                }

                cout << fixed << setprecision(4);
                cout << "Option Price: " 
                     << blackScholesPrice(S, K, T, sigma, r, type) 
                     << "\n";
                break;

            case 2:
                cout << "Enter Spot Price (S): ";
                cin >> S;
                cout << "Enter Strike Price (K): ";
                cin >> K;
                cout << "Enter Time to Maturity in Years (T): ";
                cin >> T;
                cout << "Enter Volatility (sigma, e.g. 0.2): ";
                cin >> sigma;
                cout << "Enter Risk-Free Rate (r, e.g. 0.05): ";
                cin >> r;
                cout << "Enter Option Type (call/put): ";
                cin >> type;
                cout << "Enter Market Option Price: ";
                cin >> marketPrice;

                if (!isValidOptionType(type)) {
                    cout << "Invalid option type entered. Please enter 'call' or 'put'.\n";
                    break;
                }

                if (S <= 0 || K <= 0 || T <= 0 || sigma <= 0) {
                    cout << "Inputs must be positive values.\n";
                    break;
                }

                generateTradeSignal(S, K, T, sigma, r, type, marketPrice);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
