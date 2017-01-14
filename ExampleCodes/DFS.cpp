/*
 * vector là kiểu dữ liệu có cấu trúc như một mảng nhưng có thể thay đổi độ lớn
 * giống như danh sách liên kết (linked list)
 * để viết được linked list thì phải cần tới con trỏ (pointer)
 * nhưng dùng linked list cũng không có cái lợi là nếu muốn truy cập một phần tử
 * thì phải duyệt qua hết tất cả các phần tử trước nó, còn với vector thì có thể
 * truy cập trực tiếp với độ phức tạp là một hằng số
 *
 * vector có rất nhiều lợi ích và ứng dụng khác nhau, một trong những ứng dụng đó
 * là tạo danh sách kề
 * nếu viêt danh sách kề theo phong cách tường minh thì rất là nhiêu khê dài dòng
 * nhưng khi làm việc với vector thì rất đơn giản
 */

#include <cstdio>
#include <iostream>   // cin cout
#include <vector>     // vector push_back
using namespace std;

const int N=100009;

int n, m, b[N]={};
vector<int> a[N]; // mảng a gồm N phần tử với kiểu dữ liệu của mỗi phần tử là vector<int>

// có thể thay vector<int> thành vector<char> , vector<long long> , ...
// với giá trị trong cặp ngoặc nhọn < > là kiểu dữ liệu (int, char, long long, string, ...)

void doc(){
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>> x>> y;
        a[x].push_back(y); // thêm đỉnh y vào danh sách các đỉnh kề với x
        a[y].push_back(x); // đường đi hai chiều
    }
}

void DFS(int u){
    if(b[u] != 0) return;
    b[u]=1;
    cout<< u<< " ";

    // vòng for này dùng để duyệt qua các phần tử trong vector a[u]
    // vì vector tự giới hạn độ lớn của nó nên để biết số lượng phần tử có trong nó (ở đây là
    // số lượng đỉnh kề với u) thì ta gọi hàm size() để lấy độ lớn
    for(int i=0; i<a[u].size(); i++){
        int v = a[u][i]; // a[u][i] là đỉnh kề thứ i của đỉnh u
        DFS(v);
    }
}

int main(){
    freopen("DFS.inp","r",stdin);
    doc();

    // lúc này, mảng a[] là danh sách kề của các đỉnh từ 1 -> n
    // với mỗi phần tử của mảng a[] là một vector:
    //     - a[i]    : là danh sách các đỉnh kề với đỉnh i
    //     - a[i][j] : là đỉnh kề thứ j với đỉnh i

    for(int i=1; i<n+1; i++){
        printf("Dinh ke voi %d: ",i);
        cout<< "Dinh ke voi "<< i<< ":"<< endl;
        for(int j=0; j<a[i].size(); j++) cout<< a[i][j]<< " ";
        cout<< endl;
    }

    cout<< endl<< "Danh sach cac dinh duoc duyet theo DFS: ";
    DFS(1); // DFS theo danh sách kề
    return 0;
}
