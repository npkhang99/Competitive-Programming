#include <stdio.h>
using namespace std;

const int N=109;

int n;
double a[N], sum=0;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lf",&a[i]), sum+=a[i];
	printf("%.12lf\n",sum/n);
	return 0;
}
