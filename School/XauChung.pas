Uses Math;
Const fi='XauChung.inp';
      fo='XauChung.out';
Var s1,s2:string;
    L:array[0..255,0..255] of integer;
    n,m:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,s1);
        readln(f,s2);
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
        n:=length(s1); m:=length(s2);
        fillchar(L,sizeof(L),0);
        for i:=1 to n do
            for j:=1 to m do
                if s1[i]=s2[j] then L[i,j]:=L[i-1,j-1]+1
                else L[i,j]:=max(L[i-1,j] , L[i,j-1]);
        xuat(L[n,m]);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
