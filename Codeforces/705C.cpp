#include <stdio.h>
#include <vector>
using namespace std;

const int N=300009;

int n, q, cnt[N]={}, type, x, lastT=0, b[N]={}, ans=0;
vector<int> a;

int main(){
    scanf("%d%d",&n,&q);
    for(int i=0; i<q; i++){
        scanf("%d%d",&type,&x);
        if(type==1){
            a.push_back(x);
            cnt[x]+=1;
            ans+=1;
            printf("%d\n",ans);
            continue;
        }
        if(type==2){
            b[x]=a.size();
            ans-=cnt[x];
            cnt[x]=0;
            printf("%d\n",ans);
            continue;
        }
        if(x<lastT){ printf("%d\n",ans); continue; }
        for(int t=lastT; t<x; t++){
            if(b[a[t]]>t) continue;
            ans-=1;
            b[a[t]]=t+1;
            cnt[a[t]]-=1;
        }
        lastT = x;
        printf("%d\n",ans);
    }
    return 0;
}
