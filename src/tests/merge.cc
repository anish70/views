#include <iostream>
#include <algorithm>

using namespace std;

static int input[] = {54,6,50,40,30,20,26,73,1,80,63,44,39,98,12};

void merge(int a[], int b[], int low, int pivot, int high)
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


void merge_sort(int a[], int b[], int low, int high)
{
        int pivot;
        if (low<high) {
                pivot=(low+high)/2;
                merge_sort(a,b,low,pivot);
                merge_sort(a,b,pivot+1,high);
                merge(a,b,low,pivot,high);
        }
}

void swapme(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort(int first, int last)
{
// {54,6,50,40,30,20,26,73,1,80,63,44,39,98,12};
	if (first >= last) return;

	//Start with the pivot as the first element in the list
	int pivot = input[first];
	int i = first;
	int j = last;

	while (i < j) {
		// Search the list for a data element that is greater than or equal to
		// the chosen pivot element. Search from the left.
		while (input[i] <= pivot && i < last)
			i += 1;

                        // Search the list for a data element that is less than or equal to
                        // the chosen pivot element. Search from the right.
                        while (input[j] >= pivot && j > first)
                                j -= 1;

			if (i < j) {
				//swap(X[i],X[j])
				swapme(&input[i], &input[j]);
			}
	}

	//swap(X[j],X[first])
	swapme(&input[j], &input[first]);

	//Recursively apply quick sort on the two splits
	quick_sort(first, j-1);
	quick_sort(j+1, last);
}

int
main()
{
	int nelem = sizeof(input)/sizeof(input[0]);
	int result[nelem];

	merge_sort(input, result, 0, nelem -1);
	for (int i = 0; i < nelem; i++) {
		cout << " " <<  result[i];
	}
	cout << endl;

	quick_sort(0, nelem-1);
	for (int i = 0; i < nelem; i++) {
		cout << " " <<  input[i];
	}
	cout << endl;
	return 0;
}
