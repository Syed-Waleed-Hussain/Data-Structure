#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim) {
  int sum = 0;
  if (dim == 0) { // base case
    for (int i = 0; i < sizes[0]; i++) {
      sum += arr[i][0]; // add each element to the sum
    }
  } else {
    for (int i = 0; i < sizes[dim]; i++) {
      if (arr[i] != nullptr) { // recursively call the function on each sub-array
        sum += recursiveArraySum(arr[i], sizes, dim - 1);
      }
    }
  }
  return sum;
}

int main() {
  
  int arr1[] = {1, 2, 3};
  int arr2[] = {4, 5, 6};
  int arr3[] = {7, 8, 9};
  int* arr[] = {arr1, arr2, arr3};
  int sizes[] = {3, 3}; // sizes of each dimension

  int sum = recursiveArraySum(arr, sizes, 1); 
  cout << "Sum of all elements: " << sum << endl;

  return 0;
}