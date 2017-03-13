#include <bits/stdc++.h>
#define EPS 1e-12
#define fr first
#define sc second
#define vi vector<int>
#define LL  long long int
#define LSOne(S) (S & (-S))
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int n;
vector<vi > E;
int dfs(int u,int p)
{
    int z=E[u].size();
    int a=0;
    for(int i=0;i<z;i++)
        if(E[u][i]!=p)
            a=max(a,1+dfs(E[u][i],u));
     return a;
}
int minL;
vi find_centorids()
{
    vector<pii >  A;
    for(int i=0;i<n;i++)
        A.pb(mp(dfs(i,i)+1,i));
    sort(A.begin(),A.end());
    int a=A[0].fr;
    vi ans;
    for(int i=0;i<n;i++)
    	if(A[i].fr==a) ans.pb(A[i].sc);
    	else break;
    minL=a;
    return ans;
}
LL dp[1010][1010];
LL call(int i,int rem,int p)
{
	if(rem<=0) return 0;
	LL &ret=dp[i][rem];
	if(ret!=-1) return ret;
	int z=E[i].size();
	if(z==1) return ret=1;
	ret=0;
	if(rem>=2)
	ret=(ret+call(i,rem-1,p))%mod;
	rem--;
	LL temp=1;
	int f=0;
	for(int j=0;j<z;j++)
		if(E[i][j]!=p)
			{
				temp=(temp*call(E[i][j],rem,i))%mod;
			}
	return ret= (ret+temp)%mod;

}
int main()
{
    int T,I=1;
    cin>>T;
    while(T--)
    {
        printf("Case %d: ",I++);
        scanf("%d",&n);
        int a,b;
        E.assign(n+1,vi());
        for(int i=0;i<n-1;i++)
            {
                scanf("%d %d",&a,&b);
                a--;b--;
                E[a].pb(b);
                E[b].pb(a);
            }
        vi A= find_centorids();
        LL ans=0;
        for(int i=0;i<A.size();i++)
        {
        	memset(dp,-1,sizeof(dp));
        	//cout<<A[i];
        	ans=(ans+call(A[i],minL,A[i]))%mod;
        	//cout<<ans<<endl;
    	}
    	printf("%d %lld\n",minL,ans);
    }
    return 0;
}
