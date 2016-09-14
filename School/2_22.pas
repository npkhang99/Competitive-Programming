Const fi='2_22.inp';
      fo='2_22.out';
Var a:array['A'..'Z'] of integer;
    s:string;
//--------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,st);
        close(f);
    End;
//--------------------------------------------------------
Procedure xuat;
    Var 
    Begin
        
    End;
//========================================================
BEGIN
    docfile;
    xuat;
END.