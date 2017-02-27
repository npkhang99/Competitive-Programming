// HackerRank - CodeSprint 9 - Grading Students
#include <iostream>
using namespace std;

int round(int x){
    if(x < 38 || x % 5 < 3) return x;
    for(int i = x; i <= 100; i++)
        if(i % 5 == 0) return i;
    return -1;
}

int main(){
    int TC; cin>> TC;
    while(TC--){
        int score; cin>> score;
        cout<< round(score)<< endl;
    }
    return 0;
}
