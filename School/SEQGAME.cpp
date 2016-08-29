/* Cho một dãy số a[1], a[2], ..., a[n]
 * tìm i, j biến thành a[i] = a[j] = a[i]+a[j]
 * làm k lần sao cho tích của dãy số là nhỏ nhất có thể
 * 
 * xét: nếu đổi 2 phân tử i, j thì ta có:
 * tích ban đầu: a[i] * a[j] * ...
 * tích lúc sau: (a[i]+a[j])^2 * ...
 * 
 * Ta có (a+b)^2 >= 4ab (Cauchy), dấu '=' xảy ra <=> a = b
 * vậy, ta chỉ cần chọn 1 lần 2 số có tích nhỏ nhất
 * rồi sau này có thể chọn lại 2 số sau khi biến đổi hết những lượt còn lại
 * tức là tăng một lượng bằng 4^(k-1)
 */

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int N=109;

int n, m, check[19][19]={};
string a[N], b[N];

long long toInt(string a){
	long long x=0;
	for(int i=0; i<a.length(); i++) x = x*10 + int(a[i])-48;
	return x;
}

string inc(string a, string b="1"){
	while(a.length()<b.length()) a = "0"+a;
	while(b.length()<a.length()) b = "0"+b;
	string ans="";
	int x, y, c, nho = 0;
	for(int i=a.length()-1; i>=0; i--){
		x = int(a[i]) - 48; y = int(b[i]) - 48;
		c = x+y+nho; nho = c/10; c%=10;
		ans = char(c+48)+ans;
	}
	if(nho>0) ans = char(nho+48) + ans;
	return ans;
}

string multiply(string a, string b){
	string ans="0";
	for(int i=b.length()-1; i>=0; i--){
		string tmp="";
		int x, y, c, nho=0;
		for(int j=a.length()-1; j>=0; j--){
			x = int(a[j])-48; y = int(b[i])-48;
			c = x*y+nho; nho = c/10; c%=10;
			tmp = char(c+48)+tmp;
		}
		if(nho>0) tmp = char(nho+48)+tmp;
		for(int j=b.length()-1; j>i; j--) tmp.append("0");
		ans = inc(ans,tmp);
	}
	return ans;
}

string min(string a, string b){
	if(a.length() > b.length()) return b;
	if(a.length() < b.length()) return a;
	for(int i=0; i<a.length(); i++)
		if(a[i]>b[i]) return b;
		else if(a[i]<b[i]) return a;
	return a;
}

string div(string a, long long b){
	string ans="";
	long long x=0;
	for(int i=0; i<a.length(); i++){
		x = x*10 + (int(a[i])-48);
		if(i<l || () x/b==0) continue;
		if(x/b>0 && i<a.length()-1) ans += char(x/b+48);
		else if(i==a.length()-1) ans += char(x/b+48);
		x%=b;
	}
	return ans;
}

int main(){
	freopen("SEQGAME.inp","r",stdin);
	freopen("SEQGAME.out","w",stdout);
	cin>> n>> m;
	string original="1";
	for(int i=0; i<n; i++){
		cin>> a[i];
		b[i] = a[i];
		original = multiply(original,a[i]);
	}
	string ans="", up="1";
	for(int k=0; k<m-1; k++) up = multiply(up,"4");
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(!check[toInt(a[i])][toInt(a[j])]){
				b[i] = b[j] = inc(a[i],a[j]);
				// string mul = multiply(div(original , toInt(a[i])*toInt(a[j])), multiply(b[i],b[i]));
				string mul = "1";
				for(int k=0; k<n; k++){
					if(b[k]=="0"){ mul="0"; break; }
					mul = multiply(mul,b[k]);
				}
				string tmp = multiply(mul,up);
				ans = (ans=="")? tmp:min(ans,tmp);
				b[i] = a[i]; b[j]=a[j];
				check[toInt(a[i])][toInt(a[j])] = check[toInt(a[j])][toInt(a[i])] = 1;
			}
	printf("%s\n",ans.c_str());
	return 0;
}
