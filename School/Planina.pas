Const fi='Planina.inp';
      fo='Planina.out';
Var n:integer;
//---------------------------------------------------------
Procedure doc;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:int64);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x); write(x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:integer;
        point:int64;
    Begin
        point:=2;
        for i:=1 to n do point:=2*point-1;
        xuat(point*point);
    End;
//---------------------------------------------------------
BEGIN
    doc;
    xuly;
END.