#include <cstdio>
#include <stack>
using namespace std;

const int N = 1009;

int n, a[N];

int main(){
    while(scanf("%d",&n), n){
        while(scanf("%d",&a[0]), a[0]){
            for(int i=1; i<n; i++)
                scanf("%d",&a[i]);

            bool flag = false;
            stack<int> st;
            for(int i=0, j=1; i<n; i++){
                if(j > a[i] && st.top() != a[i]){
                    printf("No\n");
                    flag = true;
                    break;
                }
                while(j <= a[i]) st.push(j++);
                if(st.top() != a[i]){
                    printf("No\n");
                    flag = true;
                    break;
                }
                st.pop();
            }
            if(!flag) printf("Yes\n");
        }
        printf("\n");
    }
    return 0;
}
