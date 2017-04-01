#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n;
vector<ii> edges;
bitset<N> parent[N], child[N];

void print_result(int x = -1, int y = -1, int z = -1){
    printf("%d %d %d\n", x, y, z);
    exit(0);
}

int get_first_on_bit(bitset<N> binary){
    for(int i=0; i<=n; i++)
        if(binary.test(i)) return i;
    return -1;
}

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            int x; scanf("%d", &x);
            if(x){
                edges.push_back(ii(i,j));
                parent[j].set(i);
                child[i].set(j);
            }
        }

    for(ii edge : edges){
        int u = edge.first,
            v = edge.second;
        bitset<N> have_in_common = parent[u] & child[v];
        if(have_in_common.any()){
            print_result(get_first_on_bit(have_in_common), u, v);
        }
    }

    print_result();
    return 0;
}
