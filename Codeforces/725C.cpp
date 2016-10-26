#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cnt[256]={}, r[256]={}, rep1=0, rep2=0;
char st[28]={}, ans[2][13]={};

void ex(){
    for(int i=0; i<2; i++){
        for(int j=0; j<13; j++) printf("%c",ans[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    while(~scanf("%s",st)){
        printf("================\n");
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<strlen(st); i++){
            cnt[st[i]] += 1;
            if(cnt[st[i]] == 1) r[st[i]] = i;
            else rep2 = i, rep1 = r[st[i]];
        }

        if(rep2 - rep1 == 1){
            printf("Impossible\n\n");
            continue;
        }

        memset(ans,'-',sizeof(ans));

        if(!rep1 && rep2 == 26){
            for(int i=0; i<13; i++) ans[0][i] = st[i];
            for(int i=13; i<26; i++) ans[1][25-i] = st[i];
            ex();
            continue;
        }

        
    }
    return 0;
}
