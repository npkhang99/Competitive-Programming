// Finding Minimum Spanning Tree
// Worst case runtime: O(VE)
Const fi='Kruskal.inp';
      maxN=1000;
      maxM=2000;
Type Edge=Record
        u,v,val,tt:integer;
     End;
Var G:array[1..maxM] of Edge;
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
Procedure swap(var a,b:Edge);
    Var t:Edge;
    Begin
        t:=b;
        b:=a;
        a:=t;
    End;
//------------------------------
Procedure QSort(l,r:integer);
    Var x,i,j:integer;
    Begin
        i:=l;j:=r;
        x:=G[i + random(j-i+1)].val;
        repeat
            while G[i].val>x do inc(i);
            while G[j].val<x do dec(j);
            if i<=j then
                Begin
                    swap(G[i],G[j]);
                    inc(i);
                    dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if j>l then QSort(l,j);
    End;
//------------------------------
Procedure Kruskal;
    Var i,s,t:integer;
    Begin
        QSort(1,m);
        fillchar(c,sizeof(c),false);
        fillchar(d,sizeof(d),false);
        T:=1;
        C[1]:=true; D[G[1].u]:=true; D[G[1].v]:=true; S:=G[1].val;
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
        writeln(s);
    End;
//==============================
BEGIN
    docfile;
    Kruskal;
END.
