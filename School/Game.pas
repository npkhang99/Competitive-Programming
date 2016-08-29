Const fi='Game.inp';
	  fo='Game.out';
Var a,sl:array[0..1000009] of longint;
	n:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i,x:longint;
		ch:char;
	Begin
		assign(f,fi); reset(f);
		readln(f,n);
		for i:=1 to n do
			Begin
				readln(f,ch,x);
				if ch='L' then a[i]:=-x
				else a[i]:=x;
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x,r:longint);
	Var f:text;
	Begin
		assign(f,fo); rewrite(f);
		if x>0 then
			Begin
				writeln(f,x); writeln(x);
				write(f,r-sl[r]+1,' ',r); write(r-sl[r]+1,' ',r);
			End
		else write(f,x);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,l,r:longint;
		bmax:int64;
		b:array[0..1000009] of longint;
	Begin
		l:=1; r:=1; bmax:=0; b[0]:=0; sl[0]:=0;
		for i:=1 to n do
			if b[i-1]+a[i]>=0 then
				Begin
					b[i]:=b[i-1]+a[i];
					sl[i]:=sl[i-1]+1;
					if b[i]>bmax then
						Begin
							r:=i;
							bmax:=b[i];
						End;
				End
			else Begin
					b[i]:=0;
					l:=i;
					sl[i]:=0;
				 End;
		xuat(bmax,r);
	End;
//---------------------------------------------------------
BEGIN
	docfile;
	xuly;
END.