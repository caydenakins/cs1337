#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()
{
   string name;
   double share, purchase, sale, purchaseStock, purchaseCommission, saleStock, saleCommission, cost, income;

   cout << "Enter name of the company" << endl;
   getline(cin, name);
   cout << "Enter shares of stock" << endl;
   cin >> share;
   cout << "Enter purchase price" << endl;
   cin >> purchase;
   cout << "Enter sale price" << endl;
   cin >> sale;

   cout << "Company: " << name << endl;
   cout << "Shares: " << share << endl << endl;

   purchaseStock = share * purchase;
   purchaseCommission = purchaseStock * 0.035;
   cost = purchaseStock + purchaseCommission;

   cout << "Purchase/share: $" << setprecision(2) << fixed << purchase << endl;
   cout << "Cost of stock: $" << setprecision(2) << fixed << purchaseStock << endl;
   cout << "Cost of commission: $" << setprecision(2) << fixed << purchaseCommission << endl;
   cout << "Total cost: $" << setprecision(2) << fixed << cost << endl;

   saleStock = share * sale;
   saleCommission = saleStock * 0.035;
   income = saleStock - saleCommission;

   cout << "Sale/share: $" << setprecision(2) << fixed << sale << endl;
   cout << "Income from stock: $" << setprecision(2) << fixed << saleStock << endl;
   cout << "Cost of commission: $" << setprecision(2) << fixed << saleCommission << endl;
   cout << "Total income: $" << setprecision(2) << fixed << income << endl;
}
