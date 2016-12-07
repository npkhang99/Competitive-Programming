Const fi='TruDan.inp';
      fo='TruDan.out';
Var a,s:array[0..1000000] of integer;
    n,m:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        m:=0;
        while not seekeof(f) do
            Begin
                inc(m); read(f,s[m]);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,a[n]); write(a[n]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
            if a[i]=0 then
                for j:=1 to m do
                    if (i-s[j]>=0) and (a[i-s[j]]=0) then
                        Begin
                            a[i]:=1;
                            break;
                        End;
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
    xuat;
END.
