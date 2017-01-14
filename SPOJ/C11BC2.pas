// SPOJ submission 14881373 (PAS fpc) plaintext list. Status: AC, problem C11BC2, contest SPOJVN. By mansblacks (Khang), 2015-08-13 05:56:19.
Const fi='';
Type canh=Record
        u,v:longint;
     End;
Var a,tv:array[1..100000] of canh;
    Adj,Head:array[0..100000] of longint;
    T:array[1..100000] of longint;
    b:array[1..100000] of boolean;
    n,m,dem,d:longint;
//---------------------------------------------------------
Procedure doc;
    Var f:text;
        i,k,x:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        fillchar(T,sizeof(T),0);
        d:=0;
        for i:=1 to n-1 do
            Begin
                readln(f,x,k);
                if k=1 then
                    Begin
                        inc(d);
                        a[d].u:=i+1;
                        a[d].v:=x;
                    End;
            End;
        for i:=1 to m do
            with tv[i] do
                readln(f,u,v);
        close(f);
    End;
//---------------------------------------------------------
Procedure chuyen;
    Var    i:longint;
    Begin
        fillchar(head,sizeof(head),0);
        for i:=1 to d do
            with a[i] do
                Begin
                    inc(Head[u]);
                    inc(Head[v]);
                End;
        for i:=1 to n do
            Head[i]:=Head[i-1]+Head[i];
        for i:=1 to d do
            with a[i] do
                Begin
                    Adj[Head[u]]:=v;
                    Adj[Head[v]]:=u;
                    dec(Head[u]);
                    dec(Head[v]);
                End;
        Head[n+1]:=d;
    End;
//---------------------------------------------------------
Procedure DFS(i:longint);
    Var j:longint;
    Begin
        b[i]:=true;
        T[i]:=dem;
        for j:=Head[i]+1 to Head[i+1] do
            if not B[Adj[j]] then DFS(Adj[j]);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:longint;
    Begin
        chuyen;
        fillchar(b,sizeof(b),false);
        dem:=0;
        for i:=1 to n do
            if not b[i] then
                Begin
                    inc(dem);
                    DFS(i);
                End;
        //for i:=1 to d do write(Head[i],' '); writeln;
        //for i:=1 to d do write(Adj[i],' '); writeln;
        //for i:=1 to n do write(T[i],' '); writeln;
        for i:=1 to m do
            with tv[i] do
                if T[u]=T[v] then writeln('NO')
                else writeln('YES');
    End;
//=========================================================
BEGIN
    doc;
    xuly;
END.
