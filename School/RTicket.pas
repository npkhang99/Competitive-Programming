Uses math;
Const maxc=999999999999999;
Var a,t:array[1..100000] of int64;
    L,C:array[1..3] of int64;
    n,s,g:longint;
//---------------------------------------------------------
Procedure doc;
	Var f:text;
		i:longint;
	Begin
		assign(f,'RTicket.inp');
		reset(f);
		read(f,L[1],L[2],L[3],C[1],C[2],C[3]);
		read(f,n);
		read(f,s,g);
		a[1]:=0;
		for i:=2 to n do read(f,a[i]);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,'RTicket.out');
		rewrite(f);
		write(f,t[g]); write(t[g]);
		close(f);
	End;
//---------------------------------------------------------
Function tien(i,j:longint):int64;
	Var kc:longint;
	Begin
		kc:=a[i]-a[j];
		if kc<=L[1] then exit(C[1])
		else if kc<=L[2] then exit(C[2])
		else exit(C[3]);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j:longint;
	Begin
		t[s]:=0;
		for i:=s+1 to g do
			Begin
				t[i]:=maxc;
				j:=i-1;
				while (j>=s) and (a[i]-a[j]<=L[3]) do
					Begin
						t[i]:=min(t[i],t[j]+tien(i,j));
						dec(j);
					End;
			End;
	End;
//=========================================================
BEGIN
    doc;
    xuly;
	xuat;
END.