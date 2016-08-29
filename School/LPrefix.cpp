#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int N=5009;

int n, m=0, done[N]={};
string a[N], d[N], ans="";
stack<int> b[30];

// string comp(string a, string b){
	// return (a.length()>b.length() || (a.length()==b.length() && a<b))? a:b;
// }

int comp(string a, string b){
	return a.length()>b.length() || (a.length()==b.length() && a<b);
}

int find(string a, string b){
	for(int i=0; i<b.length()-a.length()+1; i++)
		for(int j=0; j<a.length(); j++)
			if(a[i+j]!=b[j]) return 0;
	return 1;
}

int main(){
	// freopen("LPrefix.inp","r",stdin);
	// freopen("LPrefix.out","w",stdout);
	cin>> n;
	for(int i=0; i<n; i++){
		cin>> a[i];
		m = (m<a[i].length())? a[i].length():m;
	}
	
	for(int j=0; j<m; j++){
		for(int i=0; i<n; i++){
			if(done[i]) continue;
			if(j>a[i].length()-1){ done[i]=1; continue; }
			b[a[i][j]-'A'].push(i);
		}
		for(int al=0; al<26; al++){
			if(b[al].empty()) continue;
			int i = b[al].top();
			if(!done[i]){
				if(b[al].size()<2){
					done[i] = 1;
					b[al].pop();
					continue;
				}
				while(!b[al].empty()){
					d[b[al].top()]+=a[i][j];
					b[al].pop();
				}
			}
		}
		// for(int i=0; i<n; i++) printf("%d - %s\n",i,d[i].c_str());
		// printf("\n");
	}
	sort(d,d+n,comp);
	for(int i=1; i<n; i++)
		if(find(d[i],d[i-1])){ printf("%s\n",d[i-1].c_str()); break; }
	// printf("%s\n",ans.c_str());
	return 0;
}