#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    cout << "========== Basic Calculator ==========\n";

    cout << "Enter the first number: ";
    while (!(cin >> num1)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the second number: ";
    while (!(cin >> num2)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        result = num1 + num2;
        cout << "Result: " << result << endl;
    } 
    else if (operation == '-') {
        result = num1 - num2;
        cout << "Result: " << result << endl;
    } 
    else if (operation == '*') {
        result = num1 * num2;
        cout << "Result: " << result << endl;
    } 
    else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Result: " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed.\n";
        }
    } 
    else {
        cout << "Invalid operation. Please use +, -, *, or /.\n";
    }

    cout << "=====================================\n";

    return 0;
}