// SPOJ submission 14763650 (PAS fpc) plaintext list. Status: AC, problem VSTEPS, contest SPOJVN. By mansblacks (Khang), 2015-07-28 05:27:49.
Var a:array[0..100000] of longint;
    b:array[1..100000] of boolean;
    n,k:longint;
//---------------------------------------------------------
Procedure doc;
    Var i,tam:longint;
    Begin
        fillchar(b,sizeof(b),false);
        readln(n,k);
        for i:=1 to k do 
            Begin
                read(tam);b[tam]:=true;
            End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:longint;
    Begin
        a[1]:=1;a[0]:=0;
        for i:=2 to n do
            if b[i] then a[i]:=0
            else a[i]:=(a[i-1]+a[i-2]) mod 14062008;
        write(a[n]);
    End;
//=========================================================
BEGIN
    doc;
    xuly;
END.