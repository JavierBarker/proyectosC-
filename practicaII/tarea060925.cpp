#include <iostream>
#include <string>
#include <vector>

using namespace std;

//DECLARAR VARIABLES GLOBALES Y ESTRUCTURAS

struct Estudiante {
    string nombre;
    int edad;
    // vector<float> calificaciones{};
};

// DECLARANDO VARIABLES
Estudiante estudiantes [100];
int contadorEstudiantes = 0;

void mostrarMenu();
void registrarEstudiante(Estudiante nuevoEstudiante[], int &contador);

int main(){
    //mostrar menu
    mostrarMenu();
    return 0;
}


void mostrarMenu()
{
    int opcion;
    do
    {
        cout << "---------GESTIÓN DE CALIFICACIONES---------" << endl;
        cout << "1. Registrar un nuevo Estudiante 📖" << endl;
        cout << "2. Mostrar Estudiantes 📃" << endl;
        cout << "3. Buscar Estudiante por Nombre 🔔" << endl;
        cout << "4. Estudiante con Mejor Promedio 📠" << endl;
        cout << "5. Crear Archivo con los Aprobados 📚" << endl;
        cout << "6. Estadísticas 📚" << endl;
        cout << "7. Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            // registrarLibro(inventario, contadorLibros);
            cout << endl;
            break;
        case 2:
            // mostrarInventario(inventario, contadorLibros);
            cout << endl;
            break;
        case 3:
            // mostrarInventario();
            cout << endl;
            break;
        case 4:
            // mostrarInventario();
            cout << endl;
            break;
        case 5:
            // mostrarEstadisticas();
            cout << endl;
            break;
        case 6:
            // mostrarEstadisticas();
            cout << endl;
            break;
        case 7:
            cout << "Saliendo del programa... 🫡" << endl;
            cout << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo. 🚨" << endl;
            cout << endl;
        }
    } while (opcion != 7);
}

void registrarEstudiante(Estudiante nuevoEstudiante[], int &contador){

    cout << "----------REGISTRAR ESTUDIANTES----------" << endl;
    cout << "--Ingrese el Nombre del Estudiante: ";
    getline(cin, nuevoEstudiante[contador].nombre);
    cout << endl;
    cin.ignore();

    cout << "--Ingrese la Edad del Estudiante: ";
    cin >> nuevoEstudiante[contador].edad;
    cin.ignore();

    char opcion;
    // int contadorNotas = 0;

    cout << "--Ingrese la Nota 1: ";

    do
    {
        cout << "----------Desea ingresar otra nota?----------"<< endl;
        cout << "Elija la opcion (s/n)";
        cin >> opcion;

        cout << "--Ingrese la Nota: ";
        cin >> nuevoEstudiante[contador].edad;
        cin.ignore();
    } while (opcion != 's');
    
    
}
