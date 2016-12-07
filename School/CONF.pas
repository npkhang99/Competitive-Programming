Const fi='CONF.inp';
      fo='CONF.out';
Type kenh=Record
        s1,s2,val:longint;
     End;
Var a,g,tr:array[1..100,1..100] of longint;
    d:array[1..1000000] of kenh;
    //tr:array[1..100] of integer;
    n,k1,k2,k3,u:integer;
    tong,sl,m:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j:longint;
    Begin
        assign(f,fi);
        reset(f);
        fillchar(a,sizeof(a),0);
        readln(f,n,m);
        for i:=1 to n do
            for j:=1 to n do
                if i=j then g[i,j]:=0
                else g[i,j]:=maxint;
        for i:=1 to m do
            with d[i] do
                Begin
                    read(f,s1,s2,val);
                    g[s1,s2]:=val; g[s2,s1]:=val;
                End;
        read(f,k1,k2,k3);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i,j:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,tong,' ',sl);
        for i:=1 to n-1 do
            for j:=i+1 to n do
                if a[i,j]=1 then writeln(f,i,' ',j);
        close(f);
    End;
//---------------------------------------------------------
Procedure Floyd;
    Var i,j,k:integer;
    Begin
        for i:=1 to n do
            for j:=1 to n do tr[i,j]:=j;
        for k:=1 to n do
            for i:=1 to n do
                for j:=1 to n do
                    if g[i,j]>g[i,k]+g[k,j] then
                        Begin
                            g[i,j]:=g[i,k]+g[k,j];
                            tr[i,j]:=tr[i,k];
                        End;
    End;
//---------------------------------------------------------
Procedure ddi(i:integer);
    Begin
        if i<>u then
            Begin
                if a[i,tr[i,u]]=0 then
                    Begin
                        tong:=tong+g[i,tr[i,u]];
                        inc(sl);
                    End;
                a[i,tr[i,u]]:=1; a[tr[i,u],i]:=1;
                ddi(tr[i,u]);
            End;
    End;
//---------------------------------------------------------
Procedure tim(Var u:integer);
    Var i,ss:longint;
    Begin
        ss:=maxint; u:=0;
        for i:=1 to n do
            if g[i,k1]+g[i,k2]+g[i,k3]<ss then
                Begin
                    ss:=g[i,k1]+g[i,k2]+g[i,k3];
                    u:=i;
                End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Begin
        Floyd;
        tim(u);
        ddi(k1); ddi(k2); ddi(k3);
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
    xuat;
END.
