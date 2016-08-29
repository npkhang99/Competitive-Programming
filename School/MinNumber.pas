Const fi='MinNumber.inp';
	  fo='MinNumber.out';
Var s:string;
	k,n:byte;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,k);
		read(f,s);
		n:=length(s);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,s);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,d:integer;
	Begin
		d:=0; i:=1; s:=s+char(20);
		while d < n-k do
			Begin
				while (s[i]<=s[i+1]) and (i<=n) do inc(i);
				delete(s,i,1);
				dec(i);
				inc(d);
			End;
		delete(s,k+1,1);
		xuat;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.