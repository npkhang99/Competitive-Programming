#include <iostream>
#include <math.h>
using namespace std;

double a,b,c;

int main(){
    cin>> a>> b>> c;
    cout<< (long long)(ceil(a/c)*ceil(b/c));
    return 0;
}