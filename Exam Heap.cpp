#include<iostream>
using namespace std;

class Minheap{
    public:
    int* arr;
    int position;
    int size;
    Minheap(int s):size(s),position(0){
        arr = new int[s];
    }
    int left(int i){
        return i *2 +1;
    }
     int right(int i){
        return i *2 +2;
    }
    int parent(int i){
        return (i -1)/2;
    }
    void insertion(int score){
        if(position == size){
            cout<<"Heap is full, can not add more in Heap."<<endl;
        }
        arr[position] = score;
        heapifyup(position);
        position++;
    }
    void heapifyup(int pos){
        while( pos != 0 && arr[parent(pos)] > arr[pos]){
            swap(arr[parent(pos)],arr[pos]);
            pos = parent(pos);
        }
    }
    void heapifydown(int curr){
        int min = curr;
        int l =left(curr);
        int r = right(curr);
        if(l < position && arr[l] < arr[min]){
            min = l;
        }
        if(r < position && arr[r] < arr[min]){
            min = r;
        }
        if(min != curr){
            swap(arr[min],arr[curr]);
            heapifydown(min);
        }
    }
    void deletemin(){
        if(position == 0){
            cout<<"No more scores"<<endl;
        }
        cout<<arr[0] <<" ";
        arr[0] = arr[position -1];
        position--;
        heapifydown(0);
    }
};
int main(){
    int scores[7]={ 45,20,35,10,50,30,25 };
    Minheap heap(7);
        for(int i=0; i<7 ;i++){
            heap.insertion(scores[i]);
        }
   cout << "Top Three Performers:";
    for (int i = 0; i < 3; i++) {
        heap.deletemin();
    }
    cout << endl;

    cout << "Worst Performers: ";
    for (int i = 0; i < 4; i++) {
        heap.deletemin();
    }
    cout << endl;
    return 0;
}