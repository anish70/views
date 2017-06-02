// Program: bubble_sort.cpp
// Author: Megh Thakkar
// Purpose: Sort an array of n elements in ascending order
// using the bubble sort method

#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class mysort {
private:
	int *X;
        int n;
public:
	//List of data elements
	//Number of elements in the list
	mysort (int size) { X = new int[n=size]; }
	~mysort( ) { delete [ ]X; }
	void load_list (int input[ ] );
	void print_my_list(const char *title);
	void print_new_list(const char *title, int b[]);
	void bubble_sort(int input[ ]);
	void insertion_sort(int input[ ]);
	void selection_sort(int input[ ]);
	void quick_sort(int first, int last);
	void merge_sort(int a[], int b[], int low, int high);
	void merge(int a[], int b[], int low, int pivot, int high);
	void shell_sort(int input[]);
	void heap_sort(int input[]);
	void construct_heap();
	void establish_heap_property(int root, int limit);
};

void mysort::load_list(int input[])
{
    for (int i = 0; i < n; i++)
        X[i] = input[i];
}

void mysort::print_my_list(const char *title)
{
	cout << title << endl;
        cout << "\t";
	for (int i = 0; i < n; i++)
               cout << " " << X[i];
        cout << endl;
}

void mysort::print_new_list(const char *title, int b[])
{
	cout << title << endl;
        cout << "\t";
	for (int i = 0; i < n; i++)
               cout << " " << b[i];
        cout << endl;
}

void mysort::bubble_sort( int input[ ])
{
	int swapped = 1;
	load_list(input);
	// cout << “List to be sorted in ascending order using bubble sort” << endl;
	print_my_list("Bubble: before:");

	// The FOR loop is executed once for each element in the array.
	// At the end of each iteration, one element will be “bubbled” to
	// its correct position and is not considered for further iterations
	// of the loop.
	for (int i = 0; i < n && swapped == 1; i++) {
		// If at the end of an iteration there was no swapping done
		// then it indicates that the list is sorted as desired and
		// there is no need to do more iterations.
		swapped = 0;
                for (int j = 0; j < n-(i+1) ; j++) {
			// if X[j] > X[j+1] then it indicates that they are out of order.
			// Therefore swap them.
			if (X[j]>X[j+1]) {
				int temp;
				temp = X[j];
				X[j] = X[j+1];
				X[j+1] = temp;
				swapped = 1;
			}
		}
	}

	print_my_list("Bubble: after:");
	cout << endl;
}

void mysort::insertion_sort( int input[ ])
{
	char *title;
	// The array S is used for storing the elements as they get sorted.
	int S[100];
	load_list(input);

	print_my_list("Insertion Sort: before:");
	S[0] = X[0];

	//Each iteration of the FOR loop compares X[i] with the elements
	//in the sorted list S, in order to find its place in the array S.
       for (int i = 1; i < n ; i++) {
		int temp = X[i];
		int j = i-1;
		while (( S[j] > temp ) && ( j >= 0)) {
			S[j+1] = S[j];
			--j;
		}
		S[j+1] = temp;
	}

	//The method “show_list” uses the private array X. Therefore, we copy the
	// sorted array S to X , so that it can be printed.
	for (int m = 0; m < n; m++)
	       X[m] = S[m];
	print_my_list("Insertion Sort: after:");
	cout << endl;
}


void mysort::selection_sort(int input[])
{
	load_list(input);
	print_my_list("Selection Sort: Before:");

	// Using the FOR loop, iteratively find the lowest element in the list
	// and then move it to its correct position.
	for (int j = 0; j < (n-1); j++) {
		// For each iteration, start with the lowest element as the element
		// at index j.
		int lowest = j;
		for (int k = j+1; k < n ; k++) {
			if (X[k] < X[lowest])
				lowest = k;
		}
		//Once an element lower than the lowest known thus far is found, swap them.
	       int temp;
	       temp = X[j];
	       X[j] = X[lowest];
	       X[lowest] = temp;
	}
	print_my_list("Selection Sort: After:");
	cout << endl;
}

