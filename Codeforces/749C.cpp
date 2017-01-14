#include <bits/stdc++.h>
using namespace std;

const int N = 200009;

int n;
char st[N]={};
vector<int> rep, dem;

int main(){
    scanf("%d %s",&n,st);
    dem.push_back(1e9);
    rep.push_back(1e9);
    for(int i=n-1; i>=0; i--)
        if(st[i] == 'D') dem.push_back(i+1);
        else rep.push_back(i+1);

    while(rep.size() > 1 && dem.size() > 1){
        int c_rep = rep.size()-1, rep_deny = dem.size()-1;
        int c_dem = dem.size()-1, dem_deny = rep.size()-1;
        while(c_rep > 0 || c_dem > 0){
            if(rep_deny == 0 || dem_deny == 0) break;
            if(c_rep > 0 && rep[c_rep] < dem[c_dem]){
                fprintf(stderr, "Rep %d denied Dem %d\n", rep[c_rep], dem[rep_deny]);
                dem.pop_back(); c_rep--; rep_deny--;
                if(c_dem == dem.size()) c_dem--;
                continue;
            }
            fprintf(stderr, "Dem %d denied Rep %d\n", dem[c_dem], rep[dem_deny]);
            rep.pop_back(); c_dem--; dem_deny--;
            if(c_rep == rep.size()) c_rep--;
        }
        if(rep_deny == 0 || dem_deny == 0) break;
    }
    
    fprintf(stderr, "Living Rep:"); for(int i=1; i<rep.size(); i++) fprintf(stderr, " %d", rep[i]); fprintf(stderr, "\n");
    fprintf(stderr, "Living Dem:"); for(int i=1; i<dem.size(); i++) fprintf(stderr, " %d", dem[i]); fprintf(stderr, "\n");
    printf("%c\n", rep.size()>1? 'R':'D');
    return 0;
}
