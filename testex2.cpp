#include <iostream>
using namespace std;

class Date {
public:
    int year;
    int month;
    int day;

    void input() {
        
        do {
            cout << "Enter year :";
            cin >> year;
            if (year <= 0) {
                cout << "Invalid year. Please enter a positive number." << endl;
            }
        } while (year <= 0);

        
        do {
            cout << "Enter month : ";
            cin >> month;
            if (month < 1 || month > 12) {
                cout << "Invalid month. Please enter a value between 1 and 12." << endl;
            }
        } while (month < 1 || month > 12);

        
        int maxDays = getMaxDaysInMonth(month, year);
        do {
            cout << "Enter day : ";
            cin >> day;
            if (day < 1 || day > maxDays) {
                cout << "Invalid day. Please enter a value between 1 and " << maxDays << "." << endl;
            }
        } while (day < 1 || day > maxDays);
    }

private:

    int getMaxDaysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:

                if (isLeapYear(year)) {
                    return 29;
                } else {
                    return 28;
                }
            default:
                return 0;
        }
    }

    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true; 
                } else {
                    return false; 
                }
            } else {
                return true;
            }
        }
        return false; 
    }
};


int compareDates(const Date& date1, const Date& date2) {
    if (date1.year < date2.year) {
        return -1;
    } else if (date1.year > date2.year) {
        return 1;
    }

    if (date1.month < date2.month) {
        return -1;
    } else if (date1.month > date2.month) {
        return 1;
    }

    if (date1.day < date2.day) {
        return -1;
    } else if (date1.day > date2.day) {
        return 1;
    }

    return 0;
}

int main() {
    Date date1, date2;

    cout << "Enter Person 1:" << endl;
    date1.input();

    cout << "\nEnter Person 2:" << endl;
    date2.input();

    int result = compareDates(date1, date2);

    if (result == -1) {
        cout << "\nPerson 2 is youngest." << endl;
    } else if (result == 1) {
        cout << "\nPerson 1 is youngest." << endl;
    } else {
        cout << "\nBoth Person are the same." << endl;
    }

    return 0;
}