void mysort::quick_sort(int first, int last)
{
	//”temp” variable is temporary space used during swapping int temp;
	if (first < last) {
		int temp;

		//Start with the pivot as the first element in the list
		int pivot = X[first];
		//The variable “i” is used for scanning from the left.
		int i = first;
		//The variable “j” is used for scanning from the right.
		int j = last;

		while (i < j) {
			// Search the list for a data element that is greater than or equal to
			// the chosen pivot element. Search from the left.
			while (X[i] <= pivot && i < last)
				i += 1;
			// Search the list for a data element that is less than or equal to
			// the chosen pivot element. Search from the right.
			while (X[j] >= pivot && j > first)
				j -= 1;
			if (i < j) {
				//swap(X[i],X[j])
				temp = X[i];
				X[i] = X[j];
				X[j] = temp;
			}
		}

		//swap(X[j],X[first])
		temp = X[first];
		X[first] = X[j];
		X[j] = temp;
		//Recursively apply quick sort on the two splits
		quick_sort(first, j-1);
		quick_sort(j+1, last);
	}

}


void mysort::merge_sort(int a[], int b[], int low, int high)
{
	int pivot;
	if (low<high) {
		pivot=(low+high)/2;
		merge_sort(a,b,low,pivot);
		merge_sort(a,b,pivot+1,high);
		merge(a,b,low,pivot,high);
	}
}

void mysort::merge(int a[], int b[], int low, int pivot, int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=pivot+1;
 
    while((h<=pivot)&&(j<=high)) {
        if(a[h]<=a[j]) {
            b[i]=a[h];
            h++;
        } else {
            b[i]=a[j];
            j++;
        }
        i++;
    }

    if(h>pivot) {
        for(k=j; k<=high; k++) {
            b[i]=a[k];
            i++;
        }
    } else {
        for(k=h; k<=pivot; k++) {
            b[i]=a[k];
            i++;
        }
    }

    for(k=low; k<=high; k++) a[k]=b[k];
}
 
void mysort::shell_sort( int input[ ])
{
	int i,h;
	int temp;
	//Load the input list in the private array
	load_list(input);
	print_my_list("Shell Sort: Before:");

	//Implementing the shell_sort algorithm
	for (h = 1; h <= n/9; h = 3*h + 1) ;

	//Use diminishing values for “h”--the step.
	for ( ; h > 0; h /=3) {
		for (i = h ; i < n ; i++) {
			int j;
			temp = X[i];
			for ( j = i-h ; j >=0 ; j -= h ) {
				if (temp < X[j]) {
					X[j+h] = X[j];
				} else
					break;
			}
			X[j+h] = temp;
		}
	}
	print_my_list("Shell Sort: After:");
	cout << endl;
}

void mysort::establish_heap_property(int root, int limit)
{
	int done = 0;
	int biggest = X[root];
	int j=2*root;

	while ((j <= limit) && (done == 0)) {
		//Find which is the maximum among the left and right children
		if ((j < limit) && (X[j] < X[j + 1])) {
			j++;
		}

		//Compare the maximum child found with biggest.
		//If biggest is the maximum ➥exit.
		if (biggest >= X[j])
			done= 1;
		else {
			X[j/2] = X[j];
			j = 2 * j;
		}
	}
	X[j/2] = biggest;
}

void mysort::construct_heap(void)
{
	for (int i = n/2; i > 0; i--) {
		establish_heap_property (i, n);
	}
}

void mysort::heap_sort(int input[])
{
	print_my_list("Heap Sort: Before:");

	construct_heap();

	for (int i = (n - 1); i > 0; i--) {
		//Swap X[i+1] and X[1]
		int temp = X[i + 1];
		X[i + 1] = X[1];
		X[1] = temp;
		//  Place the root in the sorted position
		input[i] = X[i + 1];
		establish_heap_property (1, i);
	}

	input[0] = X[1];
	print_my_list("Heap Sort: After:");
	cout << endl;
}


//main( ) : Test driver for bubble sort
int
main()
{
	// Create a new object which has the method “bubble_sort”
	mysort sort_obj(15);
	static int unsorted_list[] = {54,6,50,40,30,20,26,73,1,80,63,44,39,98,12};
	sort_obj.bubble_sort(unsorted_list);
	sort_obj.insertion_sort(unsorted_list);
	sort_obj.selection_sort(unsorted_list);
	sort_obj.shell_sort(unsorted_list);
	sort_obj.heap_sort(unsorted_list);

	sort_obj.load_list(unsorted_list);
	sort_obj.print_my_list("Quick Sort: Before:");
	sort_obj.quick_sort(0, 14);
	sort_obj.print_my_list("Quick Sort: After:");
	cout << endl;

	sort_obj.load_list(unsorted_list);
	sort_obj.print_my_list("Merge Sort: Before:");
	int new_obj[15];
	sort_obj.merge_sort(unsorted_list, new_obj, 0, 14);
	sort_obj.print_new_list("Merge Sort: After:", new_obj);
}

