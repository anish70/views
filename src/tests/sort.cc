#include <string>
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a   = *b;
    *b   = temp;
}

int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);

    for (int j = si; j <= ei - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[ei]);
    return (i + 1);
}

void quickSort(int A[], int si, int ei) { // A[] --> Array to be sorted

    if(si < ei) { // si  --> Starting index; e1 —> Ending index
        int pi = partition(A, si, ei); /* Partitioning index */
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

void
bubble_sort(int a[], int num)
{
	cout << __func__ << " : ";

	for (int i = num-1; i > 1; i--)
		for (int j = 0; j < i-1; j++)
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
}

void
insertion_sort(int a[], int num)
{
	cout << __func__ << " : ";

	for (int i = 0; i < num-1; i++) {
		int j = i;
		while (j && (a[j] < a[j-1])) {
			swap(&a[j], &a[j-1]);
			--j;
		}
	}
}

int
main()
{
	static int unsorted_list[] = {54,6,50,40,30,20,26,73,1,80,63,44,39,98,12};
	int num = sizeof(unsorted_list)/sizeof(unsorted_list[0]);

	// bubble_sort(unsorted_list, num);
	// insertion_sort(unsorted_list, num);
	quickSort(unsorted_list, 0, num -1);
        for (int i = 0; i < num; i++)
		cout << " " << unsorted_list[i];
	cout << endl;
}

