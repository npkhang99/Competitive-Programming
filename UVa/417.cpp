#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string st;
unordered_map<string,int> a;

void prep(int dept, char last, string st, int x){
    if(x > dept){
        a[st] = ++cnt;
        return;
    }
    for(char ch = last + 1; ch <= 'z'; ch++)
        prep(dept, ch, st + ch, x+1);
}

int main(){
    prep(1,'a'-1,"",1); prep(2,'a'-1,"",1); prep(3,'a'-1,"",1);
    prep(4,'a'-1,"",1); prep(5,'a'-1,"",1);
    while(cin>> st)
        cout<< a[st]<< endl;
    return 0;
}
