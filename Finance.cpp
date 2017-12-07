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
  cin >> grossAverage;
  cout << endl;
  cout << endl;
  //User input bills
  cout << "Next we will enter bill information." << endl;
  cout << "Rent/Mortgage: ";
  cin >> rent[0];
  cout << "Electric bill: ";
  cin >> electricBill[0];
  cout << "Internet bill: ";
  cin >> internetBill[0];
  cout << "Gas bill: ";
  cin >> gasBill[0];
  cout << "Credit card bill: ";
  cin >> creditCardBill[0];
  cout << "Car loan: ";
  cin >> carLoan[0];
  cout<< "Car Insurance: ";
  cin >> carInsurance[0];
  //Return all values in order to make them usable in future functions
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
  double percent = 100;
  rent[1] = (rent[0] * percent) / grossAverage;
  electricBill[1] = (electricBill[0] * percent) / grossAverage;
  internetBill[1] = (internetBill[0] * percent) / grossAverage;
  creditCardBill[1] = (creditCardBill[0] * percent) / grossAverage;
  gasBill[1] = (gasBill[0] * percent) / grossAverage;
  carLoan[1] = (carLoan[0] * percent) / grossAverage;
  carInsurance[1] = (carInsurance[0] * percent) / grossAverage;
  entertainment[1] = (entertainment[0] * percent) / grossAverage;
  food[1] = (food[0] * percent) / grossAverage;
  cellphone[1] = (cellphone[0] * percent) / grossAverage;
  health[1] = (health[0] * percent) / grossAverage;
  transportation[1] = (transportation[0] * percent) / grossAverage;
  other[1] = (other[0] * percent) / grossAverage;

  return rent[1], electricBill[1], internetBill[1], creditCardBill[1], gasBill[1], carLoan[1], carInsurance[1], entertainment[1], food[1], cellphone[1], health[1], transportation[1];
}

//function to calculate annual amount spent on those bills
double calculateAnnual() {
  double months = 12;
  rent[2] = rent[0] * months;
  electricBill[2] = electricBill[0] * months;
  internetBill[2] = internetBill[0] * months;
  creditCardBill[2] = creditCardBill[0] * months;
  gasBill[2] = gasBill[0] * months;
  carLoan[2] = carLoan[0] * months;
  carInsurance[2] = carInsurance[0] * months;
  entertainment[2] = entertainment[0] * months;
  food[2] = food[0] * months;
  cellphone[2] = cellphone[0] * months;
  health[2] = health[0] * months;
  transportation[2] = transportation[0] * months;
  other[2] = other[0] * months;
  return rent[2], electricBill[2], internetBill[2], creditCardBill[2], gasBill[2], carLoan[2], carInsurance[2], entertainment[2], food[2], cellphone[2], health[2], transportation[2];
}

//function to print chart showing finance information
char chart() {
  const int nameWidth = 50;
  const int numWidth = 50;
  const char separator = ' ';

  cout << "Distribution of Income" << endl;
  cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << left << setw(nameWidth) << setfill(separator) << "Bill";
  cout << left << setw(nameWidth) << setfill(separator) << "Percent of Income";
  cout << left << setw(nameWidth) << setfill(separator) << "Total Annual Cost" << endl;
  cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << left << setw(nameWidth) << setfill(separator) << "Rent/Mortgage";
  cout << left << setw(numWidth) << setfill(separator) << rent[1];
  cout << left << setw(numWidth) << setfill(separator) << rent[2] << endl;
  cout << left << setw(nameWidth) << setfill(separator) << "Electric Bill";
  cout << left << setw(numWidth) << setfill(separator) << electricBill[1];
  cout << left << setw(numWidth) << setfill(separator) << electricBill[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Internet Bill";
  cout << left << setw(numWidth) << setfill(separator) << internetBill[1];
  cout << left << setw(numWidth) << setfill(separator) << internetBill[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Gas Bill";
  cout << left << setw(numWidth) << setfill(separator) << gasBill[1];
  cout << left << setw(numWidth) << setfill(separator) << gasBill[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Credit Card Bill";
  cout << left << setw(numWidth) << setfill(separator) << creditCardBill[1];
  cout << left << setw(numWidth) << setfill(separator) <<creditCardBill[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Car Payment";
  cout << left << setw(numWidth) << setfill(separator) << carLoan[1];
  cout << left << setw(numWidth) << setfill(separator) << carLoan[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Car Insurance";
  cout << left << setw(numWidth) << setfill(separator) << carInsurance[1];
  cout << left << setw(numWidth) << setfill(separator) << carInsurance[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Entertainment Expenses";
  cout << left << setw(numWidth) << setfill(separator) << entertainment[1];
  cout << left << setw(numWidth) << setfill(separator) << entertainment[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Food Expenses";
  cout << left << setw(numWidth) << setfill(separator) << food[1];
  cout << left << setw(numWidth) << setfill(separator) << food[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Cell Phone Bill";
  cout << left << setw(numWidth) << setfill(separator) << cellphone[1];
  cout << left << setw(numWidth) << setfill(separator) << cellphone[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Health Expenses";
  cout << left << setw(numWidth) << setfill(separator) << health[1];
  cout << left << setw(numWidth) << setfill(separator) << health[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Transportation expenses";
  cout << left << setw(numWidth) << setfill(separator) << transportation[1];
  cout << left << setw(numWidth) << setfill(separator) << transportation[2] << endl;
  cout << left << setw(numWidth) << setfill(separator) << "Other expenses";
  cout << left << setw(numWidth) << setfill(separator) << other[1];
  cout << left << setw(numWidth) << setfill(separator) << other[2];
}

int main() {
  inputData();
  extraExpenses();
  calculatePercent();
  calculateAnnual();
  chart();
  return 0;
}
