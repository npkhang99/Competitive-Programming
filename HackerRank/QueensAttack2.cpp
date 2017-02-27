// HackerRank - CodeSprint 9 - Queen's Attack II
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;

typedef vector<iii> viii;

typedef map<int,viii> miviii;

#define x first.first
#define y first.second

#define all(a) (a).begin(), (a).end()

const int N = 100009;

int n, k;
long long ans[N]={};
iii a[N]={};
miviii b, c;

int comp(iii a, iii b){
    swap(a.x,a.y);
    swap(b.x,b.y);
    return a < b;
}

int main(){
    scanf("%d %d",&k,&n);
    for(int i=0; i<=n; i++)
        scanf("%d %d",&a[i].x,&a[i].y), a[i].second = i;

    sort(a,a+n+1);
    for(int i=0; i<=n; i++){
        int l, r;
        if(i==0 || a[i-1].x != a[i].x) l = 0;
        else l = a[i-1].y;
        if(i==n-1 || a[i+1].x != a[i].x) r = k+1;
        else r = a[i+1].y;
        ans[a[i].second] += r-l-2;
    }
    
    sort(a,a+n,comp);
    for(int i=0; i<=n; i++){
        int l, r;
        if(i==0 || a[i-1].y != a[i].y) l = 0;
        else l = a[i-1].x;
        if(i==n-1 || a[i+1].y != a[i].y) r = k+1;
        else r = a[i+1].x;
        ans[a[i].second] += r-l-2;
    }

    for(int i=0; i<=n; i++)
        b[a[i].y - a[i].x].push_back(a[i]),
        c[a[i].x + a[i].y].push_back(a[i]);

    for(miviii::iterator it = b.begin(); it != b.end(); it++){
        viii curr = it -> second;
        int diff;
        diff = min(curr[0].x, curr[0].y);
        curr.push_back(iii(ii(curr[0].x - diff, curr[0].y - diff),-1));
        diff = min(k+1 - curr[0].x, k+1 - curr[0].y);
        curr.push_back(iii(ii(curr[0].x + diff, curr[0].y + diff),-1));
        sort(all(curr));
        for(int i=1; i<curr.size()-1; i++){
            int l = curr[i-1].x, r = curr[i+1].x;
            ans[curr[i].second] += r-l-2;
        }
    }

    for(miviii::iterator it = c.begin(); it != c.end(); it++){
        viii curr = it -> second;
        int diff;
        diff = min(k+1 - curr[0].x, curr[0].y);
        curr.push_back(iii(ii(curr[0].x + diff, curr[0].y - diff),-1));
        diff = min(curr[0].x, k+1 - curr[0].y);
        curr.push_back(iii(ii(curr[0].x - diff, curr[0].y + diff),-1));
        sort(all(curr),comp);
        for(int i=1; i<curr.size()-1; i++){
            int l = curr[i-1].y, r = curr[i+1].y;
            ans[curr[i].second] += r-l-2;
        }
    }

    printf("%lld\n",ans[0]);
    return 0;
}
