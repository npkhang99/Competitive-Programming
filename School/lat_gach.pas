Uses crt;
Var a:array[1..10000,1..10000] of longint;
    k,d:longint;
//------------------------------
Procedure cover(x,y,s,t:longint);
   Begin
        if s=2 then
           Begin
                inc(d);
                if t<>1 then a[x,y]:=d;
                if t<>2 then a[x,y+1]:=d;
                if t<>3 then a[x+1,y]:=d;
                if t<>4 then a[x+1,y+1]:=d;
                exit;
           End;
        if t=1 then
           Begin
                cover(x,y+s div 2,s div 2,3);
                cover(x+s div 2,y,s div 2,2);
                cover(x+s div 2,y+s div 2,s div 2,1);
                cover(x+s div 4,y+s div 4,s div 2,1);
           End;
        if t=2 then
           Begin
                cover(x,y,s div 2,4);
                cover(x+s div 2,y,s div 2,2);
                cover(x+s div 2,y+s div 2,s div 2,1);
                cover(x+s div 4,y+s div 4,s div 2,2);
           End;
        if t=3 then
           Begin
                cover(x,y,s div 2,4);
                cover(x,y+s div 2,s div 2,3);
                cover(x+s div 2,y+s div 2,s div 2,1);
                cover(x+s div 4,y+s div 4,s div 2,3);
           End;
        if t=4 then
           Begin
                cover(x,y,s div 2,4);
                cover(x+s div 2,y,s div 2,2);
                cover(x,y+s div 2,s div 2,3);
                cover(x+s div 4,y+s div 4,s div 2,4);
           End;
   End;
//------------------------------
Procedure xuat;
   Var i,j:integer;
   Begin
        for i:=1 to (1 shl k) do
            Begin
                 for j:=1 to (1 shl k) do write(a[i,j]:3);
                 writeln;
            End;
   End;
//==============================
BEGIN
     clrscr;
     write('Nhap K: ');readln(k);
     cover(1,1,1 shl k,2);
     xuat;
     readln;
END.
