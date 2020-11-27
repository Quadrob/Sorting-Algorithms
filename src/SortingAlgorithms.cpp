//============================================================================
// Name        : SortingAlgorithms.cpp
// Author      : Robert Zeelie
// Version     : 1.00.00
// Copyright   : Your copyright notice
// Description : Given an array storing 1000 integers, write a C++ program that
//				 implements Bubble Sort, Quick Sort and Insertion Sort algorithms
//				 in sorting the array in ascending order. It also implements a
//				 binary search to find the position of an integer.
//============================================================================

#include <iostream>

using namespace std;

//size of array
#define SIZE 1000

//abstract class
class sortingAlgorithms {

	//initialize an array of size 1000
	int randArray[SIZE];

public:
	//constructor
	sortingAlgorithms();

	void printArray();		//function to print out the array

	void bubbleSort();		//function to sort an array using bubble sort

	int partition(int start, int end);//function to partition the array into lower and upper subarrays for quick sort
	void recursiveQuickSort(int start, int end);//function to recursively call its self and sort the array
	void quickSort();		//function to sort an array using quick sort

	void insertionSort();	//function to sort an array using insertion sort

	void binarySearch();		//function to call the recursive binary search for an element in an array
	int recursiveBinarySearch(int array[], int start, int end, int searchItem);//recursive binary search function
};

//details of the constructor function
sortingAlgorithms::sortingAlgorithms() {

	//int to store random number
	int randomNum;

	//for loop to fill array
	for (int i = 0; i < SIZE; i++) {
		//get a random number between 0 and the size of array then add to array
		randomNum = rand() % SIZE;
		randArray[i] = randomNum;
	}
}


//details for printing the array function
void sortingAlgorithms::printArray() {

	cout << "{";

	//for loop to loop through array
	for (int i = 0; i < SIZE; i++) {

		//if its the last array element close array
		if (i == SIZE - 1) {
			cout << randArray[i] << "}" << endl;

		} else {	//else just print element as normal
			cout << randArray[i] << ", ";
		}
	}
}

//details for the bubble sort function
void sortingAlgorithms::bubbleSort() {

	//for loop to iterate over the array
	for (int iteration = 1; iteration < SIZE; iteration++) {
		//for loop to go through each element of array
		for (int index = 0; index < SIZE - iteration; index++) {
			//element is greater than the next element swap them around
			if (randArray[index] > randArray[index + 1]) {
				//swap the index and index + 1 element around
				int tempValue = randArray[index];
				randArray[index] = randArray[index + 1];
				randArray[index + 1] = tempValue;
			}
		}
	}

	//print the array after sorting
	cout << "\n\nArray after Bubble Sorting:" << endl;
	printArray();
}

//details of the partition function
int sortingAlgorithms::partition(int start, int end) {

	int pivot = randArray[end];	// pivot
	int index = start;

	for (int iterator = start; iterator < end; iterator++) {

		//if current element is smaller than pivot, increment the low element swap elements at index and iterator
		if (randArray[iterator] <= pivot) {

			int tempValue = randArray[iterator];
			randArray[iterator] = randArray[index];
			randArray[index] = tempValue;

			index++;	//increment index of smaller element
		}
	}
	//swap elements
	int tempValue = randArray[index];
	randArray[index] = randArray[end];
	randArray[end] = tempValue;

	return index;	//return smaller element index
}

//details for the recursive function
void sortingAlgorithms::recursiveQuickSort(int start, int end) {

	if (start < end) {

		//partition the array
		int pivot = partition(start, end);

		//sort the sub arrays independently
		recursiveQuickSort(start, pivot - 1);
		recursiveQuickSort(pivot + 1, end);
	}
}

//details for the quick sort function
void sortingAlgorithms::quickSort() {

	//call the recursive function
	recursiveQuickSort(0, SIZE - 1);

	//print the array after sorting
	cout << "\n\nArray after Quick Sorting:" << endl;
	printArray();
}

//details for the insertion sort array
void sortingAlgorithms::insertionSort() {

	//for loop to go through array
	for (int index = 1; index < SIZE; index++) {
		//store element value and previous element position
		int tempValue = randArray[index];
		int position = index - 1;
		//while array position isn't 0 and previous element isn't greater
		while (position >= 0 && randArray[position] > tempValue) {
			//replace position of the next element with the previous element and decrease position
			randArray[position + 1] = randArray[position];
			--position;
		}
		//move value to new position
		randArray[position + 1] = tempValue;
	}

	//print the array after sorting
	cout << "\n\nArray after Insertion Sorting:" << endl;
	printArray();
}


//details for binarySearch function
void sortingAlgorithms::binarySearch(){

	//variables
	int userSearch;
	int position;

	//get the value to search for
	cout << "\n\nPlease enter the value you would like to search for : " << endl;
	cin >> userSearch;

	//call the recursive function and save the index it returns in position
	position = recursiveBinarySearch(randArray, 0, SIZE - 1, userSearch);

	//if the number isn't found tell user
	if(position == -1){
		cout << "\n\nThe value : " << userSearch << " was not found in the array!" << endl;

	}else{//else tell user index it was found at
		++position;
		cout << "\n\nThe value : " << userSearch << " was found at position : " << position << " of the array!" << endl;
	}
}


//details of the binary search recursive function
int sortingAlgorithms::recursiveBinarySearch(int array[], int start, int end, int searchItem){

	//if start is greater than end save middle element
	if (start <= end){
		int middleElement = start + (end - start) / 2;
		//cout<<middleElement;

		// If the element is present at the middle itself
		if (array[middleElement] == searchItem){
			return middleElement;
		}

		// If element is smaller than middle, then it can only be present in left subarray
		if (array[middleElement] > searchItem){
			return recursiveBinarySearch(array, start, middleElement - 1, searchItem);

		}else{
			// Else the element can only be present in right subarray
			return recursiveBinarySearch(array, middleElement + 1, end, searchItem);
		}
	}
	return -1;
}


//main function
int main() {

	//an instance of the sorting class
	sortingAlgorithms SortArray;
	int userInput;

	//display original array
	cout << "\tSorting Algorithms\n\nThe unsorted array is:" << endl;
	SortArray.printArray();

	//do this while user doesn't enter 0
	do {
		//display menu
		cout << "\n\nSorting Operations" << endl;
		cout << "1) Sort array using Bubble Sort"
				<< "\n2) Sort array using Quick Sort"
				<< "\n3) Sort array using Insertion Sort"
				<< "\n4) Search for a number in the array"
				<< "\n\n0) Exit program" << endl;

		cout << "\nPlease enter your choice : " << endl;
		cin >> userInput;

		switch (userInput) {
		case 1:

			SortArray.bubbleSort();
			break;

		case 2:
			SortArray.quickSort();
			break;

		case 3:
			SortArray.insertionSort();
			break;

		case 4:
			//to perform binary search the array needs to be sorted
			SortArray.quickSort();
			SortArray.binarySearch();
			break;

		case 0:
			cout << "\n\n\t** Exiting Application!**" << endl;
			break;

		default:
			cout << "\n\n\t'" << userInput << "' is invalid input!" << endl;
		}
	} while (userInput != 0);

	cout << "\n\nThank you for using my application :)" << endl;

	return 0;
}

