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

//Function for generic bills
void inputData () {
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
}

//Function for extra bills/expenses
void extraExpenses() {
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
    cin >> extraExpense;
    switch(extraExpense) {
      case 'A':   cout << "Entertainment expense: ";
                  cin >> entertainment;
                  break;
      case 'B':   cout  << "Food/Groceries expense: ";
                  cin >> food;
                  break;
      case 'C':   cout << "Cell phone expense: ";
                  cin >> cellphone;
                  break;
      case 'D':   cout << "Gym/Health expense: ";
                  cin >> health;
                  break;
      case 'E':   cout << "Transportation/Gas expense: ";
                  cin >> transportation;
                  break;
      default:    cout << "Invalid response";
    }
    char additions;
    cout << "Are there more expenses? (Y/N): ";
    cin >> additions;
    if (additions == 'Y') { continue;}
    else {
      cout << "Great all data has been taken";
      break;
    }
}
  else {
    cout << "Great all data has been taken";
    break;
    }
  }
}

int main() {
  inputData();
  extraExpenses();
  return 0;
}
