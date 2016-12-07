#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, c;
vector<ii> a;
map<int,int> b;

int comp(ii a, ii b){
    return ::b[a.second] > ::b[b.second] || (::b[a.second] == ::b[b.second] && a.first < b.first);
}

int main(){
    // freopen("RAZ.inp","r",stdin);
    // freopen("RAZ.out","w",stdout);
    scanf("%d%d",&n,&c);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        if(!b[x]) a.push_back(ii(i,x));
        b[x] += 1;
    }

    sort(a.begin(), a.end(), comp);
    for(int i=0; i<a.size(); i++)
        for(int j=0; j<b[a[i].second]; j++)
            printf("%d ",a[i].second);
    printf("\n");
    return 0;
}
