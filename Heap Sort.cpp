#include<iostream>
using namespace std;

void heapifymax(int arr[],int size,int i){
    int largest = i;
    int left = i * 2 +1;
    int right = i * 2 +2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapifymax(arr,size,largest);
    }
}
void heapifymin(int arr[],int size,int i){
    int smallest = i;
    int left = i * 2 +1;
    int right = i * 2 +2;

    if(left < size && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < size && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i],arr[smallest]);
        heapifymin(arr,size,smallest);
    }
}
void createmaxheap(int arr[],int size){
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifymax(arr, size, i);
    }
}
void deletevalue(int arr[],int &size, int val){
    int index = -1;
     for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            index = i;
            break;
        }
    }
    if(index == -1){
        cout<<"Value is not found..!"<<endl;
        return;
    }
    arr[index] = arr[size -1];
    size--;
    heapifymax(arr,size,index);
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void createminheap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifymin(arr, size, i);
    }
}
void heapSort(int arr[], int size) {
    createmaxheap(arr, size);
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapifymax(arr, i, 0); 
    }
}
int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE] = {25, 30, 35, 11, 15, 19, 18, 55, 78, 36};
    int size = 10;

    // Part (a) - Create a Max Heap and Delete 55
    cout << "Original Array:" << endl;
    display(arr, size);

    createmaxheap(arr, size);
    cout << "Max Heap:" << endl;
    display(arr, size);

    deletevalue(arr, size, 55);
    cout << "Max Heap after deleting 55:" << endl;
    display(arr, size);

    // Part (b) - Create a Min Heap and Delete 18
    createminheap(arr, size);
    cout << "Min Heap:" << endl;
    display(arr, size);

    deletevalue(arr, size, 18);
    cout << "Min Heap after deleting 18:" << endl;
    display(arr, size);

    // Part (c) - Sort the Max Heap
    heapSort(arr, size);
    cout << "Heap Sorted Array:" << endl;
    display(arr, size);

    return 0;
}