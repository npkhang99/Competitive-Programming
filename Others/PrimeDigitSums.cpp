// HackerRank - World CodeSprint 8 - Prime Digit Sums
#include <bits/stdc++.h>
using namespace std;

const int N = 400009;

int n, a[N]={};

bool isPrime(int x){
    if(x < 2) return false;
    for(int i=2; i <= (int)round(sqrt(x)); i++)
        if(x % i == 0) return false;
    return true;
}

// bool check(string s, int l){
//     for(int i=0; i < s.size() - l + 1; i++){
//         int temp = 0;
//         for(int j=i; j <= i+l-1; j++)
//             temp += s[j] - 48;
//         if(!isPrime(temp)) return false;
//     }
//     return true;
// }

// int check(int x){
//     for(int i=pow(10,x-1); i < pow(10,x); i++)
//         if(check(to_string(i),3) && check(to_string(i),4) && check(to_string(i),5)) a[x] += 1;
//     fprintf(stderr, "%d\n", a[x]);
//     return a[x];
// }

// void worst(){
//     for(int i=100; i<1000; i++)
//         if(check(to_string(i),3)) a[3] += 1;
//     for(int i=1000; i<10000; i++)
//         if(check(to_string(i),3) && check(to_string(i),4)) a[4] += 1;
// }

int main(){
    return 0;
}
