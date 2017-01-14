#include <iostream>
#include <stdio.h>
using namespace std;

const int N=109;

int n, m;
double a[N]={}, loan, downpayment;

int main(){
    ios::sync_with_stdio(false);
    while(cin>> n>> downpayment>> loan>> m, n>0){
        int last = -1;
        for(int i=0; i<m; i++){
            int month; double val;
            cin>> month>> val;
            a[month] = val;
            for(last+=1; last<month; last++) a[last] = a[last-1];
        }
        for(last+=1; last<=n; last++) a[last] = a[last-1];
        int months = 0;
        double pay = loan/n, paid = 0, worth = (loan+downpayment)*(1-a[0]);
        // printf("%2d %10.3lf %10.3lf %10.3lf %10.3lf\n",months,a[months],worth,paid,loan-paid);
        while(loan - paid > worth){
            months += 1;
            worth *= 1-a[months];
            paid += pay;
            // printf("%2d %10.3lf %10.3lf %10.3lf %10.3lf\n",months,a[months],worth,paid,loan-paid);
        }
        if(months==1) printf("%d month\n",months);
        else printf("%d months\n",months);
    }
    return 0;
}
