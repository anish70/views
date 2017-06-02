#include <iostream>
using namespace std;

void MAX_HEAPIFY(int a[], int i, int n)
{
	int l,r,largest,temp;
	l = 2*i;
	r = l + 1;
	largest = ((l<=n) && a[l] > a[i]) ? l : i;

	if ((r<=n) && (a[r] > a[largest])) {
		largest = r;
	}
	
	if (largest != i) {
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		MAX_HEAPIFY(a, largest,n);
	}
}

void BUILD_MAX_HEAP(int a[], int n)
{
	// for n=12;  for from 6 to 1
	for(int k = n/2; k >= 1; k--) {
		MAX_HEAPIFY(a, k, n);
	}
}

void HEAPSORT(int a[], int n)
{
	BUILD_MAX_HEAP(a,n);

	for (int i = n; i >= 2; i--) {
		int temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		MAX_HEAPIFY(a, 1, i - 1);
	}
}

int main()
{
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;

	int a[n];
	cout<<"Enter the elements in the array"<<endl;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}

	HEAPSORT(a, n);
	cout<<":::::::SORTED FORM::::::"<<endl;
	for (int i = 1; i <= n; i++) {
		cout<<a[i]<<endl;
	}
}
