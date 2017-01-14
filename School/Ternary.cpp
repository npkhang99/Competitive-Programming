#include <cstdio>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

int a, b, c;
string x, y, z;

string to_tri(int x){
    stack<int> S;
    while(x){
        S.push(x%3);
        x/=3;
    }
    string st = "";
    while(!S.empty()) st += char(S.top()+48), S.pop();
    return st;
}

string subtract(string c, string a){
    string st(c.size(),'0');
    for(int i=0; i<c.size(); i++){
        int sub = (3 + c[i] - a[i]) % 3;
        st[i] = char(sub+48);
    }
    return st;
}

int to_dec(string b){
    int power = b.size()-1, ans = 0;
    for(int i=0; i<b.size(); i++)
        ans += (b[i]-48)*(int)pow(3,power--);
    return ans;
}

int main(){
    // freopen("Ternary.inp","r",stdin);
    // freopen("Ternary.out","w",stdout);
    scanf("%d%d",&a,&c);
    x = to_tri(a), z = to_tri(c);
    while(x.size() < z.size()) x = '0'+x;
    while(z.size() < x.size()) z = '0'+z;
    b = to_dec(subtract(z,x));
    printf("%d\n",b);
    return 0;
}
