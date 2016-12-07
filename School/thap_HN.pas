Uses crt;
Var n:integer;
//------------------------------
Procedure try(d,tg,c,i:integer);
   Begin
        if i=1 then writeln('Chuyen 1 dia tu ',d,' sang ',c)
        else Begin
                  try(d,c,tg,i-1);
                  try(d,tg,c,1);
                  try(tg,d,c,i-1);
             End;
   End;
//==============================
BEGIN
     clrscr;
     write('Nhap N: ');readln(n);
     try(1,2,3,n);
     readln;
END.
