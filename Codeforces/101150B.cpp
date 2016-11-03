#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[109], b[109][59], n, m, c;
vector<int> d[19];

int findFirstFreeDesk(){
    for(int i=1; i<=m; i++)
        if(d[i].size() < c) return i;
    return m+1;
}

int fullFill(int req){
    int desk = 0, cost = 0;
    for(int i=1; i<=m+1; i++){
        for(int j=0; j<d[i].size(); j++)
            if(d[i][j] == req){
                desk = i; d[i].erase(d[i].begin()+j);
                break;
            }
        if(desk) break;
    }
    int firstFree = findFirstFreeDesk();
    d[firstFree].push_back(req);
    cost += desk + firstFree;
    if(firstFree == 1) return cost;
    int move = d[1][0], newDesk = findFirstFreeDesk(); d[1].erase(d[1].begin());
    d[firstFree].pop_back();
    d[newDesk].push_back(move); cost += 1 + newDesk;
    d[1].push_back(req); cost += firstFree + 1;
    return cost;
}

int main(){
    while(scanf("%d%d%d",&m,&c,&n), m || c || n){
        for(int i=0; i<19; i++) d[i].clear();
        for(int i=0; i<=100; i++) d[m+1].push_back(i);

        int req = 0;
        for(int i=1; i<=n; i++){
            scanf("%d",&a[i]); req = max(req, a[i]);
            for(int j=1; j<=a[i]; j++)
                scanf("%d",&b[i][j]);
        }

        int ans = 0;
        for(int i=1; i<=req; i++){
            for(int j=1; j<=n; j++){
                if(a[j] < i) continue;
                int cost = fullFill(b[j][i]);
                ans += cost;
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
