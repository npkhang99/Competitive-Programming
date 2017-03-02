{--- Nguyen Phuc Khang . 10 Tin ---}
Const fi='GAPNHAU.inp';
      fo='GAPNHAU.out';
Var G:array[1..10000,1..10000] of integer;
    L:array[1..10000] of longint;
    C:array[1..10000] of boolean;
    n,m,s1,s2,t:longint;
//------------------------------
Procedure docfile;
   Var f:text;
       i,j,g1,g2:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,s1,s2,t);
        for i:=1 to n do
            for j:=1 to n do
                G[i,j]:=maxint;
        for i:=1 to m do
            Begin
                 readln(f,g1,g2,G[g1,g2]);
                 G[g2,g1]:=G[g1,g2];
            End;
        close(f);
   End;
//------------------------------
Procedure xuat(x,y:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x,' ',y);
        close(f);
   End;
//------------------------------
Function dijkstra(s:longint):longint;
   Var i,u,v,Lmin:longint;
   Begin
        for i:=1 to n do
            L[i]:=G[s,i];
        fillchar(c,sizeof(c),false);
        C[s]:=true;
        repeat
              u:=0;Lmin:=maxint;
              for i:=1 to n do
                  if (not C[i]) and (L[i]<Lmin) then
                     Begin
                          Lmin:=L[i];
                          u:=i;
                     End;
              for v:=1 to n do
                  if (not C[v]) and (G[u,v]<maxint) and (L[v]>L[u]+G[u,v]) then
                     Begin
                          L[v]:=L[u]+G[u,v];
                     End;
              C[u]:=true;
        until C[t];
        dijkstra:=L[t];
   End;
//==============================
BEGIN
     docfile;
     xuat(dijkstra(s1),dijkstra(s2));
END.
