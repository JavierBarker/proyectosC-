#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
//	Función	para	convertir	a	mayúsculas
string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}
//	Función	para	contar	vocales
int contarVocales(string str)
{
    int count = 0;
    string vocales = "aeiouAEIOU";
    for (char c : str)
    {
        if (vocales.find(c) != string::npos)
        {
            count++;
        }
    }
    return count;
}
//	Función	para	invertir	una	cadena
string invertirCadena(string str)
{
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    string palabra = "Algoritmos";
    cout << "Original:	" << palabra << endl;
    cout << "Mayúsculas:	" << toUpperCase(palabra) << endl;
    cout << "Vocales:	" << contarVocales(palabra) << endl;
    cout << "Invertida:	" << invertirCadena(palabra) << endl;
    return 0;
}