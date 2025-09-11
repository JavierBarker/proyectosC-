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

pair<boolean, string> resultado = validarTitulo(string titulo){

    string textoConvertido;
    if(titulo.length() == 0){
        cout << "ERROR!! 🚨 DEBE INGRESAR EL TÍTULO DEL LIBRO! 🚨" << endl;
        cout << endl;
        return make_pair;
    }

    if(titulo.length() < 3){
        cout << "ERROR!! 🚨 DEBE TENER POR LO MENOS 3 CARACTERES! 🚨" << endl;
        cout << endl;
        return make_pair;
    }

    
    return make_pair;

}
