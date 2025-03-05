#include <iostream>

using namespace std;

template <typename T>
class BinaryHeap {
private:
    T* _heap;
    size_t _size;
    size_t _capacity;

    void ShiftUp(size_t pos){
        while (pos > 0 && _heap[pos] < _heap[(pos - 1) / 2]){
            swap(_heap[pos], _heap[(pos - 1) / 2]);
            pos  = (pos - 1) / 2;
        }
    }

    void ShiftDown(size_t pos){
        while (2 * pos + 1 < _size){
            size_t left = 2*pos + 1, right = 2*pos + 2;
            size_t tmp = (right < _size && _heap[right] < _heap[left]) ? right : left;
            
            if (_heap[pos] <= _heap[tmp]) break;
            
            swap(_heap[pos], _heap[tmp]);
            pos = tmp;
        }
    }

    inline void Resize(){
        _capacity *= 2;
        T* newHeap = new T[_capacity];
        copy(_heap, _heap + _size, newHeap);
        delete[] _heap;
        _heap = newHeap;
    }
public:
    BinaryHeap(size_t capacity) : _heap(new T[capacity]),
                                   _capacity(capacity),
                                   _size(0) {} 

    T GetMin(){
        if (_size == 0) throw "Heap is Empty";
        T min = _heap[0];
        _heap[0] = _heap[--_size];
        ShiftDown(0);         
        return min;
    }

    void Insert(T elem){
        if (_size == _capacity) Resize();

        _heap[_size++] = elem;
        ShiftUp(_size - 1);
    }

    void BuildBHeap(){
        if (_size == 0) return;
        for(size_t i = _size / 2; i-- > 0;){
            ShiftDown(i);
        }
    }


    BinaryHeap Megre(BinaryHeap& b){
        BinaryHeap result(2 * (_size + b._size));

        for (size_t i = 0; i < _size; i++) 
            result.Insert(_heap[i]);
        
        for (size_t i = 0; i < b._size; i++) 
            result.Insert(b._heap[i]);

        return result;
    }


    ~BinaryHeap(){
        delete [] _heap;
        _heap = nullptr;
    }
};
