#include <iostream>
using namespace std;

int main() 
{
    int dollar_in_cents {100};                  // 1 dollar = 100 cents.
    int quarter_in_cents {25};                  // 1 quarter = 25 cents.
    int dime_in_cents {10};                     // 1 dime = 10 cents.
    int nickel_in_cents {5};                    // 1 nickel = 5 cents.
    int penny_in_cents {1};                     // 1 penny = 1 cent.
    int dollar, quarter, dime, nickel, penny;
    int cents;

    
    cout << boolalpha;                          // This displays true and false instead of 1 and 0.
    cout << "Enter an amount in cents: ";
    cin >> cents;

    dollar = cents / dollar_in_cents;
    cents = cents % dollar_in_cents;            // Gives remainder.

    quarter = cents / quarter_in_cents;
    cents = cents % quarter_in_cents;

    dime = cents / dime_in_cents;
    cents = cents % dime_in_cents;

    nickel = cents / nickel_in_cents;
    cents = cents % nickel_in_cents;

    penny = cents / penny_in_cents;
    
    cout << "Dollars: " << dollar << endl;
    cout << "Quarters: " << quarter << endl;
    cout << "Dimes: " << dime << endl;
    cout << "Nickels: " << nickel << endl;
    cout << "Pennies: " << penny << endl;

    return 0;
}
