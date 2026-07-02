#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operacion;

    cout << "=== Kalkulatori Im ===" << endl;
    cout << "Shkruaj numrin e pare: ";
    cin >> num1;

    cout << "Shkruaj operacionin (+, -, *, /): ";
    cin >> operacion;

    cout << "Shkruaj numrin e dyte: ";
    cin >> num2;

    double rezultati;

    if (operacion == '+') {
        rezultati = num1 + num2;
    } else if (operacion == '-') {
        rezultati = num1 - num2;
    } else if (operacion == '*') {
        rezultati = num1 * num2;
    } else if (operacion == '/') {
        if (num2 == 0) {
            cout << "Gabim: nuk mund te pjesetosh me zero!" << endl;
            return 1;
        }
        rezultati = num1 / num2;
    } else {
        cout << "Operacion i panjohur!" << endl;
        return 1;
    }

    cout << "Rezultati: " << rezultati << endl;

    return 0;
}