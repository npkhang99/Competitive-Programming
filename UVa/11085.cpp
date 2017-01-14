#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int a[9]={}, t = 0, c[8]={}, s_diag[100]={};
vector<vector<int> > v;
vector<int> b(8,0);
set<int> m_diag;

void btrack(int i){
    if(i==8){
        v.push_back(b);
        return;
    }
    for(int j=1; j<=8; j++)
        if(!c[j] && !s_diag[i+j] && m_diag.find(j-i) == m_diag.end()){
        c[j] = 1; s_diag[i+j] = 1; m_diag.insert(j-i);
        b[i] = j;
        btrack(i+1);
        c[j] = 0; s_diag[i+j] = 0; m_diag.erase(j-i);
    }
}

int find(){
    int ans = 7;
    for(int i=0; i<v.size(); i++){
        int temp = 0;
        for(int j=0; j<8; j++)
            temp += (a[j] != v[i][j]);
        ans = min(ans,temp);
        if(ans == 0) return 0;
    }
    return ans;
}

int main(){
    btrack(0);
    while(~scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]))
        printf("Case %d: %d\n",++t, find());
    return 0;
}
