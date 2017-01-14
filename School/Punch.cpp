// PreVOI 2017 - Day 1
#include <bits/stdc++.h>
using namespace std;

const int N = 1000009;

int n, ans=1e9, c[N]={}, cnt[1 << 16]={}, m;
bitset<16> a[N][4];
set<int> have;

bitset<16> rotate(bitset<16> a){
    bitset<16> b;
    for(int i=3; i>=0; i--)
        for(int j=0; j<4; j++)
            b[4*j + (3-i)] = a[4*i + j];
    return b;
}

void optimize1(){ // 0.8
    for(int i=0; i<16; i++)
        for(int j=0; j<16; j++)
            if(i != j){
                int d = 0;
                for(int k=0; k<n; k++)
                    d += (a[k][c[k]][i] != 1) + (a[k][c[k]][j] != 1);
                ans = min(d, ans);
                if(ans == 0){
                    printf("0\n");
                    exit(0);
                }
            }
}

void optimize2(){ // 1
    multiset<int> s;
    for(int i=0; i<16; i++){
        int d = 0;
        for(int k=0; k<n; k++)
            d += (a[k][c[k]][i] != 1);
        s.insert(d);
    }
    int temp = *s.begin() + *(++s.begin());
    ans = min(ans, temp);
    if(ans == 0){
        printf("0\n");
        exit(0);
    }
}

void btrack(int i){
    if(i == n){
        // optimize1();
        optimize2();
        return;
    }
    for(int j=0; j<4; j++){
        c[i] = j;
        btrack(i+1);
    }
}

void solution1(){ // 0.8 or 1.0
    btrack(0);
    printf("%d\n",ans);
}

void solution2(){ // 4.0
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            if(i != j){
                int temp = 0;
                for(int k=0; k<n; k++){
                    int p = 1e9;
                    for(int h=0; h<4; h++)
                        p = min(p, (a[k][h][i] == 0) + (a[k][h][j] == 0));
                    temp += p;
                    if(temp >= ans) break;
                }
                ans = min(ans, temp);
                if(ans == 0){
                    printf("0\n");
                    return;
                }
            }
        }
    }
    printf("%d\n",ans);
}

void solution3(){ // AC - 6.0
    for(int i=0; i<16; i++){
        for(int j=i+1; j<16; j++){
            int temp = 0;
            for(int k = 0; k < m; k++){
                int p = 1e9;
                for(int h=0; h<4; h++)
                    p = min(p, (a[k][h][i] == 0) + (a[k][h][j] == 0));
                temp += p * cnt[a[k][0].to_ulong()];
                if(temp >= ans) break;
            }
            ans = min(ans, temp);
            if(!ans){
                printf("0\n");
                return;
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    // freopen("Punch.inp","r",stdin);
    // freopen("Punch.out","w",stdout);
    while(~scanf("%d",&n)){
        have.clear(); m = 0;
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x); cnt[x] += 1;
            if(have.find(x) != have.end()) continue;
            a[m][0] = x; have.insert(x);
            for(int j=1; j<4; j++)
                a[m][j] = rotate(a[m][j-1]);
            m++;
        }
        // solution1();
        // solution2();
        solution3();
    }
    return 0;
}
