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

void DFS(int x,int cut);

struct node {
    int a,w;
    node(){}
    node(int x,int y){a = x; w = y;};
};

map <int, int> visit;
map <int, int>::iterator itt;
map <int , vector<node> > my;
map <int , vector<node> >::iterator it;

int main()
{
    int n,t=1,T;
    sf("%d",&T);
    while(T--)
    {
        sf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int a,b,w;
            sf("%d %d %d",&a,&b,&w);
            my[a].push_back(node(b,w));
            my[b].push_back(node(a,w));
            visit[a] = inf;
            visit[b] = inf;
        }
        visit[0] = 0;
        DFS(0,0);
        int maxi = 0,in;
        for(itt=visit.begin();itt!=visit.end();itt++)
        {
            int f = itt->fs;
            int s = itt->sc;
            if(s>=maxi) in = f;
        }
        for(itt=visit.begin();itt!=visit.end();itt++)
        {
            int cur = itt->fs;
            visit[cur]=inf;
        }
        visit[in] = 0;
        DFS(in,0);
        maxi=0;
        for(itt=visit.begin();itt!=visit.end();itt++)
        {
            int s = itt->sc;
            if(s>maxi) maxi = s;
        }
        pf("Case %d: %d\n",t++,maxi);
        visit.clear();
        my.clear();
    }
    return 0;
}

void DFS(int x,int cut)
{
    int len = my[x].size();
    for(int i=0;i<len;i++)
    {
        int p = my[x][i].a;
        int k = my[x][i].w;
        if(k + cut < visit[p])
        {
            visit[p] = k + cut;
            DFS(p,k + cut);
        }
    }
}
