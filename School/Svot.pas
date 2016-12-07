Uses Math;
Const fi='Svot.inp';
      fo='Svot.out';
Var a,L,tr:array[0..1000,0..1000] of longint;
    n,m:integer;
    f:text;
//---------------------------------------------------------
Procedure docfile;
    Var i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        fillchar(a,sizeof(a),0);
        for i:=1 to m do
            Begin
                for j:=1 to n do read(f,a[j,i]);
                readln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure trace(i,j:integer);
    Begin
        if (i>0) then
            Begin
                trace(i-1,j-tr[i,j]);
                writeln(f,i,' ',tr[i,j]);
            End;
    End;
//---------------------------------------------------------
Procedure xuat(x:integer);
    Var i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,x);
        trace(n,m);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,k:integer;
    Begin
        fillchar(L,sizeof(L),0);
        for i:=1 to n do
            for j:=1 to m do
                Begin
                    L[i,j]:=L[i-1,j]; tr[i,j]:=0;
                    for k:=0 to j do
                        if L[i,j]<L[i-1,j-k]+a[i,k] then
                            Begin
                                L[i,j]:=L[i-1,j-k]+a[i,k];
                                tr[i,j]:=k;
                            End;
                End;
        xuat(L[n,m]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
