Uses math;
Const fi='DAYCHUV.inp';
	  fo='DAYCHUV.out';
Var a,tang,giam:array[1..1000] of longint;
	n:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do 
			Begin
				readln(f,a[i]);
				tang[i]:=1;giam[i]:=1;
			End;
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
	Var maxx,i,j:integer;
	Begin
		maxx:=1;
		for i:=1 to n do
			for j:=1 to i-1 do
				Begin
					if a[i]<a[j] then tang[i]:=max(tang[i] , tang[j]+1);
					if a[n-i+1]<a[n-j+1] then giam[n-i+1]:=max(giam[n-i+1] , giam[n-j+1]+1);
				End;
		{for i:=n downto 1 do
			for j:=n downto i+1 do
				if a[i]<a[j] then giam[i]:=max(giam[i] , giam[j]+1);}
		for i:=1 to n do
			maxx:=max(maxx , min(giam[i],tang[i]));
		xuat(maxx+maxx-1);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.