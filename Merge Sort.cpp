#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r){
	int size1= mid - l +1;
	int size2 = r-mid;
	int left[size1],right[size2];
	
	for(int i=0;i<size1;i++){
		left[i]=arr[l+i];
	}
	for(int i=0;i<size2;i++){
		right[i]=arr[mid+1+i];
	}
	
	int i=0,j=0,k=l;
	
	while(i<size1 && j<size2){
		if(left[i] <= right[j]){
			arr[k]=left[i];
			k++;i++;
		}else{
			arr[k]=right[j];
			k++;j++;
		}
	}
	while(i<size1){
		arr[k]=left[i];
			k++;i++;
	}
	while(j<size2){
		arr[k]=right[j];
			k++;j++;
	}
	
}



void mergesort(int arr[],int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}



int main(){
	int arr[5]={5,1,8,3,0};
	mergesort(arr,0,4);
	for(int i=0;i<5;i++){
		cout<<arr[i]<<" ";
	}
	
}