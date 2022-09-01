#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, mn_mx;
	cin>>n>>mn_mx;

	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	sort(arr, arr+n);

	cout<<arr[mn_mx-1]<<" "<<arr[n-mn_mx];

	return 0;
}