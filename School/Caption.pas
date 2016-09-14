Const fi='Caption.inp';
      fo='Caption.out';
Var a:array[1..100,1..100] of longint;
    no:array[1..100] of longint;
    n,m,s,t:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j,tam,x,y:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,s,t);
        for i:=1 to n do
            Begin
                read(f,tam);
                if tam=0 then no[i]:=maxlongint
                else no[i]:=tam;
            End;
        for i:=1 to n do
            for j:=1 to n do
                if i=j then a[i,j]:=0
                else a[i,j]:=maxlongint;
        for i:=1 to m do
            Begin
                readln(f,x,y,tam);
                a[x,y]:=tam; a[y,x]:=tam;
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
    Var b:array[1..100] of boolean;
        L:array[1..100] of longint;
        i,u,v,Lmin:longint;
    Begin
        if s=t then xuat(0);
        fillchar(b,sizeof(b),false);
        for i:=1 to n do
            L[i]:=a[s,i];
        b[s]:=true;
        repeat
            Lmin:=maxlongint; u:=0;
            for i:=1 to n do
                if (not b[i]) and (L[i]<Lmin) and (L[i]<no[i]) then
                    Begin
                        Lmin:=L[i];
                        u:=i;
                    End;
            if u=0 then xuat(-1);
            for v:=1 to n do
                if (not b[v]) and (a[u,v]<maxlongint) and (L[v]>L[u]+a[u,v]) and (L[u]+a[u,v]<no[i]) then
                    L[v]:=L[u]+a[u,v];
            b[u]:=true;
        until b[t];
        xuat(L[t]);
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
END.