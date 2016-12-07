Uses Math;
Const fi='Choose.inp';
      fo='Choose.out';
Var a,b:array[0..10000] of longint;
    n,k:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        b[0]:=0;
        for i:=1 to n do
            Begin
                readln(f,a[i]);
                b[i]:=b[i-1]+a[i];
            End;;
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
    Var L:array[-1..10000] of longint;
        i,j:integer;
    Begin
        fillchar(L,sizeof(L),0);
        for i:=1 to k do L[i]:=b[i];
        for i:=k+1 to n do
            for j:=i downto i-k do
                L[i]:=max(L[i], L[j-1] + b[i]-b[j]);
        for i:=1 to n do write(L[i],' ');
        xuat(L[n]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
