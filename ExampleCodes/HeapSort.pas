Const fi='Sort.inp';
Var a:array[1..1000000] of longint;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
            write(f,a[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure swap(Var x,y:longint);
    Begin
        x:=x+y;
        y:=x-y;
        x:=x-y;
    End;
//---------------------------------------------------------
Procedure DownHeap(i,n:longint);
    Var j:longint;
    Begin
        j:=2*i;
        if j>n then exit;
        if (j+1<=n) and (a[j+1]>a[j]) then j:=j+1;
        if a[i]<a[j] then
            Begin
                swap(a[i],a[j]);
                DownHeap(j,n);
            End;
    End;
//---------------------------------------------------------
Procedure HeapSort;
    Var i:longint;
    Begin
        for i:=n div 2 downto 1 do
            DownHeap(i,n);
        for i:=n downto 2 do
            Begin
                swap(a[1],a[i]);
                DownHeap(1,i-1);
            End;
    End;
//=========================================================
BEGIN
    docfile;
    HeapSort;
    xuat;
END.
