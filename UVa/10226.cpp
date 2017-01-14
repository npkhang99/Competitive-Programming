#include <bits/stdc++.h>
using namespace std;

int T, n;
char st[39];
map<string,int> cnt;

int main(){
    scanf("%d\n\n",&T);
    while(T--){
        cnt.clear(); n = 0;
        while(gets(st)){
            if(strlen(st) == 0) break;
            cnt[string(st)] += 1; n+=1;
        }
        for(map<string,int>::iterator it = cnt.begin(); it != cnt.end(); it++)
            printf("%s %.4lf\n", it->first.c_str(), it->second*100.0 / n);
        if(T) printf("\n");
    }
    return 0;
}
