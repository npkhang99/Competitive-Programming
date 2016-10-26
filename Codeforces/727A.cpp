#include <cstdio>
#include <stack>
using namespace std;

int a, b;
stack<int> st;

int main(){
    scanf("%d%d",&a,&b);
    while(b>=a){
        if(b==a){ st.push(a); break; }
        else if(b % 2 == 0) st.push(b), b /= 2;
        else if(b % 10 == 1) st.push(b), b /= 10;
        else break;
    }
    if(b!=a){ printf("NO\n"); return 0; }
    printf("YES\n%d\n",st.size());
    while(!st.empty()) printf("%d ",st.top()), st.pop();
    return 0;
}
