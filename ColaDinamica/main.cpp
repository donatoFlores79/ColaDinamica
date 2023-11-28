#include "constancia.h"

using namespace std;

template<class T>
class Cola;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};

    void imprimir();
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* cola;
public:
    Cola():cola(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(T elem);
    node<T>* buscar(string&, string&) const;
    bool eliminar();
    void imprimir();
    int numSocios()const;
};

template <class T>
void node<T>::imprimir(){
    cout<< data;
}
template<class T>
void Cola<T>::imprimir(){
    node<T>* aux=cola;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
    cout<< "\n\n";
}

template <class T>
node<T>* Cola<T>::buscar(string& nombre, string& domicilio) const{
    node<T>* actual = cola;
    while(actual != nullptr){
        if(actual->data.getNombre() == nombre && actual->data.getDomicilio() == domicilio)
            return actual;
        actual = actual->sig;
    }

    return nullptr;
}

template<class T>
bool Cola<T>::eliminar(){
    node<T>* primerNodo = primero();

    if(vacia()){
        return false;
    }
    else{
        cola = cola->sig;
        delete primerNodo;
        return true;
    }
}

template<class T>
void Cola<T>::insertar(T elem){
    node<T>* aux = new node<T>;
    aux->data = elem;

    node<T>* ultimoNodo = ultimo();
    if(ultimoNodo == nullptr){
        aux->sig = cola;
        cola = aux;
    }
    else{
        aux->sig = ultimoNodo->sig;
        ultimoNodo->sig = aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=cola;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return cola;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux = cola;
    while(aux->sig != nullptr){
        aux = aux->sig;
    }
    return aux;
}

template<class T>
bool Cola<T>::vacia()const{
    if(cola==nullptr)
        return true;
    return false;
}

template <class T>
int Cola<T>::numSocios() const{
    int contador = 0;

    node<T>* actual = cola;
    while(actual != nullptr){
        contador++;
        actual = actual->sig;
    }

    return contador;
}

int main()
{
    Cola<Constancia> colaConstancias;

    int opc = 0;
    while(opc != 3){

        cout<< "1.Dar de alta solicitud de constancia\n";
        cout<< "2.Elaborar constancia\n";
        cout<< "3.Salir\n";
        cout<< " --->";
        cin>> opc;

        switch(opc){
            case 1:
                {
                Constancia x;
                cout<< "\n- Datos de la solicitud -\n";
                cin>> x;
                colaConstancias.insertar(x);
                }
                break;
            case 2:
                cout<< "\n";
                if(colaConstancias.vacia())
                    cout<< "La cola esta vacia\n";
                else{
                    node<Constancia>* primerConstancia = colaConstancias.primero();
                    primerConstancia->imprimir();
                    colaConstancias.eliminar();
                }
                break;
            case 3:
                break;
            default:
                cout<< "Ingresa una opcion valida\n";
        }

        cout<< "\n\n";
    }

    return 0;
}
