#ifndef HEAP_H
#define HEAP_H

template <class T>
class heap{
private:
    bool isMin;
    int size;
    std::vector<T> MinMaxHeap;

public:
    heap(std::vector<T> a, int size, bool isMin);
    void heapify(int i);

    int left(int i)  {return (2 * i + 1);}
    int right(int i) {return (2 * i + 2);}

    void insert(int el);
    void remove(int el);

    T get_root();
    T extract_root();

    int get_size();
    int get_min();
    int get_max();
    bool search(int input);

    bool compare(T a, T b);
};

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


template <class T>
void heap<T>::heapify(int i){
    int l = left(i);
    int r = right(i);

    if(isMin==true){
        
        int smallest = i;
        if (l < size && MinMaxHeap[l] < MinMaxHeap[i]){
            smallest = l;
        }
        if (r < size && MinMaxHeap[r] < MinMaxHeap[smallest]){
            smallest = r;
        }
        //if the child is smaller than parent,swap them
        if (smallest != i) {
            swap(&MinMaxHeap[i], &MinMaxHeap[smallest]);
        //now check newly swaped number is smaller than its children or not
        heapify(smallest);
        }

    }else{
        int biggest = i;
        if (l < size && MinMaxHeap[l] > MinMaxHeap[i]){
            biggest = l;
        }
        if (r < size && MinMaxHeap[r] > MinMaxHeap[biggest]){
            biggest = r;
        }
        //if the child is bigger than parent,swap them
        if (biggest != i) {
            swap(&MinMaxHeap[i], &MinMaxHeap[biggest]);
        //now check newly swaped number is bigger than its children or not
        heapify(biggest);
        }
    }

    // if(isMin==true){
    //     int parent = (i - 1) / 2;
    //     if(parent>0){
    //         if(MinMaxHeap[i]<MinMaxHeap[parent]){
    //             swap(&MinMaxHeap[i], &MinMaxHeap[parent]);
    //             heapify(parent);
                
    //         }
    //     }
    // }else{
    //     int parent = (i - 1) / 2;
    //     if(parent>0){
    //         if(MinMaxHeap[i]>MinMaxHeap[parent]){
    //             swap(&MinMaxHeap[i], &MinMaxHeap[parent]);
    //             heapify(parent);
    //         }
    //     }
    // }

    // std::cout << MinMaxHeap[0] << std::endl;



}



template <class T>
heap<T>::heap(std::vector<T> a, int input_size, bool isMin_input){
    size = input_size;
    MinMaxHeap = a;
    isMin = isMin_input;

    int i = (size - 1) / 2;
    while (i >= 0){
        heapify(i);
        i--;
    }
    
}



template <class T>
void heap<T>::insert(int el){
    size += 1;
    MinMaxHeap.resize(size);
    MinMaxHeap[size-1] = el;




    int i = (size - 1) / 2;
    while (i >= 0){
        heapify(i);
        i--;
    }

  

    //heapify(size-1);
}



template <class T>
void heap<T>::remove(int el){
    int lastElement = MinMaxHeap[size - 1];
    int position;
    for (int i = 0; i < size; i++){
        if(MinMaxHeap[i]==el){
            position = i;
            MinMaxHeap[i] = lastElement;
            MinMaxHeap.resize(size - 1);
            size -= 1;
        }
    }


    int i = (size - 1) / 2;
    while (i >= 0){
        heapify(i);
        i--;
    }


    //heapify(position);
}




template <class T>
T heap<T>::get_root(){
    return MinMaxHeap[0];
}

template <class T>
T heap<T>::extract_root(){
    int lastElement = MinMaxHeap[size - 1];
    MinMaxHeap[0] = lastElement;
    size -= 1;
    heapify(0);
}

template <class T>
int heap<T>::get_size(){
    return size;
}

template <class T>
int heap<T>::get_min(){
    int min = 9999;

    for (int i=0; i < size; i++){
        if (MinMaxHeap[i] < min)
        {
            min = MinMaxHeap[i];
        }
    }
    return min;
}

template <class T>
int heap<T>::get_max(){
    int max = -9999;
    for (int i=0; i < size; i++){
        if(MinMaxHeap[i]>max){
            max = MinMaxHeap[i];
        }
    }
    return max;
}

template <class T>
bool heap<T>::search(int input){
    bool result = false;
    for (int i=0; i < size; i++){
        if(MinMaxHeap[i]==input){
            result = true;
        }
    }
    return result;
}





#endif