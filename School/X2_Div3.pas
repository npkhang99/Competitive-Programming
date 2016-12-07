Const fi='X2_Div3.inp';
      fo='X2_Div3.out';
Var n:int64;
//------------------------------
Procedure docfile;
   Var f:text;
   Begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
   End;
//------------------------------
Procedure xuat(S:string);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,s);
        close(f);
   End;
//------------------------------
Procedure solve;
   Var s:string;
   Begin
        s:='';
        while n>1 do
              Begin
                   if odd(n) then
                      Begin
                           n:=n*3+1;
                           s:='/3'+s;
                      End
                   else Begin
                             n:=n div 2;
                             s:='*2'+s;
                        End;
              End;
        s:='1'+s;
        xuat(s);
   End;
//==============================
BEGIN
     docfile;
     solve;
END.
