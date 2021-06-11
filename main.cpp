#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
	Node a(11);
	
	LinkedList lista(1, a);
	lista.insert(2);
	lista.insert(5);
	lista.insert(1);
	lista.insert(10);
	lista.insert(3);
	lista.print();
	//1 2 3 5 10 11 
	
	lista.removeInd(4);
	lista.print();
	//1 3 5 10 11
	
	lista.removeVal(10);
	cout << lista << '\n';
	//1 3 5 11
	
	//Probando indices fuera de rango 
	//y elementos que no estan en la lista
	lista.removeInd(7);
	lista.removeVal(20);
	return 0;
}
