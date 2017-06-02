#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_me(int a[], int len) {
	for (int i =0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main ()
{
    int first[] = {5,10,15,20,25,40};
    int second[] = {50,25,30,20,40,10};

    sort (first, first + 6);
    sort (second, second + 6);

    cout << "First: "; print_me(first, 6);
    cout << "Second: "; print_me(second, 6);

    vector<int> v(20);
    vector<int>::iterator it;
    it = set_union (first, first + 6, second, second + 6, v.begin());
    v.resize(it - v.begin());
    cout << "The union has " << (v.size()) << " elements: "<<endl;
    for (it = v.begin(); it != v.end(); ++it)
        cout<< *it<<"  ";
    cout <<endl;

    it = set_difference (first, first + 6, second, second + 6, v.begin());
    v.resize(it - v.begin());
    cout << "The difference has " << (v.size()) << " elements: "<<endl;
    for (it = v.begin(); it != v.end(); ++it)
        cout<< *it<<"  ";
    cout <<endl;

    vector<int> s(20);
    it = set_intersection (second, second + 6, first, first + 6, s.begin());
    s.resize(it - s.begin());
    cout << "The intersection has " << (s.size()) << " elements: "<<endl;
    for (it = s.begin(); it != s.end(); ++it)
        cout<< *it<<"  ";
    cout <<endl;

    vector<int> u(20);
    it = merge (second, second + 6, first, first + 6, u.begin());
    u.resize(it - u.begin());
    cout << "The merge has " << (u.size()) << " elements: "<<endl;
    for (it = u.begin(); it != u.end(); ++it)
        cout<< *it<<"  ";
    cout <<endl;
    return 0;
}
