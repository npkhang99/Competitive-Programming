#include <cstdio>
using namespace std;

const int N = 200009;

int n, a[N], b[N], c[N], check_b[N][32], check_c[N][32], cnt[N];

bool testBit(int mask, int bit){
    return 1 & (mask >> bit);
}

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(int i=0; i<n; i++){
        scanf("%d",&c[i]);
        if(c[i] < b[i]){
            printf("-1\n");
            return 0;
        }
    }

    long long sum_a = 0;
    for(int i=0; i<n; i++)
        sum_a += b[i] + c[i];

    if(sum_a % (2*n)){
        printf("-1\n");
        return 0;
    }

    sum_a /= 2*n;
    for(int i=0; i<n; i++){
        int s = b[i]+c[i] - sum_a;
        if(s % n){
            printf("-1\n");
            return 0;
        }
        a[i] = s / n;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<=30; j++)
            if(testBit(a[i],j))
                cnt[j] += 1;

    for(int i=0; i<n; i++)
        for(int j=0; j<=30; j++){
            if(!testBit(a[i],j)){
                check_b[i][j] = 0;
                check_c[i][j] = cnt[j];
                continue;
            }
            check_b[i][j] = cnt[j];
            check_c[i][j] = n;
        }
    for(int i=0; i<n; i++){
        int reconstruct_b = 0, reconstruct_c = 0;
        for(int j=0; j<=30; j++){
            reconstruct_b += check_b[i][j] * (1 << j);
            reconstruct_c += check_c[i][j] * (1 << j);
        }
        if(reconstruct_b != b[i] || reconstruct_c != c[i]){
            printf("-1\n");
            return 0;
        }
    }

    for(int i=0; i<n; i++)
        printf("%d%c",a[i],i==n-1? '\n':' ');
    return 0;
}
