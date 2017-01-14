Const fi='';
Var n,k:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        
        close(f);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
