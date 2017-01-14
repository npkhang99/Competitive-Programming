#include <stdio.h>
#include <algorithm>
using namespace std;

const int N=100009;

int n, q, a[N]={}, toLeft[N]={}, toRight[N]={}, IT[4*N]={};

void preprocess(){
    toLeft[1] = 1;
    for(int i=2; i<=n; i++)
        if(a[i] == a[i-1]) toLeft[i] = toLeft[i-1] + 1;
        else toLeft[i] = 1;

    toRight[n] = 1;
    for(int i=n-1; i>0; i--)
        if(a[i] == a[i+1]) toRight[i] = toRight[i+1] + 1;
        else toRight[i] = 1;
}

void createIT(int i, int l, int r){
    if(l>r || IT[i]) return;
    if(l==r){ IT[i] = 1; return; }

    int mid = (l+r)/2;

    if(a[mid] == a[mid+1]){
        int left  = min(toLeft[mid], mid - l + 1),
            right = min(toRight[mid+1], r - mid);
        IT[i] = left + right;
    }

    createIT(i*2, l, mid);
    createIT(i*2+1, mid+1, r);

    IT[i] = max(IT[i], max(IT[2*i], IT[2*i+1]));
}

int getMax(int i, int l, int r, int L, int R){
    if(l > r || R < l || r < L) return 0;
    if(L <= l && r <= R) return IT[i];

    int mid = (l+r)/2;

    int temp = 0;
    if(a[mid] == a[mid+1]){
        int left  = min(toLeft[mid], mid - L + 1),
            right = min(toRight[mid+1], R - mid);
        temp = left + right;
    }else temp = 1;

    int t1 = getMax(2*i, l, mid, L, R),
        t2 = getMax(2*i+1, mid+1, r, L, R);

    return max(temp, max(t1, t2));
}

int main(){
    while(scanf("%d",&n), n){
        scanf("%d",&q);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        preprocess();

        for(int i=0; i<=4*n; i++) IT[i] = 0;
        createIT(1,1,n);

        for(int i=0; i<q; i++){
            int x, y; scanf("%d%d",&x,&y);
            printf("%d\n",getMax(1,1,n,x,y));
        }
    }
    return 0;
}
