#include <bits/stdc++.h>
using namespace std;

const int N = 509;

int n, total, cnt;
bool b[2][N]={};
char a[2][N]={};

bool ver(int i){
    return a[0][i] == a[1][i] && a[0][i] == '#';
}

int get_body(int i){
    if(a[0][i] == '#') return 0;
    if(a[1][i] == '#') return 1;
    return -1;
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%d ", &n);
        for(int i=0; i<2; i++)
            scanf("%s", a[i]);

        total = 0;
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                if(a[i][j] == '#') total++;

        cnt = 0;
        int last = -1, met = 0;
        bool valid = true;
        for(int i=0; i<n && valid && met < total; i++){
            if(ver(i)){
                cnt++; met += 2;
                continue;
            }

            int p = get_body(i);

            if(p == -1 && met && met < total){
                valid = false;
                break;
            }

            if(p == -1) continue;

            if(last == -1){
                last = p;
                cnt = 0; met++;
                continue;
            }

            if(!cnt && p != last) valid = false;
            else if(cnt && cnt % 2 == 1 && p == last) valid = false;
            else if(cnt && cnt % 2 == 0 && p == 1 - last) valid = false;

            last = p;
            cnt = 0;
            met++;
        }

        printf("%s\n", valid? "yes":"no");
    }
    return 0;
}
