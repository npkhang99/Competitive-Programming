Const fi='Tours.inp';
      fo='Tours.out';
Type canh=Record
        u,v:integer;
     End;
Var a:array[1..20000] of canh;
    b:array[1..20000] of boolean;
    T,h,ad:array[0..40000] of integer;
    tr:array[1..20000] of integer;
    n,m,d:integer;
    f:text;
//---------------------------------------------------------
Procedure chuyen;
    Var i:integer;
    Begin
        for i:=1 to n do
            h[i]:=h[i-1]+h[i];
        for i:=1 to m do
            with a[i] do
                Begin
                    ad[h[u]]:=v;
                    ad[h[v]]:=u;
                    dec(h[u]);
                    dec(h[v]);
                End;
        h[n+1]:=2*m;
    End;
//---------------------------------------------------------
Procedure hopnhat(x,y:integer);
    Var k,j:integer;
    Begin
        if T[x]<>T[y] then
            Begin
                inc(d);
                k:=T[y];
                for j:=1 to n do
                    if T[j]=k then T[j]:=T[x];
            End;
    End;
//---------------------------------------------------------
Procedure docfile;
    Var i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        d:=0; h[0]:=0;
        for i:=1 to n do T[i]:=i;
        for i:=1 to m do
            Begin
                readln(f,a[i].u,a[i].v);
                hopnhat(a[i].u,a[i].v);
                inc(h[a[i].u]);
                inc(h[a[i].v]);
            End;
        d:=n-d;
        chuyen;
        close(f);
    End;
//---------------------------------------------------------

//---------------------------------------------------------
Procedure DFS(i:integer);
    Var j:integer;
    Begin
        
    End;
//---------------------------------------------------------
Procedure xuly;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,m-n+d);
        fillchar(b,sizeof(b),0);
        for j:=1 to n do
            Begin
                tr[1]:=i;
                DFS(2);
            End;
        close(f);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
