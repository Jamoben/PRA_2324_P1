#include <ostream>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;

    public:

        /* Métodos de ListLinked */

	ListLinked(){
	  first = nullptr;
          n = 0;
	}

	~ListLinked(){
	  Node<T>* aux = first;
	  while(aux != nullptr){
	    Node<T>* next = aux->next;
	    delete next;
	    aux = next;
	  }
	}

	T operator[](int pos){
	  if(pos < 0 || pos >=n ){
	    throw out_of_range("Posicion invalida");
	  }
			
	  Node<T>* aux = first;
	    for(int i = 0;i < pos;i++){
	      aux = aux->next;
	    }
	  return aux->data;
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
	  out << "List => [";
          Node<T>* aux = list.first;
	  int siguiente = 0;
	  while(aux != nullptr){
	    out << "\n\t" << aux->data;
	    aux = aux->next;
	    siguiente = 1;
	  }
	  if(siguiente){
            out << "\n";
          }
	  out << "]";
          return out;
 	}

        /* Métodos de List */

        void insert(int pos, T e) override{
          if(pos < 0 || pos > size()){
              throw out_of_range("Posición no válida");
          }else{
            Node<T>* aux = new Node<T>(e);
	    aux = first;
	    for(int i = 1 ; i < pos ; i++){
              aux = aux->next;
            }
	    n += 1;
          }
        }

        void append(T e) override{
          insert(n, e);
        }

        void prepend(T e) override{
          insert(0, e);
        }

        T remove(int pos) override{
          if(pos < 0 || pos > size()){
              throw out_of_range("Posición no válida");
          }else{
	    Node<T>* aux = first;
	    for(int i = 1; i < pos; i++){
		aux = aux->next;
	    }
            Node<T>* borrar = aux->next;
            aux->next = borrar->next;
	    T elemento = borrar->data;
	    delete borrar;
	    n--;
            return elemento;
          }
        }

        T get(int pos) override{
          if(pos < 0 || pos > size()){
              throw out_of_range("Posición no válida");
          }else{ 
             Node<T>* aux = first;
	     for (int i = 0; i < pos; i++) {
	       aux = aux->next;
	     }
	  return aux->data;
          }
        }  

        int search(T e) override{
	  Node<T>* aux = first;
          for(int i = 0; i < size(); i++){
            if(aux->data == e)
              return i;
          }
          return -1;
        }

        bool empty() override{
          if (size() == 0)
            return true;
          else
            return false;
        }

        int size() override{
          return n;
        }   
};
