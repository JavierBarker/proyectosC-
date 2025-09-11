#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    bool validar = false;
    vector<int> lista = {1, 2, 4, 7, 9};

    cout << "---Encontrar Numero---" << endl;
    cout << "Ingrese el numero a buscar: ";
    cin >> num;

    for (int i = 0; i < static_cast<int>(lista.size()); i++) {
        if (lista[i] == num) {
            validar = true;
            break;
        }
    }

 
    if (validar == true) {
        cout << "El numero " << num << " se encuentra en la lista." << endl;
    } else {
        cout << "El numero " << num << " no se encuentra en la lista." << endl;
    }
    
    return 0;
}