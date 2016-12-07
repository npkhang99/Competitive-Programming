Uses Math;
Const fi='BongDa.inp';
      fo='BongDa.out';
Var a:array[1..1000,1..1000] of boolean;
    b:array[1..1000] of boolean;
    L:array[1..1000] of integer;
    n,k:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        ch:char;
        i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        fillchar(a,sizeof(a),0);
        for i:=1 to n do
            Begin
                for j:=1 to n do
                    Begin
                        read(f,ch);
                        if ch='1' then
                            Begin
                                a[i,j]:=true;
                            End;
                    End;
                readln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:integer);
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        if x<>n-1 then
            Begin
                write(f,'-1');
                close(f);
                halt;
            End;
        for i:=1 to n do write(f,L[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure DFS(u:integer);
    Var v:integer;
    Begin
        b[u]:=true;
        for v:=1 to n do
            if (not b[v]) and (a[u,v]) then DFS(v);
        L[k]:=u; dec(k);
    End;
//---------------------------------------------------------
Procedure topo;
    Var d:array[1..1000] of integer;
        u,i,j,v,dmax:integer;
    Begin
        fillchar(d,sizeof(d),0);
        k:=n; dmax:=0;
        for i:=1 to n do
            if not b[i] then DFS(i);
        for i:=1 to n-1 do
            for j:=i+1 to n do
                Begin
                    u:=L[i]; v:=L[j];
                    if (a[u,v]) and (d[v]<d[u]+1) then
                        Begin
                            d[v]:=d[u]+1;
                            dmax:=max(dmax, d[v]);
                        End;
                End;
        xuat(dmax);
    End;
//=========================================================
BEGIN
    docfile;
    topo;
END.
