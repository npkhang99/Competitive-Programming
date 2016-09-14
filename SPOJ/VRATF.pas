// SPOJ submission 17402767 (PAS fpc) plaintext list. Status: AC, problem VRATF, contest SPOJVN. By mansblacks (Khang), 2016-07-31 06:24:16.
Const fi='';
      fo='';
Var n,k,d:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,d);
        close(f);
    End;
//---------------------------------------------------------
Procedure try(i:longint);
    Var x,y:longint;
    Begin
        if (i>0) then
            Begin
                if ((i+k) mod 2<>0) or (i<=k) then inc(d)
                else Begin
                        x:=(i-k) div 2;
                        y:=(i+k) div 2;
                        try(x); try(y);
                    End;
            End;
    End;
//=========================================================
BEGIN
    docfile;
    d:=0;
    try(n);
    xuat;
END.