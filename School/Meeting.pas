Const fi='Meeting.inp';
      fo='Meeting.out';
Type canh=Record
        u,v:integer;
     End;
Var a:array[1..1000] of canh;
    b:array[1..1000] of boolean;
    c,dem:array[0..1000] of byte;
    n,m:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        m:=0;
        while not eof(f) do
            Begin
                inc(m);
                with a[m] do readln(f,u,v);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,dem[0],' ',dem[1]);
        for i:=1 to n do
            if c[i]=0 then write(f,i,' ');
        writeln(f);
        for i:=1 to n do
            if c[i]=1 then write(f,i,' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure DFS(s,d:integer);
    Var j:integer;
    Begin
        b[s]:=true; c[s]:=d; inc(dem[d]);
        for j:=1 to m do
            with a[j] do
                if (b[u] xor b[v]) then
                    Begin
                        if not b[u] then DFS(u,1-d)
                        else DFS(v,1-d);
                    End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:integer;
    Begin
        fillchar(c,sizeof(c),0);
        fillchar(b,sizeof(b),false);
        for i:=1 to n do
            if not b[i] then
                if dem[0]<=dem[1] then DFS(i,0)
                else DFS(i,1);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.
