#include <iostream>
using namespace std;

int main() {
    double num1, num2, resultado; 
    char operacion; 
     
    cout << "Ingrese el primer numero: "; 
    cin >> num1; 
    cout << "Ingrese la operacion (+, -, *, /): "; 
    cin >> operacion; 
    cout << "Ingrese el segundo numero: "; 
    cin >> num2; 
     
    switch(operacion) { 
        case '+': 
            resultado = num1 + num2; 
            break; 
        case '-': 
            resultado = num1 - num2; 
            break; 
        case '*': 
            resultado = num1 * num2; 
            break; 
        case '/': 
            if(num2 != 0) { 
                resultado = num1 / num2; 
            } else { 
                cout << "Error: Division por cero" << endl; 
                return 1; 
            } 
            break; 
        default: 
            cout << "Operacion no valida" << endl; 
            return 1; 
    } 
     
    cout << "Resultado: " << resultado << endl; 
    
    return 0;
}