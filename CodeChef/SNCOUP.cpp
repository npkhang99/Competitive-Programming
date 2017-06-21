#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n;
char a[N]={};
vector<int> b[2];

void make(int i){
    scanf(" %s", a); 
    for(int j=0; j<n; j++)
        if(a[j] == '*') b[i].push_back(j);
}

bool in_range(int i, int a, int b){
    return a <= i && i <= b;
}

bool isSeperate(){
    return b[0].back() <= b[1][0] || b[1].back() <= b[0][0];
}

bool isInside(){
    return (in_range(b[0][0], b[1][0], b[1].back()) && in_range(b[0].back(), b[1][0], b[1].back())) ||
        (in_range(b[1][0], b[0][0], b[0].back()) && in_range(b[1].back(), b[0][0], b[0].back()));
}

int doIntersect(){
    if(in_range(b[0][0], b[1][0], b[1].back())){
        int p = lower_bound(b[1].begin(), b[1].end(), b[0][0]) - b[1].begin();
        return p + max(b[1].size() - p, b[0].size()) - 1;
    }
    int p = lower_bound(b[0].begin(), b[0].end(), b[1][0]) - b[0].begin();
    return p + max(b[0].size() - p, b[1].size()) - 1;
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        b[0].clear(); b[1].clear();
        scanf("%d", &n);
        make(0); make(1);

        if(b[0].empty() || b[1].empty()){
            printf("%d\n", max(b[0].size(), b[1].size()) + 1);
            continue;
        }

        int ans = 1;
        if(isSeperate()){
            ans += b[0].size() + b[1].size() - 2;
        }else if(isInside()){
            ans += max(b[0].size(), b[1].size()) - 1;
        }else{
            // printf("dis guy ");
            ans += doIntersect();
        }

        printf("%d\n", ans);
    }
    return 0;
}
