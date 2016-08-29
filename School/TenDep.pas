Uses Math;
Const fi='TenDep.inp';
	  fo='TenDep.out';
Var t:byte;
	cA,cB,mA,mB:longint;
	f2:text;
//---------------------------------------------------------
Procedure xuly;
	Var Smax,c1,c2,m1,m2,mid,left,head:longint;
	Begin
		c1:=min(cA,cB);	if c1=cA then m1:=mA else m1:=mB;
		c2:=max(cA,cB);	if c2=cA then m2:=mA else m2:=mB;
		if m1=0 then
			Begin
				writeln(f2,min(c2,m2));
				exit;
			End;
		if m2=0 then
			Begin
				writeln(f2,min(c1,m1));
				exit;
			End;
		if (c1=0) or (c2=0) then
			Begin
				writeln(f2,'0');
				exit;
			End;
		mid:=min(c2 div (c1-1), m2);
		left:=c2 - mid*(c1-1);
		Smax:=c1+mid*(c1-1);
		if left>0 then
			Begin
				head:=min(left div 2, m2);
				left:=min(left-head, m2);
			End
		else Begin
				head:=0;
				left:=0;
			 End;
		Smax:=Smax+head+left;
		writeln(f2,Smax);
	End;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		test:byte;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,t);
		for test:=1 to t do
			Begin
				readln(f,cA,cB,mA,mB);
				xuly;
			End;
		close(f);
	End;
//=========================================================
BEGIN
	assign(f2,fo);
	rewrite(f2);
	docfile;
	close(f2);
END.