#include <cstdio>
using namespace std;

const int N = 29;

int n, l, a[N], b[N], c[N], ans;

void btrack(int i){
    if(i == n){
        int temp = 0;
        for(int j=0; j<n; j++)
            temp += a[j]*b[j];
        if(temp >= ans && temp <= l){
            ans = temp;
            for(int j=0; j<n; j++)
                c[j] = b[j];
        }
        return;
    }
    for(int j=0; j<=1; j++){
        b[i] = j;
        btrack(i+1);
    }
}

int main(){
    while(~scanf("%d %d",&l,&n)){
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]), b[i] = c[i] = 0;
        ans = 0;
        btrack(0);
        for(int i=0; i<n; i++)
            if(c[i]) printf("%d ",a[i]);
        printf("sum:%d\n",ans);
    }
    return 0;
}
