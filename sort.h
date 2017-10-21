#include <iostream>
using namespace std;

//function to check if a value is in an array
//if the value is found the for loop stops and the function returns 1
//if not found the loop goes to end and returns 0
int found(int arr[], int value, int len) {
	for (int i = 0; i<len; i++) {
		if (value == arr[i]) {
			return 1;
			break;
		}
		else {
			return 0;
		}
	}
	
}



//function will search for the smallest int and place it first
//in the sorted array. then find the second smallest and so on
int* sort(int arr[], int len) {
	
	//declare the sorted array
	int* sortedArr = NULL;
	sortedArr = new int[len] {};
	
	
	//declare the array to store used indexes
	int* indexArr = NULL;
	indexArr = new int [len] {};
	
	
	//fill the index array with -1's 
	//this is done because 0's would cause trouble
	//because 0 is an index that can be used.
	for(int i = 0; i<len; i++)
	{
		indexArr[i] = -1;
	}
	
	int indexSmallestValue;
	int smallestValue;

	//loop that sorts the array
	for (int i = 0; i<len; i++) {
		
		//makes sure you select a new smallest value every iteration
		indexSmallestValue = 0;
		while(found(indexArr,indexSmallestValue,len)==1)
		{
			indexSmallestValue++;
		}
		smallestValue = arr[indexSmallestValue];

		//finds the smallest value in the array and makes sure the value isn't already used
		for (int j = 0; j < len; j++) {
				if (smallestValue > arr[j] && found(indexArr, j, len) != 1) {
					smallestValue = arr[j];
					indexSmallestValue = j;
				}
			
			//index of the smallest value is put in the index array
			//value of the smallest value is put in the sorted array
			indexArr[i] = indexSmallestValue;
			sortedArr[i] = smallestValue;
		}
	}
	return sortedArr;
}

int main() {
	int len;

	cout << "Lenght of array: ";
	cin >> len;

	//variables
	int *arr = new int[len];

	//fill array with given values
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	//print given array
	for(int i=0; i<len;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//sort array
	int* sortedArr = sort(arr,len); 

	//print sorted array
	for (int i = 0; i<len; i++)
	{
		cout << sortedArr[i] << " ";
	}
	cout << endl;

	//end program
	delete[] arr;
	delete[] sortedArr;
	return 0;
}