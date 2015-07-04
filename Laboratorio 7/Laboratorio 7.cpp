// Prueba27.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template <typename T>
struct nodo{                                  //one element of list
	T dato;                                  //data item
	nodo* siguiente;                        //pointer to next link
	nodo* anterior;                        //pointer to "back" link                         
	nodo* actual;
};

template<class T>
class Iterador {
private:
	nodo<T> * anterior;
	nodo<T> * actual;

public:

	Iterador(nodo<T> * actual) {
		this->anterior = actual;
		this->actual = actual;
	}
	~Iterador() {
	}
	// Preincremento
	Iterador<T>& operator++() {
		bool continuar = true;
		while (continuar && actual != 0) {
			continuar = false;
			Nodo<T> * tmp = actual;
			if (actual != NULL && anterior == actual->hIzq) {
				if (actual->hDer != NULL) {
					actual = actual->hDer;
				}
				else {
					actual = actual->padre;
					continuar = true;
				}
			}
			else if (actual != NULL && anterior == actual->hDer) {
				actual = actual->padre;
				continuar = true;
			}
			else if (actual->hIzq != NULL) {
				actual = actual->hIzq;
			}
			else if (actual->hDer != NULL) {
				actual = actual->hDer;
			}
			else {
				actual = actual->padre;
				continuar = true;
			}
			anterior = tmp;
		}
		return *this;
	}

	// Posincremento
	Iterador<T> operator++(int) {
		Iterador<T> tmp(this->actual);
		++(*this);
		return tmp;
	}
};


template <class T>
class DoubleLinkedList{                              //a list of links
private:
	nodo<T>* primero;                      //pointer to first link
	nodo<T>* anterior;
public:
	DoubleLinkedList(){                          //no-argument constructor
		primero = NULL;
		anterior = NULL;
	}                                  //no first link
	void agregarItem(T d);            //add data item (one link)
	void agregarFinal(T d);               //add data item (one link)
	void mostrar();                 //display all links

	Iterador<T> begin() {
		return Iterador<T>(primero);
	}

	Iterador<T> end() {
		return Iterador<T>(NULL);
	}
	Iterador<T> rBegin() {
		return Iterador<T>(primero);
	}

	Iterador<T>  rEnd() {
		return Iterador<T>(NULL);
	}

};

template <class T>
void DoubleLinkedList<T>::agregarItem(T d){         //add data item
	nodo<T> *nuevoNodo = new nodo<T>;
	nuevoNodo->dato = d;
	//insert at head of link list
	nuevoNodo->siguiente = primero;
	primero = nuevoNodo;
}
//-------------------------------------------------------------void
template <class T>
void DoubleLinkedList<T>::agregarFinal(T d){         //add data item
	nodo<T> *nuevoNodo = new nodo<T>;
	nodo<T> *nodoActual = new nodo<T>;
	nuevoNodo->dato = d;
	nuevoNodo->siguiente = NULL;
	if (primero == NULL) {
		primero = nuevoNodo;
	}
	else {
		nodo<T>* nodoActual = primero;
		while (nodoActual->siguiente != NULL)
		nodoActual = nodoActual->siguiente;
		nodoActual->siguiente = nuevoNodo;
	}
}

template <class T>
void DoubleLinkedList<T>::mostrar(){                   //display all links
	nodo<T>* actual = primero;                //set ptr to first link
	while (actual != NULL){                  //quit on last link
		cout << actual->dato << endl;       //print data
		actual = actual->siguiente;        //move to next link
	}
}

int _tmain(int argc, _TCHAR* argv[]) {



	DoubleLinkedList<int> li;       //make linked list
	li.agregarItem(25);
	li.agregarItem(27);    //add four items to list
	li.agregarItem(36);
	li.agregarFinal(99);
	li.agregarItem(49);
	li.agregarFinal(72);
	li.mostrar();      //display entire list

	DoubleLinkedList<char> lch;         //make linked list
	lch.agregarItem('a');      //add four items to list
	lch.agregarItem('b');
	lch.agregarItem('c');
	lch.mostrar();           //display entire list

	Iterador<int> itli = li.begin();

	return 0;
}