Const fi='Dulich.inp';
      fo='Dulich.out';
      infty=maxint;
Var G:array[1..100,1..100] of integer;
    C:array[1..100] of boolean;
    T,Nghiem:array[1..100] of integer;
    n,u,v,d,max,dmax:integer;
    f:text;
//-------------------------------
Procedure docfile;
   Var i,j,g1,g2:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,u,v);
        for i:=1 to n do
            for j:=1 to n do
                G[i,j]:=infty;
        while not eof(f) do
            Begin
                 readln(f,g1,g2,G[g1,g2]);
                 G[g2,g1]:=G[g1,g2];
            End;
        close(f);
   End;
//-------------------------------
Procedure xuat;
   Var i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,max);
        write(f,nghiem[1]);
        for i:=2 to dmax do
            write(f,'->',nghiem[i]);
        close(f);
   End;
//-------------------------------
Procedure toiuu;
   Var i,tam:integer;
   Begin
        tam:=infty;
        for i:=1 to d-1 do
            if tam>G[T[i],T[i+1]] then tam:=G[T[i],T[i+1]];
        if tam>max then
           Begin
                max:=tam;
                nghiem:=T;
                Dmax:=d;
           End;
   End;
//-------------------------------
Procedure DFS(i:integer);
   Var j:integer;
   Begin
        if i=v then toiuu
        else for j:=1 to n do
                 if (G[i,j]<infty) and (not C[j]) then
                    Begin
                         inc(d);
                         C[j]:=true;
                         T[d]:=j;
                         DFS(j);
                         dec(d);
                         C[j]:=false;
                    End;
   End;
//===============================
BEGIN
     docfile;
     d:=1;T[d]:=u;max:=0;Dmax:=0;
     fillchar(c,sizeof(c),false);
     C[u]:=true;
     DFS(u);
     xuat;
END.
