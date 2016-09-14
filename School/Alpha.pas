Uses Math;
Const fi='Alpha.inp';
      fo='Alpha.out';
Type hang=Record
        v,val:integer;
     End;
Var a:array[1..1000] of hang;
    L:array[0..1000,0..1000] of longint;
    n,m:integer;
    t:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        t:=0;
        for i:=1 to n do
            with a[i] do 
                Begin
                    readln(f,v,val);
                    t:=t+val;
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        fillchar(L,sizeof(L),0);
        for i:=1 to n do
            for j:=1 to m do
                with a[i] do
                    if j>=v then L[i,j]:=max(L[i-1,j], L[i-1,j-v]+val)
                    else L[i,j]:=L[i-1,j];
        xuat(t-L[n,m]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.