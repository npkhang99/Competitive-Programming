//--- Nguyen Phuc Khang . 10 Tin
Const fi='matkhau.inp';
      fo='matkhau.out';
Var f1:text;
    n:byte;
    s:string[4];
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
Procedure try(i:byte);
   Var j:char;
   Begin
        if i>4 then writeln(f1,s)
        else for j:='A' to char(n+64) do
                 Begin
                      s[i]:=j;
                      try(i+1);
                 End;
   End;
//==============================
BEGIN
     assign(f1,fo);
     rewrite(f1);
     docfile;
     fillchar(s,sizeof(s),' ');
     try(1);
     close(f1);
END.