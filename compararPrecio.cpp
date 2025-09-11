#include <iostream>
#include <vector>

using namespace std;

int main(){
    double nuevoPrecio, promedio;
    vector<double> listaPrecios = {40.32, 34.98, 53.56, 32.90, 33.35};

    cout << "Ingrese el monto a Comparar ----------------------------------------" << endl;
    cin >> nuevoPrecio;

    if (nuevoPrecio < 0)
    {
        cout << "Este monto no es Valido :(" << endl;
        cout << "" << endl;
        return 0;
    }

    for (int i = 0; i < 5; i++)
    {
        if (listaPrecios[i] == nuevoPrecio)
        {
            cout << "El monto es igual a la Empresa " << (i + 1) << endl;
        }

        promedio = promedio + listaPrecios[i];
    }

    promedio = promedio / 5;

    if (nuevoPrecio > promedio)
    {
        cout << "El monto: " << nuevoPrecio << ", Es mayor al Promedio: " << promedio << endl;
    }else{
        cout << "El monto: " << nuevoPrecio << ", Es menor al Promedio: " << promedio << endl;
    }
    
    
    

    return 0;
}