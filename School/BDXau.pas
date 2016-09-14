Uses Math;
Const fi='BDXau.inp';
      fo='BDXau.out';
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
Procedure xuat(x:integer);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        for i:=0 to n do L[i,0]:=i;
        for i:=0 to m do L[0,i]:=i;
        for i:=1 to n do
            for j:=1 to m do
                if s1[i]=s2[j] then L[i,j]:=L[i-1,j-1]
                else L[i,j]:=min(L[i-1,j-1]+1 , min(L[i,j-1]+1 , L[i-1,j]+1));
        xuat(L[n,m]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.