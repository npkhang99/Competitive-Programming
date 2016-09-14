Const fi='DFS.inp';
Var a:array[1..1000,1..1000] of integer;
    b:array[1..1000] of boolean;
    n,m:integer;

Procedure doc;
    Var i,j,x,y:integer;
        f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
            for j:=1 to n do a[i,j]:=0;
        for i:=1 to m do
            Begin
                read(f,x,y);
                a[x,y]:=1;
                a[y,x]:=1;
            End;
        close(f);
    End;

Procedure DFS(u:integer);
    Var v:integer;
    Begin
        if b[u] then exit;
        write(u,' ');
        b[u]:=true;
        for v:=1 to n do
            if (a[u,v]=1) and (not b[v]) then DFS(v);
    End;

BEGIN
    doc;
    fillchar(b,sizeof(b),false);
    DFS(1);
END.