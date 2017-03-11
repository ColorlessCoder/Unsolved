#include <bits/stdc++.h>
#define EPS 1e-12
#define fr first
#define sc second
#define vi vector<int>
#define LL  long long int
#define LSOne(S) (S & (-S))
#define pii pair<int,int>
#define pb push_back
using namespace std;
struct Querys{
 int a,b,c,d;
 Querys(){}
 Querys(int x,int y,int z,int f){
    d=f;
    a=x;
    b=y;
    c=z;
 }
};

struct point2{
int a,b,c;
point2(){}
point2(int x,int y,int z)
{
    a=x;b=y;c=z;
}
};
class Ft
{
public:
    vi ft;
    int d;
    Ft(){}
    Ft(int n){d=n; ft.assign(n+1,0); }
    int kth(int v)
    {
        int m=d,a=d,ans=-1;
        while(a)
        {
            a>>=1;
            if(ft[m]>=v)
            {
                if(ft[m]==v) ans=m;
                m-=a;
            }
            else{
                v-=ft[m];
                m+=a;
            }
        }
        return ans;
    }
    void adjust(int k, int v) { // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};
class Ft2 {
private:
vector<LL> ft;
public:
Ft2() {}
// initialization: n + 1 zeroes, ignore index 0
Ft2(int n) { ft.assign(n + 1, 0); }
LL rsq(int b) { // returns RSQ(1, b)
LL sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
return sum; }
LL rsq(int a, int b) { // returns RSQ(a, b)
    if(a>b) return 0;
    if(a<=0) return 0;
return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
void adjust(int k, LL v) { // note: n = ft.size() - 1
for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};
point2 Points[300000];
point2 MP[300000];
vector<pii > A;
vector<pii > B;
vector<pii > C;
Querys Query[300000];
int n;
int main()
{
    int T,I=1;
    int n=0;
    cin>>T;
    while(T--)
    {
        printf("Case %d:\n",I++);
        n=0;
        int d=1<<18;
        LL ans=0;
        int Q;
        A.clear();
        B.clear();
        C.clear();
        scanf("%d",&Q);
        Ft P1(d);
        Ft P2(d);
        Ft P3(d);
        Ft2 X(d);
        Ft2 Y(d);
        Ft2 Z(d);
        int a,b,c;
        n=1;
        for(int i=0;i<Q;i++)
        {
            char ch[10];
            scanf("%s",ch);
            if(ch[0]=='i')
            {
                scanf("%d %d %d",&a,&b,&c);
                Query[i]=Querys(a,b,c,0);
                A.pb(pii(a,n));
                B.pb(pii(b,n));
                C.pb(pii(c,n));
                n++;
            }
            else
            {
                scanf("%d",&a);
                 Query[i]=Querys(a,0,0,1);
            }
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        for(int i=1;i<n;i++)
        {
            Points[A[i-1].sc].a=i;
            Points[B[i-1].sc].b=i;
            Points[C[i-1].sc].c=i;
        }
        n=1;
        int act=0;
        for(int i=0;i<Q;i++)
        {
            if(Query[i].d == 0)
            {
                P1.adjust(Points[n].a,1);
                P2.adjust(Points[n].b,1);
                P3.adjust(Points[n].c,1);
                X.adjust(Points[n].a,A[Points[n].a -1].fr);
                Y.adjust(Points[n].b,B[Points[n].b -1].fr);
                Z.adjust(Points[n].c,C[Points[n].c -1].fr);
                act++;
                n++;
                int m=(act+1)/2;
                a=P1.kth(m);
                b=P2.kth(m);
                c=P3.kth(m);
                LL ans=X.rsq(1,a-1) + Y.rsq(1,b-1) + Z.rsq(1,c-1);
                LL ans2=X.rsq(a+1,n+10) + Y.rsq(b+1,n+10) + Z.rsq(c+1,n+10);
                LL tot= (-act+m+m-1)*(A[a-1].fr+B[b-1].fr+C[c-1].fr)-ans+ans2;
                printf("%lld\n",tot);
            }
            else{
                int dd=n;
                n=Query[i].a;
                P1.adjust(Points[n].a,-1);
                P2.adjust(Points[n].b,-1);
                P3.adjust(Points[n].c,-1);
                X.adjust(Points[n].a,-A[Points[n].a -1].fr);
                Y.adjust(Points[n].b,-B[Points[n].b -1].fr);
                Z.adjust(Points[n].c,-C[Points[n].c -1].fr);
                act--;
                n=dd;
                if(act==0)
                {
                    printf("0\n");continue;
                }
                int m=(act+1)/2;
                a=P1.kth(m);
                b=P2.kth(m);
                c=P3.kth(m);
                LL ans=X.rsq(1,a-1) + Y.rsq(1,b-1) + Z.rsq(1,c-1);
                LL ans2=X.rsq(a+1,n+10) + Y.rsq(b+1,n+10) + Z.rsq(c+1,n+10);
                LL tot= (-act+m+m-1)*(A[a-1].fr+B[b-1].fr+C[c-1].fr)-ans+ans2;
                printf("%lld\n",tot);
            }
        }

    }
    return 0;
}
