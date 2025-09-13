#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class GestorArchivos {
public:
    // Función para escribir texto en un archivo
    static bool escribirTexto(const string& nombreArchivo, const string& contenido) {
        ofstream archivo(nombreArchivo);
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escritura: " << nombreArchivo << endl;
            return false;
        }
        
        archivo << contenido;
        archivo.close();
        
        cout << "Archivo '" << nombreArchivo << "' escrito exitosamente." << endl;
        return true;
    }
    
    // Función para escribir múltiples líneas
    static bool escribirLineas(const string& nombreArchivo, const vector<string>& lineas) {
        ofstream archivo(nombreArchivo);
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para escritura: " << nombreArchivo << endl;
            return false;
        }
        
        for (const auto& linea : lineas) {
            archivo << linea << endl;
        }
        
        archivo.close();
        cout << "Archivo '" << nombreArchivo << "' con múltiples líneas escrito exitosamente." << endl;
        return true;
    }
    
    // Función para agregar contenido al final de un archivo
    static bool agregarTexto(const string& nombreArchivo, const string& contenido) {
        ofstream archivo(nombreArchivo, ios::app);
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para agregar: " << nombreArchivo << endl;
            return false;
        }
        
        archivo << contenido << endl;
        archivo.close();
        
        cout << "Contenido agregado al archivo '" << nombreArchivo << "'." << endl;
        return true;
    }
    
    // Función para leer todo el contenido de un archivo
    static string leerTextoCompleto(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para lectura: " << nombreArchivo << endl;
            return "";
        }
        
        string contenido;
        string linea;
        
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }
        
        archivo.close();
        return contenido;
    }
    
    // Función para leer archivo línea por línea
    static vector<string> leerLineas(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        vector<string> lineas;
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo para lectura: " << nombreArchivo << endl;
            return lineas;
        }
        
        string linea;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }
        
        archivo.close();
        return lineas;
    }
    
    // Función para verificar si un archivo existe
    static bool archivoExiste(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo);
        return archivo.good();
    }
    
    // Función para escribir datos binarios
    static bool escribirBinario(const string& nombreArchivo, const vector<int>& datos) {
        ofstream archivo(nombreArchivo, ios::binary);
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo binario para escritura: " << nombreArchivo << endl;
            return false;
        }
        
        // Escribir el tamaño del vector primero
        size_t tamaño = datos.size();
        archivo.write(reinterpret_cast<const char*>(&tamaño), sizeof(tamaño));
        
        // Escribir los datos
        archivo.write(reinterpret_cast<const char*>(datos.data()), datos.size() * sizeof(int));
        
        archivo.close();
        cout << "Archivo binario '" << nombreArchivo << "' escrito exitosamente." << endl;
        return true;
    }
    
    // Función para leer datos binarios
    static vector<int> leerBinario(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo, ios::binary);
        vector<int> datos;
        
        if (!archivo.is_open()) {
            cerr << "Error: No se pudo abrir el archivo binario para lectura: " << nombreArchivo << endl;
            return datos;
        }
        
        // Leer el tamaño del vector
        size_t tamaño;
        archivo.read(reinterpret_cast<char*>(&tamaño), sizeof(tamaño));
        
        // Redimensionar el vector y leer los datos
        datos.resize(tamaño);
        archivo.read(reinterpret_cast<char*>(datos.data()), tamaño * sizeof(int));
        
        archivo.close();
        return datos;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8); // Habilitar UTF-8
    cout << "=== Ejemplo de Lectura y Escritura de Archivos en C++ ===" << endl << endl;
    
    // 1. Escribir texto simple
    string nombreArchivo = "ejemplo.txt";
    string contenido = "¡Hola mundo desde C++!\nEste es un ejemplo de escritura de archivos.";
    
    GestorArchivos::escribirTexto(nombreArchivo, contenido);
    
    // 2. Leer el archivo completo
    cout << "\n--- Contenido del archivo ---" << endl;
    string contenidoLeido = GestorArchivos::leerTextoCompleto(nombreArchivo);
    cout << contenidoLeido << endl;
    
    // 3. Escribir múltiples líneas
    vector<string> lineas = {
        "Primera línea",
        "Segunda línea",
        "Tercera línea con números: 123",
        "Cuarta línea con caracteres especiales: áéíóú ñ"
    };
    
    string archivoLineas = "lineas.txt";
    GestorArchivos::escribirLineas(archivoLineas, lineas);
    
    // 4. Leer línea por línea
    cout << "\n--- Leyendo línea por línea ---" << endl;
    vector<string> lineasLeidas = GestorArchivos::leerLineas(archivoLineas);
    for (size_t i = 0; i < lineasLeidas.size(); ++i) {
        cout << "Línea " << (i + 1) << ": " << lineasLeidas[i] << endl;
    }
    
    // 5. Agregar contenido al archivo existente
    GestorArchivos::agregarTexto(archivoLineas, "Nueva línea agregada al final");
    
    // 6. Verificar si un archivo existe
    cout << "\n--- Verificando existencia de archivos ---" << endl;
    cout << "¿Existe 'ejemplo.txt'? " << (GestorArchivos::archivoExiste("ejemplo.txt") ? "Sí" : "No") << endl;
    cout << "¿Existe 'noexiste.txt'? " << (GestorArchivos::archivoExiste("noexiste.txt") ? "Sí" : "No") << endl;
    
    // 7. Ejemplo con archivos binarios
    cout << "\n--- Ejemplo con archivos binarios ---" << endl;
    vector<int> datosBinarios = {10, 20, 30, 40, 50, 100, 200};
    string archivoBinario = "datos.bin";
    
    GestorArchivos::escribirBinario(archivoBinario, datosBinarios);
    
    vector<int> datosLeidos = GestorArchivos::leerBinario(archivoBinario);
    cout << "Datos leídos del archivo binario: ";
    for (int dato : datosLeidos) {
        cout << dato << " ";
    }
    cout << endl;
    
    // 8. Ejemplo interactivo
    cout << "\n--- Ejemplo interactivo ---" << endl;
    cout << "Escribe algo para guardar en un archivo (presiona Enter): ";
    string textoUsuario;
    getline(cin, textoUsuario);
    
    if (!textoUsuario.empty()) {
        string archivoUsuario = "mi_archivo.txt";
        GestorArchivos::escribirTexto(archivoUsuario, textoUsuario);
        
        cout << "Tu texto guardado fue: " << endl;
        cout << GestorArchivos::leerTextoCompleto(archivoUsuario) << endl;
    }
    
    cout << "\n¡Ejemplos completados!" << endl;
    return 0;
}