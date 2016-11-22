#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;   // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
  _sieve_size = upperbound + 1;                   // add 1 to include upperbound
  bs.set();                                                 // set all bits to 1
  bs[0] = bs[1] = 0;                                     // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);  // also add this vector containing list of primes
} }                                           // call this method in main method
int A[100005];
int main()
{
    int n=(1e5)+5;
    sieve(n);
    memset(A,-1,sizeof(A));
    A[1]=0;
    for(int i=1;i<n;i++)
        if(A[i]!=-1)
    {
        //cout<<1;
        for(int j=0;j<primes.size();j++)
        {
                int v=primes[j];
        if(i+v > n) break;
            if((A[i+v]!=-1)||(i==1))
                A[i+v]=max(A[i+v],A[i]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {if(A[i]==3) ans++;}//cout<<A[i]<<" " ;}
    cout<<ans;
    return 0;
}
