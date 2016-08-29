// SPOJ submission 14845335 (PAS fpc) plaintext list. Status: AC, problem ADS, contest SPOJVN. By mansblacks (Khang), 2015-08-08 05:27:21.
Var T:array[1..2000] of integer;
	n,m,d:integer;
//--------------------------------------------------
Procedure hopnhat(a,b:integer);
	Var j,k:integer;
	Begin
		if T[a]<>T[b] then
			Begin
				inc(d);
				k:=T[b];
				for j:=1 to n do
					if T[j]=k then T[j]:=T[a];
			End;
	End;
//--------------------------------------------------
Procedure doc;
	Var i,a,b:integer;
	Begin
		readln(n,m);
		d:=0;
		for i:=1 to n do T[i]:=i;
		for i:=1 to m do
			Begin
				readln(a,b);
				hopnhat(a,b);
			End;
		write(m-d);
	End;
//==================================================
BEGIN
	doc;
END.