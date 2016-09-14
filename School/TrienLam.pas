Uses math;
Const fi='TrienLam.inp';
      fo='TrienLam.out';
Type trienlam=record
        d,c,val:integer;
     End;
Var a:array[1..9999] of trienlam;
    b:array[1..9999] of longint;
    n,maxx:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        maxx:=0;
        for i:=1 to n do
            with a[i] do 
                Begin
                    readln(f,d,c);
                    val:=c-d;
                    b[i]:=val;
                    maxx:=max(maxx,b[i]);
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,maxx);
        close(f);
    End;
//---------------------------------------------------------
Procedure doi(var x,y:trienlam);
    Var tam:trienlam;
    Begin
        tam:=y;
        y:=x;
        x:=tam;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:integer);
    Var m,i,j,tam:integer;
    Begin
        i:=l;j:=r;m:=a[(i+j) div 2].c;
        repeat
            while a[i].c<m do inc(i);
            while a[j].c>m do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    tam:=b[j];b[j]:=b[i];b[i]:=tam;
                    inc(i);dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if l<j then QSort(l,j);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        QSort(1,n);
        for i:=2 to n do
            for j:=1 to i-1 do
                if ((a[i].d>=a[j].c) or (a[i].c<=a[j].d)) then
                    Begin
                        b[i]:=max(b[i] , b[j]+a[i].val);
                        maxx:=max(b[i],maxx);
                    End;
        xuat;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.