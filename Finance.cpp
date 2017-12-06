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
using namespace std;

//Global variables
double grossAverage; //monthly income variable
double rent[3];
double electricBill[3]; //electric bill due
double internetBill[3]; //internet bill due
double creditCardBill[3]; //credit card bill due
double gasBill[3]; //gas bill due
double carLoan[3]; //car payment due
double carInsurance[3]; // car insurance bill due
double entertainment[3];//entertaiment expense
double food[3]; //food expense
double cellphone[3]; //cell phone expense
double health[3]; // health expense
double transportation[3]; // transportation expense
double other[3]; //other expense not listed in list

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
  return grossAverage, rent, electricBill, internetBill, gasBill, creditCardBill, carLoan, carInsurance;
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
  rent[1] = (rent[0] * 100) / grossAverage;
  electricBill[1] = (electricBill[0] * 100) / grossAverage;
  internetBill[1] = (internetBill[0] * 100) / grossAverage;
  creditCardBill[1] = (creditCardBill[0] * 100) / grossAverage;
  gasBill[1] = (gasBill[0] * 100) / grossAverage;
  carLoan[1] = (carLoan[0] * 100) / grossAverage;
  carInsurance[1] = (carInsurance[0] * 100) / grossAverage;
  entertainment[1] = (entertainment[0] * 100) / grossAverage;
  food[1] = (food[0] * 100) / grossAverage;
  cellphone[1] = (cellphone[0] * 100) / grossAverage;
  health[1] = (health[0] * 100) / grossAverage;
  transportation[1] = (transportation[0] * 100) / grossAverage;

  return rent, electricBill, internetBill, creditCardBill, gasBill, carLoan, carInsurance, entertainment, food, cellphone, health, transportation;
}

//function to calculate annual amount spent on those bills
double calculateAnnual() {
  rent[2] = rent[0] * 12;
  electricBill[2] = electricBill[0] * 12;
  internetBill[2] = internetBill[0] * 12;
  creditCardBill[2] = creditCardBill[0] * 12;
  gasBill[2] = gasBill[0] * 12;
  carLoan[2] = carLoan[0] * 12;
  carInsurance[2] = carInsurance[0] * 12;
  entertainment[2] = entertainment[0] * 12;
  food[2] = food[0] * 12;
  cellphone[2] = cellphone[0] * 12;
  health[2] = health[0] * 12;
  transportation[2] = transportation[0] * 12;
  return rent, electricBill, internetBill, creditCardBill, gasBill, carLoan, carInsurance, entertainment, food, cellphone, health, transportation;
}

//function to print chart showing finance information
void chart() {
  cout << "Distribution of Income" << endl;
  cout << "-------------------------------------------------------------------" << endl;
  cout << "Bill      "<<"    Percent of Income     " << "   Annual Cost" << endl;
  cout << "-------------------------------------------------------------------" << endl;
  cout << "Rent/Mortgage" << setw(7)<< rent[1] << rent[2] << endl;
  cout << "Electric Bill" << setw(7) << electricBill[1] << electricBill[2] << endl;
  cout << "Internet Bill" << setw(7) << internetBill[1] << internetBill[2] << endl;
  cout << "Credit Card Bill" << setw(7) << creditCardBill[1] << creditCardBill[2] << endl;
  cout << "Gas Bill" << setw(7) << gasBill[1] << gasBill[2] << endl;
  cout << "Car Loan" << setw(7) << carLoan[1] << carLoan[2] << endl;
  cout << "Car Insurance" << setw(7) << carInsurance[1] << carInsurance[2] << endl;
  cout << "Entertainment" << setw(7) << entertainment[1] << entertainment[2] << endl;
  cout << "Food" << setw(7) << food[1] << food[2] << endl;
  cout << "Cellphone" << setw(7) << cellphone[1] << cellphone[2] << endl;
  cout << "Health" << setw(7) << health[1] << health[2] << endl;
  cout << "Transportation" << setw(7) << transportation[2] << transportation[2] << endl;
}

int main() {
  inputData();
  extraExpenses();
  calculate();
  chart();
  return 0;
}
