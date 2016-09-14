Const fi='Pro.inp';
      fo='Pro.out';
Var k,l,m,n:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,k,n,m,l);
        close(f);
    End;
//---------------------------------------------------------
Function lthua(x:integer):longint;
//=========================================================
BEGIN
    docfile;
    xuly;
END.