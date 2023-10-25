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
        /* Métodos de List */
        void insert(int pos, T e) override{
          if(pos < 0 || pos > size()){
              throw out_of_range("Posición no válida");
          }else{
            arr[pos] = e;
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
            T elemento = arr[pos];
            arr[pos] = NULL;
            return elemento;
          }
        }

        T get(int pos) override{
          if(pos < 0 || pos > size()){
              throw out_of_range("Posición no válida");
          }else{ 
            return arr[pos];
          }
        }  

        int search(T e) override{
          for(int i = 0; i < size(); i++){
            if(arr[i] == e)
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
