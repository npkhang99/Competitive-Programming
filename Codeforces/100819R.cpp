#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 109;

int n;
pair<string,string> a[N];

int main(){
    cin>> n; cin.ignore();
    for(int i=0; i<n; i++)
        cin>> a[i].second>> a[i].first;
    sort(a,a+n);
    for(int i=0; i<n; i++)
        cout<< a[i].second<< " "<< a[i].first<< endl;
    return 0;
}
