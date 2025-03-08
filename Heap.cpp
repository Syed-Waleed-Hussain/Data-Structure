#include<iostream>
using namespace std;

void maxheap(int arr[],int size,int i){
    int largest = i;
    int left = i * 2 +1;
    int right = i * 2 +2;

    if(left > size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right > size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        maxheap(arr,size,largest);
    }
}
void deleteroot(int arr[], int &size){
    if(size <= 0){
        cout<<"Empty heap ..!"<<endl;
        return;
    }
    arr[0] = arr[size -1];
    size--;
    maxheap(arr,size,0);

}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int heaparr[100]={10,20,60,50,30,40};
    int size = 6;
    cout<<"Initial Heap:"<<endl;

    display(heaparr,size);

    cout<<"Removing the root as it has highest priority."<<endl;
    deleteroot(heaparr,size);

    cout<<"Updated Heap :"<<endl;
    display(heaparr,size);

    return 0;
}