/*
 * Sắp xếp có lẽ là một trong những vấn đề thường xuyên gặp nhất không
 * chỉ trong Competitive Programming mà cả trong vấn đề hằng ngày
 * và trong lập trình nhiều thứ khác
 *
 * Các ngôn ngữ lập trình hiện nay thì hầu như đều có hàm sắp xếp của mình
 * C++ cũng không phải là một ngoại lệ với hàm sort() trong thư viện algorithm
 *
 * hàm sort() có 3 tham số: first_iterator, last_iterator và compare
 * trong đó 2 tham first_iterator và last_iterator là bắt buộc
 * vì chúng dùng để định dạng vùng sắp xếp
 * còn tham số thứ 3 thì optional là hàm sắp xếp riêng (chi tiết phía dưới)
 *
 * hàm sort sẽ được gọi theo format như sau:
 * sort(first_iterator, last_iterator[, compare])
 * khi gọi như thế nó sẽ sắp xếp các giá trị trong khoảng
 * [first_iterator , last_iterator)
 * với có hoặc không có hàm so sánh riêng của mình
 * chú ý ở đây là con trỏ chứ không phải là giá trị vị trí
 *
 * giả sử có mảng a[], nếu ta gọi sort(a+x,a+y)
 * thì nó sẽ sắp xếp trong khoảng các phần tử từ [x;y) hay x -> (y-1)
 * vd: sắp xếp khoảng từ 1 -> m thì: x = 1, y = m+1
 * chú ý, nếu x hoặc y là 0 thì có thể bỏ +x hoặc +y
 *
 * khi gọi hàm sắp xếp 2 tham số với hàm so sánh mặc định
 * thì hàm sẽ tự hiểu là mình đang sắp xếp tăng dần
 * lưu ý hàm so sánh mặc định chỉ được dùng cho mảng có kiếu dữ liệu đơn giản
 * như int, double, ... và pair<> nhưng không dùng dùng cho struct
 * nếu dùng struct phải viết hàm so sánh riêng
 */

#include <iostream>        // cin, cout
#include <stdlib.h>        // srand, rand
#include <time.h>          // time
#include <algorithm>       // sort
using namespace std;

// le' STRUCT
struct leStruct{
    int x,y;
}b[10009];

int a[10009], n;

// hàm so sánh riêng luôn có 2 tham số cùng kiểu với kiểu của mảng
// nếu hàm trả về true thì sẽ không hoán đổi vị trí và false thì sẽ đổi vị trí
// để dễ hiểu hơn, ta có 2 trường hợp return đơn giản sau:
// giả sử đang có 2 tham số (a,b)
// return a>b : sẽ sắp xếp theo chiều tăng dần
// return a<b : sẽ sắp xếp theo chiều giảm dần

// hàm comp1() này có tác dụng để sắp xếp mảng a[] theo chiều tăng dần
int comp1(int a, int b){
    return a>b;
}

// hàm comp2() có tác dụng sắp xếp tăng theo chiều x
// nếu x bằng nhau thì sẽ sắp xếp giảm theo chiều y
int comp2(leStruct a, leStruct b){
    return a.x<b.x || (a.x==b.x && a.y>b.y);
}

int main(){
    // tạo mảng ngẫu nhiên
    srand(time(0));
    // cin>> n;
    n = 7;
    for(int i=0; i<n; i++){
        a[i] = rand()%20;
        b[i].x = rand()%10;
        b[i].y = rand()%10;
    }

    cout<< "Cac mang goc: \n";
    for(int i=0; i<n; i++) cout<< a[i]<< " ";
    cout<< endl<< endl;
    for(int i=0; i<n; i++) cout<< b[i].x<< " "<< b[i].y<< endl;
    cout<< endl;

    // sắp xếp tăng dần các phần tử từ 0 -> n-1
    sort(a,a+n);
    cout<< "Sap xep mang a[] tang dan: ";
    for(int i=0; i<n; i++) cout<< a[i]<< " ";
    cout<< endl;

    // sắp xếp giảm dần các phần tử từ 0 -> n-1
    sort(a,a+n,comp1);
    cout<< "Sap xep mang a[] giam dan: ";
    for(int i=0; i<n; i++) cout<< a[i]<< " ";
    cout<< endl;

    // để sắp xếp 2 tiêu chí ta cũng cần viết hàm so sánh riêng
    // với điều kiện trả về có thay đổi một chút
    // cũng giống như sắp xếp nhiều tiêu chí thôi
    sort(b,b+n,comp2);
    cout<< "Sap xep mang b[] theo 2 tieu chi: \n";
    for(int i=0; i<n; i++) cout<< b[i].x<< " "<< b[i].y<< endl;
    return 0;
}
