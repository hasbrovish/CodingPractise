#include <iostream>
#include<vector>
#include<cmath>
#define ll long long int
using namespace std;
//Preprocessing prime upto sqrt(R) mostly 10^6
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
//Finding prime in L to R
vector<ll> primeRange(ll L,ll R){
	vector<int> prime=Primes();
	vector<int> isPrime(R-L+1,true);
	for(int i=0;i<prime.size();i++){
		ll k=ceil((1.0*L)/prime[i]);
		for(ll j=max(k,(ll)2);j*prime[i]<=R;j++) // k<2 leads to strike of prime itself [Not Valid]
		{
			isPrime[j*prime[i]-L]=false; //Setting offset for the large index that array can not hold
		}
	}
	vector<ll> primeNum;
	for(int i=0;i<isPrime.size();i++){
		if(isPrime[i])
		primeNum.push_back(i+L);
	}
	return primeNum;
}
int main() {
	// your code goes here

//for(ll i=0;i<primeList.size();i++)
//cout<<primeList[i]<<" ";
vector<ll> primeR=primeRange(1000000000000,1000001000000);
//for(int i=0;i<primeR.size();i++)
//cout<<primeR[i]<<" ";
cout<<primeR.size();
	return 0;
	
}
