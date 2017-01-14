#include <bits/stdc++.h>
using namespace std;

typedef pair<char,char> cc;

const int N = 1009;

int n;
char s[N]={}, t[N]={};
bool flag = false;
vector<cc> a;

cc rev(cc a){ return cc(a.second, a.first); }

int check(cc key){
    for(int i=0; i<a.size(); i++){
        // fprintf(stderr, "%c %c - %c %c\n", key.first, key.second, a[i].first, a[i].second);
        if(key == a[i] || rev(key) == a[i]) return 1;
        if((key.first == a[i].first && key.second != a[i].second) || (rev(key).first == a[i].first && rev(key).second != a[i].second) || (key.first == rev(a[i]).first && key.second != rev(a[i]).second) || (rev(key).first == rev(a[i]).first && rev(key).second != rev(a[i]).second)) return -1;
    }
    return 0;
}

int main(){
    scanf("%s %s",s,t);
    n = strlen(s);
    int x = 0;
    for(int i=0; i<n; i++){
        cc key = cc(s[i],t[i]);
        int exist = check(key);
        // fprintf(stderr, "%c %c - %d\n", s[i], t[i], exist);
        if(exist == -1){
            flag = true;
            break;
        }
        if(!exist) a.push_back(key);
        if(!exist && s[i] == t[i]) x+=1;
    }

    if(flag){ printf("-1\n"); return 0; }
    printf("%d\n", (int)a.size() - x);
    for(int i=0; i<a.size(); i++) if(a[i].first != a[i].second) printf("%c %c\n",a[i].first, a[i].second);
    return 0;
}
