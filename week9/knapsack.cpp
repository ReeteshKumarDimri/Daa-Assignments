// C/C++ program to solve fractional Knapsack Problem
#include <bits/stdc++.h>

using namespace std;
class Item {
    public:
	int value, weight,pos;
    Item(){};
	Item(int v, int w ,int p):value(v),weight(w),pos(p){}
};
bool cmp(class Item a, class Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}
double fractionalKnapsack(int W, class Item arr[], int n)
{
	sort(arr, arr + n, cmp);
    cout<<"Item Weight : \n";
	double finalvalue = 0.0;
	for (int i = 0; i < n; i++) {
		if (arr[i].weight <= W) {
            cout<<arr[i].pos<<"-"<<arr[i].weight<<endl;
			W -= arr[i].weight;
			finalvalue += arr[i].value;

		}
		else {
            cout<<arr[i].pos<<"-"<<W<<endl;
			finalvalue += arr[i].value
						* ((double)W
							/ (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}
int main()
{
    Item arr[10];
    int n;
    cin>>n;
    int weights[10];
    int values[10];
    for(int i = 0 ; i < n  ; i++)
        cin>>weights[i];
    for(int i = 0 ; i < n  ; i++)
       {
            cin>>values[i];
            arr[i] = Item(values[i],weights[i],i+1);
       } 
    int W;
    cin>>W; 
	cout << "Maximum value = "<< fractionalKnapsack(W, arr, n);
	return 0;
}
