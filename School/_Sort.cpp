#include <iostream>
#include <algorithm>
using namespace std;

int a[]={50,20,30,60,80,100,90,10,40,70}; // mang co 10 phan tu voi chi so [0 - 9]

void printArray(){
	for(int i=0; i<10; i++) cout<< a[i]<< " ";
	cout<< endl;
}

int comp1(int a, int b){
	return a>b;
}

int main(){
	cout<< "Mang ban dau:\n  "; printArray();
	//------------------------------------------------------------
	sort(a+5,a+10);
	cout<< "Sau khi sap xep 5 phan tu cuoi:\n  "; printArray();
	//------------------------------------------------------------
	sort(a,a+10);
	cout<< "Sau khi sap xep ca mang:\n  "; printArray();
	//------------------------------------------------------------
	sort(a,a+10,comp1);
	cout<< "Sau khi sap xep ca mang voi ham sap xep:\n  "; printArray();
	return 0;
}