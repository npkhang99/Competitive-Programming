// HackerRank - World CodeSprint 8
#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, m, a[N]={}, ranking[N]={};

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&a[n-i-1]);

    ranking[n-1] = 1;
    for(int i=n-2; i >= 0; i--)
        ranking[i] = ranking[i+1] + (a[i] != a[i+1]);
    for(int i=0; i<n; i++)
        fprintf(stderr, "%d%c", ranking[i], i==n-1?'\n':' ');
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        int score = 0; scanf("%d",&score);
        int p = lower_bound(a,a+n,score) - a;
        if(a[p] == score) printf("%d\n", ranking[p]);
        else printf("%d\n", ranking[p]+1);
    }
    return 0;
}
