/*
 * vector la kieu du lieu co cau truc nhu mot mang nhung co the thay doi do lon
 * giong danh sach lien ket (linked list)
 * de viet duoc linked list thi phai can toi con tro (pointer)
 * ma cu he dung toi pointer thi cha ai thich lam nen vector la mot su thay the rat tot
 *
 * vector co rat nhieu loi ich va ung dung khac nhau, mot trong nhung ung dung do
 * la tao danh sach ke
 * neu viet danh sach ke theo kieu tuong minh thi rat met, trong khi dung vector chi can
 * vai dong lenh la xong
 */

#include <iostream> // cin
#include <stdio.h>	// printf freopen
#include <vector>	// vector push_back
using namespace std;

const int N=100009;

int n, m, b[N]={};
vector<int> a[N]; // mang a gom N phan tu voi kieu cua moi phan tu la vector<int>

// co the thay vector<int> thanh vector<char> , vector<long long> , ...
// voi gia tri trong cap < > la kieu du lieu (int, char, long long, string, ...)

void doc(){
	cin>> n>> m;
	for(int i=0; i<m; i++){
		int x,y;
		cin>> x>> y; // doc vao 2 dinh ke x, y

		a[x].push_back(y); // them dinh y vao danh sach cac dinh ke voi x
		a[y].push_back(x); // them dinh x vao danh sach cac dinh ke voi y
	}
}

void DFS(int u){
	if(b[u]) return; // mot gia tri tra ve true khi no khac 0 va tra ve false khi no bang 0
					 // nen cau lenh nay co the viet lai la if(b[u]!=0) return;
	printf("%d ",u); b[u]=1;

	// vong for de lay cac phan tu trong vector a[u]
	// vi vector tu gioi han do lon cua mang nen chi can dung ham a[u].size() de lay do lon
	for(int i=0; i<a[u].size(); i++){
		int v = a[u][i]; // lay v la dinh ke thu j cua dinh i trong vector a[u]
		DFS(v);
	}
}

int main(){
	freopen("DFS.inp","r",stdin); // dieu chinh luong vao cua stdin (doc file)
	doc();

	// luc nay mang a[] la danh sach ke cua cac dinh 1 -> n
	// moi phan tu cua mang a[] la mot mang con (tuong tu mang 2 chieu)
	// a[i]: la danh sach cac dinh ke voi dinh i
	// a[i][j]: la dinh ke thu j voi dinh i

	for(int i=1; i<n+1; i++){
		printf("Dinh ke voi %d: ",i);
		for(int j=0; j<a[i].size(); j++) printf("%d ",a[i][j]);
		printf("\n");
	}

	printf("\nDanh sach cac dinh duoc duyet theo DFS: ");
	DFS(1); // duyet DFS theo ds ke
	return 0;
}
