Uses Math;
Const fi='CatTon.inp';
	  fo='CatTon.out';
Var L:array[0..30, 0..30, 0..50] of int64;
	n,m,k:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		read(f,n,m,k);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:Text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,L[n,m,k]); write(L[n,m,k]);
		close(f);
	End;
//---------------------------------------------------------
Function try(nn,mm,uu:integer):int64;
	Var i,u:integer;
	Begin
		if L[nn, mm, uu]<maxlongint then exit(L[nn, mm, uu]);
		if uu=0 then
			Begin
				L[nn, mm, uu]:=0;
				exit(0);
			End;
		if nn*mm=uu then
			Begin
				L[nn, mm, uu]:=0;
				exit(0);
			End;
		if (nn*nn=uu) or (mm*mm=uu) then
			Begin
				L[nn, mm, uu]:=min(nn*nn, mm*mm);
				exit(L[nn, mm, uu]);
			End;
		if (nn*mm<uu) then
			Begin
				L[nn, mm, uu]:=maxlongint;
				exit(maxlongint);
			End;
		//Horizontal cut
		for i:=1 to nn-1 do
			for u:=0 to uu do
				L[nn, mm, uu]:=min(int64(try(i, mm, u) + try(nn-i, mm, uu-u) + mm*mm), L[nn, mm, uu]);
		//Vertitry cut
		for i:=1 to mm-1 do
			for u:=0 to uu do
				L[nn, mm, uu]:=min(int64(try(nn, i, u) + try(nn, mm-i, uu-u) + nn*nn), L[nn, mm, uu]);
		exit(L[nn, mm, uu]);
	End;
//---------------------------------------------------------
Procedure khoitao;
	Var i,j,x:integer;
	Begin
		for i:=0 to n do
			for j:=0 to m do
				for x:=0 to k do L[i,j,x]:=maxlongint;
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		khoitao;
		L[n,m,k]:=try(n, m, k);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
	xuat;
END.
