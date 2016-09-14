Uses Math;
Const fi='DoiXung.inp';
      fo='DoiXung.out';
Var a:ansistring;
    n:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,a);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:integer);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var L:array[0..1000,0..1000] of integer;
        i,j:integer;
    Begin
        fillchar(L,sizeof(L),0);
        n:=length(a);
        for i:=1 to n do
            for j:=1 to n do
                if a[i]=a[n-j+1] then L[i,j]:=L[i-1,j-1]+1
                else L[i,j]:=max(L[i-1,j], L[i,j-1]);
        xuat(L[n,n]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.