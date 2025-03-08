#include<iostream>
using namespace std;

int main(){
	
	int arr[5]={5,1,3,9,2};
	int n=5;
	
	for(int gap=n/2;gap>0;gap/=2){
		for(int j=gap;j<n;j++){
			int temp = arr[j];
			int i =j;
			for( i=j;i>=gap && arr[i-gap]>temp;i-=gap){
				arr[i]=arr[i-gap];
			}
			arr[i] = temp;
		}
		
	}
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	
}