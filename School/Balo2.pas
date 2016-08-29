Uses Math;
Const fi='Balo2.inp';
	  fo='Balo2.out';
Type dovat=Record
		val,v:longint;
	 End;
Var a:array[1..500] of dovat;
	L:array[0..500,0..500] of longint;
	n,m:integer;
	f:text;
//---------------------------------------------------------
Procedure docfile;
	Var	i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m);
		for i:=1 to n do
			with a[i] do readln(f,v,val);
		close(f);
	End;
//---------------------------------------------------------
Procedure trace(i,j:integer);
	Begin
		if (i>0) and (j>0) then
			Begin
				if L[i,j]=L[i-1,j] then trace(i-1,j)
				else
					Begin
						trace(i-1,j-a[i].v);
						writeln(f,a[i].v,' ',a[i].val);
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
				with a[i] do
					if v<=j then L[i,j]:=max(L[i-1,j] , L[i-1,j-v]+val)
					else L[i,j]:=L[i-1,j];
		xuat(L[n,m]);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.