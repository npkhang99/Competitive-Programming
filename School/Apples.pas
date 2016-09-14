Const fi='Apples.inp';
      fo='Apples.out';
Var a:array[1..1000000] of longint;
    n,m,k,l,r:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,m,k);
        readln(f,n);
        for i:=1 to n do readln(f,a[i]);
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
Function dichuyen(l,r,t:longint):shortint;
    Begin
        if t<l then exit(-1)
        else if t>r then exit(1)
        else exit(0);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var d,i:longint;
    Begin
        l:=1; r:=l+k-1; d:=0;
        for i:=1 to n do
            case dichuyen(l,r,a[i]) of
                -1:    Begin
                        d:=d+l-a[i];
                        l:=a[i]; r:=l+k-1;
                    End;
                1:    Begin
                        d:=d+a[i]-r;
                        r:=a[i]; l:=r-k+1;
                    End;
            End;
        xuat(d);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.