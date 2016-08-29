#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define Read(a) cin>> a.x>> a.y

const int N=100009;

struct point{
	long double x,y;
}a[N], adil, bera, bin;

struct distances{
	long double val;
	int index;
}d[N], da[N], db[N];

int n, b[N]={};

void doc(){
	Read(adil); Read(bera); Read(bin);
	cin>> n;
	for(int i=0; i<n; i++) Read(a[i]);
}

long double dist(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int comp(distances a, distances b){
	return a.val<b.val;
}

void xuly(){
	int af=0,bf=0;
	long double ans=0;
	// calc the distance from starting point
	// and trash bin to others
	for(int i=0; i<n; i++){
		da[i].index = db[i].index = d[i].index = i;
        // from trash bin
		d[i].val = dist(bin,a[i])*2;
		// from starting point
		da[i].val = dist(adil,a[i]) + dist(bin,a[i]);
		db[i].val = dist(bera,a[i]) + dist(bin,a[i]);
	}
	// sort the distances
	sort(d,d+n,comp); sort(da,da+n,comp); sort(db,db+n,comp);
	for(int i=0; i<n; i++)
		printf("%.9Lf, %d  --  %.9Lf, %d  --  %.9Lf, %d\n",da[i].val,da[i].index,db[i].val,db[i].index,d[i].val,d[i].index);
    printf("\n");
	// do THE job
	int i=0, j=0, adilStarted=0, beraStarted=0, t=0;
	while(i!=n && j!=n){
		long double acost=0, bcost=0, fcost=0;
		if(!adilStarted) acost=da[i].val;
		else acost=d[i].val;
		if(!beraStarted) bcost=db[j].val;
		else bcost=d[j].val;
		fcost = min(acost,bcost);
		ans += fcost;
		if(fcost==acost){
			if(!adilStarted){
				adilStarted=1;
				i=0;
                t=da[i].index;
			}else t=d[i].index;
            printf("Adil goes to %d, cost %.9Lf -> %.9Lf\n",t,fcost,ans);
		}else if(fcost==bcost){
			if(!beraStarted){
				beraStarted=1;
				j=0;
                t=db[j].index;
			}else t=d[j].index;
            printf("Bera goes to %d, cost %.9Lf -> %.9Lf\n",t,fcost,ans);
		}
        b[t]=1;
		while(i<n && ((!adilStarted && b[da[i].index]) || (adilStarted && b[d[i].index]))) i++;
		while(j<n && ((!beraStarted && b[db[j].index]) || (beraStarted && b[d[j].index]))) j++;
	}
	printf("%.12Lf\n",ans);
}

int main(){
	doc();
	xuly();
	return 0;
}
