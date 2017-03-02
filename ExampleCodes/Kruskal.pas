(* Thuật toán Kruskal tìm cây khung nhỏ nhất (Minimal Spanning Tree)
 * Độ phức tạp trung bình: O(E log V)
 * http://vn.spoj.com/problems/QBMST/
 * NOTE:
 * - Code này cài đặt bằng cấu trúc dữ liệu Disjoint Set (viết tắt là DSU - quản lý các tập không giao nhau)
 * - Code DSU này được tối ưu bằng rank của cây (chiều cao của cây)
 * - Mảng par[] lưu đỉnh cha của đỉnh tương ứng | par[i] = x : x là cha của i (par = parent)
 ***************************************************************************************************************)
Const fi='Kruskal.inp';
Type Edge=Record
        u,v,w:longint;
     End;
Var e:array[1..20009] of Edge;
    par,rank:array[1..20009] of longint;
    n,m:longint;
//------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to m do
            with e[i] do readln(f,u,v,w);
        close(f);
    End;
//------------------------------
Procedure swap(var a,b:Edge);
    Var t:Edge;
    Begin
        t:=b;
        b:=a;
        a:=t;
    End;
//------------------------------
Procedure qsort(l,r:longint);
    Var x,i,j:longint;
    Begin
        i:=l; j:=r;
        x:=e[i + random(j-i+1)].w;
        repeat
            while e[i].w < x do inc(i);
            while e[j].w > x do dec(j);
            if i<=j then
                Begin
                    swap(e[i],e[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if i<r then qsort(i,r);
        if j>l then qsort(l,j);
    End;
//------------------------------
Procedure init; // khởi tạo các giá trị cần thiết
    Var i:longint;
    Begin
        for i:=1 to n do
            Begin
                par[i]:=i;      // ban đầu mỗi đỉnh là 1 cây (cha của nó là chính nó)
                rank[i]:=0;     // 
            End;
    End;
//------------------------------
Function root(p:longint):longint; // lấy gốc của đỉnh p
    Begin
        if p = par[p] then exit(p)
        else exit(root(par[p]));
    End;
//------------------------------
Function is_same_set(u,v:longint):Boolean; // kiểm tra xem 2 đỉnh u và v có cùng thuộc 1 cây hay không
    Begin
        exit(root(u) = root(v));
    End;
//------------------------------
// hợp nhất tối ưu - tránh được trường hợp cây quá dài (đỉnh đang xét ở quá xa gốc) khiến độ phức tạp khi lấy gốc quá lớn
// theo kinh nghiệm thì dùng cách cài này có thể giảm thời gian chạy một cách đáng kể, tránh bị TLE
// có một bài nếu dùng join bình thường thì thời gian lên đến 0.7s ở test max nhưng dùng cách này thì chỉ còn 0.1s test max
Procedure optimized_join(u,v:longint);
    Begin
        u:=root(u); v:=root(v);
        if rank[u] <= rank[v] then
            Begin
                par[u] := v;
                if rank[u] = rank[v] then inc(rank[v]);
            End
        else par[v] := u;
    End;
//------------------------------
Procedure normal_join(u,v:longint); // hợp nhất bình thường (không cần xét rank[])
    Begin
        u:=root(u); v:=root(v);
        par[u] := v;
    End;
//------------------------------
Procedure Kruskal;
    Var i,ans,cnt:longint;
    Begin
        qsort(1,m); // -> sắp xếp danh sách cạnh theo thứ tự không giảm theo trọng số
        ans:=0; cnt:=0;
        for i:=1 to m do
            with e[i] do
                Begin
                    if is_same_set(u,v) then continue; // nếu u và v thuộc cùng 1 cây (chung gốc) thì bỏ qua cạnh này
                    inc(cnt); // tăng số lượng cạnh trong cây khung lên 1
                    inc(ans,w); // tăng trọng số của cây khung lên bằng trọng số của cạnh
                    join(u,v); // hợp nhất 2 cây chứa u và v
                    if cnt = n-1 then break; // nếu cây khung đã chứa n-1 cạnh thì thoát
                End;
        writeln(ans);
    End;
//==============================
BEGIN
    randomize;
    docfile;
    init;
    Kruskal;
END.
