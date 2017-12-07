/* C++ Project by Evelyn Garcia
The purpose of this program is to give you patterns of your expenses
It will be based off monthly expenses/income
Based off monthly can determine your annual and biannual averages
Working on outliers that may skew data
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;

//Global variables
double grossAverage = 0; //monthly income variable
double rent[] = {0.0, 0.0, 0.0};
double electricBill[] = {0.0, 0.0, 0.0}; //electric bill due
double internetBill[] = {0.0, 0.0, 0.0}; //internet bill due
double creditCardBill[] = {0.0, 0.0, 0.0}; //credit card bill due
double gasBill[] = {0.0, 0.0, 0.0}; //gas bill due
double carLoan[] = {0.0, 0.0, 0.0}; //car payment due
double carInsurance[] = {0.0, 0.0, 0.0}; // car insurance bill due
double entertainment[] = {0.0, 0.0, 0.0};//entertaiment expense
double food[] = {0.0, 0.0, 0.0}; //food expense
double cellphone[] = {0.0, 0.0, 0.0}; //cell phone expense
double health[] = {0.0, 0.0, 0.0}; // health expense
double transportation[] = {0.0, 0.0, 0.0}; // transportation expense
double other[] = {0.0, 0.0, 0.0}; //other expense not listed in list

//Function for generic bills
double inputData () {
  //User input income
  cout << "Enter monthly average gross income: ";
  cin >> grossAverage; //Monthly average
  cout << endl;
  cout << endl;
  //User input bills
  cout << "Next we will enter bill information." << endl;
  cout << "Rent/Mortgage: ";
  cin >> rent[0]; //rent first double of array
  cout << "Electric bill: ";
  cin >> electricBill[0]; // electric first double in array
  cout << "Internet bill: ";
  cin >> internetBill[0]; // internet first double in array
  cout << "Gas bill: ";
  cin >> gasBill[0];// gas bill first double in array
  cout << "Credit card bill: ";
  cin >> creditCardBill[0]; //credit card bill first double in array
  cout << "Car loan: ";
  cin >> carLoan[0]; // car loan first double in array
  cout<< "Car Insurance: ";
  cin >> carInsurance[0]; // car Insurance first double in array
  //Return all values in order to make them usable in future functions
  // Using all first numbers of arrays
  return grossAverage, rent[0], electricBill[0], internetBill[0], gasBill[0], creditCardBill[0], carLoan[0], carInsurance[0];
}

//Function for extra bills/expenses
double extraExpenses() {
  //response variable
  char response;
  //user input
  cout << endl << endl;
  cout << "Are there other monthly expenses you would like to add? (Y/N): ";
  cin >> response; //if else determined by input
  //If there are more responses user can choose from a number of categories
  //Categories will then lead to input
  while (response == 'Y' || response == 'N') { //categories visual
    if (response == 'Y') {
    char extraExpense;
    cout << "Please choose a category: " << endl; //Currently 5 options
    cout << "--------------------------" << endl; //chart
    cout << "A - Entertainment" << endl;
    cout << "B - Food/Groceries" << endl;
    cout << "C - Cell Phone" << endl;
    cout << "D - Gym/Health" << endl;
    cout << "E - Transportation/Gas" << endl;
    cout << "F - Other" << endl;
    cin >> extraExpense;//user input for extra expenses
    switch(extraExpense) {
      case 'A':   cout << "Entertainment expense: ";
                  cin >> entertainment[0]; //entertainment expense
                  break;
      case 'B':   cout  << "Food/Groceries expense: ";
                  cin >> food[0];//food expense
                  break;
      case 'C':   cout << "Cell phone expense: ";
                  cin >> cellphone[0];//cell phone expense
                  break;
      case 'D':   cout << "Gym/Health expense: ";
                  cin >> health[0];//health expense
                  break;
      case 'E':   cout << "Transportation/Gas expense: ";
                  cin >> transportation[0];//tranpostation expense
                  break;
      case 'F':   cout << "Other expense: ";
                  cin >> other[0]; //other expenses not on list
                  break;
      default:    cout << "Invalid response"; //all other inputs
    }
    char additions; //user input for additional expenses
    cout << "Are there more expenses? (Y/N): ";
    cin >> additions; //user input from previous question
    if (additions == 'Y') { continue;} //reloop
    else {
      cout << "Great all data has been taken" << endl;
      break; //end loop
    }
}
  else { //Output if no other expenses are being added
    cout << "Great all data has been taken" << endl;
    break; // end loop
    }
  }
}

//function to calculate percentage of income for each bill
double calculatePercent() {
  double percent = 100; //Multiply by 100 for percent
  rent[1] = (rent[0] * percent) / grossAverage; //rent percent
  electricBill[1] = (electricBill[0] * percent) / grossAverage; //electric percent
  internetBill[1] = (internetBill[0] * percent) / grossAverage; // internet percent
  creditCardBill[1] = (creditCardBill[0] * percent) / grossAverage; // credit card percent
  gasBill[1] = (gasBill[0] * percent) / grossAverage; // gas percent
  carLoan[1] = (carLoan[0] * percent) / grossAverage; // car loan percent
  carInsurance[1] = (carInsurance[0] * percent) / grossAverage;// car insurance percent
  entertainment[1] = (entertainment[0] * percent) / grossAverage; // entertainment percent
  food[1] = (food[0] * percent) / grossAverage; // food expenses percent
  cellphone[1] = (cellphone[0] * percent) / grossAverage; //cell phone percent
  health[1] = (health[0] * percent) / grossAverage;//health percent
  transportation[1] = (transportation[0] * percent) / grossAverage; //transportation percent
  other[1] = (other[0] * percent) / grossAverage; //other percent

  //Return all values in order to make them usable in future functions
  // Using all second numbers of arrays
  return rent[1], electricBill[1], internetBill[1], creditCardBill[1], gasBill[1], carLoan[1], carInsurance[1], entertainment[1], food[1], cellphone[1], health[1], transportation[1], other[1];
}

//function to calculate annual amount spent on those bills
double calculateAnnual() {
  double months = 12; //number of months in a year
  rent[2] = rent[0] * months; //rent annual spent
  electricBill[2] = electricBill[0] * months; //electric annual spent
  internetBill[2] = internetBill[0] * months;//internet annual spent
  creditCardBill[2] = creditCardBill[0] * months;//credit card annual spent
  gasBill[2] = gasBill[0] * months; //gas annual spent
  carLoan[2] = carLoan[0] * months; //car loan annual spent
  carInsurance[2] = carInsurance[0] * months;//car insurane annual spent
  entertainment[2] = entertainment[0] * months; //entertainment annual spent
  food[2] = food[0] * months; //food annual spent
  cellphone[2] = cellphone[0] * months; //cellphone annual spent
  health[2] = health[0] * months; //health annual spent
  transportation[2] = transportation[0] * months; //transportation annual spent
  other[2] = other[0] * months; //other annual spent

  //Return all values in order to make them usable in future functions
  // Using all third numbers of arrays
  return rent[2], electricBill[2], internetBill[2], creditCardBill[2], gasBill[2], carLoan[2], carInsurance[2], entertainment[2], food[2], cellphone[2], health[2], transportation[2], other[2];
}

//function to calculate totals for all values
double calculateTotals() {
  double totalMonthly = 0;
  double totalPercentage = 0;
  double totalAnnual = 0;

  totalMonthly = rent[0] + electricBill[0] + internetBill[0] + creditCardBill[0] + gasBill[0] + carLoan[0] + carInsurance[0] + entertainment[0] + food[0] + cellphone[0] + health[0] + transportation[0] + other[0];
}

//function to print chart showing finance information
char chart() {
  const int width = 30; //spacing for chart values
  const char separator = ' '; //spacing

  cout << "Distribution of Income" << endl; //title of chart
  cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
  //Title of bill followed by percent income and then total annual cost
  cout << left << setw(width) << setfill(separator) << "Bill";
  cout << left << setw(width) << setfill(separator) << "Monthly Payment";
  cout << left << setw(width) << setfill(separator) << "Percent of Income";
  cout << left << setw(width) << setfill(separator) << "Total Annual Cost" << endl;
  cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
  //All information properly spaced using array values
  cout << left << setw(width) << setfill(separator) << "Rent/Mortgage";
  cout << left << setw(width) << setfill(separator) << rent[0];
  cout << left << setw(width) << setfill(separator) << rent[1];
  cout << left << setw(width) << setfill(separator) << rent[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Electric Bill";
  cout << left << setw(width) << setfill(separator) << electricBill[0];
  cout << left << setw(width) << setfill(separator) << electricBill[1];
  cout << left << setw(width) << setfill(separator) << electricBill[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Internet Bill";
  cout << left << setw(width) << setfill(separator) << internetBill[0];
  cout << left << setw(width) << setfill(separator) << internetBill[1];
  cout << left << setw(width) << setfill(separator) << internetBill[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Gas Bill";
  cout << left << setw(width) << setfill(separator) << gasBill[0];
  cout << left << setw(width) << setfill(separator) << gasBill[1];
  cout << left << setw(width) << setfill(separator) << gasBill[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Credit Card Bill";
  cout << left << setw(width) << setfill(separator) << creditCardBill[0];
  cout << left << setw(width) << setfill(separator) << creditCardBill[1];
  cout << left << setw(width) << setfill(separator) << creditCardBill[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Car Payment";
  cout << left << setw(width) << setfill(separator) << carLoan[0];
  cout << left << setw(width) << setfill(separator) << carLoan[1];
  cout << left << setw(width) << setfill(separator) << carLoan[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Car Insurance";
  cout << left << setw(width) << setfill(separator) << carInsurance[0];
  cout << left << setw(width) << setfill(separator) << carInsurance[1];
  cout << left << setw(width) << setfill(separator) << carInsurance[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Entertainment Expenses";
  cout << left << setw(width) << setfill(separator) << entertainment[0];
  cout << left << setw(width) << setfill(separator) << entertainment[1];
  cout << left << setw(width) << setfill(separator) << entertainment[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Food Expenses";
  cout << left << setw(width) << setfill(separator) << food[0];
  cout << left << setw(width) << setfill(separator) << food[1];
  cout << left << setw(width) << setfill(separator) << food[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Cell Phone Bill";
  cout << left << setw(width) << setfill(separator) << cellphone[0];
  cout << left << setw(width) << setfill(separator) << cellphone[1];
  cout << left << setw(width) << setfill(separator) << cellphone[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Health Expenses";
  cout << left << setw(width) << setfill(separator) << health[0];
  cout << left << setw(width) << setfill(separator) << health[1];
  cout << left << setw(width) << setfill(separator) << health[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Transportation expenses";
  cout << left << setw(width) << setfill(separator) << transportation[0];
  cout << left << setw(width) << setfill(separator) << transportation[1];
  cout << left << setw(width) << setfill(separator) << transportation[2] << endl;
  cout << left << setw(width) << setfill(separator) << "Other expenses";
  cout << left << setw(width) << setfill(separator) << other[0];
  cout << left << setw(width) << setfill(separator) << other[1];
  cout << left << setw(width) << setfill(separator) << other[2] << endl << endl;
  cout << left << setw(width) << setfill(separator) << "Total";
  cout << left << setw(width) << setfill(separator) << totalMonthly;
  cout << left << setw(width) << setfill(separator) << totalPercentage;
  cout << left << setw(width) << setfill(separator) << totalAnnual << endl;
}

int main() {
  inputData();
  extraExpenses();
  calculatePercent();
  calculateAnnual();
  chart();
  return 0;
}
