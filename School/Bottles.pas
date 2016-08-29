Uses Math;
Const fi='Bottles.inp';
	  fo='';
Var a,L,tr:array[-2..10000] of integer;
	n:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do 
			Begin
				read(f,a[i]);
				L[i]:=a[i];
				tr[i]:=0;
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,t,x,y:integer;
	Begin
		L[0]:=0; tr[0]:=0; t:=0;
		for i:=2 to n do
			if tr[tr[i-1]]+1=tr[i-1] then
				Begin
					L[i-1]:=L[i-4]+a[i-2]+a[i-1];
					tr[i-1]:=i-2; tr[i-2]:=i-4;
					t:=max(t,L[i-1]);
				End
			else Begin
					x:=L[i-2]+a[i];
					y:=L[i-3]+a[i]+a[i-1];
					if x>y then
						Begin
							L[i]:=x;
							tr[i]:=i-2;
						End
					else Begin
							L[i]:=y;
							tr[i]:=i-1; tr[i-1]:=i-3;
						 End;
					t:=max(t, max(x,y));
				 End;
		write(t);
		xuat
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.