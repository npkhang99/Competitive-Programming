Const fi='Buying.inp';
      fo='Buying.out';
Type keo=Record
        val,sl:qword;
     End;
Var a:array[1..100000] of keo;
    n:longint;
    s:qword;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,s);
        for i:=1 to n do
            with a[i] do
                Begin
                    readln(f,val,sl);
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:qword);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure doi(Var x,y:keo);
    Var tam:keo;
    Begin
        tam:=x;
        x:=y;
        y:=tam;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:longint);
    Var i,j:longint;
        m:qword;
    Begin
        i:=l; j:=r; m:=a[(i+j) div 2].val;
        repeat
            while a[i].val<m do inc(i);
            while a[j].val>m do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if l<j then QSort(l,j);
        if i<r then QSort(i,r);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:longint;
        d,t:qword;
    Begin
        QSort(1,n);
        d:=0;
        for i:=1 to n do
            Begin
                t:=s div a[i].val;
                if t>a[i].sl then t:=a[i].sl;
                d:=d+t;
                s:=s - a[i].val*t;
            End;
        xuat(d);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
