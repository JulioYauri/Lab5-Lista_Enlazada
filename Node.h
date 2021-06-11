#ifndef __NODE_H__
#define __NODE_H__
#include<iomanip>
class Node{
	private:	
		int elem;
		Node* next;
	public:
		Node(){elem = 0; next = nullptr;}
		Node(int _elem){elem = _elem; next = nullptr;}
		Node(Node& n){elem = n.getElem(); next = n.getNext();}
		
		int getElem(){return elem;}
		Node* getNext(){return next;}
		
		void setElem(int n){elem = n;}
		void setNext(Node* n){next = n;}
		
		friend std::ostream &operator<<(std::ostream& salida, Node& n){
			salida << n.elem << " ";
			return salida;
		}
};

#endif
