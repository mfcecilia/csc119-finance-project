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
int grossAverage; //monthly income variable
int electricBill; //electric bill due
int internetBill; //internet bill due
int creditCardBill; //credit card bill due
int gasBill; //gas bill due
int carLoan; //car payment due
int carInsurance; // car insurance bill due
int entertainment;//entertaiment expense
int food; //food expense
int cellphone; //cell phone expense
int health; // health expense
int transportation; // transportation expense
int other; //other expense not listed in list

//Function for generic bills
int inputData () {
  //User input income
  cout << "Enter monthly average gross income: ";
  cin >> grossAverage;
  //User input bills
  cout << "Next we will enter bill information." << endl;
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
  return grossAverage, electricBill, internetBill, gasBill, creditCardBill, carLoan, carInsurance;
}

//Function for extra bills/expenses
int extraExpenses() {
  //response variable
  char response;
  //user input
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
      cout << "Great all data has been taken";
      break; //end loop
    }
}
  else { //Output if no other expenses are being added
    cout << "Great all data has been taken";
    break; // end loop
    }
  }
}

//function to calculate percentage of income for each bill
int calculate() {
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

  return electricBill, internetBill, creditCardBill, gasBill, carLoan, carInsurance, entertainment, food, cellphone, health, transportation;
}

//function to print chart showing finance information
void chart() {
  cout << "Distribution of Income" << endl;
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
  return 0;
}
