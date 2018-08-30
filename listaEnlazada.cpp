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

using namespace std;

namespace listaenlazada
{
    template<class T>
    Final <T>::Final(): cabeza(NULL)
    {
        
    }
    
    template<class T>
    Final <T>::~Final()
    {
        
    }
    
    template<class T>
    void Final<T>::deleteFinal()
    {
        NodoPtr temp_Ptr, temp_Ptr_2;
        
        for (temp_Ptr = cabeza; temp_Ptr != NULL; )
        {
            temp_Ptr_2 = temp_Ptr;
            temp_Ptr = temp_Ptr->siguiente;
            delete temp_Ptr_2;
        }
        
        cabeza = NULL;
    }
    
    template<class T>
    void Final <T>::rotar()
    {
        int cant_elemento, rotar_element;
        T element_new;
        
        cout << endl;
        cout << "Favor introducir la cantidad del elementos : " << endl;
        cin >> cant_elemento;
        
        while((cant_elemento <= 0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error favor intruducir un numero positivo" << endl;
            cout << "Favor introducir la cantidad del elementos : " << endl;
            cin >> cant_elemento;
        }
        
        cout << "Favor introducir los datos: " << endl;
        
        for(int i = 1; i <= cant_elemento; i++)
        {
            cin >> element_new;
            
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Elemento invalido solo puede contener numeros" << endl;
                cout << "Favor introducir los datos : " << endl;
                cin >> element_new;
            }
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = element_new;
                temp_Ptr->Posicion = i;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = element_new;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
            }
        }
        
        cout << "Favor indicar cuantos espacios deseas juntar" << endl;
        cin >> rotar_element;
        
        while((rotar_element > cant_elemento) || (rotar_element <=0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error no se puede rotar un elemento dos veces" << endl;
            cout << "Favor indicar cuantos espacios deseas juntar" << endl;
            cin >> rotar_element;
        }
        
        cout << "Sus elementos son los siguientes" << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
        }
        
