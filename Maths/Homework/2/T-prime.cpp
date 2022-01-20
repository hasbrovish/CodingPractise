//Number is three-prime if it have extacly 3 divisors . 1<=t<=10,1<=N<=10^6,1<=arr[i]<=10^9
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<bool> primes()
{
	vector<bool> isPrime(1000001,true);
	isPrime[0]=isPrime[1]=false;
	for(long long int  i=2;i<1000001;i++){ //Do not forgot to put long long int
		if(isPrime[i]){
			for(long long int j=i;j*i<1000001;j++){ //Do not forget to put long long int
				isPrime[i*j]=false;
			}
		}
	}
	return isPrime;
}
int main() {
    // your code goes here
	vector<bool> isPrime=primes();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		long long sum=0;
		for(int i=0;i<n;i++)
		{cin>>arr[i];
		 int s=sqrt(arr[i]);
		 //cout<<s;
		 if(s*s==arr[i])
			 if(isPrime[s])
				 sum+=arr[i];
		}
	cout<<sum<<endl;
		}
    return 0;
}
