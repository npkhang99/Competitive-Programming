Const fi='ELECTRIC.inp';
      fo='ELECTRIC.out';
      maxN=1000;
      maxM=2000;
Type electric=Record
        u,v,val,tt:integer;
     End;
Var G:array[1..maxM] of electric;
    C:array[1..maxM] of boolean;
    D:array[1..maxN] of boolean;
    n,m:integer;
//------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to m do
            with G[i] do
                 Begin
                      readln(f,u,v,val);
                      tt:=i;
                 End;
        close(f);
   End;
//------------------------------
Procedure doi1(var a,b:electric);
   Var t:electric;
   Begin
        t:=b;
        b:=a;
        a:=t;
   End;
//------------------------------
Procedure doi2(var a,b:boolean);
   Var t:boolean;
   Begin
        t:=b;
        b:=a;
        a:=t;
   End;
//------------------------------
Procedure QSort2(l,r:integer);
   Var i,j,x:integer;
   Begin
        i:=l;j:=r;
        x:=G[(i+j) div 2].tt;
        repeat
              while G[i].tt<x do inc(i);
              while G[j].tt>x do dec(j);
              if i<=j then
                 Begin
                      doi1(G[i],G[j]);
                      doi2(C[i],C[j]);
                      inc(i);
                      dec(j);
                 End;
        until i>j;
        if i<r then QSort2(i,r);
        if j>l then QSort2(l,j);
   End;
//------------------------------
Procedure xuat(x:integer);
   Var f:text;
       i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        QSort2(1,n-1);
        writeln(f,x);
        for i:=1 to n-1 do
            if C[i] then writeln(f,G[i].tt);
        close(f);
   End;
//------------------------------
Procedure QSort1(l,r:integer);
   Var x,i,j:integer;
   Begin
        i:=l;j:=r;
        x:=G[(i+j) div 2].val;
        repeat
              while G[i].val>x do inc(i);
              while G[j].val<x do dec(j);
              if i<=j then
                 Begin
                      doi1(G[i],G[j]);
                      inc(i);
                      dec(j);
                 End;
        until i>j;
        if i<r then QSort1(i,r);
        if j>l then QSort1(l,j);
   End;
//------------------------------
Procedure Kruskal;
   Var i,s,t:integer;
   Begin
        QSort1(1,m);
        fillchar(c,sizeof(c),false);
        fillchar(d,sizeof(d),false);
        T:=1;C[1]:=true;D[G[1].u]:=true;D[G[1].v]:=true;S:=G[1].val;
        repeat
              for i:=1 to m do
                  if (not C[i]) and (D[G[i].u] Xor D[G[i].v]) then
                     Begin
                          C[i]:=true;
                          D[G[i].u]:=true;
                          D[G[i].v]:=true;
                          inc(T);
                          S:=S+G[i].val;
                          break;
                     End;
        until T=N-1;
        xuat(s);
   End;
//==============================
BEGIN
     docfile;
     Kruskal;
END.
