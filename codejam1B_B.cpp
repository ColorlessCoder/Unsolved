#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<iostream>
#include<algorithm>
#include<deque>
#include<stack>
#define vi vector<int>
#define vll vector<LL>
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define fr first
#define sc second
#define MAX 50010
#define LL   long long int
#define ll   long long int
//#define LLL long long int
#define inf (1ll<<62)
#define INF 10000000
#define mod 1000000007
//#define N 65
#define mMax 30010
#define nMax 2010
#define SZ(a) a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep1(i,b) for(int i=1;i<=b;i++)
#define rep2(i,b) for(int i=0;i<b;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define all(A) A.begin(),A.end()
#define isf(a) scanf("%d",&a);
#define Lsf(a) scanf("%I64d",&a);
#define csf(a) scanf("%c",&a);
using namespace std;
LL bigmod(LL a,LL b,LL Mod)
{
    if(b==0) return 1ll;
    if(b%2) return (a*bigmod(a,b-1,Mod))%Mod;
    LL c=bigmod(a,b/2,Mod);
    return (c*c)%Mod;
}
int A[10];
vector<string> SR;
vector<string> SV;
vector<string> SO;
vector<string> SB;
vector<string> SY;
vector<string> SG;
int main()
{
	int T,I=1;
	list<char>::iterator it;
	cin>>T;
	while(T--)
	{
		SR.clear();
		SV.clear();
		SO.clear();
		SB.clear();
		SY.clear();
		SG.clear();
		printf("Case #%d: ",I++);
		int n;
		scanf("%d",&n);
		for(int i=0;i<6;i++) scanf("%d",&A[i]);
		bool flag=true;
		int R=A[0];
		int O=A[1];
		int Y=A[2];
		int G=A[3];
		int B=A[4];
		int V=A[5];
		if(B<O-1 || Y<V-1 || R<G-1) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		string temp;
		temp="";
		for(int i=0;i<O;i++)
		{
			if(i) {temp.push_back('B');B--;}
			temp.pb('O');
		}
		SO.pb(temp);
		temp="";
		for(int i=0;i<V;i++)
		{
			if(i) {temp.push_back('Y'); Y--;}
			temp.pb('V');
		}
		SV.pb(temp);
		temp="";
		for(int i=0;i<G;i++)
		{
			if(i) {temp.push_back('R');R--;}
			temp.pb('G');
		}
		SG.pb(temp);
		temp="";
		string first="";
		string last="";
		int c=-1,d=-1;
		O=min(O,1);
		G=min(G,1);
		V=min(V,1);
		if(B>1 && O==1)  {
			O--;
			temp='B'+SO[1]+'B';
			SB.pb(temp);
			B--;
		}
		if(R>1 && G==1)  {
			G--;
			temp='R'+SG[1]+'R';
			SR.pb(temp);
			R--;
		}
		if(Y>1 && V==1)  {
			V--;
			temp='Y'+SV[1]+'Y';
			SY.pb(temp);
			Y--;
		}
		if(O>0 && G>0 && V>0)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(O>0)
		{
			if(B==0 && (R+G+Y+V)>0) {
			printf("IMPOSSIBLE\n");
			continue;
		}
			else if(B>0)
			{
				first=SO[0];
				O--;
				c=0;
			}
			else first=SO[0];
		}
		if(G>0)
		{
			if(R==0 && (O+B+Y+V)>0) {
			printf("IMPOSSIBLE\n");
			continue;
		}
			else if(R>0)
			{
				if(first=="")
				{first=SG[0];c=1;}
				else
				{last=SG[0];d=1;}
				G--;
			}
			else first=SG[0];
		}
		if(V>0)
		{
			if(Y==0 && (G+O+Y+R)>0) {
			printf("IMPOSSIBLE\n");
			continue;
		}
			else if(Y>0)
			{
				if(first=="")
				{first=SV[0];c=2;}
				else
				{last=SV[0];d=2;}
				V--;
			}
			else first=SV[0];
		}
		list<char> D;
		if(R+Y+B >0)
		{
			if(c>-1 || d>-1)
            {
                int temp=0;
                if(c==0)
                    {temp=B;rep1(i,B) D.pb('B');}
                else                if(c==1)
                    {temp=R;rep1(i,R) D.pb('R');}
                    else                 if(c==2)
                    {temp=Y;rep1(i,Y) D.pb('Y');}
                it=D.back();
                if(d==1)
                {
                    if(temp<)
                }

			}
			else{}
		}
	}
	return 0;
}
