// SPOJ submission 14845130 (PAS fpc) plaintext list. Status: AC, problem BCLKCOUN, contest PTIT. By mansblacks (Khang), 2015-08-08 04:43:52.
Const dx:array[1..8] of shortint=(-1,-1,-1,0,1,1,1,0);
	  dy:array[1..8] of shortint=(-1,0,1,1,1,0,-1,-1);
Var a:array[1..100] of string;
	n,m:integer;
//---------------------------------------------------------
Procedure doc;
	Var i:integer;
	Begin
		readln(n,m);
		for i:=1 to n do
			Begin
				readln(a[i]);
			End;
	End;
//---------------------------------------------------------
Function ok(x,y,i:integer):boolean;
	Begin
		ok:=(x+dx[i]>=1) and (x+dx[i]<=n) and (y+dy[i]>=1) and (y+dy[i]<=m);
	End;
//---------------------------------------------------------
Procedure gan(x,y,d:integer);
	Var i:integer;
	Begin
		a[x][y]:='.';
		for i:=1 to 8 do
			if (ok(x,y,i)) and (a[x+dx[i]][y+dy[i]]='W') then gan(x+dx[i],y+dy[i],d);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,d:integer;
	Begin
		d:=0;
		for i:=1 to n do
			Begin
				for j:=1 to m do
					if a[i][j]='W' then 
						Begin
							inc(d);
							gan(i,j,d);
						End;
			End;
		write(d);
	End;
//=========================================================
BEGIN
	doc;
	xuly;
END.