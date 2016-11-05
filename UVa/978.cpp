#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n, m, k, T;
priority_queue<int> green, blue;
vector<ii> battles;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&k,&n,&m);
        for(int i=0; i<n; i++){
            int x; scanf("%d",&x);
            green.push(x);
        }
        for(int i=0; i<m; i++){
            int x; scanf("%d",&x);
            blue.push(x);
        }

        while(!green.empty() && !blue.empty()){
            for(int i=0; i<k; i++){
                int gr = 0, bl = 0;
                if(!green.empty()){
                    gr = green.top();
                    green.pop();
                }
                if(!blue.empty()){
                    bl = blue.top();
                    blue.pop();
                }
                if(!gr && !bl) break;
                battles.push_back(ii(gr,bl));
            }
            for(ii batt:battles)
                if(batt.first > batt.second) green.push(batt.first - batt.second);
                else if(batt.first < batt.second) blue.push(batt.second - batt.first);
            battles.clear();
        }
        if(green.empty() && blue.empty()) printf("green and blue died\n");
        else if(!green.empty()){
            printf("green wins\n");
            while(!green.empty()){
                printf("%d\n",green.top());
                green.pop();
            }
        }else {
            printf("blue wins\n");
            while(!blue.empty()){
                printf("%d\n",blue.top());
                blue.pop();
            }
        }
        if(T) printf("\n");
    }
    return 0;
}
