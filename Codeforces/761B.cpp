#include <bits/stdc++.h>
using namespace std;

const int N = 109;

int n, m;
vector<int> a, b;

int main(){
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        a.push_back(x);
    }
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        b.push_back(x);
    }

    for(int i=0; i<n; i++)
        b.push_back(b[i] + m);

    vector<int> ans;
    for(int i=1; i<n; i++)
        ans.push_back(a[i] - a[i-1]);

    for(int k=0; k<n; k++){
        bool the_same = true;
        for(int i=k+1; i < k+n; i++){
            if(b[i] - b[i-1] != ans[i - k - 1]){
                the_same = false;
                break;
            }
        }
        if(the_same){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
