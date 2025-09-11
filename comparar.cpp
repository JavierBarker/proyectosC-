#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    cout << "=== COMPARADOR DE DOS NÚMEROS ===" << endl;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    
    cout << "\n--- RESULTADO ---" << endl;
    if (num1 > num2) {
        cout << "El mayor es: " << num1 << endl;
    }
    else if (num1 < num2) {
        cout << "El mayor es: " << num2 << endl;
    }
    else {
        cout << "Los números son iguales (" << num1 << ")" << endl;
    }
    
    return 0;
}