#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE;

    public:
        void insert(int pos, T e){
          if(pos < 0 || pos > size()-1){
              throw std::out_of_range("Posición no válida");
          }else{
            arr[pos] = e;
          }
        }

        void append(T e){
          arr[max] = e;
        }

        void prepend(T e){
          arr[0] = e;
        }

        T remove(int pos){
          if(pos < 0 || pos > size()-1){
              throw std::out_of_range("Posición no válida");
          }else{
            T elemento = arr[pos];
            arr[pos] = NULL;
            return elemento;
          }
        }

        T get(int pos){
          if(pos < 0 || pos > size()-1){
              throw std::out_of_range("Posición no válida");
          }else{
            T elemento = arr[pos];
            return elemento;
          }
        }  

        int search(T e){
          for(int i = 0; i < size() - 1; i++){
            if(arr[i] == e)
              return i;
          }
          return -1;
        }

        bool empty(){
          if (size() == 0)
            return true
          else
            return false
        }

        int size(){
          return arr.size();
        }          
};
