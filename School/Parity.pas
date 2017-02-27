Const fi='Parity.inp';
      fo='Parity.out';
Var a,L:array[-1000000..1000000] of longint;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            read(f,a[i]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,c:longint;
        ans:int64;
        f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        fillchar(L, sizeof(L), 0);
        c:=0; L[0]:=1; ans := 0;
        for i:=1 to n do
            Begin
                if odd(a[i]) then inc(c)
                else dec(c);
                inc(ans, L[c]);
                inc(L[c]);
            End;
        writeln(f,ans);
        close(f);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