        cout << "Sus elementos rotados son " << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            if(rotar_element < temp_Ptr->Posicion)
            {
                cout << temp_Ptr->elemento << endl;
            }
        }
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            if(rotar_element >= temp_Ptr->Posicion)
            {
                cout << temp_Ptr->elemento << endl;
            }
        }
        

    }
    /////////////////////////////////////////////////////////////////////
    
    template<class T>
    void Final <T>::juntar()
    {
        int cant_elemento, juntar_eleme;
        T element_new;
        T hogar = 0;
        T juntar_array[50];
        int a=0;
        int k=1;
        
        cout << endl;
        cout << "Favor introducir la cantidad del elementos : " << endl;
        cin >> cant_elemento;
        
        while((cant_elemento <= 0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error favor intruducir un numero positivo" << endl;
            cout << "Favor introducir la cantidad del elementos : " << endl;
            cin >> cant_elemento;
        }
        
        cout << "Favor introducir los datos: " << endl;
        
        for(int i = 1; i <= cant_elemento; i++)
        {
            cin >> element_new;
            
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Elemento invalido solo puede contener numeros" << endl;
                cout << "Favor introducir los datos : " << endl;
                cin >> element_new;
            }
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = element_new;
                temp_Ptr->Posicion = i;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = element_new;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
            }
        }
        
        cout << "Favor indicar cuantos espacios deseas juntar" << endl;
        cin >> juntar_eleme;
        
        while((juntar_eleme > cant_elemento) || (juntar_eleme <=0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error no se puede rotar un elemento dos veces" << endl;
            cout << "Favor indicar cuantos espacios deseas juntar" << endl;
            cin >> juntar_eleme;
        }
        
        
        cout << "Los elementos que agrego son" <<endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            hogar = temp_Ptr->elemento;
            if(k == 1)
            {
                juntar_array[a] = 0;
            }
            
            if(k <= juntar_eleme)
            {
                juntar_array[a] = juntar_array[a] + hogar;
                
                if(k+1 > juntar_eleme)
                {
                    k=0;
                    a++;
                }
            }
            k++;
        }
        
        cabeza = NULL;
        
        
        for(int i=0; i <= (cant_elemento/juntar_eleme); i++)
        {
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = juntar_array[i];
                temp_Ptr->Posicion = i +1;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = juntar_array[i];
                temp_Ptr->siguiente->Posicion = i +1;
                temp_Ptr->siguiente->siguiente = NULL;
            }
            
        }
        cout << "Elementos nuevos" << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
        }
    }
    
    //////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////
    
    
    template<class T>
    void Final <T>::eliminar()
    {
        int cant_elemento;
        T element_new, eliminar_elemento;
        
        cout << endl;
        cout << "Favor introducir la cantidad del elementos : " << endl;
        cin >> cant_elemento;
        
        while((cant_elemento <= 0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error favor intruducir un numero positivo" << endl;
            cout << "Favor introducir la cantidad del elementos : " << endl;
            cin >> cant_elemento;
        }
        
        cout << "Favor introducir los datos: " << endl;
        
        for(int i = 1; i <= cant_elemento; i++)
        {
            cin >> element_new;
            
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Elemento invalido solo puede contener numeros" << endl;
                cout << "Favor introducir los datos : " << endl;
                cin >> element_new;
            }
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = element_new;
                temp_Ptr->Posicion = i;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = element_new;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
            }
        }
        cout << "Sus elementos son los siguientes" << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
        }

        cout << "Favor de indicar cual elemento desea eliminar" << endl;
        cin >> eliminar_elemento;
        
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error no se puede rotar un elemento dos veces" << endl;
            cout << "Favor indicar cuantos espacios deseas juntar" << endl;
            cin >> eliminar_elemento;
        }
        
        cout << "Sus nuevos elementos son los siguientes" << endl;
        
        NodoPtr aqui = cabeza;
        
        while((aqui->elemento != eliminar_elemento) && aqui->siguiente !=NULL)
        {
            aqui = aqui->siguiente;
        }
        
        if(aqui->elemento == eliminar_elemento)
        {
            for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
            {
                if(temp_Ptr->elemento != eliminar_elemento)
                {
                    cout << temp_Ptr->elemento << endl;
                }
            }
        }
        else
        {
            cout << "El elemento no fue encontrado" << endl;
        }
        
        

    }
    
    template<class T>
    void Final <T>::ordenar_mit()
    {
        int cant_elemento;
        T element_new;
        T arreglotmp[50];
        int e =0;
        
        cout << endl;
        cout << "Favor introducir la cantidad del elementos : " << endl;
        cin >> cant_elemento;
        
        while((cant_elemento <= 0) || cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Error favor intruducir un numero positivo" << endl;
            cout << "Favor introducir la cantidad del elementos : " << endl;
            cin >> cant_elemento;
        }
        
        cout << "Favor introducir los datos: " << endl;
        
        for(int i = 1; i <= cant_elemento; i++)
        {
            cin >> element_new;
            
            while(cin.fail())
            {
                cin.clear();
                cin.ignore();
                cout << "Elemento invalido solo puede contener numeros" << endl;
                cout << "Favor introducir los datos : " << endl;
                cin >> element_new;
            }
            
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = element_new;
                temp_Ptr->Posicion = i;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = element_new;
                temp_Ptr->siguiente->Posicion = i;
                temp_Ptr->siguiente->siguiente = NULL;
            }
        }
        
        cout << "Sus elementos guardados" << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
            arreglotmp[e] = temp_Ptr->elemento;
            e++;
        }
        
        cabeza = NULL;
        
        T espacio;
        int conteo = 0;
        for(int t=0; t <= cant_elemento/2; t++)
        {
            for(int k= 0; k < (cant_elemento/2)-1; k++)
            {
                if(arreglotmp[k] > arreglotmp[k+1])
                {
                    espacio = arreglotmp[k];
                    arreglotmp[k] = arreglotmp[k+1];
                    arreglotmp[k+1] = espacio;
                }
            }
            conteo++;
        }
        
        for(int t=conteo-1; t <= cant_elemento-1; t++)
        {
            for(int k= conteo-1; k < (cant_elemento)-1; k++)
            {
                if(arreglotmp[k] < arreglotmp[k+1])
                {
                    espacio = arreglotmp[k];
                    arreglotmp[k] = arreglotmp[k+1];
                    arreglotmp[k+1] = espacio;
                }
            }
        }
        
        for(int i=0; i <= cant_elemento-1; i++)
        {
            if(cabeza == NULL)
            {
                NodoPtr temp_Ptr;
                temp_Ptr = new Nodo<T>;
                
                temp_Ptr->elemento = arreglotmp[i];
                temp_Ptr->Posicion = i +1;
                temp_Ptr->siguiente = cabeza;
                
                cabeza = temp_Ptr;
            }
            else
            {
                NodoPtr temp_Ptr;
                temp_Ptr = cabeza;
                
                while(temp_Ptr->siguiente != NULL)
                {
                    temp_Ptr = temp_Ptr->siguiente;
                }
                temp_Ptr->siguiente = new Nodo<T>;
                
                temp_Ptr->siguiente->elemento = arreglotmp[i];
                temp_Ptr->siguiente->Posicion = i +1;
                temp_Ptr->siguiente->siguiente = NULL;
            }

        }
        cout << "Elementos invertidos" << endl;
        
        for(NodoPtr temp_Ptr = cabeza; temp_Ptr != NULL; temp_Ptr = temp_Ptr->siguiente)
        {
            cout << temp_Ptr->elemento << endl;
        }
    }
}
















