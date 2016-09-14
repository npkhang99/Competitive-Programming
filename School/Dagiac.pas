Uses Math;
Const fi='DaGiac.inp';
      fo='DaGiac.out';
Var c:array[0..100,0..4] of qword;
    n:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,c[n,4]); write(c[n,4]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        for i:=0 to n do
            Begin
                c[i,0]:=1;
                if i<=4 then c[i,i]:=1;
            End;
        for i:=2 to n do
            for j:=1 to min(4,i-1) do
                c[i,j]:=c[i-1,j-1]+c[i-1,j];
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.