Const fi='NIM.inp';
      fo='NIM.out';
Var a:array[1..20000] of integer;
    n,w:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        if w=0 then write(f,'0')
        else write(f,'1');
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:integer;
    Begin
        w:=0 xor a[1];
        for i:=2 to n do w:=w xor a[i];
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
    xuat;
END.