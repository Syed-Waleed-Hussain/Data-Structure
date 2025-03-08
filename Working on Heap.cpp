#include<iostream>
using namespace std;

void minheap(int arr[],int i){
    int parent = (i-1)/2;
    while(i > 0 && arr[i] < arr[parent]){
        swap(arr[i],arr[parent]);
        i = parent;
        parent = (i-1)/2;
    }
}
void addpackage(int arr[],int &size,int priority){
    arr[size] = priority;
    minheap(arr, size);
    size++;
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int heaparr[100]={4,2,1,6,8};
    int size = 5;
    cout<<"Initial Heap :"<<endl;
    display(heaparr,size);

    int p=0;
    cout<<"Enter a priority to add :"<<endl;
    cin>>p;
    addpackage(heaparr,size,p);

    cout<<"Updated Heap :"<<endl;
    display(heaparr,size);
}