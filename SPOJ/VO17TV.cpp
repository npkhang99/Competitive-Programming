#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, m, k, b[N]={}, minimum = 1e9;
string a[N], P, T="";
set<string> s;

void prepKMP(){
    int i = 0, j = -1;
    b[0] = -1;
    while(i < P.size()){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int KMP(int from){
    int cnt = 1;
    for(int t = 0; t < n; t++){
        if(t == from) continue;
        int i = 0, j = 0;
        while(i < a[t].size()){
            while(j >= 0 && a[t][i] != P[j]) j = b[j];
            i++; j++;
            if(j == P.size()){
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin>> n>> k;
    for(int i=0; i<n; i++){
        cin>> a[i];
        T += '$' + a[i];
        minimum = min(minimum, (int)a[i].size());
    }

    int ans = 0;
    for(int t=0; t<n; t++){
        for(int i=0; i<a[t].size(); i++)
            for(int j=i+1; j<=a[t].size() && j - i <= minimum; j++){
                string b(a[t].begin()+i, a[t].begin()+j);
                if(s.find(b) != s.end()) continue;
                P = b;
                s.insert(P);
                prepKMP();
                int temp = KMP(t);
                if(temp >= k) ans = max(ans, (int)P.size());
            }
    }
    cout<< ans<< '\n';
    return 0;
}
