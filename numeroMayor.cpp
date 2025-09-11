#include <iostream>

using namespace std;

int main() {
    // Declaramos las variables
    int numero1, numero2, numero3;
    int mayor;

    // Asignamos valores a las variables
    cout << "Ingrese el primer numero: ";
    cin >> numero1; 

    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

    cout << "Ingrese el tercer numero: ";
    cin >> numero3;

    // Determinar el mayor
    if (numero1 >= numero2 && numero1 >= numero3) {
        mayor = numero1;
    } else if (numero2 >= numero1 && numero2 >= numero3) {
        mayor = numero2;
    } else {
        mayor = numero3;
    }

    // Imprimimos los resoltados
    cout << "El numero mayor es: " << mayor << endl;
    
    return 0;
}