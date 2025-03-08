#include<iostream>
using namespace std;

int main(){
	
	int arr[5]={4,7,1,3,9};
	int n=5;
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				int temp = arr[i];
				arr[i]= arr[j];
				arr[j]= temp;
			}
		}
	}
		for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	
	
	
	
}