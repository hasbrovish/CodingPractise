https://codeforces.com/contest/776/problem/B

#include<iostream>
#include<vector>
#define vi vector<int>
#define ll long long int
using namespace std;
 
vi prime(100010,1);
void sieve(ll limit){
    prime[0]=prime[1]=0;
    for(ll i=0;i*i<=limit;i++){
        if(prime[i])
        {
            for(ll j=i;j*i<=limit;j++){
                prime[i*j]=0;
            }
        }
    }
}
int main(){
    sieve(100005);
    int n;
    cin>>n;
    if(n>2)
        cout<<"2\n";
    else
    cout<<"1\n";
    
    for(int i=2;i<=n+1;i++)
    {
        if(prime[i])
        cout<<"1"<<" ";
        else
        cout<<"2"<<" ";
    }
}

//faults:
//N==2 , one color is suitable because 2,3 both r prime , same color can be given to both .No prime factor divisor included here. 
