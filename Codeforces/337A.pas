Uses Math;
Var a:array[1..50] of integer;
    n,m:integer;
//---------------------------------------------------------
Procedure doc;
    Var i:integer;
    Begin
        readln(n,m);
        for i:=1 to m do
            read(a[i]);
    End;
//---------------------------------------------------------
Procedure doi(Var a,b:integer);
    Var tam:integer;
    Begin
        tam:=a;
        a:=b;
        b:=tam;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:integer);
    Var i,j,x:integer;
    Begin
        i:=l; j:=r; x:=a[(i+j) div 2];
        repeat
            while a[i]<x do inc(i);
            while a[j]>x do dec(j);
            if i<=j then
                Begin
                    doi(a[i], a[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if l<j then QSort(l,j);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,Amin,Amax,kq:integer;
    Begin
        kq:=maxint;
        QSort(1,m);
        for i:=n to m do
            Begin
                Amin:=maxint; Amax:=-maxint;
                for j:=(i-n+1) to i do
                    Begin
                        Amin:=min(Amin, a[j]);
                        Amax:=max(Amax, a[j]);
                    End;
                kq:=min(kq, Amax-Amin);
            End;
        write(kq);
    End;
//=========================================================
BEGIN
    doc;
    xuly;
END.
