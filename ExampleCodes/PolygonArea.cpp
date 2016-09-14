#include <stdio.h>
using namespace std;

const int N=1000009;

struct Point{
	int x, y;
} a[N];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	a[n] = a[0];
	
	int size = 0;
	for(int i=0; i<n; i++)
		size += (a[i].x-a[i+1].x)*(a[i].y+a[i+1].y);
	printf("%.3lf\n",size/2.0);
	return 0;
}
