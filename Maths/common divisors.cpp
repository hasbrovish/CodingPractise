//given two number a and b find all the common divisors in them.
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd1(int a,int b){
	if(a%b==0)
		return b;
	gcd1(b,a%b);
}
int main() {
    // your code goes here
	int t;
	cin>>t;
	while(t--){
		long long int a,b;
		cin>>a>>b;
		int gcd=gcd1(a,b);
		//vector<int> div(1000000,0);
		if(gcd==1)
			cout<<1<<endl;
		else{
		int count=0;
		for(int i=1;i*i<=gcd;i++){
			if(gcd%i==0){
			if(i == (gcd/i))
				//cout<<"s"<<i;
		   count++;
			else
			{
				//cout<<i<<" "<<a/i<<"a";
			count++;
				count++;
			//cout<<a/i<<"o";
				//int val=a/i;
			//div[val]++;
			}}
		}
		/*for()
		int count=0;
		for(int i=1;i*i<=b;i++){
			if(b%i==0)
			if(i==b/i)
				if(div[i]>0)
					count++;
			if(div[i]>0)
				count++;
			if(div[b/i]>0)
				count++;
	}*/
		cout<<count<<endl;
	}}
    return 0;
}
