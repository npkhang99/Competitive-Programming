#include <stdio.h>

int n, h, ans=0;

int main(){
    scanf("%d %d",&n,&h);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d",&x);
        if(x>h) ans+=2;
        else ans+=1;
    }
    printf("%d",ans);
    return 0;
}
