#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

boolean validarTitulo(string titulo);
// void procesarAutor();

int main(){
    SetConsoleOutputCP(CP_UTF8);
    //DECLARAR VARIABLES
    string tituloLibro;

    //SOLICITAR EL TITULO DEL LIBRO
    do
    {

        cout << "---------INGRESE EL TÍTULO DEL LIBRO---------" << endl;
        getline(cin, tituloLibro);

    } while (validarTitulo(tituloLibro) == false);

    cout << "FELICIDADES!! ✅ EL TITULO FUE VALIDADO! ✅" << endl;
    cout << endl;


    return 0;
}

