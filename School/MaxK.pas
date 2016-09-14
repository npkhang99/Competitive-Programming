Const fi='MaxK.inp';
      fo='MaxK.out';
Var a,L:array[0..1000000] of longint;
    n,k,Lmax:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        L[0]:=0; Lmax:=0;
        readln(f,n,k);
        for i:=1 to n do
            Begin
                read(f,a[i]);
                L[i]:=L[i-1]+a[i];
                if i<=k then Lmax:=Lmax+a[i];
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(vt:longint);
    Var f:text;
        i:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,Lmax);
        for i:=vt-k+1 to vt do
            write(f,a[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,vt:longint;
    Begin
        vt:=k;
        for i:=k+1 to n do
            if L[i]-L[i-k]>Lmax then
                Begin
                    vt:=i;
                    Lmax:=L[i]-L[k];
                End;
        xuat(vt);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.