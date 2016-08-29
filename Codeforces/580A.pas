Uses Math;
Var a:array[1..100000] of longint;
	n:longint;
//---------------------------------------------------------
Procedure doc;
	Var i:longint;
	Begin
		readln(n);
		for i:=1 to n do read(a[i]);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,d,dmax:longint;
	Begin
		dmax:=0; d:=1;
		for i:=2 to n do
			if a[i]>=a[i-1] then inc(d)
			else Begin
					dmax:=max(dmax, d);
					d:=1;
				 End;
		dmax:=max(dmax, d);
		write(dmax);
	End;
//=========================================================
BEGIN
	doc;
	xuly;
END.