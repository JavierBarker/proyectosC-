#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>


using namespace std;

//variables globales
string usuario, contrasenha;

void mostrarMenu();
int calcularCubo(int numero);
int multiplicar(int numero1, int numero2);

int main(){
    SetConsoleOutputCP(CP_UTF8); // Habilitar UTF-8

    //validar usuario y contraseña
    cout << "Ingrese su usuario: ";
    getline(cin, usuario);  

    cout << "Ingrese su contraseña: ";
    getline(cin, contrasenha);
    cout << endl;

    if (usuario == "admin" && contrasenha == "admin123") {
        cout << "¡Inicio de sesión exitoso! Bienvenido, " << usuario << ". ✅" << endl;
        cout << endl;
        mostrarMenu();
    } else {
        cout << "🚨 Usuario o contraseña incorrectos. 🚨" << endl;
        cout << endl;
    }
    

    return 0;
}

void mostrarMenu(){
    int opcion;
    do
    {
        cout << "----------MENÚ DE OPCIONES----------" << endl;
        cout << "1. Calcular Cubo 💢" << endl;
        cout << "2. Multiplicar 2 Números ✖️" << endl;
        cout << "3. Salir." << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << endl;

        switch (opcion){
            case 1:
                cout << "----------CALCULAR CUBO----------" << endl;
                float numero;
                cout << "Ingrese un número: ";
                cin >> numero;
                cin.ignore(); // Limpiar el buffer de entrada
                cout << endl;
                cout << "El cubo de " << numero << " es: " << calcularCubo(numero) << endl;
                cout << endl;
            break;

            case 2:
                int numero1, numero2;
                cout << "----------MULTIPLICAR 2 NÚMEROS----------" << endl;
                cout << "Ingrese el primer número: ";
                cin >> numero1;
                cout << "Ingrese el segundo número: ";
                cin >> numero2;
                cin.ignore(); // Limpiar el buffer de entrada
                cout << endl;

                cout << "El resultado de la multiplicación es: " << to_string(multiplicar(numero1, numero2)) << endl;
                cout << endl;
            break;

            case 3:
                cout << "¡Hasta luego! Usuario: " << usuario << " 🫡" << endl;
                cout << endl;

            break;

            default: 
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                cout << endl;
        }
    } while (opcion != 3);
}

int calcularCubo(int numero){
    return numero * numero * numero;
}

int multiplicar(int numero1, int numero2){
    return numero1 * numero2;
}