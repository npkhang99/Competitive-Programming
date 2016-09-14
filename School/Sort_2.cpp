#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

struct something{
    int x,y;
}b[10009];

int a[10009], n;

// ham so sanh rieng luon co 2 tham so a,b co cung kieu voi kieu cua mang
// lenh return tra ve truong hop minh khong hoan doi cac ky tu
// don gian hon ta co cac truong hop return don gian sau:
// return a>b : se cho ra mang giam dan
// return a<b : se cho ra mang tang dan

// ham comp1() se dung de sap xep giam dan mang a[]
int comp1(int a, int b){
    return a>b;
}

// ham comp2() se dung de sap xep tang dan theo x, neu x bang thi giam dan theo y
int comp2(something a, something b){
    return a.x<b.x || (a.x==b.x && a.y>b.y);
}

int main(){
    // tao mang ngau nhien
    srand(time(0));
    cin>> n;
    for(int i=0; i<n; i++){
        a[i] = rand()%20;
        b[i].x = rand()%10;
        b[i].y = rand()%10;
    }
    
    // sap xep mac dinh khong ham so sanh rieng khong dung duoc cho mang kieu struct
    // gia su co mang a[]
    // sort(a+x,a+y) -> sap xep trong khoang cac phan tu [x;y) hay x -> y-1
    sort(a,a+n); // sap xep tu phan tu 0 -> (n-1)
    for(int i=0; i<n; i++) cout<< a[i]<< " ";
    cout<< endl;
    
    // de sap xep tu dinh nghia thi viet them 1 ham so sanh, o day la ham comp1()
    sort(a,a+n,comp1);
    for(int i=0; i<n; i++) cout<< a[i]<< " ";
    cout<< endl<< endl;
    
    // de sap xep theo 2 tieu chi hoac hon thi ta dung mot ham sap xep rieng voi dk return thay doi 1 chut
    // giong nhu sap xep theo nhieu tieu chi trong quick sort ben pascal
    sort(b,b+n,comp2);
    for(int i=0; i<n; i++) cout<< b[i].x<< " "<< b[i].y<< endl;
    return 0;
}