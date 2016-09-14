Const fi='BinBack.inp';
      fo='BinBack.out';
Var a:array[1..5000] of integer;
    b:array[1..5000] of boolean;
    n,m:integer;
//----------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do read(f,a[i]);
        close(f);
    End;
//----------------------------------------------------------
Procedure doi(var x,y:integer);
    Var tam:integer;
    Begin
        tam:=x;
        x:=y;
        y:=tam;
    End;
//----------------------------------------------------------
Procedure QSort(l,r:integer);
    Var i,j,x:integer;
    Begin
        i:=l;j:=r;x:=a[(i+j) div 2];
        repeat
            while a[i]>x do inc(i);
            while a[j]<x do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    inc(i);dec(j);
                End;
        until i>j;
        if l<j then QSort(l,j);
        if r>i then QSort(i,r);
    End;
//----------------------------------------------------------
Procedure xuat(s:integer);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,s);
        close(f);
    End;
//----------------------------------------------------------
Procedure Greedy;
    Var i,j,t,d:integer;
    Begin
        QSort(1,n);
        fillchar(b,sizeof(b),false);
        d:=0;
        for i:=1 to n do
            if not b[i] then
                Begin
                    t:=0;
                    if a[i]<=m then
                        Begin
                            t:=a[i];b[i]:=true;
                        End;
                    for j:=i+1 to n do
                        if (a[j]<=m-t) and (not b[j]) then
                            Begin
                                t:=t+a[j];
                                b[j]:=true;
                            End;
                    inc(d);
                End;
        xuat(d);
    End;
//==========================================================
BEGIN
    docfile;
    Greedy;
END.
