Const fi='xaunp.inp';
      fo='xaunp.out';
Var a:array[1..202,1..2000] of string;
    b:array[0..202] of longint;
    n,m:integer;
    s:string;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        t:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,t,n,m);
        read(f,t,s);
                delete(s,1,1);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(st:string;x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,st);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure fibo;
    Var i:integer;
    Begin
        b[0]:=1;b[1]:=2;
        for i:=2 to n do b[i]:=b[i-1]+b[i-2];
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,vt:longint;
    Begin
        fibo;
        a[1,1]:='0';a[1,2]:='1';vt:=0;
        for i:=2 to n do
            for j:=1 to b[i] do
                Begin
                    if j<=b[i-1] then a[i,j]:='0'+a[i-1,j]
                    else a[i,j]:='1'+a[i-1,j-b[i-1]];
                    if a[i,j]=s then vt:=j;
                End;
        xuat(a[n,m],vt);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
