Const fi='TamPhan.inp';
	  fo='TamPhan.out';
Type dinh=Record
		x,y:real;
	 End;
Var a:array[1..50] of dinh;
	tr:array[1..50,1..50] of byte;
	d,L:array[1..50,1..50] of real;
	n:byte;
	f:text;
//---------------------------------------------------------
Procedure docfile;
	Var i:byte;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			with a[i] do readln(f,x,y);
		close(F);
	End;
//---------------------------------------------------------
Procedure ddi(i,j:byte);
	Begin
		if j>=i+3 then
			Begin
				if d[i,tr[i,j]]>0 then writeln(f,i,' ',tr[i,j]);
				if d[tr[i,j],j]>0 then writeln(f,tr[i,j],' ',j);
				ddi(i,tr[i,j]);
				ddi(tr[i,j],j);
			End;
	End;
//---------------------------------------------------------
Procedure xuat;
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,L[1,n]:0:4);
		ddi(1,n);
		close(f);
	End;
//---------------------------------------------------------
Procedure tinhkc;
	Var i,j:byte;
	Begin
		for i:=1 to n do
			for j:=i to n do
				if (abs(i-j)=1) or (i-j=0) then d[i,j]:=0
				else Begin
						d[i,j]:=sqrt(sqr(a[i].x-a[j].x) + sqr(a[i].y-a[j].y));
						d[j,i]:=d[i,j];
					 End;
	End;
//---------------------------------------------------------
Procedure taobang;
	Var i,j,k,Kmin:byte;
		Lmin:real;
	Begin
		fillchar(L,sizeof(L),0);
		for i:=n downto 1 do
			for j:=i to n do
				if j<i+3 then
					Begin
						L[i,j]:=0;
						tr[i,j]:=0;
					End
				else Begin
						Lmin:=maxint; kmin:=0;
						for k:=i+1 to j-1 do
							if L[i,k]+L[k,j]+d[i,k]+d[k,j] < Lmin then
								Begin
									Lmin:=L[i,k]+L[k,j]+d[i,k]+d[k,j];
									Kmin:=k;
								End;
						L[i,j]:=Lmin; tr[i,j]:=kmin;
					 End;
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		tinhkc;
		taobang;
		xuat;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.
