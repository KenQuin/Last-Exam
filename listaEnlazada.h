#ifndef listaEnlazada_h
#define listaEnlazada_h
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

using namespace std;

namespace listaenlazada
{
    template <class T>
    struct Nodo
    {
        T elemento;
        int Posicion;
        Nodo<T> *siguiente;
    };
    
    template<class T>
    class Final
    {
    public:
        Final();
        ~Final();
        
        typedef Nodo<T>* NodoPtr;
        
        void deleteFinal();
        
        void rotar();
        void juntar();
        void eliminar();
        void ordenar_mit();
        
    private:
        Nodo<T>* cabeza;
    };
}
#endif