Const fi='Army.inp';
	  fo='Army.out';
Type dthang=Record
		x1,y1,x2,y2:dword;
	 End;
Var a:array[1..20] of dthang;
	n,k:byte;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:byte;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			Begin
				with a[i] do readln(f,x1,y1,x2,y2);
			End;
		close(f);
	End;
//---------------------------------------------------------

//=========================================================
BEGIN
	docfile;
	xuly;
END.