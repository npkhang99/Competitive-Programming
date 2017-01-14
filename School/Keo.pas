Uses Math;
Const fi='Keo.inp';
      fo='Keo.out';
Var a:array[1..500] of longint;
    L:array[0..500,0..500] of longint;
    b:array[1..500] of boolean;
    n,k,t:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        t:=0;
        for i:=1 to n do 
            Begin
                read(f,a[i]);
                t:=t+a[i];
            End;
        k:=t div 2;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,L[n,k],' ',t-L[n,k]);
        for i:=1 to n do
            if not b[i] then write(f,a[i],' ');
        writeln(f);
        for i:=1 to n do
            if b[i] then write(f,a[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure trace(i,j:longint);
    Begin
        if (i>0) and (j>0) then
            Begin
                if L[i,j]=L[i-1,j] then trace(i-1,j)
                else Begin
                        b[i]:=true;
                        trace(i-1,j-a[i]);
                     End;
            End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:longint;
    Begin
        fillchar(L,sizeof(L),0);
        fillchar(b,sizeof(b),false);
        for i:=1 to n do
            for j:=1 to k do
                if j>=a[i] then L[i,j]:=max(L[i-1,j-a[i]]+a[i] , L[i-1,j])
                else L[i,j]:=L[i-1,j];
        trace(n,k);
        xuat;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
