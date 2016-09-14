Uses Math;
Const fi='MaKhoa.inp';
      fo='MaKhoa.out';
Var a,b,t:array[1..301] of longint;
    n,k,m:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do read(f,a[i]);
        readln(f);
        for i:=1 to n do read(f,b[i]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x); write(x);
        close(f);
    End;
//---------------------------------------------------------
Procedure add(Var x:longint);
    Begin
        inc(x);
        if x>k then x:=0;
    End;
//---------------------------------------------------------
Function chenh(x:integer):longint;
    Begin
        if a[x]=b[x] then exit(0)
        else if a[x]<b[x] then exit(b[x]-a[x])
        else exit(k-a[x]+b[x]+1);
    End;
//---------------------------------------------------------
Procedure chuyen;
    Var j:integer;
    Begin
        for j:=n downto 1 do
            a[j+1]:=a[j];
        a[1]:=a[n+1];
    End;
//---------------------------------------------------------
Function tinh(x:integer):longint;
    Var tam:longint;
    Begin
        tam:=a[x]+m;
        if tam=b[x] then exit(0)
        else if tam<b[x] then exit(b[x]-tam)
        else exit(k-tam+b[x]+1);
    End;
//---------------------------------------------------------
Procedure taoT;
    Var j:integer;
    Begin
        for j:=1 to n do
            Begin
                t[j]:=chenh(j);
            End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,dmin,d,h:longint;
    Begin
        dmin:=maxlongint;
        for i:=1 to n do
            Begin
                if i>1 then chuyen;
                taoT;
                for j:=1 to n do
                    Begin
                        m:=t[j];
                        d:=i-1+m;
                        for h:=1 to n do
                            d:=d+tinh(h);
                        dmin:=min(dmin, d);
                    End;
            End;
        xuat(dmin);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.