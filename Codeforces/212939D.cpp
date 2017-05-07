#include <bits/stdc++.h>
using namespace std;

typedef pair<char,int> ci;

int n, k;
bool b[1000009]={}, not_prime[1000009]={};
string a;

void calc_a(){
    int cnt = 0;
    not_prime[0] = not_prime[1] = true;
    for(long long i = 2; i <= 620000; i++){
        if(not_prime[i]) continue;
        for(long long j = i*i; j <= 620000; j += i)
            not_prime[j] = true;
        a += to_string(i);
        if(++cnt == n) return;
    }
}

int main(){
    scanf("%d %d", &n, &k);

    calc_a();

    priority_queue<ci, vector<ci>, greater<ci> > q;
    int p = 0;
    while(k && p < a.size()){
        if(q.empty() || q.top().first >= a[p]){
            q.push(ci(a[p],-p)); p++;
            continue;
        }
        while(k && !q.empty() && a[p] > q.top().first){
            b[-q.top().second] = 1;
            q.pop(); k--;
        }
        q.push(ci(a[p],-p)); p++;
    }

    while(k--){
        b[-q.top().second] = true;
        q.pop();
    }

    bool delete_all = true;
    for(int i=0; i<a.size(); i++)
        if(!b[i]){
            printf("%c",a[i]);
            delete_all = false;
        }
    printf("%s", delete_all? "0\n":"\n");
    return 0;
}
