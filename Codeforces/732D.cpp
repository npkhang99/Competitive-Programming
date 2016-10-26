#include <cstdio>
#include <stack>
using namespace std;

const int N=100009;

int n, m, a[N]={}, b[N]={}, c[N]={}, totalTest = 0;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        if(!c[a[i]] && a[i]) totalTest += 1, c[a[i]] = 1;
    }
    if(totalTest < m){ printf("-1\n"); return 0; }
    for(int i=1; i<=m; i++) scanf("%d",&b[i]), c[i] = 0;

    int l = 1, r = n, ans = -1;
    while(l <= r){
        int mid = (l+r)/2;
        
        stack<int> st;
        for(int i=mid; i>=1; i--)
            if(!c[a[i]] && a[i]){
                st.push(i), c[a[i]] = 1;
                if(st.size() == m) break;
            }

        if(st.size() < m){
            while(!st.empty()) c[a[st.top()]] = 0, st.pop();
            l = mid + 1;
            continue;
        }

        int taken = 0;
        // + 1 for the test day
        while(!st.empty() && taken + b[a[st.top()]] + 1 <= st.top()){
            taken += b[a[st.top()]] + 1;
            c[a[st.top()]] = 0;
            st.pop();
        }

        if(!st.empty()){
            while(!st.empty()) c[a[st.top()]] = 0, st.pop();
            l = mid + 1;
        }else ans = mid, r = mid - 1;
    }

    printf("%d\n",ans);
    return 0;
}
