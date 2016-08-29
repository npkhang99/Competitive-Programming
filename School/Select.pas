Uses Math;
Const fi='Select.inp';
	  fo='Select.out';
Var a:array[1..4,1..10000] of integer;
	L,tr:array[1..40000] of longint;
	n:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i,j:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			Begin
				for j:=1 to 4 do read(f,a[j,i]);
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
Function dong(i:word):integer;
	Begin
		dong:=((i-1) div n)+1;
	End;
//---------------------------------------------------------
Function cot(i:word):integer;
	Begin
		cot:=((i-1) mod n)+1;
	End;
//---------------------------------------------------------
Function ke(i,j:word):boolean;
	Var di,dj,ci,cj:integer;
	Begin
		if j=0 then exit(false);
		di:=dong(i); dj:=dong(j);
		ci:=cot(i); cj:=cot(j);
		exit((((di=dj) and (abs(ci-cj)=1)) or ((ci=cj) and (abs(di-dj)=1))) or ke(i, tr[j]));
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j:word;
		Lmax:longint;
	Begin
		fillchar(L,sizeof(L),0);
		L[1]:=a[1,1]; Lmax:=L[1]; tr[1]:=0;
		for i:=2 to n*4 do
			for j:=0 to i-1 do
				if (not ke(i,j)) and (L[i]<L[j]+a[dong(i), cot(i)]) then
					Begin
						L[i]:=L[j]+a[dong(i), cot(i)];
						tr[i]:=j;
						Lmax:=max(Lmax,L[i]);
					End;
		for i:=1 to n*4 do write(L[i],' ');
		writeln;
		write(Lmax);
		xuat(Lmax);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.