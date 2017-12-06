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
double rent;
double electricBill; //electric bill due
double internetBill; //internet bill due
double creditCardBill; //credit card bill due
double gasBill; //gas bill due
double carLoan; //car payment due
double carInsurance; // car insurance bill due
double entertainment;//entertaiment expense
double food; //food expense
double cellphone; //cell phone expense
double health; // health expense
double transportation; // transportation expense
double other; //other expense not listed in list

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
  cin >> rent;
  cout << "Electric bill: ";
  cin >> electricBill;
  cout << "Internet bill: ";
  cin >> internetBill;
  cout << "Gas bill: ";
  cin >> gasBill;
  cout << "Credit card bill: ";
  cin >> creditCardBill;
  cout << "Car loan: ";
  cin >> carLoan;
  cout<< "Car Insurance: ";
  cin >> carInsurance;
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
                  cin >> entertainment; //entertainment expense
                  break;
      case 'B':   cout  << "Food/Groceries expense: ";
                  cin >> food;//food expense
                  break;
      case 'C':   cout << "Cell phone expense: ";
                  cin >> cellphone;//cell phone expense
                  break;
      case 'D':   cout << "Gym/Health expense: ";
                  cin >> health;//health expense
                  break;
      case 'E':   cout << "Transportation/Gas expense: ";
                  cin >> transportation;//tranpostation expense
                  break;
      case 'F':   cout << "Other expense: ";
                  cin >> other; //other expenses not on list
                  break;
      default:    cout << "Invalid response"; //all other inputs
    }
    char additions; //user input for additional expenses
    cout << "Are there more expenses? (Y/N): ";
    cin >> additions; //user input from previous question
    if (additions == 'Y') { continue;} //reloop
    else {
      cout << "Great all data has been taken" << endl << endl;
      break; //end loop
    }
}
  else { //Output if no other expenses are being added
    cout << "Great all data has been taken" << endl << endl;
    break; // end loop
    }
  }
}

//function to calculate percentage of income for each bill
double calculate() {
  rent = (rent * 100) / grossAverage;
  electricBill = (electricBill * 100) / grossAverage;
  internetBill = (internetBill * 100) / grossAverage;
  creditCardBill = (creditCardBill * 100) / grossAverage;
  gasBill = (gasBill * 100) / grossAverage;
  carLoan = (carLoan * 100) / grossAverage;
  carInsurance = (carInsurance * 100) / grossAverage;
  entertainment = (entertainment * 100) / grossAverage;
  food = (food * 100) / grossAverage;
  cellphone = (cellphone * 100) / grossAverage;
  health = (health * 100) / grossAverage;
  transportation = (transportation * 100) / grossAverage;

  return electricBill, rent, internetBill, creditCardBill, gasBill, carLoan, carInsurance, entertainment, food, cellphone, health, transportation;
}

//function to print chart showing finance information
void chart() {
  cout << "Distribution of Income" << endl;
  cout << "Rent/Mortgage" << setw(7)<< rent << endl;
  cout << "Electric Bill" << setw(7) << electricBill << endl;
  cout << "Internet Bill" << setw(7) << internetBill << endl;
  cout << "Credit Card Bill" << setw(7) << creditCardBill << endl;
  cout << "Gas Bill" << setw(7) << gasBill << endl;
  cout << "Car Loan" << setw(7) << carLoan << endl;
  cout << "Car Insurance" << setw(7) << carInsurance << endl;
  cout << "Entertainment" << setw(7) << entertainment << endl;
  cout << "Food" << setw(7) << food << endl;
  cout << "Cellphone" << setw(7) << cellphone << endl;
  cout << "Health" << setw(7) << health << endl;
  cout << "Transportation" << setw(7) << transportation << endl;
}

int main() {
  inputData();
  extraExpenses();
  calculate();
  chart();
  return 0;
}
