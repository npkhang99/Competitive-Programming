Const fi='Balo.inp';
      fo='Balo.out';
Type balo=Record
        val,wei,tt:integer;c:real;
     End;
Var a:array[1..100] of balo;
    b,c:array[1..100] of integer;
    n,wmax,tmax:integer;
    ctmax:real;
//----------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,wmax);
        for i:=1 to n do
            with a[i] do read(f,val);
        readln(f);
        for i:=1 to n do
            with a[i] do
                Begin
                    read(f,wei);
                    c:=val/wei;
                    tt:=i;
                End;
        close(f);
    End;
//----------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,tmax);
        for i:=1 to n do write(f,c[i],' ');
        writeln(f);
        for i:=1 to n do write(f,a[i].tt,' ');
        close(f);
    End;
//----------------------------------------------------------
Procedure doi(var x,y:balo);
    Var tam:balo;
    Begin
        tam:=y;
        y:=x;
        x:=tam;
    End;
//----------------------------------------------------------
Procedure QSort(l,r:integer);
    Var i,j:integer;
        x:real;
    Begin
        i:=l;j:=r;x:=a[(i+j) div 2].c;
        repeat
            while a[i].c>x do inc(i);
            while a[j].c<x do dec(j);
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
Procedure ktra(t:integer;ct:real);
    Begin
        if t>tmax then
            Begin
                c:=b;
                tmax:=t;
                ctmax:=ct;
            End;
    End;
//----------------------------------------------------------
Procedure BL(i,t,w:integer;ct:real);
    Var j,x,y:integer;
        z:real;
    Begin
        if ct<ctmax then exit;
        if i>n then ktra(t,ct)
        else for j:=(w div a[i].wei) downto 0 do
                Begin
                    b[i]:=j;
                    x:=t+a[i].val*j;
                    y:=w-a[i].wei*j;
                    if i<n then z:=x+y*a[i+1].c
                    else z:=x+y;
                    BL(i+1,x,y,z);
                End;
    End;
//==========================================================
BEGIN
    docfile;
    QSort(1,n);
    tmax:=0;ctmax:=0;
    BL(1,0,wmax,wmax*a[1].c);
    xuat;
END.
