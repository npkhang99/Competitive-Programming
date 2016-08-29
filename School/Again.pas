Uses Math;
Const fi='Again.inp';
	  fo='Again.out';
Var a,tr:array[0..300] of integer;
	L:array[0..300] of int64;
	n,vt:integer;
	t:int64;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,t);
		for i:=1 to n do read(f,a[i]);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x:int64);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x);
		close(f);
		halt;
	End;
//---------------------------------------------------------
Procedure xauchung;
	Var i,j,tt:integer;
	Begin
		fillchar(tr,sizeof(tr),0);
		vt:=1;
		for i:=1 to n*3 do L[i]:=1;
		for i:=2 to n*3 do
			for j:=1 to i-1 do
				if (a[((i-1) mod n)+1]>=a[((j-1) mod n)+1]) and (L[i]<L[j]+1) then
					Begin
						L[i]:=L[j]+1;
						vt:=i;
						tr[i]:=j;
					End;
	End;
//---------------------------------------------------------
Function tim_mid:integer;
	Var i,d:integer;
	Begin
		i:=tr[vt]; d:=0;
		repeat
			if i in [n+1..n*2] then inc(d);
			i:=tr[i];
		until i<=n;
		exit(d);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var mid:integer;
		ans:int64;
	Begin
		xauchung;
		mid:=tim_mid;
		ans:=mid*(t-2)+L[vt];
		xuat(ans);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.