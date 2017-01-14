#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

const int N=59;

int n, m, c[N][N]={}, a[N][N]={}, b[N][N]={}, s1, s2, t1, t2;
string facing;

bool inRange(int check, int lo, int hi){
    return lo < check && check < hi;
}

int abs(int x){ return x<0? -x:x; }

struct Position{
    int x, y, face, cost;

    bool reached(int des_x, int des_y){ return x == des_x && y == des_y; }
    bool canGo(int steps){
        switch(face){
            case 0: return inRange(x+steps,0,n) && !a[x+steps][y] && b[x+steps][y] > cost+1;
            case 1: return inRange(y+steps,0,m) && !a[x][y+steps] && b[x][y+steps] > cost+1;
            case 2: return inRange(x-steps,0,n) && !a[x-steps][y] && b[x-steps][y] > cost+1;
            case 3: return inRange(y-steps,0,m) && !a[x][y-steps] && b[x][y-steps] > cost+1;
        }
    }
    void go(int steps){
        cost++;
        switch(face){
            case 0: x+=steps; break;
            case 1: y+=steps; break;
            case 2: x-=steps; break;
            case 3: y-=steps; break;
        }
    }
    // -1: turn right, 1: turn left
    void turn(int degree){
        if(!degree) return;
        cost++; face = abs(face+degree)%4;
    }
    void turnLeft(){ cost++; face = (face+1) % 4; }
    void turnRight(){ cost++; face = (face-1) % 4; }

    Position(int a, int b, string c){
        x = a, y = b;
        if(c=="east") face = 0;
        if(c=="north") face = 1;
        if(c=="west") face = 2;
        if(c=="south") face = 3;
        cost = 1;
    }
};

void transform(){
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++) a[i][j] = 0, b[i][j] = 10E8;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(c[i][j]==1) a[i][j] = a[i][j+1] = a[i+1][j] = a[i+1][j+1] = 1;
}

void BFS(){
    // int ans = 10E8;
    queue<Position> q;
    q.push(Position(s1,s2,facing)); b[s1][s2] = 1;
    while(!q.empty()){
        Position curr = q.front(); q.pop();
        for(int i=-1; i<=1; i++){
            Position temp = curr;
            temp.turn(i);
            for(int j=1; j<4; j++){
                Position p = temp;
                if(p.canGo(j)){
                    p.go(j); q.push(p); b[p.x][p.y] = p.cost;
                    // printf("%d %d - %d %d -> %d %d - %d %d\n",
                    //     curr.x+1,curr.y+1,curr.face,curr.cost,
                    //        p.x+1,   p.y+1,   p.face,   p.cost);
                }else break;
            }
        }
    }
    cout<< (b[t1][t2]==10E8? -1:b[t1][t2])<< '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin>> n>> m, n && m) {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++) cin>> c[i][j];
        transform();
        cin>> s1>> s2>> t1>> t2>> facing;
        // s1++, s2++, t1++, t2++;
        BFS();
    }
    return 0;
}
