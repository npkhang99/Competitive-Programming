#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

string st;
int k, id, period;
priority_queue<ii, vector<ii>, greater<ii> > q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> st){
        if(st == "Register"){
            cin>> id>> period;
            for(int i=1; i<=10000; i++) q.push(ii(period*i,id));
            continue;
        }
        cin>> k;
        for(int i=0; i<k; i++)
            cout<< q.top().second<< '\n', q.pop();
    }
    return 0;
}
