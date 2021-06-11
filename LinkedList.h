#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__
#include<iostream>
#include "Node.h"
class LinkedList{
	private:
		int size;
		Node* head;
	public:
		LinkedList(int _size, Node _head){size = _size; head = &_head;};
		~LinkedList();	
		Node* getHead(){return head;}
		void insert(int);
		void removeInd(int);
		void removeVal(int);
		void print();
		friend std::ostream& operator<<(std::ostream& salida, LinkedList l);
};

std::ostream& operator<<(std::ostream& salida, LinkedList l){
	Node* aux1 = l.getHead();
	if(aux1 == nullptr){
		salida << "Lista vacia\n";
		return salida;
	}
	while(aux1 != nullptr){
		salida << *aux1;
		aux1 = aux1->getNext();
	}
	salida << '\n';
	return salida;
}

LinkedList::~LinkedList(){
	/*
	Node* aux1 = head;
	Node* aux2 = nullptr;
	while(aux1 != nullptr){
		aux2 = aux1;
		delete aux1;
		aux1 = aux2->getNext();
	}
	delete aux2;
	*/
}
void LinkedList::insert(int n){
	Node *aux1 = new Node(n);
    Node *aux2 = head;
    //lista vacía
    if (head == nullptr) {
        head = aux1;
        size++;
        return;
    }
    //inserta al inicio
    if(head->getElem() > n) {
        aux1->setNext(head);
        head = aux1;
    }else{
    	//busca la posicion
        while((aux2->getNext() != nullptr) && (aux2->getNext())->getElem() < n){
            aux2=(aux2->getNext());
        }
        aux1->setNext(aux2->getNext());
        aux2->setNext(aux1);
    }
    size++;
}
void LinkedList::removeInd(int pos){
	Node *aux = head;
	Node *ant = nullptr;
    if(aux == nullptr){
    	std::cout << "Lista vacia\n";
    	return;
	}
	if(pos > size){
		std::cout << "Elemento fuera de rango\n";
		return;
	}
	if(pos == 1){
		head = head->getNext();
		size--;
		return;
	}
	pos--;
	while(pos--){
		ant = aux;
		aux = aux -> getNext();
	}
	ant -> setNext(aux->getNext());
	size--;
}
void LinkedList::removeVal(int val){
	Node *aux = head;
	Node *sig = head->getNext();
	if(head == nullptr){
		std::cout << "Lista vacia\n";
		return;
	}
	while(sig != nullptr){
		if(sig->getElem() == val){
			aux->setNext(sig->getNext());
			size--;
			return;
		}
		aux = aux -> getNext();
		sig = sig -> getNext();
	}
	std::cout << "No se encontro el dato\n";
}
void LinkedList::print(){
	Node* aux1 = head;
	if(aux1 == nullptr){
		std::cout << "Lista vacia\n";
		return;
	}
	while(aux1 != nullptr){
		std::cout << *aux1;
		aux1 = aux1->getNext();
	}
	std::cout << '\n';
}

#endif
