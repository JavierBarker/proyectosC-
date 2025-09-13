#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

//DECLARAR VARIABLES GLOBALES Y ESTRUCTURAS

struct Estudiante {
    string nombre;
    int edad;
    vector<float> calificaciones;
};

// DECLARANDO VARIABLES
int contadorEstudiantes = 0;
vector<Estudiante> estudiantes;
string nombreArchivo = "estudiantes.txt"; //delaro el nombre del archivo

void mostrarMenu();
void registrarEstudiante(vector<Estudiante> &estudiantes, int &contador);
void leerEstudiantes();


class Archivos {
public:
    // Función para escribir texto en un archivo
    static bool guardarEstudiante(Estudiante nuevoEstudiante){
        string calificacionesStr;
        ofstream archivo(nombreArchivo, ios::app); //abro el archivo en modo escritura

        //verifico si el archivo se abrió correctamente
        if (!archivo.is_open()) {
            cout << "Error: No se pudo abrir el archivo: " << nombreArchivo << endl;
            return false;
        }

        for (size_t i = 0; i < nuevoEstudiante.calificaciones.size(); i++)
        {
            ostringstream oss;
            oss << fixed << setprecision(2) << nuevoEstudiante.calificaciones[i];

            calificacionesStr += (nuevoEstudiante.calificaciones.size() - 1 == i) 
                ? oss.str()
                : oss.str() + ",";
        }

        
        archivo << nuevoEstudiante.nombre << "," << nuevoEstudiante.edad << "," << calificacionesStr << endl;
        archivo.close();
        cout << "Estudiante agregado al archivo con éxito! ✅" << endl;
        return true;
    }

    static vector<string> leerEstudiantes(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        vector<string> estudiantes;
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << endl;
            return estudiantes;
        }
        
        string linea;
        while (getline(archivo, linea)) {
            estudiantes.push_back(linea);
        }
        
        archivo.close();
        return estudiantes;
    }

    static vector<string> buscarEstudiante(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        vector<string> estudiantes;
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << endl;
            return estudiantes;
        }
        
        string linea;
        while (getline(archivo, linea)) {
            estudiantes.push_back(linea);
        }
        
        archivo.close();
        return estudiantes;
    }

    static float calcularPromedioEstudiante(){

    }
};


int main(){
    SetConsoleOutputCP(CP_UTF8); // Habilitar UTF-8
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
        cout << "1. Registrar un nuevo Estudiante 🧑‍💻" << endl;
        cout << "2. Mostrar Estudiantes 📃" << endl;
        cout << "3. Buscar Estudiante por Nombre 🔍" << endl;
        cout << "4. Estudiante con Mejor Promedio 🚩" << endl;
        cout << "5. Crear Archivo con los Aprobados ✅" << endl;
        cout << "6. Estadísticas 📚" << endl;
        cout << "7. Salir" << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << endl; 

        switch (opcion)
        {
        case 1:
            registrarEstudiante(estudiantes, contadorEstudiantes);
            cout << endl;
            break;
        case 2:
            leerEstudiantes();
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

void registrarEstudiante(vector<Estudiante> &estudiantes, int &contador){

    Estudiante nuevoEstudiante;
    cout << "----------REGISTRAR ESTUDIANTES----------" << endl;
    cout << "--Ingrese el Nombre del Estudiante: ";
    getline(cin, nuevoEstudiante.nombre);
    

    cout << "--Ingrese la Edad del Estudiante: ";
    cin >> nuevoEstudiante.edad;
    cin.ignore();

    //Declarar variables para las notas
    char opcion;
    float nota;

    //ingreso de notas
    cout << "--Ingrese la Nota 1: ";
    cin >> nota;
    nuevoEstudiante.calificaciones.push_back(nota);

    cout << "--Ingrese la Nota 2: ";
    cin >> nota;
    nuevoEstudiante.calificaciones.push_back(nota);

    cout << "--Ingrese la Nota 3: ";
    cin >> nota;
    nuevoEstudiante.calificaciones.push_back(nota);

    do
    {
        cout << "----------Desea ingresar otra nota?----------"<< endl;
        cout << "Elija la opcion (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << endl;

        if (opcion == 's')
        {
            cout << "--Ingrese la Nota " << (nuevoEstudiante.calificaciones.size() + 1) <<": ";
            cin >> nota;
            cout << endl;
            nuevoEstudiante.calificaciones.push_back(nota);
        }

    } while (opcion == 's');

    //agregar estudiante al archivo
    Archivos::guardarEstudiante(nuevoEstudiante);

    //agregar el nuevo estudiante al vector
    estudiantes.push_back(nuevoEstudiante);

    //incrementar el contador
    contador++;

    cout << endl;
    cout << "Estudiante registrado con éxito! ✅" << endl;
    cout << endl;

}

void leerEstudiantes(){
    cout << "----------LISTA DE ESTUDIANTES----------" << endl;
    vector<string> estudiantesLeidos = Archivos::leerEstudiantes(nombreArchivo);

    if (estudiantesLeidos.empty()) {
        cout << "Archivo vacio." << endl;
        return;
    }

    for (const auto& linea : estudiantesLeidos) {
        cout << "**" << linea << "**" << endl;
    }
    cout << endl;
}