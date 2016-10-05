#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

const int N=1009;

int n, t, k=0;
string st;
queue<int> q[N], order;
unordered_map<int,int> a;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> t, t){
        cout<< "Scenario #"<< ++k<< '\n';
        a.clear();
        while(!order.empty()) order.pop();
        for(int i=0; i<t; i++){
            cin>> n;
            int x;
            while(!q[i].empty()) q[i].pop();
            for(int j=0; j<n; j++)
                cin>> x, a[x] = i;
        }
        while(cin>> st, st!="STOP"){
            if(st == "ENQUEUE"){
                cin>> n;
                int x = a[n];
                if(q[x].empty()) order.push(x);
                q[x].push(n);
            }
            if(st == "DEQUEUE"){
                if(order.empty()) continue;
                int next = order.front();
                cout<< q[next].front()<< '\n';
                q[next].pop();
                if(q[next].empty()) order.pop();
            }
        }
        cout<< '\n';
    }
    return 0;
}
