Uses Matj;
Const fi='BDXau.inp';
Var L:array[0..255,0..255] of integer;
    s1,s2:string;
    n,m:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:Text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,s1);
        readln(f,s2);
        n:=length(s1); m:=length(s2);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        for i:=0 to n do L[n,0]:=i;
        for i:=0 to m do L[0,m]:=i;
        for i:=1 to n do
            for j:=1 to m do
                if s1[i]=s2[j] then L[i,j]:=L[i-1,j-1]
                else L[i,j]:=min(L[i-1,j-1]+1 , min(L[i,j-1]+1 , L[i-1,j]+1));
        writeln(L[n,m]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.