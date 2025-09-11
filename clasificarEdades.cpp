#include <iostream> 
#include <string> 
using namespace std; 

int main(){
    int edad; 
    string categoria; 
     
    cout << "Ingrese su edad: "; 
    cin >> edad; 
     
    if(edad < 0) { 
        categoria = "Edad no valida"; 
    } else if(edad <= 12) { 
        categoria = "Niño"; 
    } else if(edad <= 17) { 
        categoria = "Adolescente"; 
    } else if(edad <= 64) { 
        categoria = "Adulto"; 
    } else { 
        categoria = "Adulto Mayor"; 
    } 
     
    cout << "Categoria: " << categoria << endl; 

    return 0;
}