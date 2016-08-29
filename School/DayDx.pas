Uses Math;
Const fi='DayDx.inp';
	  fo='DayDx.out';
Var a:array[1..5000] of integer;
	L:array[0..5000,0..5000] of integer;
	b:array[1..5000] of boolean;
	n:integer;
	f:text;
//---------------------------------------------------------
Procedure docfile;
	Var i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do read(f,a[i]);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
		i:integer;
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,L[1,n]);
		for i:=1 to n do
			if b[i] then write(f,a[i],' ');
		close(f);
	End;
//---------------------------------------------------------
Procedure ddi(i,j:integer);
	Begin
		if (i<=j) then
			Begin
				if a[i]=a[j] then
					Begin
						b[i]:=true; b[j]:=true;
						ddi(i+1,j-1);
					End
				else if L[i,j]=L[i+1,j] then ddi(i+1,j)
				else ddi(i,j-1);
			End;
	End;
//---------------------------------------------------------
Procedure khoigan;
	Var i:integer;
	Begin
		for i:=1 to n do
			Begin
				L[i,i]:=1;
				b[i]:=false;
			End;
	End;
//---------------------------------------------------------
Procedure taobang;
	Var i,j:integer;
	Begin
		khoigan;
		for i:=n-1 downto 1 do
			for j:=i+1 to n do
				if a[i]=a[j] then L[i,j]:=L[i+1,j-1]+2
				else L[i,j]:=max(L[i+1,j], L[i,j-1]);
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		taobang;
		ddi(1,n);
		xuat;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.
