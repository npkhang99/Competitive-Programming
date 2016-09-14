Uses Math;
Const fi='COMNET.inp';
      fo='COMNET.out';
Var T:array[1..5000] of word;
    n,m,d:dword;
//---------------------------------------------------------
Procedure hopnhat(x,y:word);
    Var j,k:word;
    Begin
        if T[x]<>T[y] then
            Begin
                inc(d);
                k:=T[y];
                for j:=1 to n do
                    if T[j]=k then T[j]:=T[x];
            End;
    End;
//---------------------------------------------------------
Procedure khoigan;
    Var i:word;
    Begin
        d:=0;
        for i:=1 to n do T[i]:=i;
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,u,v:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        khoigan;
        for i:=1 to m do
            Begin
                readln(f,u,v);
                hopnhat(min(u,v), max(u,v));
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i,u,v:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        u:=T[1]; v:=T[1];
        if n-d=1 then write(f,'0')
        else Begin
                writeln(f,n-d-1);
                for i:=1 to n do
                    if T[i]<>v then
                        Begin
                            v:=T[i];
                            writeln(f,u,' ',v);
                        End;
             End;
        close(f);
    End;
//=========================================================
BEGIN
    docfile;
    xuat;
END.
