Uses Math;
Const fi='Balo1.inp';
	  fo='Balo1.out';
Var a:array[1..500] of integer;
	L:array[0..500,0..500] of longint;
	n,m:integer;
	f:text;
//---------------------------------------------------------
Procedure docfile;
	Var i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m);
		for i:=1 to n do read(f,a[i]);
		close(f);
	End;
//---------------------------------------------------------
Procedure trace(i,j:integer);
	Begin
		if (i>0) and (j>0) then
			Begin
				if L[i,j]=L[i-1,j] then trace(i-1,j)
				else Begin
						trace(i-1,j-a[i]);
						write(f,a[i],' ');
					 End;
			End;
	End;
//---------------------------------------------------------
Procedure xuat(x:longint);
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,x);
		trace(n,m);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j:integer;
	Begin
		fillchar(L,sizeof(L),0);
		for i:=1 to n do
			for j:=1 to m do
				if a[i]<=j then L[i,j]:=max(L[i-1,j] , L[i-1,j-a[i]]+a[i])
				else L[i,j]:=L[i-1,j];
		xuat(L[n,m]);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.