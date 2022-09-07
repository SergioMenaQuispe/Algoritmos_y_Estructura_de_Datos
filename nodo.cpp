#ifndef NODO
#define NODO

template<class T>
class Nodo
{
private:
    T dato;
    Nodo * sig;
public:
    Nodo(){
        sig = NULL;
    }

    Nodo(T dato){
        this->dato = dato;
        sig = NULL;
    }

    T getDato(){
        return this->dato;
    }

    void setSiguiente(Nodo * sig){
        this->sig = sig;
    }

    Nodo * getSiguiente(){
        return this->sig;
    }

    ~Nodo(){
        //cout<<dato<<"ELiminado"<<endl;
    }
};

#endif


