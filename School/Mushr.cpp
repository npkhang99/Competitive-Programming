#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int N=40009;

typedef pair<int,int> ii;

int n, b, e, p;
vector<int> a[N];
//---------------------------------------------------------
class path {
  public:
	int costTo[N], cost;
	void init(int, int);
	void showCostTo();
	void showCostTo(int destination){ cout<< costTo[destination]<< endl; }
	void calCostFrom(int);
};

void path::init(int c, int s){
	this->cost=c;
	for(int i=1; i<=n; i++) this->costTo[i]=10E8;
	this->costTo[s]=0;
}

void path::showCostTo(){
	for(int i=1; i<=n; i++)
		cout<< this->costTo[i]<< " ";
	cout<< endl;
}

void path::calCostFrom(int s){
	int visit[N], val=this->cost;
	priority_queue<ii, vector<ii>, greater<ii> > q;
	for(int i=1; i<=n; i++) visit[i]=0;
	q.push(ii(0,s));
	while(!q.empty()){
		if(visit[q.top().second]) continue;
		int u=q.top().second, du=q.top().first;
		q.pop(); visit[u]=1;
		for(int v=0; v<a[u].size(); v++)
			if(!visit[a[u][v]] && du+val < this->costTo[a[u][v]]){
				this->costTo[a[u][v]] = du+val;
				q.push(ii(this->costTo[a[u][v]], a[u][v]));
			}
	}
}

path ti, teo, chung;
//---------------------------------------------------------
void doc(){
	int m;
	cin>> b>> e>> p>> n>> m;
	ti.init(b,1); teo.init(e,2); chung.init(p,n);
	for(int i=1; i<=m; i++){
		int x, y;
		cin>> x>> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}

void xuly(){
	int ans=10E8;
	ti.calCostFrom(1); teo.calCostFrom(2); chung.calCostFrom(n);
	// ti.showCostTo(); teo.showCostTo(); chung.showCostTo();
	for(int i=1; i<=n; i++) ans=min(ans, ti.costTo[i]+teo.costTo[i]+chung.costTo[i]);
	cout<< ans;
}

int main(){
	freopen("Mushr.inp","r",stdin);
	freopen("Mushr.out","w",stdout);
	doc();
	xuly();
	return 0;
}
