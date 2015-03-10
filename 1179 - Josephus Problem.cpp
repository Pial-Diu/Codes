#include <bits/stdc++.h>

#define Max      1000000
#define pf       printf
#define sf       scanf
#define CLR(a)   memset(a,0,sizeof(a))
#define SET(a)   memset(a,-1,sizeof(a))
#define pb       push_back
#define fs       first
#define sc       second
#define TCASE    int T,t=1;scanf("%d",&T);while(T--)
#define lop1(n)  for(int i=0;i<n;i++)
#define lop2(n)  for(int i=1;i<=n;i++)
#define lup(a)   for(int i=0;i<strlen(a);i++)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef unsigned long lu;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const int inf = 0x7f7f7f7f;

int main()
{
    int t=1,T,n,k;
    sf("%d",&T);
    while(T--)
    {
        sf("%d %d",&n,&k);
        int ans =0;
        for(int i=2;i<=n;i++)   ans = (ans+k)%i;
        pf("Case %d: %d\n",t++,ans+1);
    }
    return 0;
}
