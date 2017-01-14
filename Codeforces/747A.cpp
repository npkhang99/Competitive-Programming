#include <iostream>
using namespace std;

int n, a, b;

int main(){
    cin>> n;
    for(int i=1; i <= n; i++){
        if(n % i != 0) continue;
        int j = n / i;
        if(i > j) break;
        a = i, b = j;
    }
    cout<< a<< " "<< b<< endl;
    return 0;
}
