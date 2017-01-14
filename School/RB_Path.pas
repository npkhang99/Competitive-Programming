Const fi='RB_Path.inp';
      fo='RB_Path.out';
Var a:array[1..1000,1..1000] of longint;
    c:array[1..1000,1..1000] of boolean;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j,tam,x,y,tt,m:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
            for j:=1 to n do
                if i=j then a[i,j]:=0
                else a[i,j]:=maxlongint;
        for i:=1 to m do
            Begin
                readln(f,x,y,tam,tt);
                a[x,y]:=tam; a[y,x]:=tam;
                if tt=0 then c[x,y]:=false
                else c[x,y]:=true;
                c[y,x]:=c[x,y];
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x); write(x);
        close(f);
        halt;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var b,tt:array[1..1000] of boolean;
        L:array[1..1000] of longint;
        i,u,v,Lmin:longint;
    Begin
        fillchar(b,sizeof(b),false);
        for i:=1 to n do
            Begin
                L[i]:=a[1,i];
                tt[i]:=c[1,i];
            End;
        b[1]:=true;
        repeat
            Lmin:=maxlongint; u:=0;
            for i:=1 to n do
                if (not b[i]) and (L[i]<Lmin) then
                    Begin
                        Lmin:=L[i];
                        u:=i;
                    End;
            if u=0 then xuat(-1);
            for v:=1 to n do
                if (not b[v]) and (a[u,v]<maxlongint) and (L[v]>L[u]+a[u,v]) and (c[u,v] xor tt[u]) then
                    Begin
                        L[v]:=L[u]+a[u,v];
                        tt[v]:=c[u,v];
                    End;
            b[u]:=true;
        until b[n];
        xuat(L[n]);
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
END.
