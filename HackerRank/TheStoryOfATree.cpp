// // HackerRank - University CodeSprint 2 - The Story of a Tree
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, m, k, correct_guess[N]={}, correct_reversed_guess[N]={}, correct = 0;
bool visited[N]={};
vector<int> adj[N];
vector<ii> guess;

void dfs(int u){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            correct_guess[v] = correct_guess[u];
            correct_reversed_guess[v] = correct_reversed_guess[u];

            if(binary_search(guess.begin(), guess.end(), ii(u,v))){
                correct++;
                correct_guess[v]++;
            }

            if(binary_search(guess.begin(), guess.end(), ii(v,u))){
                correct_reversed_guess[v]++;
            }
            dfs(v);
        }
    }
}

void init(){
    memset(visited, false, sizeof visited);
    memset(correct_guess, 0, sizeof correct_guess);
    memset(correct_reversed_guess, 0, sizeof correct_reversed_guess);
    guess.clear(); correct = 0;
    for(int i=1; i<=n; i++)
        adj[i].clear();
}

int main(){
    int TC; scanf("%d", &TC);
    while(TC--){
        init();
        scanf("%d", &n);
        for(int i=1; i<n; i++){
            int x, y; scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        scanf("%d %d", &m, &k);
        for(int i=0; i < m; i++){
            int x, y; scanf("%d %d", &x, &y);
            guess.push_back(ii(x,y));
        }

        sort(guess.begin(), guess.end());
        dfs(1);

        int ans = correct >= k;
        for(int i=2; i<=n; i++){
            ans += correct - correct_guess[i] + correct_reversed_guess[i] >= k;
        }

        int gcd = __gcd(ans, n);
        printf("%d/%d\n", ans / gcd, n / gcd);
    }
    return 0;
}
