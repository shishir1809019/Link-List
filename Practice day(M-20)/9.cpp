#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	int count = 0;
	for(int i = 0, j = n-1; i<j; i++,j--){
		if(arr[i] + arr[j] == k)
			count++;
	}	
	cout<<count<<endl;
	return 0;
}