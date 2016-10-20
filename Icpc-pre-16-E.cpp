#include<bits/stdc++.h>
#define vi vector<int>
#define LL long long int
#define mp make_pair
#define pii pair<LL,int>
#define fr first
#define sc second
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repe(a,b,c) for(int a=b;a<=c;a++)
#define REP(i,n)    for(i=0;i<n;i++)
using namespace std;
pii Q[1005];
pii A[100005];
bool cmp(pii a,pii b){
    return a.sc < b.sc;
}
bool cmp2(pii a,pii b){
    return a.fr>b.fr;
}

int tree[100005];
int MaxVal ;

// returns idx with given cf
// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return
// the greatest one
int findG(int cumFre){
    int idx = 0;

    int bitMask = 1<<4;

    while ((bitMask != 0) && (idx < MaxVal)){
        int tIdx = idx + bitMask;
        if (tIdx<=MaxVal && cumFre > tree[tIdx]){
            idx = tIdx;
            cumFre -= tree[tIdx];
        }
        bitMask >>= 1;
    }
        return idx;
}

//add val to f[idx].
//MaxVal = Just max value of index
void update(int idx ,int val)
{
    while (idx <= MaxVal)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int query (int n)
{
	int sum = 0;
	while (n > 0) {
		sum += tree[n];
		n -= (n&-n);
	}
	return sum;
}


int main()
{
    int T,I=1;
    cin>>T;
    while(T--){
            printf("Case %d:",I++);
    int n,q;
    scanf("%d %d",&n,&q);
    rep(i,0,n) {scanf("%lld",&A[i].fr);A[i].sc=i+1;}
    rep(i,0,q) {scanf("%lld",&Q[i].fr);Q[i].sc=i;}
    sort(A,A+n,cmp2);
    sort(Q,Q+q);
    memset(tree,0,sizeof(tree));
    MaxVal=n;
    LL upper=0,last=0;
    int j=0,tot=0,Lj=0;
    rep(k,0,q)
    {
        while(Q[k].fr > upper)
        {
            last=upper;
            Lj=j;
            for(;j<n;j++)
            {
                if((j!=Lj)&& (A[j].fr!=A[j-1].fr)) break;
                update(A[j].sc,1);tot++;
            }
            if(j==n) { upper+= (j*A[j-1].fr);}
            else  upper+=(j* (A[j-1].fr-A[j].fr) );
        }
        Q[k].fr-=last;
        Q[k].fr%=tot;
        if(Q[k].fr==0) Q[k].fr=tot;
      //  cout<<Q[k].fr<<Q[k].sc<<endl;
        Q[k].fr= findG(Q[k].fr)+1;
    }
        sort(Q,Q+q,cmp);
        for(int i=0;i<q;i++) printf(" %lld",Q[i].fr);
    printf("\n");
    }
    return 0;
}
