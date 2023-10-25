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
              throw out_of_range("Posición no válida");
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
            for(int i = 0; i < new_size; i++){
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            max = new_size;
        }        

        /* Métodos de List */

        void insert(int pos, T e) override{
          if(pos < 0 || pos >= max){
              throw out_of_range("Posición no válida");
          }
          if((n+1) > max){
            resize(n+1);
          }
          if(pos > n-1 || n == 0){
            arr[n] = e;
          }else{
            for(int i = 0,x = n,m = pos; m < n ;i++,m++){
              arr[x-i] = arr[(x-i)-1];
            }
            arr[pos] = e;
          }
          n += 1;
        }

        void append(T e) override{
          insert(n, e);
        }

        void prepend(T e) override{
          insert(0, e);
        }

        T remove(int pos) override{
          if(pos < 0 || pos >=max || n == 0 || pos >=n){
            throw out_of_range("Posicion no valida");
          }

          T borrar = arr[pos];

          if(pos == n-1){
            arr[pos] = -1;
          }else{
            for(int i = pos; i < n-1 ;i++){
              arr[i] = arr[i+1];
            }
          }
          n--;
          return borrar;
		}

        T get(int pos) override{
          if(pos < 0 || pos >= max){
              throw out_of_range("Posición no válida");
          }else{ 
            return arr[pos];
          }
        }  

        int search(T e) override{
          for(int i = 0; i < n; i++){
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
