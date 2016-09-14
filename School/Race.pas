Const fi='Race.inp';
      fo='Race.out';
Type ngua=Record
        v,tt:longint;
     End;
     mang=array[1..100000] of ngua;
Var a,b,st:mang;
    c:array[1..100000] of boolean;
    n,r:longint;
    f:text;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        fillchar(c,sizeof(c),false);
        for i:=1 to n do
            Begin
                read(f,a[i].v);
                a[i].tt:=i;
            End;
        for i:=1 to n do
            Begin
                read(f,b[i].v);
                b[i].tt:=i;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure doi(Var z,t:ngua);
    Var tam:ngua;
    Begin
        tam:=t;
        t:=z;
        z:=tam;
    End;
//---------------------------------------------------------
Procedure qsort(Var x:mang; l,r:longint);
    Var i,j,m:longint;
    Begin
        i:=l; j:=r; m:=x[(i+j) div 2].v;
        repeat
            while x[i].v<m do inc(i);
            while x[j].v>m do dec(j);
            if i<=j then
                Begin
                    doi(x[i],x[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if j>l then qsort(x,l,j);
        if i<r then qsort(x,i,r);
    End;
//---------------------------------------------------------
Procedure put(value:ngua);
    Begin
        inc(r);
        st[r]:=value;
    End;
//---------------------------------------------------------
Function get:ngua;
    Begin
        get:=st[r];
        dec(r);
    End;
//---------------------------------------------------------
Function rong:boolean;
    Begin
        exit(r<=0);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:longint;
    Begin
        qsort(a,1,n); qsort(b,1,n);
        r:=0; j:=1;
        for i:=1 to n do
            Begin
                while (a[i].v>b[j].v) and (j<=n) do
                    Begin
                        put(b[j]);
                        inc(j);
                    End;
                if (not rong) then
                    Begin
                        writeln(f,a[i].tt,' ',get.tt);
                        c[i]:=true;
                    End;
            End;
        for i:=j to n do put(b[i]);
        for i:=1 to n do
            if not c[i] then writeln(f,a[i].tt,' ',get.tt);
    End;
//=========================================================
BEGIN
    assign(f,fo);
    rewrite(f);
    docfile;
    xuly;
    close(f);
END.