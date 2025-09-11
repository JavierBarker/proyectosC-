#include <iostream>

using namespace std;

int main() {
    int numero;

    cout << "Tabla de multiplicar" << endl;
    cout << "---------------------" << endl;
    cout << "Ingrese un numero para generar la tabla: ";
    cin >> numero;

    cout << "" << endl;
    cout << "Tabla del " << numero << ":" << endl;
    cout << "---------------------" << endl;
    for (int i = 1; i <= 10; i++) 
    {
        cout << numero << " x " << i << " = " << numero * i << endl;
    }
    
    return 0;
}