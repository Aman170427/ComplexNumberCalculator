#include <iostream>
#include <limits>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Parameterized constructor
    Complex(double r = 0, double i = 0)
    {
        real = r;
        imag = i;
    }

    // Overloading + operator
    Complex operator+(const Complex& c) const
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overloading - operator
    Complex operator-(const Complex& c) const
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overloading << operator
    friend ostream& operator<<(ostream& out, const Complex& c)
    {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";

        return out;
    }
};

// Function to accept valid numeric input
double getNumber(const char message[])
{
    double value;

    while (true)
    {
        cout << message;

        if (cin >> value)
            return value;

        cout << "Invalid input! Please enter a valid number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "   COMPLEX NUMBER CALCULATOR\n";
        cout << "================================\n";
        cout << "1. Perform Addition and Subtraction\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter 1 or 2.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            double r1, i1, r2, i2;

            r1 = getNumber("Enter real part of first number: ");
            i1 = getNumber("Enter imaginary part of first number: ");

            r2 = getNumber("Enter real part of second number: ");
            i2 = getNumber("Enter imaginary part of second number: ");

            Complex c1(r1, i1);
            Complex c2(r2, i2);

            Complex sum = c1 + c2;
            Complex difference = c1 - c2;

            cout << "\nFirst Complex Number: " << c1;
            cout << "\nSecond Complex Number: " << c2;
            cout << "\nAddition Result: " << sum;
            cout << "\nSubtraction Result: " << difference << "\n";

            break;
        }

        case 2:
            cout << "Thank you for using the calculator!\n";
            break;

        default:
            cout << "Invalid choice! Please select 1 or 2.\n";
        }

    } while (choice != 2);

    return 0;
}

