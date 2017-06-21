// CSP 2015 day 1
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,int> ii;

const int N = 100009;

int n, q;
long long score[N]={};
bool logged_in[N]={};
set<ii> ranking;

int main(){
    // freopen("Judger.inp","r",stdin);
    // freopen("Judger.out","w",stdout);
    scanf("%d %d", &n, &q);

    for(int i=1; i<=n; i++){
        ranking.insert(ii(0,i));
        logged_in[i] = true;
    }
    
    while(q--){
        int type, i, delta;
        scanf("%d", &type);

        if(type == 1){
            scanf("%d", &i);
            if(logged_in[i] == true) continue;
            logged_in[i] = true; score[i] = 0;
            ranking.insert(ii(score[i],i));
        }

        if(type == 2){
            scanf("%d", &i);
            if(logged_in[i] == false) continue;
            logged_in[i] = false;
            ranking.erase(ii(score[i],i));
        }

        if(type == 3){
            scanf("%d %d", &i, &delta);
            if(logged_in[i] == true){
                ranking.erase(ii(score[i],i));
                score[i] -= delta;
                ranking.insert(ii(score[i],i));
            }
        }

        if(type == 4){
            if(ranking.size() > 0){
                set<ii>::iterator it = ranking.begin();
                int cnt = 0;
                for(; it != ranking.end() && cnt < 3; it++, cnt++)
                    printf("%lld ", -it->first);
            }else printf("EMPTY");
            printf("\n");
        }
    }
    return 0;
}
