Uses Math;
Const fi='STREET.inp';
	  fo='STREET.out';
	  maxA=1000000000000000000;
Var a:array[0..5000] of int64;
	n,k:int64;
//---------------------------------------------------------
Procedure xuly;
	Var i3,i5,i7,x3,x5,x7,x:int64;
	Begin
		k:=0; a[0]:=1; i3:=0; i5:=0; i7:=0;
		while (a[k]<maxA) do
			Begin
				x3:=a[i3]*3; x5:=a[i5]*5; x7:=a[i7]*7;
				x:=min(x3, min(x5, x7));
				inc(k); a[k]:=x; writeln(a[k]);
				if x=x3 then inc(i3);
				if x=x5 then inc(i5);
				if x=x7 then inc(i7);
			End;
		dec(k);
		write(k);
	End;
//---------------------------------------------------------
Function binS(l,r:integer):integer;
	Var m:int64;
	Begin
		if l>r then  exit(-1);
		m:=a[(l+r) div 2];
		if n=m then exit((l+r) div 2)
		else if n<m then exit(binS(l, (l+r) div 2-1))
		else exit(binS((l+r) div 2+1, r));
	End;
//---------------------------------------------------------
Procedure docfile;
	Var f1,f2:text;
		vt:integer;
	Begin
		assign(f1,fi); reset(f1);
		assign(f2,fo); rewrite(f2);
		while not seekeof(f1) do
			Begin
				readln(f1,n);
				vt:=binS(1,k);
				if vt=-1 then writeln(f2,'N')
				else if vt mod 2=1 then writeln(f2,'L')
				else writeln(f2,'R');
			End;
		close(f1); close(f2);
	End;
//=========================================================
BEGIN
	xuly;
	docfile;
END.