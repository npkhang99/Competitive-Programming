Uses crt;
Var n,d:integer;
    s:string;
{-------------------}
Procedure xuat;
   Var j:integer;
   Begin
        if pos('11',s)=0 then 
		   Begin
		        inc(d);
				writeln(s);
			End;
   End;
{-------------------}
Procedure try(i:integer);
   var j:char;
   Begin
        if i>n then xuat
        else for j:='0' to '1' do
            begin
                 s[i]:=j;
                 try(i+1);
            end;
   End;
{===================}
BEGIN
     clrscr;
     write('Nhap N: ');readln(n);
     s:='0000';d:=0;
     try(1);
	 write(d);
     readln;
END.
