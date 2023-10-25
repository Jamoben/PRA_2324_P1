#include <ostream>
#include "List.h"

using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;

    public:

        /* Métodos de ListArray */

        ListArray(){
            max = MINSIZE;
            n = 0;
            arr = new T[MINSIZE];            
        }

        ~ListArray(){
            delete[] arr;
        }

        T operator[](int pos){
            if(pos < 0 || pos > size()){
              throw std::out_of_range("Posición no válida");
            }else{
              return arr[pos];
            }
        }

        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
            out << "List => [";
		if(list.n > 0){
		    for(int i = 0; i < list.n ; i++){
			out << "\n\t" << list.arr[i];
		}
		    out << "\n]";
		}else{
		    out << "]";
		}
		return out;
        }

        void resize(int new_size){
            T* newarr = new T[new_size];
            for(int i = 0; i < new_size; i++)
                newarr[i] = arr[i];
            delete[] arr;
            arr = new arr;
            max = new_size;
        }        

        /* Métodos de List */

        void insert(int pos, T e) override{
          if(pos < 0 || pos > size()){
              throw std::out_of_range("Posición no válida");
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
              throw std::out_of_range("Posición no válida");
          }else{
            T elemento = arr[pos];
            arr[pos] = NULL;
            return elemento;
          }
        }

        T get(int pos) override{
          if(pos < 0 || pos > size()){
              throw std::out_of_range("Posición no válida");
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
