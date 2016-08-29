Uses Math;
Const fi='ChiaDoi.inp';
	  fo='ChiaDoi.out';
Var a:array[1..32] of longint;
	n,count:byte;
	T,u,v,valu:int64;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:byte;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		T:=0;
		for i:=1 to n do
			Begin
				read(f,a[i]);
				T:=T+a[i];
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,u,' ',v div 2);
		close(f);
	End;
//---------------------------------------------------------
Procedure toiuu(x,y:int64);
	Begin
		if x<u then
			Begin
				valu:=y;
				u:=x;
				v:=1;
			End
		else if y=valu then inc(v);
	End;
//---------------------------------------------------------
Function cal(x:int64):int64;
	Begin
		exit(abs((T-x)-x));
	End;
//---------------------------------------------------------
Procedure xuly;
	Var L:array[1..32,1..32] of int64;
		i,j,k:byte;
	Begin
		fillchar(L,sizeof(L),0);
		v:=0; u:=T; count:=0;
		for i:=1 to n do
			Begin
				L[i,i]:=a[i];
				toiuu(cal(a[i]), a[i]);
			End;
		for i:=n-1 downto 1 do
			for j:=i+1 to n do
				Begin
					for k:=i to j-1 do
						Begin
							if u>cal(L[i,k]+a[j]) then
								Begin
									L[i,j]:=L[i,k]+a[j];
									//toiuu(cal(L[i,j]),L[i,j]);
								End
							else if u=cal(L[i,k]+a[j]) then
									Begin
										L[i,j]:=L[i,k]+a[j];
										//toiuu(u,L[i,j]);
									End
							else if cal(L[i,j])>cal(L[i,k]+a[j]) then
									Begin
										L[i,j]:=L[i,k]+a[j];
										//toiuu(cal(L[i,j]),L[i,j]);
									End;
							toiuu(cal(L[i,j]), L[i,j]);
						End;
				End;
		xuat;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.
