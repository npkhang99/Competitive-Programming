Const fi='Parity.inp';
      fo='Parity.out';
Var a,L:array[0..100000] of longint;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        L[0]:=0;
        for i:=1 to n do
            Begin
                read(f,a[i]);
                if odd(a[i]) then L[i]:=L[i-1]+1
                else L[i]:=L[i-1]-1;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var
    Begin
        
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.