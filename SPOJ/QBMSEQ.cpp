#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 10009;

int n, L[N]={};
vector<ii> a;
vector<int> b;

void prep(){
    int k = 2;
    b.push_back(1);
    while(b.back() + k <= 1e8) b.push_back(b.back() + (k++));
}

int main(){
    prep();
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        if(binary_search(b.begin(), b.end(), x)) a.push_back(ii(x,i));
    }

    // for(int i=0; i<10; i++) cerr<< b[i]<< ' ';
    // cerr<< endl;

    int m = 0, t = (a.size() > 0);
    for(int i=1; i<a.size(); i++){
        if(a[i-1].first <= a[i].first && a[i].second - a[i-1].second == 1) t++;
        else m = max(m, t), t = 1;
    }
    m = max(m,t);
    printf("%d\n",m);
    return 0;
}
