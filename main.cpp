#include "Binary_Heap.h"

int main(){
    BinaryHeap<int> bh(10);
    bh.Insert(11);
    bh.Insert(12);
    bh.Insert(1000);
    bh.Insert(0);
    bh.Insert(-111);
    bh.Insert(0);
    bh.Insert(1);
    bh.Insert(2);
    bh.Insert(3);
    bh.Insert(4);

    bh.BuildBHeap();

    cout << bh.GetMin() << endl;
    
    for (int i = 0; i < 9; i++) cout << bh.GetMin() << endl;

    return 0;
}