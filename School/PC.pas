Const fi='PC.inp';
	  fo='PC.out';
Var a:array[1..100,1..100] of integer;
	b:array[1..100] of boolean;
	c,d:array[1..100] of integer;
	n,tmin:integer;
//----------------------------------------------------------
Procedure docfile;
	Var f:text;
		i,j:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			Begin
				for j:=1 to n do read(f,a[i,j]);
				readln(f);
			End;
		close(f);
	End;
//----------------------------------------------------------
Procedure xuat;
	Var f:text;
		i:integer;
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,tmin);
		for i:=1 to n do write(f,d[i],' ');
		close(f);
	End;
//----------------------------------------------------------
Procedure ktra(t:integer);
	Begin
		if (t < tmin) then
			Begin
				d:=c;tmin:=t;
			End;
	End;
//----------------------------------------------------------
Procedure PC(i,t:integer);
	Var j:integer;
	Begin
		if t>=tmin then exit;
		if i>n then ktra(t)
		else for j:=1 to n do
				if (not b[j]) then
					Begin
						c[i]:=j;b[j]:=true;
						PC(i+1,t+a[i,j]);
						b[j]:=false;
					End;
	End;
//==========================================================
BEGIN
	docfile;
	fillchar(b,sizeof(b),false);
	tmin:=maxint;
	PC(1,0);
	xuat;
END.