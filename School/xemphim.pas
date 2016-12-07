Uses math;
Const fi='xemphim.inp';
      fo='xemphim.out';
Var a:array[1..5000] of integer;
    n,c:integer;
//----------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,c);
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
    Var i,j,t,tmax:integer;
    Begin
        QSort(1,n);
        t:=0;
        for i:=1 to n do
            if t+a[i]<=c then 
                Begin
                    t:=t+a[i];
                    if t+a[i]=c then break;
                End;
        xuat(t);
    End;
//==========================================================
BEGIN
    docfile;
    Greedy;
END.
