Const fi='SuaDuong.inp';
      fo='SuaDuong.out';
Var n,m,k:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,k);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        kq:int64;
    Begin
        assign(f,fo);
        rewrite(f);
        kq:=(m-n+1) div k;
        kq:=kq + (n-1+((m-n+1) mod k)) div k;
        if kq*k<>m then inc(kq);
        write(f,kq);
        close(f);
    End;
//=========================================================
BEGIN
    docfile;
    xuat;
END.