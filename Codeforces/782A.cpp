#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n, ans = 0;
set<int> on_table;

int main(){
    scanf("%d", &n);
    for(int i=0; i<2*n; i++){
        int x; scanf("%d", &x);
        if(on_table.find(x) == on_table.end()){
            on_table.insert(x);
            ans = max(ans, (int)on_table.size());
        }else on_table.erase(x);
    }

    printf("%d\n", ans);
    return 0;
}
