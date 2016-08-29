/* Gọi dp[mask][submask] là số đồ thị con của đồ thị G
 * có tập đỉnh là {mask}, {submask} là tập hợp các nút lá của đồ thị con {mask}
 * (submask là tập con của mask)
 * 
 * Với 2 đỉnh x, y bất kì ta có: dp[{x,y}][{x,y}] = 1
 * Với dp[mask][submask]
 * ta tìm một đỉnh ${t} thuộc {mask} và cũng thuộc {submask} (tức ${t} là ngõ cụt)
 * tìm thêm một đỉnh ${x} nối với ${t} nhưng không thuộc {submask}
 * => dp[mask][submask] = dp[mask\{t}][submask\{t}] + dp[mask\{t}][submask\{t}+{x}]
 * Kết quả: tổng dp[1<<n - 1][submask] với |submask| = k
 */

#include <iostream>
#include <stdio.h>
using namespace std;

const int N=19;

int n, m, k, a[N][N]={}, dp[1<<N][1<<N]={};

int main(){
	scanf("%d%d%d\n",&n,&m,&k);
	for(int i=0; i<m; i++){
		int x,y; scanf("%d%d\n",&x,&y);
		a[x][y] = a[y][x] = 1;
	}

	// for(int i=0; i<n; i++) a[i][i] = 1;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(a[i][j] && !dp[1<<i][1<<j]) dp[1<<i][1<<j] = 1;
	
	return 0;
}