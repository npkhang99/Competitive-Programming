Const fi='BigC.inp';
	  fo='BigC.out';
Var a:array[1..1000] of longint;
	n,k:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,k);
		for i:=1 to n do read(f,a[i]);
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
Procedure doi(Var x,y:longint);
	Var tam:longint;
	Begin
		tam:=x;
		x:=y;
		y:=tam;
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var m,i,j:longint;
	Begin
		i:=l; j:=r; m:=a[(i+j) div 2];
		repeat
			while a[i]<m do inc(i);
			while a[j]>m do dec(j);
			if i<=j then
				Begin
					doi(a[i],a[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if i<r then qsort(i,r);
		if j>l then qsort(l,j);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var b:array[1..1000] of boolean;
		i,j,d,w:longint;
	Begin
		fillchar(b,sizeof(b),false);
		qsort(1,n); d:=0;
		for i:=n downto 1 do
			if not b[i] then
				Begin
					w:=a[i]; inc(d);
					for j:=i-1 downto 1 do
						if (w+a[j]<=k) and (not b[j]) then
							Begin
								w:=w+a[j];
								b[j]:=true;
							End;
				End;
		xuat(d);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.