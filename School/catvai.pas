Uses math;
Const fi='catvai.inp';
	  fo='catvai.out';
Var n,m:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		read(f,n,m);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x:integer);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,d:integer;
	Begin
		d:=0;i:=n;j:=m;
		if n=m then
			Begin
				xuat(0);
				halt;
			End;
		repeat
			while i>j do 
				Begin
					i:=i-j;
					inc(d);
				End;
			while j>i do
				Begin
					j:=j-i;
					inc(d);
				End;
		until i=j;
		xuat(d+1);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.