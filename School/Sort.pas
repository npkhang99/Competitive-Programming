Const fi='';
	  fo='';
Var a:array[1..10000] of integer;
	b:array[0..3] of integer;
	n:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		b[0]:=0;
		for i:=1 to n do
			Begin
				read(f,a[i]);
				inc(b[a[i]]);
			End;
		for i:=1 to 3 do
			b[i]:=b[i-1]+b[i];
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
Procedure doi(var x,y:integer);
	Var tam:integer;
	Begin
		tam:=x;
		x:=y;
		y:=tam;
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,d:integer;
	Begin
		d:=0;
		for i:=1 to n-1 do
			for j:=i+1 to n do
				if (a[i]>a[j]) and (i in [b[a[j]-1]+1..b[a[j]]]) and (j in [b[a[i]-1]+1..b[a[i]]]) then
					Begin
						doi(a[i],a[j]);
						inc(d);
					End;
		for i:=1 to n-1 do
			for j:=i+1 to n do
				if a[i]>a[j] then
					Begin
						doi(a[i],a[j]);
						inc(d);
					End;
		xuat(d);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.