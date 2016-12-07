// Bài này output tổng lớn nhất

/* Subtask 1:
* Duyệt nhị phân một dãy gồn N bit
* bit 0 tức không mời đội đó còn 1 là mới đội đó
* xét với 2 cặp i, j bất kỳ nếu kị nhau thì bỏ
* còn không thì chọn bộ bit có tổng độ hâm mộ lớn nhất
* Chú ý: Phải chọn CHẴN đội và > k
*/

/* Subtask 2:
* Đưa về bài toán cho đồ thị, tìm tập con không xung đột lớn nhất
* gọi c -> tập chọn, u -> tập ứng cử viên
* nếu gọi chọn(s,u) -> chọn({},{1,2,..,n})
* xét i có 2 trường hợp:
*    + Không chọn: c , u\{i}
*    + Chọn: c U {i}, (u\{i}) giao với N(i)    ~ Với N(i) là tập các đỉnh không kề với i
* (Bài toán NP-Hard)
*/

/* Subtask 3:
* Đồ thị không có đỉnh nào có bậc > 2
* Chia thành các vùng liên thông
* Với mỗi vùng sẽ có 2 dạng:
*    + Dạng đường thẳng
*    + Dạng vòng
* Tìm tập gồn 2h đỉnh (2h>k) mà tổng là lớn nhất
* - Với TH1: Tìm dãy số có tổng là lớn nhất
*    F[i,j]: từ 1->i chọn j số và i được chọn
*    F[i,j] = F[i',j-1]+p[i] (i'<i-1)
*    F[i,j,t]: từ 1->i chọn j, t = 0 thì số i không được chọn, t = 1 thì số i được chọn
*    F[i,j,0] = max(F[i-1,j,0] , F[i-1,j,1])
*    F[i,j,1] = F[i-1,j-1,0]+p[i]
* - Với TH2: Đưa về TH1
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int N=509;

int n, a[N], b[N];

int main(){
    
    return 0;
}
