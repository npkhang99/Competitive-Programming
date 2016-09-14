// SPOJ submission 14844863 (PAS fpc) plaintext list. Status: AC, problem BCDAISY, contest PTIT. By mansblacks (Khang), 2015-08-08 03:13:37.
Var a:array[1..250,1..250] of integer;
    b:array[1..250] of boolean;
    n,m:integer;
//---------------------------------------------------------
Procedure doc;
    Var i,c1,c2:integer;
    Begin
        fillchar(a,sizeof(a),0);
        readln(n,m);
        for i:=1 to m do
            Begin
                readln(c1,c2);
                a[c1,c2]:=1;
                a[c2,c1]:=1;
            End;
    End;
//---------------------------------------------------------
Procedure DFS(i:integer);
    Var j:integer;
    Begin
        for j:=1 to n do
            if (not b[j]) and (a[i,j]=1) then
                Begin
                    b[j]:=true;
                    DFS(j);
                End;
    End;
//---------------------------------------------------------
Procedure xuat;
    Var i,d:integer;
    Begin
        d:=0;
        for i:=1 to n do
            if not b[i] then 
                Begin
                    writeln(i);
                    inc(d);
                End;
        if d=0 then write('0');
    End;
//=========================================================
BEGIN
    doc;
    fillchar(b,sizeof(b),false);
    b[1]:=true;
    DFS(1);
    xuat;
END.