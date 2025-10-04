#include <iostream>
#include <string>

using namespace std;

int main(){

    string linea = "Programacion";
 
    // cout << linea.substr(0,7) << endl;
    // cout << linea.find("gram") << endl;

    printf(linea.substr(0,7));
    printf(linea.find("gram"));
    
    return 0;
}