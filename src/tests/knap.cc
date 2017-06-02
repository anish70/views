#include <iostream>

using namespace std;

int n;
int CAP;

pair<int,int> Knap(int i, int w, int cost[], int weight[])
{
	if (i==n+1) {
		return make_pair(0,w);
	}

	pair<int,int> profit1, profit2;

	if (w + weight[i] <= CAP) {
		pair<int,int> tmp = Knap(i+1, w + weight[i], cost, weight);
		profit1 = make_pair(tmp.first + cost[i], tmp.second);
	} else {
		profit1 = make_pair(0,0);
	}  	

	profit2 = Knap(i+1, w, cost, weight);

	return max(profit1, profit2);
}

int main()
{
	cout << "How many Elements?"; cin>>n;
	cout << "Max Caps?"; cin>>CAP;
	int cost[n], weight[n];

        for(int i=1; i<=n; i++) {
            scanf("%d %d",&weight[i],&cost[i]);
        }

        pair<int,int>P;
        P = Knap(1, 0, cost, weight);

        cout << P.first << " " << P.second << endl;
}
