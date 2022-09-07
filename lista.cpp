#include<iostream>
using namespace std;

#ifndef LISTA
#define LISTA

#include"nodo.cpp"

template<class T>
class Lista
{
private:
    Nodo<T> * head;
public:
    Lista(){}
    ~Lista(){
        Nodo<T> * aux;
        while (head != NULL)
        {
            aux = head;
            head = head->getSiguiente();
            delete aux;
        }
        
    }

    void print(){
        Nodo<T> * aux = head;
        
        while (aux != NULL)
        {
            cout<<aux->getDato()<<endl;
            aux = aux->getSiguiente();
        }
        
    }

    Nodo<T> * getHead(){
        return this->head;
    }


    // metodo find Iterativo
    void find(T dato){
        Nodo<T> * aux = head;
        int iterador = 0;
        while (aux != NULL)
        {
            if(aux->getDato() == dato){
                cout<<"Se encontro el dato("<<dato<<") en la posicion "<<iterador<<endl;
                return;
            }
            aux = aux->getSiguiente();
            ++iterador;
        }

        cout<<"No se encontro el dato("<<dato<<")"<<endl;
    }

    // metodo find Recursivo
    void find_recursive(T dato, Nodo<T> * actual){

        if(actual->getDato() == dato){
            cout<<"Se encontro el dato("<<dato<<")"<<endl;
            return;
        }
        else if(actual->getSiguiente() == NULL){
            cout<<"No se encontro el dato("<<dato<<")"<<endl;
            return;
        }else{
            find_recursive(dato,actual->getSiguiente());
        }
    }

    // push back iterativo
    void push_back(T dato){
        Nodo<T> * new_nodo = new Nodo(dato);

        if(!head){
            head = new_nodo;
        }

        else{
            Nodo<T> * aux = head;
            while(aux->getSiguiente() != NULL){
                aux = aux->getSiguiente();
            }

            aux->setSiguiente(new_nodo);
        }
    }

    // insert recursive
    void insert_recursive(T dato, Nodo<T> * actual){
        if(actual->getSiguiente() == NULL){
            Nodo<T> * new_nodo = new Nodo(dato);
            actual->setSiguiente(new_nodo);
            return;
        }

        else{
            insert_recursive(dato,actual->getSiguiente());
        }
    }

    // delete front
    void delete_front(){
        Nodo<T> * aux;
        aux = head;
        head = head->getSiguiente();
        delete aux;
    }

    // delete last
    void delete_last(){
        Nodo<T> * actual = head;
        Nodo<T> * anterior;
        while (actual->getSiguiente() != NULL)
        {
            anterior = actual;
            actual = actual->getSiguiente();
        }

        anterior->setSiguiente(NULL);
        delete actual;        
    }

    // insert position
    void insert_position(T dato, int p){
        int position = 0;
        Nodo<T> * actual = head;
        Nodo<T> * anterior;

        while (position != p && actual != NULL)
        {
            anterior = actual;
            actual = actual->getSiguiente();
            
            ++position;
        }

        if(actual == NULL){
            cout<<"No esta dentro del rango de insersion"<<endl;
            return;
        }

        Nodo<T> * new_nodo = new Nodo(dato);

        if(!anterior){

            //actual = new_nodo;

            //cout<<new_nodo->getDato()<<endl;
            //cout<<new_nodo->getDato()<<endl;
            cout<<"Hola"<<endl;
        }

        else{
            anterior->setSiguiente(new_nodo);
            new_nodo->setSiguiente(actual);
        }
        
    }

    // print reverse

    void print_reverse(){
        // find tail
        Nodo<T> * tail = head;

        while(tail->getSiguiente() != NULL){
            tail = tail->getSiguiente();
        }

        Nodo<T> * aux = head;
        while (tail != head)
        {
            cout<<tail->getDato()<<endl;
            while(aux->getSiguiente() != tail){
                aux = aux->getSiguiente();
            }
            tail = aux;
            aux = head;
        }

        cout<<tail->getDato()<<endl;
  
    }

    // print reverse recursive

    void print_reverse_recursive(){

    }

    // hallar mayor

    void max(){
        Nodo<T> * aux = head;
        T mayor = aux->getDato();

        while (aux->getSiguiente() != NULL){
            aux = aux->getSiguiente();
            if(aux->getDato() > mayor){
                mayor = aux->getDato();
            }
        }

        cout<<"El mayor es: "<<mayor<<endl;
    }

    // hallar mayor con recursividad

    void max_recursive(T & mayor, Nodo<T>*actual){
        if(actual->getDato() > mayor){
            mayor = actual->getDato();
        }

        if(actual->getSiguiente() == NULL){
            cout<<"El mayor es: "<<mayor<<endl;
        }else{
            max_recursive(mayor,actual->getSiguiente());
        }
    }
};



#endif