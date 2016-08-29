Const fi='DFS.inp';
Type canh=Record
		u,v:integer;
	 End;
Var a:array[1..1000] of canh;
	Adj,Head:array[0..1000] of integer;
	b:array[1..1000] of boolean;
	n,m:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m);
		for i:=1 to m do
			with a[i] do readln(f,u,v);
		close(f);
	End;
//---------------------------------------------------------
Procedure chuyen;
	Var	i:integer;
	Begin
		fillchar(head,sizeof(head),0);
		for i:=1 to m do
			with a[i] do
				Begin
					inc(Head[u]);
					inc(Head[v]);
				End;
		for i:=1 to n do
			Head[i]:=Head[i-1]+Head[i];
		for i:=1 to m do
			with a[i] do
				Begin
					Adj[Head[u]]:=v;
					Adj[Head[v]]:=u;
					dec(Head[u]);
					dec(Head[v]);
				End;
		Head[n+1]:=2*m;
	End;
//---------------------------------------------------------
Procedure DFS(i:integer);
	Var j:integer;
	Begin
		B[i]:=true;
		write(i,' ');
		for j:=Head[i]+1 to Head[i+1] do
			if not B[Adj[j]] then DFS(Adj[j]);
	End;
//=========================================================
BEGIN
	docfile;
	chuyen;
	fillchar(b,sizeof(b),false);
	DFS(1);
END.