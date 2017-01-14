Const fi='Valve.inp';
Var T:array[1..1000] of integer;
    n:integer;
//---------------------------------------------------------
Procedure khoigan;
    Var i:integer;
    Begin
        for i:=1 to 1000 do
            T[i]:=i;
    End;
//---------------------------------------------------------
Procedure hopnhat(a,b:integer);
    Var j,k:integer;
    Begin
        if T[a]<>T[b] then
            Begin
                k:=T[b];
                for j:=1 to n do
                    if T[j]=k then T[j]:=T[a];
            End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var f:text;
        i,u,k,v:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        khoigan;
        for i:=1 to n do
            Begin
                readln(f,u,v,k);
                if k=1 then hopnhat(u,v)
                else if T[u]<>T[v] then writeln('0')
                     else writeln('1');
            End;
        close(f);
    End;
//=========================================================
BEGIN
    xuly;
END.
