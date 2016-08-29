Var a:array[1..100] of longint;
	n,m:longint;
//--------------------------------------------------------
Procedure nhap;
	Begin
		write('Nhap N: ');readln(n);
	End;
//--------------------------------------------------------
Function ok(x:longint):longint;
	Var j:longint;
	Begin
		for j:=2 to trunc(sqrt(x)) do
			if x mod j=0 then exit(j);
		exit(0);
	End;
//--------------------------------------------------------
Procedure ngto(x:longint);
	Var i:longint;
	Begin
		if n=1 then exit;
		i:=ok(x);
		if i=0 then 
			Begin
				inc(m);a[m]:=x;
			End
		else Begin
				ngto(i);ngto(x div i);	
			 End;
	End;
//--------------------------------------------------------
Procedure xuat;
	Var i:longint;
	Begin
		m:=0;
		ngto(n);
		for i:=1 to m do write(a[i],' ');
	End;
//========================================================
BEGIN
	nhap;
	xuat;
END.