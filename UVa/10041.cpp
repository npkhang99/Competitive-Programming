#include <cstdio>
using namespace std;

const int N = 509;

int n, a[N]={};

int abs(int x){
    return x < 0? -x:x;
}

int min(int a, int b){
    return a < b? a:b;
}

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);

        int ans = 1e9;
        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=0; j<n; j++)
                temp += abs(a[i] - a[j]);
            ans = min(ans, temp);
        }
        printf("%d\n", ans);
    }
    return 0;
}
