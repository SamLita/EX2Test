#include <iostream>
using namespace std;


bool isInside(int number, int min, int max) {
    return (number >= min && number <= max);
}

int main() {
    int number, min, max;

   
    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the minimum value of the range: ";
    cin >> min;
    cout << "Enter the maximum value of the range: ";
    cin >> max;

    
    while (min > max) {
        cout << "Minimum value is greater than the maximum value. Please enter the values again.\n";
        cout << "Enter the minimum value of the range: ";
        cin >> min;
        cout << "Enter the maximum value of the range: ";
        cin >> max;
    }

    
    if (isInside(number, min, max)) {
        cout << "inside\n";
    } else {
        cout << "outside\n";
    }

    return 0;
}
