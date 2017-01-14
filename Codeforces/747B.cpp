#include <bits/stdc++.h>
using namespace std;

typedef pair<int,char> ic;

const int N = 259;

int n, a[N]={};
string genome;

int main(){
    cin>> n>> genome;
    for(int i=0; i<n; i++)
        a[genome[i]]++;
    priority_queue<ic, vector<ic>, greater<ic> > q;
    q.push(ic(a['T'],'T')); q.push(ic(a['G'],'G')); q.push(ic(a['C'],'C')); q.push(ic(a['A'],'A'));
    for(int i=0; i<a['?']; i++){
        ic c = q.top(); q.pop();
        c.first += 1;
        q.push(c);
    }
    ic c[10];
    c[1] = q.top(); q.pop();
    c[2] = q.top(); q.pop();
    c[3] = q.top(); q.pop();
    c[4] = q.top(); q.pop();
    if(c[1].first != c[2].first || c[1].first != c[3].first || c[1].first != c[4].first || c[2].first != c[3].first || c[2].first != c[4].first || c[3].first != c[4].first){
        cout<< "===\n";
        return 0;
    }

    for(int i=1; i<=4; i++){
        c[i].first -= a[c[i].second];
        cerr<< c[i].first<< " "<< c[i].second<< endl;
    }
    int j = 1;
    for(int i=0; i<n; i++){
        if(genome[i] == '?'){
            while(c[j].first == 0) j++;
            cout<< c[j].second; c[j].first--;
            continue;
        }
        cout<< genome[i];
    }
    cout<< endl;
    return 0;
}
