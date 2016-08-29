#include <bits/stdc++.h>
#define MAX_N 40001 
#define MAX_SEGMENT 33554432
 
using namespace std; 
 
typedef pair <int,int> pr; 
 
int test; 
pr a[MAX_N]; 
int covered[MAX_SEGMENT]; 
int left, right; 
int tick[MAX_SEGMENT]; 
 
int isCovered(int now, int range_left, int range_right, int left, int right) 
	{
		if (tick[now]) 
			{
				covered[now] = 1; 
				if (left != right)
				 	{
				 		tick[2 * now] = tick[2 * now + 1] = 1; 
				 		tick[now] = 0;
				 	}
			}
			
		if (range_left > right || range_right < left) return -1; 
		if (range_left <= left && right <= range_right) return covered[now]; 
		
		int mid = (left + right) / 2; 
		
		int tmp1 = isCovered(2 * now, range_left, range_right, left, mid); 
		int tmp2 = isCovered(2 * now + 1, range_left, range_right, mid + 1, right); 
		
		if (tmp1 == -1) return tmp2; 
		if (tmp2 == -1) return tmp1; 
		
		int tmp = tmp1 & tmp2; 
		
		return tmp; 
	}
	
void update_interval(int now, int range_left, int range_right, int left, int right)
	{
		if (tick[now])  
			{
				covered[now] = 1; 
				if (left != right) 
					{
						tick[2 * now] = tick[2 * now + 1] = 1;  
						tick[now] = 0;  
					}
			}
			
		if (range_left >  right || range_right < left) return; 
		
		if (range_left <= left && right <= range_right) 
			{
				covered[now] = 1; 
				if (left != right) 
					tick[2 * now] = tick[2 * now + 1] = 1; 
					
				return; 
			}
			
		int mid = (left + right) / 2; 
		update_interval(2 * now, range_left, range_right, left, mid); 
		update_interval(2 * now + 1, range_left, range_right, mid + 1, right); 
		
		covered[now] = covered[2 * now] & covered[2 * now + 1]; 
	}
 
int main () 
	{
		ios :: sync_with_stdio(false);
		cin.tie(0); 
		
		cin >> test; 
		while (test--) 
			{
				int n; 
				cin >> n; 
				int left = 10000010; 
				int right = -1; 
				for (int i = n - 1; i >= 0; i--) 
					{
						cin >> a[i].first >> a[i].second; 
						left = min(left,a[i].first); 
						right = max(right,a[i].second); 
					}
					
				// for (int i = left; i <= right; i++) cout << covered[i] << ' '; 
					
				for (int i = 0; i < MAX_SEGMENT; i++) covered[i] = tick[i] = 0; 
				
				int res = 0; 
				
				for (int i = 0; i < n; i++) 
					if (!isCovered(1,a[i].first,a[i].second,left,right)) 
						{
							update_interval(1,a[i].first,a[i].second,left,right); 
							res++; 
						}
						
				cout << res << endl;
			}
		return 0; 	
	} 