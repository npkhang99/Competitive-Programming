Uses Math;
Const fi='RTri.inp';
      fo='RTri.out';
Type diem=Record
        x,y:longint;
     End;
Var a:array[1..100000] of diem;
    dx,dy:array[1..100000] of int64;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do
                Begin
                    readln(f,x,y);
                    inc(dx[x]); inc(dy[y]);
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:int64);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x); write(x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var s:int64;
        i:longint;
    Begin
        s:=0;
        for i:=1 to n do
            with a[i] do s:=s+(dx[x]-1)*(dy[y]-1);
        xuat(s);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
