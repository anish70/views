#include <iostream>
 
using namespace std;
void merge(int*,int*,int,int,int);

void mergesort(int *a, int*b, int low, int high)
{
	int pivot;

	if (low < high) {
		pivot = (low+high)/2;
		mergesort(a, b,low, pivot);
		mergesort(a, b, pivot+1, high);
		merge(a, b,low, pivot, high);
	}
}

void merge(int *a, int *b, int low, int pivot, int high)
{
	int k;
	int h=low;
	int i=low;
	int j=pivot+1;
 
	// low to pivot && pivot+1 to high
	while ((h <= pivot) && (j <= high)) {
		if (a[h]<=a[j]) {	// low < pivot+1
			b[i] = a[h];	// copy from low
			h++;
		} else {
			b[i] = a[j];	// copy from pivot
			j++;
		}

		i++;
	}

	if (h > pivot) {	// low past pivot?
		for (k=j; k<=high; k++) {	// from pivot to high
			b[i]=a[k];		// copy over
			i++;
		}

	} else {		// low <= pivot
		for (k=h; k<=pivot; k++) {	// copy from low to pivot
			b[i]=a[k];
			i++;
		}
	}

	// do the merge from low to high
	for (k=low; k<=high; k++) {
		a[k]=b[k]; 
	}
}
 
int main()
{
	int a[] = {-12,10,43,23,-78,45,-123,56,98,41,90,24};
	int num = sizeof(a)/sizeof(int);
	int b[num];
 
	mergesort(a,b,0,num-1);
	for(int i=0; i<num; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}


