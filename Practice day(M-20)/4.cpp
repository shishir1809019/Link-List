#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n;

	int arr[n];
	int pre[n];
	
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}
	pre[0] = arr[0];
	for(int i = 1; i<n; i++){
		pre[i] = arr[i] + pre[i-1];
	}
	cin>>q;

	while(q--){
		int first, last,sum = 0;
		cin>>first>>last;
		if(first-2 < 0){
			sum = pre[last-1] - 0;
		}
		else{
			sum = pre[last-1] - pre[first-1-1];
		}
		
		cout<<sum<<endl;
	}
	
}