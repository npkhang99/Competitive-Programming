Uses math;
Const fi='2_1.inp';
	  fo='2_1.out';
	  a:array[0..15] of string[4]=('0000','0001','0010','0011','0100','0101','0110','0111','1000','1001','1010','1011','1100','1101','1110','1111');
Var st,n:string;
//----------------------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,st);
		close(f);
	End;
//----------------------------------------------------------------------
Function doi(s:string):string;
	Var i:integer;
	Begin
		for i:=0 to 15 do
			if s=a[i] then
				Begin
					case i of 10:exit('A');
							  11:exit('B');
							  12:exit('C');
							  13:exit('D');
							  14:exit('E');
							  15:exit('F');
					else exit(char(i+48));
					End;
				End;
	End;
//----------------------------------------------------------------------
Function doi16:string;
	Var d,dm,i:integer;
		s:string;
	Begin
		d:=0;s:='';dm:=0;
		for i:=length(st) downto 1 do
			Begin
				if d<4 then
					Begin
						inc(d);
						s:=st[i]+s;
					End
				else Begin
						d:=1;inc(dm);
						doi16:=doi(s)+doi16;
						s:=st[i];
					 End;
			End;
		if d>0 then
			Begin
				while length(s)<4 do s:='0'+s;
				doi16:=doi(s)+doi16;
				inc(dm);
			End;
		delete(doi16,dm+1,length(doi16));
	End;
//----------------------------------------------------------------------
Procedure xuat;
	Var f:text;
		s:string;
	Begin
		assign(f,fo);
		rewrite(f);
		s:=doi16;
        write(f,s);
		close(f);
	End;
//======================================================================
BEGIN
	docfile;
	xuat;
END.
