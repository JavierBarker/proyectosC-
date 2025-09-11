#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double primeraCalificacion, segundaCalificacion, terceraCalificacion, promedio;

    cout << "---Ingrese la Primera Calificacion (del 0 al 10): " << endl;
    cin >> primeraCalificacion;

    cout << "---Ingrese la Segunda Calificacion (del 0 al 10): " << endl;
    cin >> segundaCalificacion;

    cout << "---Ingrese la Tercera Calificacion (del 0 al 10): " << endl;
    cin >> terceraCalificacion;

    promedio = (primeraCalificacion + segundaCalificacion + terceraCalificacion) / 3;
    if (promedio >= 7)
    {
        cout << "El Alumno Aprobo: " << fixed << setprecision(2) << promedio << endl;
    }else{
        cout << "El Alumno no Aprobo: " << fixed << setprecision(2) << promedio << endl;
    }

    return 0;
}
