Const fi='ThanTien.inp';
      fo='ThanTien.out';
Type canh=Record
        u,v,val:longint;
     End;
Var G:array[1..100000] of canh;
    n,m:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to m do
            with g[i] do
                readln(f,u,v,val);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure doi(Var a,b:canh);
    Var t:canh;
    Begin
        t:=b;
        b:=a;
        a:=t;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:integer);
    Var i,j,x:integer;
    Begin
        i:=l; j:=r; x:=G[(i+j) div 2].val;
        repeat
            while G[i].val<x do inc(i);
            while G[j].val>x do dec(j);
            if i<=j then
                Begin
                    doi(G[i],G[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if j>l then QSort(l,j);
    End;
//---------------------------------------------------------
Procedure Kruskal(Var s:longint);
    Var b,c:array[1..100000] of boolean;
        i,t:longint;
    Begin
        fillchar(b,sizeof(b),false);
        c:=b;
        c[1]:=true; b[G[1].u]:=true; b[G[1].v]:=true; s:=G[1].val; t:=0;
        repeat
            for i:=1 to m do
                with G[i] do
                    if (not c[i]) and (b[u] xor b[v]) then
                        Begin
                            c[i]:=true;
                            b[u]:=true; b[v]:=true;
                            s:=s+val;
                            break;
                        End;
            inc(t);
        until T=n-1;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var s:longint;
    Begin
        QSort(1,m);
        Kruskal(s);
        xuat(s);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
