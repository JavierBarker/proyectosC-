#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>
#include <cctype>

using namespace std;

struct Libro
{
    string titulo;
    string autor;
    int anioPublicacion;
    double precio;
    int stock;
    int ejemplaresVendidos;
};
// Definir variables para usarlas globalmente
const int maxLibros = 100;
Libro inventario[maxLibros];
int contadorLibros = 0;

//	Declarar	aquí	tus	funciones	para	manejo	de	cadenas
string validarTitulo(string titulo);
string procesarAutor(string autor);
int contarVocales(string cadena);

//	Declarar	funciones	para	cálculos
double calcularPrecioConDescuento(double precio, int anio);
double calcularPrecioConIVA(double precio);
double calcularValorInventario();
double calcularPrecioPromedio();

//	Declarar	funciones	para	validaciones	lógicas
bool esLibroBestseller(int vendidos, double precio);
bool estaEnOferta(int anio, int stock);
bool libroRecomendado(int vendidos, double precio, int anio, int stock);
bool stockCritico(int stock);

//	Función	principal	del	menú
void mostrarMenu();

void registrarLibro(Libro libros[], int &contador);

void mostrarInventario(Libro libros[], int contador);

void mostrarEstadisticas();

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    // int totalLibros = 0;
    //	Tu	código	principal	aquí
    mostrarMenu();
    return 0;
}

void mostrarMenu()
{
    int opcion;
    do
    {
        cout << "---------GESTIÓN DE LIBROS---------" << endl;
        cout << "1. Registrar un nuevo libro 📖" << endl;
        cout << "2. Mostrar inventario completo 📃" << endl;
        cout << "3. Buscar libro por título 🔔" << endl;
        cout << "4. Generar reporte de ventas 📠" << endl;
        cout << "5. Mostrar estadísticas 📚" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarLibro(inventario, contadorLibros);
            break;
        case 2:
            mostrarInventario(inventario, contadorLibros);
            break;
        case 3:
            // mostrarInventario();
            break;
        case 4:
            // mostrarInventario();
            break;
        case 5:
            mostrarEstadisticas();
            break;
        case 0:
            cout << "Saliendo del programa... 🫡" << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, intente de nuevo. 🚨" << endl;
        }
    } while (opcion != 0);
}

//	Implementar	aquí	tus	funciones
string validarTitulo(string titulo)
{
    // Validar que el título no esté vacío
    if (titulo.length() == 0)
    {
        cout << "ERROR!! 🚨 DEBE INGRESAR EL TÍTULO DEL LIBRO! 🚨" << endl;
        cout << endl;
        return "ERROR";
    }
    // Validar que el título tenga al menos 3 caracteres
    if (titulo.length() < 3)
    {
        cout << "ERROR!! 🚨 DEBE TENER POR LO MENOS 3 CARACTERES! 🚨" << endl;
        cout << endl;
        return "ERROR";
    }

    // Convertir a mayúsculas la primera letra de cada palabra
    bool inicioPalabra = true;
    for (char &c : titulo)
    {
        if (isspace(c))
        {
            inicioPalabra = true;
        }
        else if (inicioPalabra && isalpha(c))
        {
            c = toupper(c);
            inicioPalabra = false;
        }
        else
        {
            c = tolower(c);
        }
    }

    return titulo;
}

string procesarAutor(string autor)
{
    // Converir nombre a mayusculas
    transform(autor.begin(), autor.end(), autor.begin(), ::toupper);
    
    // Extraer apellido y agregar entre paréntesis
    string apellido;
    size_t pos = autor.find_last_of(" ");
    apellido = (pos == string::npos) ? autor : autor.substr(pos + 1);
    autor += " (" + apellido + ")";

    return autor;
}


//Funciones para calculos
double calcularPrecioConDescuento(double precio, int anio){
    //valido que el libro tenga más de 2 años
    if ((2025 - anio) > 2){
        return precio * 0.15; //aplica 15% de descuento
    }
    return precio; //si no tiene más de 2 años, no aplica descuento
}

double calcularPrecioConIVA(double precio){
    return precio * 1.16; //aplica 16% de IVA
}

double calcularValorInventario(){
    double valorTotal = 0.0;
    //recorro el inventario y sumo el valor de cada libro (precio * stock)
    for (int i = 0; i < contadorLibros; i++)
    {
        valorTotal += (inventario[i].precio * inventario[i].stock);
    }
    
    return valorTotal;
}

double calcularPrecioPromedio(){
    double precioTotal = 0.0;

    //recorro el inventario y sumo el precio de cada libro
    for (int i = 0; i < contadorLibros; i++)
    {
        precioTotal += inventario[i].precio;
    }

    return (contadorLibros > 0) ? (precioTotal / contadorLibros) : 0.0;
}



//Funciones para validaciones lógicas
bool esLibroBestseller(int vendidos, double precio){
    //valido que el libro tenga más de 1000 vendidos y precio mayor a 300
    return (vendidos > 1000 && precio > 300);
}

bool estaEnOferta(int anio, int stock){
    //valido que el libro tenga más de 2 años o que el stock sea menor a 50
    return ((2025 - anio) > 2 || stock < 50);
}

bool libroRecomendado(int vendidos, double precio, int anio, int stock){
    /// valida si es bestseller y no está en oferta
    /// si esta en oferta lo invierte para indicar que no es recomendado
    return (esLibroBestseller(vendidos, precio) && !estaEnOferta(anio, stock));
}

