/*
Given two numbers 
L and R(inclusive) find the product of primes within this range. Print the product modulo 10^9+7. If there are no primes in that range you must print 1.
Input Format
The first line contains a positive integer T, denoting number of testcasesThe first line of each testcase contains two space - separated integers L and R, denoting the range
Constraints
1≤T≤10,1 ≤ L ≤ R ≤ 10^9,0≤ R−L≤10^6
Output Format
Print the product of all primes in the range [L,R]modulo 10^9+7
Sample Input
2
1 10
2 20
Sample Output
210
9699690
Sample Explanation
Case 1: 2∗3∗5∗7=210
Case 2: 2∗3∗5∗7∗11∗13∗17∗19=9699690*/
---------------------------------------------------------
//Code:  
#include <iostream>
#include<cmath>
#include<vector>
#define m 1000000007
#define ll long long int
using namespace std;
vector<int> Primes(){
	vector<bool> isPrime(1000001,true);
	isPrime[1]=false;
	for(ll i=2;i<=1000000;i++){
		if(isPrime[i]){
			for(ll j=i;j*i<=1000000;j++){
				isPrime[j*i]=false;
			}
		}
	}
	vector<int> primes;
	for(ll i=2;i<=1000000;i++){
		if(isPrime[i])
		primes.push_back(i);
	}
	return primes;
	
} 
ll primeRange(ll L,ll R,vector<int> prime){
	vector<bool> isPrime(R-L+1,true);
	for(int i=0;i<prime.size();i++){
		ll k=ceil((1.0*L)/prime[i]);
		for(ll j=max(k,(ll)2);j*prime[i]<=R;j++){
			isPrime[j*prime[i]-L]=false;
		}
	}
	vector<ll> primeR;
	ll pro=1;
	for(ll i=0;i<isPrime.size();i++){
		if(isPrime[i]){
		//cout<<i+L<<" ";
			pro=(pro%m*(i%m+L%m)%m)%m;
		}//primeR.push_back(i)
	}
	return pro;
}
int main() {
    // your code goes here
 vector<int> primes=Primes();
	//cout<<primes.size();
	int t;
	cin>>t;	
	while(t--){
		ll L,R;
		cin>>L>>R;
	    cout<<primeRange(L,R,primes)<<endl;
	}
	return 0;
}
