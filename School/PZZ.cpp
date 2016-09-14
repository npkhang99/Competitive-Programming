#include <iostream>
#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct swapPos{
    int x1,y1;
    int x2,y2;
};

int n;
string fin="", st="";
map<string,string> tr;

string toString(int x){
    string s="";
    if(x<10) return s.append(1,x+48);
    while(x>0){
        s = char(x%10+48) + s;
        x/=10;
    }
    return s;
}

int find(string curr){
    string dest=toString(n*n), now="";
    for(int i=0; i<curr.length(); i++){
        now = curr[i];
        if(now == dest) return i;
    }
}

int isFin(string st){
    for(int i=0; i<st.length(); i++)
        if(st[i]!=fin[i]) return 0;
    return 1;
}

void printAns(){
    string curr = fin;
    vector<swapPos> ans;
    swapPos x;
    int pos = find(curr);
    while(curr!=st){
        x.x2 = pos/n; x.y2 = pos%n;
        curr = tr[curr];
        pos = find(curr);
        x.x1 = pos/n; x.y1 = pos%n;
        ans.push_back(x);
    }
    printf("%d\n",ans.size());
    for(int i=ans.size()-1; i>=0; i--) printf("%d %d %d %d\n",ans[i].x1+1,ans[i].y1+1,ans[i].x2+1,ans[i].y2+1);
}

void BFS(){
    queue<string> q;
    string y;
    q.push(st);
    while(!q.empty()){
        string curr = q.front(); q.pop();
        int pos = find(curr);
        int i = pos/n, j = pos%n;
        // printf("%s %d %d %d\n",curr.c_str(),pos,i,j);
        if(i>0){
            y = curr;
            swap(y[pos],y[pos-n]);
            if(tr.find(y)==tr.end()){
                tr[y] = curr;
                q.push(y);
            }
            if(y==fin){ printAns(); return; }
        }
        if(i<n-1){
            y = curr;
            swap(y[pos],y[pos+n]);
            if(tr.find(y)==tr.end()){
                tr[y] = curr;
                q.push(y);
            }
            if(y==fin){ printAns(); return; }
        }
        if(j>0){
            y = curr;
            swap(y[pos],y[pos-1]);
            if(tr.find(y)==tr.end()){
                tr[y] = curr;
                q.push(y);
            }
            if(y==fin){ printAns(); return; }
        }
        if(j<n-1){
            y = curr;
            swap(y[pos],y[pos+1]);
            if(tr.find(y)==tr.end()){
                tr[y] = curr;
                q.push(y);
            }
            if(y==fin){ printAns(); return; }
        }
    }
}

int main(){
    // freopen("PZZ.inp","r",stdin);
    // freopen("PZZ.out","w",stdout);
    cin>> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            int x; cin>> x;
            st += toString(x);
            fin += toString(i*n+j+1);
        }
    if(st==fin){
        printf("0\n");
        return 0;
    }
    BFS();
    return 0;
}