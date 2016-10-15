#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int n;
char st[100009];
stack s;

int main(){
    scanf("%s",st);
    n = strlen(st);
    if(n==1 || st[0]=='#'){
        printf("-1\n");
        return 0;
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(i=='#'){
            while(i+1<n && st[i+1]==')') i+=1, cnt-=1;
            if(!cnt){ printf("-1\n"); return 0; }
            s.push
        }
        if(i==')') cnt-=1;
        else if(i=='(') cnt+=1;
        if(cnt<0){ printf("-1\n"); return 0; }
    }
    return 0;
}
