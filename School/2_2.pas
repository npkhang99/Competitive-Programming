Const fi='2_2.inp';
	  fo='2_2.out';
Var N:longint;
//------------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		read(f,n);
		close(f);
	End;
//------------------------------------------------------------
Procedure xuat;
	Var f:text;
		t,max,d,i:longint;
	Begin
		assign(f,fo);
		rewrite(f);
		t:=0;d:=0;i:=2;
		while n>1 do
			Begin
				while n mod i=0 do
					Begin
						write(f,i,' ');
						n:=n div i;
					End;
				inc(i);
			End;
		for i:=1 to n do
			if n mod i=0 then
				Begin
					inc(d);t:=t+i;
				End;
		writeln(f);
		writeln(f,d);
		writeln(f,t);
		close(f);
	End;
//============================================================
BEGIN
	docfile;
	xuat;
END.
