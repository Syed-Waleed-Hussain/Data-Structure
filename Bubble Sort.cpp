#include<iostream>
using namespace std;

int main(){
	
	int arr[5]={5,3,1,7,4};
	int n =5;
	for(int i=0;i<n;i++){
		for(int j = i+1; j<n;j++){
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