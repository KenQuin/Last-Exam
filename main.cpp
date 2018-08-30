#include <iostream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cstddef>
#include "listaEnlazada.h"
#include "listaEnlazada.cpp"


using namespace std;
using namespace listaenlazada;

void menu(int Choice)
{
    
    Final<int> num_entero;
    Final<double> num_double;
    Final<char> sea_char;
    
    int Opcion;
    
    do
    {
        cout << "1) ROTAR" << endl;
        cout << "2) JUNTAR" << endl;
        cout << "3) ELIMINAR" << endl;
        cout << "4) ORDENAR" << endl;
        cout << "0) VOLVER A ENTEROS DOBLES O CARACTERS" << endl;
        cout << "Opcion: ";
        
        cin >> Opcion;
        cout << endl;
        
        if (Opcion < 0 || Opcion > 4)
        {
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            Opcion = 5;
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }
        
        switch(Opcion)
        {
            case 1:
                if(Choice == 1)
                {
                    num_entero.deleteFinal();
                    num_entero.rotar();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.deleteFinal();
                    num_double.rotar();
                    break;
                }
                else
                {
                    sea_char.deleteFinal();
                    sea_char.rotar();
                    break;
                }
            case 2:
                if(Choice == 1)
                {
                    num_entero.deleteFinal();
                    num_entero.juntar();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.deleteFinal();
                    num_double.juntar();
                    break;
                }
                else
                {
                    sea_char.deleteFinal();
                    sea_char.juntar();
                    break;
                }
            case 3:
                if(Choice == 1)
                {
                    num_entero.deleteFinal();
                    num_entero.eliminar();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.deleteFinal();
                    num_double.eliminar();
                    break;
                }
                else
                {
                    sea_char.deleteFinal();
                    sea_char.eliminar();
                    break;
                }
            case 4:
                if(Choice == 1)
                {
                    num_entero.deleteFinal();
                    num_entero.ordenar_mit();
                    break;
                }
                else if(Choice == 2)
                {
                    num_double.deleteFinal();
                    num_double.ordenar_mit();
                    break;
                }
                else
                {
                    sea_char.deleteFinal();
                    sea_char.ordenar_mit();
                    break;
                }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
        cout << endl;
        
    }while(Opcion != 0);
    
}

void Menu_Numero()
{
    int Choice;
    do{
        cout << "ESCOGER NUMERO ENTERO O REAL" << endl;
        cout << "1) ENTERO" << endl;
        cout << "2) REAL" << endl;
        cout << "3) CARACTER" << endl;
        cout << "0) TERMINAR EL PROGRAMA" << endl;
        cout << "Opcion: ";
        cin >> Choice;
        
        if (Choice < 0 || Choice > 6)
        {
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }
        
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            Choice = 4;
            cout << "\nPORFAVOR SOMETER UNA ENTRADA VALIDA\n"<< endl;
        }

        switch(Choice)
        {
            case 1:
                cout << endl;
                menu(Choice);
                break;
            case 2:
                cout << endl;
                menu(Choice);
                break;
            case 3:
                cout << endl;
                menu(Choice);
            case 0:
                cout << "FIN DEL PROGRAMA" << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
        
    }while(Choice != 0);
}

int main()
{
    Menu_Numero();
    
    return 0;
}