/*
 * Author: Cayden Akins - CRA190000
 * Class: CS 1337.
 * Date: 1/27/20
 * Description: This program will determine which movie service a user should
 * choose based on the information (cost per day) they give, basing the choice
 * off of the cheapest one.
 *
 * Literals, Named/Symbolic Constants, and Variables:
 * netflixMonthly, vuduMonthly, huluMonthly, disneyPlusMonthly, amazonMonthly,
 * netflixRentPerDay, vuduRentPerDay, huluRentPerDay, disneyPlusRentPerDay,
 * amazonRentPerDay, totalCostNetflix, totalCostVudu, totalCostHulu,
 * totalCostDisneyPlus, totalCostAmazon, cheapestServiceCost,
 * expensiveServiceCost, amountSaved, daysTotal, movieTitle,
 * cheapestServiceName.
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  const double netflixMonthly = 8.99,
               vuduMonthly = 4.99,
               huluMonthly = 6.99,
               disneyPlusMonthly = 9.99,
               amazonMonthly = 9.69;

  double netflixRentPerDay = 0,
         vuduRentPerDay = 0,
         huluRentPerDay = 0,
         disneyPlusRentPerDay = 0,
         amazonRentPerDay = 0;

  double totalCostNetflix = 0,
         totalCostVudu = 0,
         totalCostHulu = 0,
         totalCostDisneyPlus = 0,
         totalCostAmazon = 0;

  double cheapestServiceCost,
         expensiveServiceCost,
         amountSaved;

  int daysTotal;
  string movieTitle,
         cheapestServiceName;

  // Gets the name of the movie the user inputs
  cout << "What is the name of the movie? ";
  getline(cin, movieTitle);
  cout << endl;

  // Gets the total rent per day for each service
  cout << "What is the rent per day for Netflix? ";
  cin >> netflixRentPerDay;
  cout << endl;

  cout << "What is the rent per day for Vudu? ";
  cin >> vuduRentPerDay;
  cout << endl;

  cout << "What is the rent per day for Hulu? ";
  cin >> huluRentPerDay;
  cout << endl;

  cout << "What is the rent per day for Disney Plus? ";
  cin >> disneyPlusRentPerDay;
  cout << endl;

  cout << "What is the rent per day for Amazon? ";
  cin >> amazonRentPerDay;
  cout << endl;

  cout << "How many days would you like to keep the movie? ";
  cin >> daysTotal;
  cout << endl;

  // Assigns totals for each service
  totalCostNetflix = (netflixRentPerDay * daysTotal) + netflixMonthly;
  totalCostVudu = (vuduRentPerDay * daysTotal) + vuduMonthly;
  totalCostHulu = (huluRentPerDay * daysTotal) + huluMonthly;
  totalCostDisneyPlus = (disneyPlusRentPerDay * daysTotal) + disneyPlusMonthly;
  totalCostAmazon = (amazonRentPerDay * daysTotal) + amazonMonthly;

  // Initialize Netflix as the cheapest service cost by default, replacing
  // the cheapest if the next service compared is less than the current double
  // assigned, as well as giving the string name for each service
  cheapestServiceCost = totalCostNetflix;
  cheapestServiceName = "Netflix";

  if (totalCostVudu < cheapestServiceCost) {
    cheapestServiceCost = totalCostVudu;
    cheapestServiceName = "Vudu";
  }

  if (totalCostHulu < cheapestServiceCost) {
    cheapestServiceCost = totalCostHulu;
    cheapestServiceName = "Hulu";
  }

  if (totalCostDisneyPlus < cheapestServiceCost) {
    cheapestServiceCost = totalCostDisneyPlus;
    cheapestServiceName = "Disney Plus";
  }

  if (totalCostAmazon < cheapestServiceCost) {
    cheapestServiceCost = totalCostAmazon;
    cheapestServiceName = "Amazon";
  }

  // We also have to find the most expensive service in order to determine
  // the max amount of $$$ a user is able to save based on the choice selected
  expensiveServiceCost = totalCostNetflix;

  if (totalCostVudu > expensiveServiceCost)
    expensiveServiceCost = totalCostVudu;

  if (totalCostHulu > expensiveServiceCost)
    expensiveServiceCost = totalCostHulu;

  if (totalCostDisneyPlus > expensiveServiceCost)
    expensiveServiceCost = totalCostDisneyPlus;

  if (totalCostAmazon > expensiveServiceCost)
    expensiveServiceCost = totalCostAmazon;

  amountSaved = expensiveServiceCost - cheapestServiceCost;

  // Output of all calculations
  cout << left;
  cout << setw(22) << "RENT/DAY" << setw(15) << "# OF DAYS";
  cout << setw(15) << "SERVICE" << setw(10) << "TOTAL";
  cout << endl;

  cout << setfill('-') << setw(63) << "";
  cout << endl << setfill(' ');   // Reset fill to spaces for the movie section

  cout << setprecision(2) << fixed << setw(22) << netflixRentPerDay;
  cout << setw(15) << daysTotal << setw(15) << "Netflix";
  cout << setw(10) << setprecision(2) << fixed << totalCostNetflix << endl;

  cout << setprecision(2) << fixed << setw(22) << vuduRentPerDay;
  cout << setw(15) << daysTotal << setw(15) << "Vudu";
  cout << setw(10) << setprecision(2) << fixed << totalCostVudu << endl;

  cout << setprecision(2) << fixed << setw(22) << huluRentPerDay;
  cout << setw(15) << daysTotal << setw(15) << "Hulu";
  cout << setw(10) << setprecision(2) << fixed << totalCostHulu << endl;

  cout << setprecision(2) << fixed << setw(22) << disneyPlusRentPerDay;
  cout << setw(15) << daysTotal << setw(15) << "Disney Plus";
  cout << setw(10) << setprecision(2) << fixed << totalCostDisneyPlus << endl;

  cout << setprecision(2) << fixed << setw(22) << amazonRentPerDay;
  cout << setw(15) << daysTotal << setw(15) << "Amazon";
  cout << setw(10) << setprecision(2) << fixed << totalCostAmazon << endl;

  cout << setfill('-') << setw(63) << "";
  cout << endl;

  cout << "| Lowest price to rent \"" << movieTitle << "\" is ";
  cout << cheapestServiceName << ", you may save $";
  cout << setprecision(2) << fixed << amountSaved << " |";

  cout << endl;
  cout << setfill('-') << setw(63) << "";
  cout << endl;

  return 0;
}
