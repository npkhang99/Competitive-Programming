#include <bits/stdc++.h>
using namespace std;

int x;
vector<int> values;
unordered_map<int,int> a;

int main(){
    while(~scanf("%d",&x)){
        a[x] += 1;
        if(a[x] == 1) values.push_back(x);
    }
    for(int v : values)
        printf("%d %d\n",v,a[v]);
    return 0;
}