bool stockCritico(int stock, int vendidos, double precio){
    //valido que el stock sea menor a 10 y que sea bestseller
    return (stock < 10 && esLibroBestseller(vendidos, precio));
}


void registrarLibro(Libro libros[], int &contador)
{
    int cantidadLibros = 0;
    while (cantidadLibros <= 0 || cantidadLibros > maxLibros)
    {
        // Solicitar Cantidad de Libros a Registrar
        cout << "¿Cuántos libros desea registrar? ";
        cin >> cantidadLibros;

        if (cantidadLibros <= 0 || cantidadLibros > maxLibros)
        {
            cout << "ERROR!! 🚨 DEBE INGRESAR UNA CANTIDAD VÁLIDA! 🚨" << endl;
            cout << endl;
        }
    }

    // asignar la cantidad al contador global
    contador += cantidadLibros;
    if (contador > maxLibros)
    {
        cout << "ERROR!! 🚨 NO SE PUEDE REGISTRAR ESA CANTIDAD DE LIBROS! 🚨" << endl;
        cout << "Solo se pueden registrar " << maxLibros - (contador - cantidadLibros) << " libros más." << endl;
        contador -= cantidadLibros; // revertir el contador
        return;
    }
    cout << endl;
    
    // Registrar Datos de Cada Libro
    for (int i = (contador - cantidadLibros); i < contador; i++)
    {
        cout << "--Ingrese los datos del libro 📖 " << i + 1 << ":" << endl;
        cout << "--Ingrese el Titulo: ";

        cin.ignore(); // Limpiar el buffer de entrada

        getline(cin, libros[i].titulo);
        while (validarTitulo(libros[i].titulo) == "ERROR")
        {
            cout << "--Ingrese el Titulo: ";
            getline(cin, libros[i].titulo);
        }

        libros[i].titulo = validarTitulo(libros[i].titulo);

        cout << "--Ingrese el Autor: ";
        getline(cin, libros[i].autor);
        libros[i].autor = procesarAutor(libros[i].autor);

        cout << "--Ingrese el Año de Publicación: ";
        cin >> libros[i].anioPublicacion;

        cout << "--Ingrese el Precio: ";
        cin >> libros[i].precio;

        cout << "--Ingrese el Stock: ";
        cin >> libros[i].stock;

        cout << "--Ingrese el No. de Ejemplares Vendidos: ";
        cin >> libros[i].ejemplaresVendidos;

        cout << endl;
        cout << "Libro registrado con éxito! ✅" << endl;
        cout << endl;
    }
}

void mostrarEstadisticas(){
    //recorro el inventario y cuento los libros que son bestseller y los que tienen stock critico
    int lirbrosBestsellers = 0;
    int librosStockCritico = 0;
    for (int i = 0; i < contadorLibros; i++)
    {
        lirbrosBestsellers += esLibroBestseller(inventario[i].ejemplaresVendidos, inventario[i].precio) ? 1 : 0;
        librosStockCritico += stockCritico(inventario[i].stock, inventario[i].ejemplaresVendidos, inventario[i].precio) ? 1 : 0;
    }
    
    // Mostrar estadísticas generales
    cout << endl;
    cout << endl;
    cout << "---📃 ESTADÍSTICAS GENERALES 📃---	" << endl;
    cout << "Total de libros: " << contadorLibros << endl;
    cout << "Valor total del inventario: $" << fixed << setprecision(2) << calcularValorInventario() << endl; 
    cout << "Precio promedio de los libros: $" << fixed << setprecision(2) << calcularPrecioPromedio() << endl; 
    cout << "Libros Bestsellers: " << lirbrosBestsellers << endl; 
    cout << "Libros con Stock critico: " << librosStockCritico << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
}


void mostrarInventario(Libro libros[], int contador){
    for (int i = 0; i < contador; i++)
    {
        cout << endl;
        cout << "------------------------------" << endl;
        cout << "📖 Libro " << i + 1 << " 📖" << endl;
        cout << "Título: " << libros[i].titulo << endl;
        cout << "Autor: " << libros[i].autor << endl;
        cout << "Año de Publicación: " << libros[i].anioPublicacion << endl;
        cout << "Precio: $" << fixed << setprecision(2) << libros[i].precio << endl;
        cout << "Stock: " << libros[i].stock << endl;
        cout << "Ejemplares Vendidos: " << libros[i].ejemplaresVendidos << endl;

        double precioConDescuento = calcularPrecioConDescuento(libros[i].precio, libros[i].anioPublicacion);
        double precioConIVA = calcularPrecioConIVA(precioConDescuento);

        cout << "Precio con Descuento (si aplica): $" << fixed << setprecision(2) << precioConDescuento << endl;
        cout << "Precio con IVA: $" << fixed << setprecision(2) << precioConIVA << endl;

        cout << "¿Es Bestseller? " << (esLibroBestseller(libros[i].ejemplaresVendidos, libros[i].precio) ? "Sí" : "No") << endl;
        cout << "¿Está en Oferta? " << (estaEnOferta(libros[i].anioPublicacion, libros[i].stock) ? "Sí" : "No") << endl;
        cout << "¿Es Libro Recomendado? " << (libroRecomendado(libros[i].ejemplaresVendidos, libros[i].precio, libros[i].anioPublicacion, libros[i].stock) ? "Sí" : "No") << endl;
        cout << "¿Tiene Stock Crítico? " << (stockCritico(libros[i].stock, libros[i].ejemplaresVendidos, libros[i].precio) ? "Sí" : "No") << endl;

        cout << "------------------------------" << endl;
        cout << endl;
    }
    
}


