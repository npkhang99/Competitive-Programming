#include <bits/stdc++.h>
using namespace std;

const int N = 2009;

int n, m;
bool b[N]={};
vector< pair<string,int> > a;

int main(){
    cin>> n>> m;
    for(int i=0; i<n; i++){
        string st; cin>> st;
        a.push_back(make_pair(st,1));
    }

    for(int i=0; i<m; i++){
        string st; cin>> st;
        a.push_back(make_pair(st,2));
    }

    sort(a.begin(), a.end());
    for(int i=0; i<a.size() - 1; i++)
        if(a[i].first == a[i+1].first){
            a[i].second = 3;
            a.erase(a.begin() + (i+1));
        }

    int turn = 1;
    while(true){
        int p = 0;
        if(turn == 1 && !n) break;
        if(turn == 2 && !m) break;
        for(int i=0; i<a.size(); i++)
            if(!b[i] && (a[i].second == turn || a[i].second == 3)){
                p = i;
                if(a[i].second == 3) break;
            }
        b[p] = true;
        if(a[p].second == 1) n--;
        else if(a[p].second == 2) m--;
        else {n--; m--;}
        turn = 3 - turn;
    }

    printf("%s\n", turn==2? "YES":"NO");
    return 0;
}
