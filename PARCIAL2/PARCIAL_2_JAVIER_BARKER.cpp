#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;

struct Producto {
    int id;
    string nombre;
    double precio;
    int stock;
};

vector<Producto> productos;
string nombreArchivo = "productos_3590_25_5222.txt";

//Clase
class Productos{
public: 

    //obtener Productos
    static vector<string> leerProductos(){
        ifstream archivo(nombreArchivo);
        vector<string> productos;

        cout << archivo.is_open();

        if(!archivo.is_open()){
            cerr << "Error: No se pudo abrir el archivo: " << nombreArchivo << endl;
            return productos;
        }

        string linea;
        while(getline(archivo, linea)){
            productos.push_back(linea);
        }
        return productos;
    }
    

};


//Funciones
void mostrarMenu();
// void agregarProducto();
void mostrarProductos();
void buscarPorId();

int main(){
    SetConsoleOutputCP(CP_UTF8); // Habilitar UTF-8
    mostrarMenu();
    return 0;
}


void mostrarMenu()
{
    int opcion;
    do
    {
        cout << "---------GESTIÓN DE Productos---------" << endl;
        cout << "1. Mostrar Productos 📃" << endl;
        cout << "2. Buscar producto por ID 🔍" << endl;
        cout << "3. Productos con Stock Bajo 🚧" << endl;
        cout << "4. Valor total de Inventario ✅" << endl;
        cout << "5. Producto mas Caro 📚" << endl;
        cout << "6. Agregar Producto 📠" << endl;
        cout << "7. Salir 🫡" << endl;
        cout << "-------------------------------------------" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada
        cout << endl; 

        switch (opcion)
        {
        case 1:
            mostrarProductos();
            cout << endl;
            break;
        case 2:
            buscarPorId();
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
            // agregarProducto();
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

void mostrarProductos(){
    vector<string> leerProductos = Productos::leerProductos();


    cout << endl;
    cout << "----------LISTA DE PRODUCTOS----------" << endl;

    for (size_t i = 0; i < leerProductos.size(); i++)
    {        
        cout << leerProductos[i] << endl;
        cout << endl;
    }
    
    cout << endl;
}

void buscarPorId(){
    vector<string> leerProductos = Productos::leerProductos();
    string id;

    cout << "----------Ingrese el ID a buscar----------" << endl;
    getline(cin, id);

    // for (size_t i = 0; i < leerProductos.size(); i++)
    // {        
    //     leerProductos[i].substr(0,leerProductos[i].find(',')).find(id);
    //     cout << leerProductos[i].substr(0,leerProductos[i].find(',')).find(id) << endl;
    //     cout << endl;
    // }
    // buscar por ID
    bool encontrado = false;
    
}


// void agregarProducto(){
//     Producto nuevoProducto;
//     cout << "----------REGISTRAR PRODUCTO----------" << endl;
//     cout << "--Ingrese el Nombre del Estudiante: ";
//     getline(cin, nuevoProducto);
    

//     cout << "--Ingrese la Edad del Estudiante: ";
//     cin >> nuevoEstudiante.edad;
//     cin.ignore();

//     //Declarar variables para las notas
//     char opcion;
//     float nota;

//     //ingreso de notas
//     cout << "--Ingrese la Nota 1: ";
//     cin >> nota;
//     nuevoEstudiante.calificaciones.push_back(nota);

//     cout << "--Ingrese la Nota 2: ";
//     cin >> nota;
//     nuevoEstudiante.calificaciones.push_back(nota);

//     cout << "--Ingrese la Nota 3: ";
//     cin >> nota;
//     nuevoEstudiante.calificaciones.push_back(nota);

//     do
//     {
//         cout << "----------Desea ingresar otra nota?----------"<< endl;
//         cout << "Elija la opcion (s/n): ";
//         cin >> opcion;
//         cin.ignore(); // Limpiar el buffer de entrada
//         cout << endl;

//         if (opcion == 's')
//         {
//             cout << "--Ingrese la Nota " << (nuevoEstudiante.calificaciones.size() + 1) <<": ";
//             cin >> nota;
//             cout << endl;
//             nuevoEstudiante.calificaciones.push_back(nota);
//         }

//     } while (opcion == 's');

//     //agregar estudiante al archivo
//     Archivos::guardarEstudiante(nuevoEstudiante);

//     //agregar el nuevo estudiante al vector
//     estudiantes.push_back(nuevoEstudiante);

//     //incrementar el contador
//     contador++;

//     cout << endl;
//     cout << "Estudiante registrado con éxito! ✅" << endl;
//     cout << endl;
// }



//agrear productos nuevos
//buscar producto por id
//mostrar productos en stock bajo (<=5)
//calcular valor de inventario
//mostrar el producto mas caro
