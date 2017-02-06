// Naive Dijkstra's algorithm
Const fi='Dijkstra.inp';
      fo='';
      infty=maxint;
Var G:array[1..1000,1..1000] of integer;
    L,Tr:array[1..1000] of integer;
    C:array[1..1000] of boolean;
    n,m,s,t:integer;
    f:text;
//------------------------------
Procedure docfile;
    Var i,j,x,y:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,s,t);
        for i:=1 to n do
            for j:=1 to n do
                if i=j then G[i,j]:=0
                else G[i,j]:=infty;
        for i:=1 to m do
            Begin
                readln(f,x,y,G[x,y]);
                G[y,x]:=G[x,y];
            End;
        close(f);
    End;
//------------------------------
Procedure ddi(u:integer);
    Begin
        if u=s then write(f,u)
        else Begin
                ddi(Tr[u]);
                write(f,' ',u);
             End;
    End;
//------------------------------
Procedure xuat;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,L[t]);
        ddi(t);
        close(f);
    End;
//------------------------------
Procedure Dijsktra;
    Var i,u,v,Lmin:integer;
    Begin
        for i:=1 to n do
            Begin
                L[i]:=G[s,i];
                Tr[i]:=s;
            End;
        fillchar(c,sizeof(c),false);
        c[s]:=true;
        Repeat
            u:=0;Lmin:=infty;
            for i:=1 to n do
                if (not c[i]) and (L[i]<Lmin) then
                    Begin
                        Lmin:=L[i];
                        u:=i;
                    End;
            for v:=1 to n do
                if (not c[v]) and (G[u,v]<infty) and (L[u]+G[u,v]<L[v]) then
                    Begin
                        L[v]:=L[u]+G[u,v];
                        Tr[v]:=u;
                    End;
            C[u]:=true;
        Until C[T];
    End;
//==============================
BEGIN
    docfile;
    Dijsktra;
    xuat;
END.
