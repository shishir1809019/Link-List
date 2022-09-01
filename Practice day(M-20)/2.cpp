#include<bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cout << "Enter a positive integer: ";
  cin>>n;

  // loop to check if n is prime
for(int num = 2;num<=n; num++){
  bool is_prime = true;

  for (int i = 2; i <= num/2; i++) {
    if(num % i == 0) {
      is_prime = false;
      break;
    }
  }
  if (is_prime)
    cout <<num<<" ";
 }
return 0;
}