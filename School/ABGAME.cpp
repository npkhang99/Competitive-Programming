#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, T, isRev=1;
string a, fin;

void makeFinal(int n){
    fin = "";
    for(int i=0; i<n; i++)
        if(i<n/2) fin += "A";
        else if(i==n/2) fin += "#";
        else fin += "B";
    for(int i=0; i<n; i++)
        if(a[i]!=fin[n-1-i]){ isRev = 0; return; }
}

int find(string st){
    for(int i=0; i<st.length(); i++)
        if(st[i]=='#') return i;
}

void printAns(map<string,string> tr){
    vector<int> ans;
    string curr = fin;
    while(curr != a){
        ans.push_back(find(curr));
        curr = tr[curr];
    }
    printf("%d ",ans.size());
    for(int i=ans.size()-1; i>=0; i--) printf("%d ",ans[i]+1);
    printf("\n");
}

int BFS(string s){
    queue<string> q;
    map<string,string> tr;
    string y;
    q.push(s);
    while(!q.empty()){
        string st = q.front(); q.pop();
        string y = st;
        int pos = find(st);
        // printf("%s %d\n",st.c_str(),pos);
        if(pos>0){
            swap(y[pos],y[pos-1]);
            if(tr.find(y)==tr.end()){
                q.push(y);
                tr[y] = st;
            }
            if(y==fin){ printAns(tr); return 1; }
            swap(y[pos],y[pos-1]);
        }
        if(pos<n-1){
            swap(y[pos],y[pos+1]);
            if(tr.find(y)==tr.end()){
                q.push(y);
                tr[y] = st;
            }
            if(y==fin){ printAns(tr); return 1; }
            swap(y[pos],y[pos+1]);
        }
        if(pos>1){
            swap(y[pos],y[pos-2]);
            if(tr.find(y)==tr.end()){
                q.push(y);
                tr[y] = st;
            }
            if(y==fin){ printAns(tr); return 1; }
            swap(y[pos],y[pos-2]);
        }
        if(pos<n-2){
            swap(y[pos],y[pos+2]);
            if(tr.find(y)==tr.end()){
                q.push(y);
                tr[y] = st;
            }
            if(y==fin){ printAns(tr); return 1; }
            swap(y[pos],y[pos+2]);
        }
    }
    return 0;
}

void doRev(){
    vector<int> ans;
    for(int i=0,j=n-1; i<=j; i++,j--){
        ans.push_back(i);
        if(i!=j) ans.push_back(j);
    }
    printf("%d ",ans.size());
    for(int i=0; i<ans.size(); i++) printf("%d ",ans[i]+1);
    printf("\n");
}

int main(){
    // freopen("ABGAME.inp","r",stdin);
    // freopen("ABGAME.out","w",stdout);
    cin>> T;
    for(int _=0; _<T; _++){
        cin>> a;
        n = a.length();
        isRev = 1;
        makeFinal(n);
        int found = BFS(a);
        if(!found) printf("-1\n");
    }
    return 0;
}
