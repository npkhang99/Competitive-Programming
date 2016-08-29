Const fi='Xedien.inp';
      fo='Xedien.out';
      infty=maxint;
Var G:array[1..1000,1..1000] of integer;
    L,nghiem:array[1..1000] of integer;
    C:array[1..1000] of boolean;
    n,m,s,k,d,t:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i,j,g1,g2:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,s,k);
        for i:=1 to n do
            for j:=1 to n do
                G[i,j]:=infty;
        for i:=1 to m do
            Begin
                 readln(f,g1,g2,G[g1,g2]);
                 G[g2,g1]:=G[g1,g2];
            End;
        close(f);
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
       i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to d do write(f,nghiem[i],' ');
        close(f);
   End;
//-------------------------------
Procedure Dijsktra;
   Var u,v,i,Lmin:integer;
   Begin
        for i:=1 to n do
            L[i]:=G[s,i];
        fillchar(c,sizeof(c),false);
        C[s]:=true;
        repeat
              Lmin:=infty;u:=0;
              for i:=1 to n do
                  if (not C[i]) and (L[i]<Lmin) then
                     Begin
                          Lmin:=L[i];
                          u:=i;
                     End;
              for v:=1 to n do
                  if (not c[v]) and (G[u,v]<infty) and (L[u]+G[u,v]<L[v]) then
                     L[v]:=L[u]+G[u,v];
              C[u]:=true;
        until C[t];
   End;
//===============================
BEGIN
     docfile;
     d:=0;
     for t:=1 to n do
         Begin
              Dijsktra;
              if 2*L[t]<=K then
                 Begin
                      inc(d);
                      nghiem[d]:=t;
                 End;
         End;
     xuat;
END.