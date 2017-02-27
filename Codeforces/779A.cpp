#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, a[N]={}, b[N]={};

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int x; scanf("%d", &x);
        a[x]++;
    }
    for(int i=1; i<=n; i++){
        int x; scanf("%d", &x);
        b[x]++;
    }

    vector<int> pa, pb;
    for(int i=1; i<=5; i++){
        if(a[i] > b[i]) pa.push_back(i);
        if(a[i] < b[i]) pb.push_back(i);
    }

    int ans = 0;
    for(int i=0, j=0; i<pa.size() && j < pb.size(); i++){
        while(a[pa[i]] > b[pa[i]] && j < pb.size()){
            a[pa[i]]--;
            b[pa[i]]++;
            b[pb[j]]--;
            a[pb[j]]++;
            ans++;
            if(b[pb[j]] == a[pb[j]]) j++;
        }
    }

    for(int i=1; i<=5; i++)
        if(a[i] != b[i]) ans = -1;

    printf("%d\n", ans);
    return 0;
}
