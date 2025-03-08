#include <iostream>
using namespace std;
void print(int* c,int k) {
    cout<<"( ";
    for(int i=0;i<k;i++) {
        cout<<c[i]<<" ";
    }
    cout<<")"<<endl;
}
void dateHelper(int k,int n,int start,int index,int* c)
{
    if(index==k) {
        print(c,k);
        return;
    }
    if(start<=n) {
        c[index]=start;
        dateHelper(k,n,start+1,index+1,c); 
        dateHelper(k,n,start+1,index,c);
    }
}
void date(int k, int n) {
    int* array = new int[k];
    dateHelper(k,n,1,0,array);
    delete[] array;
}
int main() {
    int k, n;
    cout << "The event will last how many days (k): ";
    cin >> k;
    cout << "What's the potential last date (n): ";
    cin >> n;
    if (k > n) {
        return 0;
    }
    date(k, n);
    return 0;
}