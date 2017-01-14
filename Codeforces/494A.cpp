#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100009;

int n, a[N]={};
char st[N];

int main(){
    scanf("%s",st);
    n = strlen(st);

    if(st[0] != '(' || st[n-1] == '('){
        printf("-1\n");
        return 0;
    }

    int last = 0;
    for(int i=1; i<=n; i++){
        if(st[i-1] == '#'){
            a[i] = a[i-1] - 1;
            last = i-1;
        }else if(st[i-1] == ')') a[i] = a[i-1] - 1;
        else a[i] = a[i-1] + 1;
        if(a[i] < 0){
            printf("-1\n");
            return 0;
        }
    }

    for(int i=0; i<n; i++)
        if(st[i] == '#' && i == last){
            if(a[i] - a[n] - 1 < 0){
                printf("-1\n");
                return 0;
            }
            printf("%d\n",a[n]+1);
        }else if(st[i] == '#') printf("1\n");
    return 0;
}
