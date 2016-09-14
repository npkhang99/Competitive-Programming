Uses Math;
Const fi='Computer.inp';
      fo='Computer.out';
Type Comp=Record
        d,c,val:integer;
     End;
Var a:array[1..1000] of comp;
    L:array[1..1000] of longint;
    n:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do
                Begin
                    readln(f,d,c,val);
                    L[i]:=0;
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
Procedure doi(Var a,b:comp);
    Var t:comp;
    Begin
        t:=a;
        a:=b;
        b:=t;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:integer);
    Var i,j,x:integer;
    Begin
        i:=l; j:=r; x:=a[(i+j) div 2].c;
        repeat
            while a[i].c<x do inc(i);
            while a[j].c>x do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if j>l then QSort(l,j);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
        x:longint;
    Begin
        QSort(1,n);
        L[1]:=a[1].val; x:=L[1];
        for i:=2 to n do
            for j:=1 to i-1 do
                if (a[i].d>=a[j].c) and (L[i]<L[j]+a[i].val) then
                    Begin
                        L[i]:=L[j]+a[i].val;
                        x:=max(x, L[i]);
                    End;
        xuat(x);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.