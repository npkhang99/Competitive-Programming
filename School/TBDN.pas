Uses Math;
Const fi='TBDN.inp';
	  fo='TBDN.out';
Var a:array[1..1000,1..1000] of integer;
	n,m:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i,j:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m);
		for i:=1 to n do
			Begin
				for j:=1 to m do read(f,a[i,j]);
				readln(f);
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x:longint);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var L:array[1..1000,1..1000] of longint;
		i,j:integer;
	Begin
		L[1,1]:=a[1,1];
		for i:=2 to m do
			L[1,i]:=L[1,i-1]+a[1,i];
		for i:=2 to n do
			L[i,1]:=L[i-1,1]+a[i,1];
		for i:=2 to n do
			for j:=2 to m do
				L[i,j]:=max(L[i-1,j], L[i,j-1]) + a[i,j];
		xuat(L[n,m]);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.