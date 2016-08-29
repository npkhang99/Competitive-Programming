Uses Math;
Const fi='LoCo.inp';
	  fo='LoCo.out';
Var a:array[1..1000,1..1000] of boolean;
	t,L,d:array[1..1000] of longint;
	b:array[1..1000] of boolean;
	n,k:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		fillchar(a,sizeof(a),false);
		for i:=1 to n do read(f,t[i]);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x:longint);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x);
		close(f);
	End;
//---------------------------------------------------------
Function tim(x,l,r:longint):longint;
	Var m:longint;
	Begin
		m:=t[(l+r) div 2];
		if l>r then exit(-1)
		else if x=m then exit((l+r) div 2)
		else if x>m then exit(tim(x,(l+r) div 2+1, r))
		else exit(tim(x, l,(l+r) div 2-1));
	End;
//---------------------------------------------------------
Procedure doi(Var x,y:longint);
	Var tam:longint;
	Begin
		tam:=x;
		x:=y;
		y:=tam;
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var m,i,j:longint;
	Begin
		i:=l; j:=r; m:=t[(i+j) div 2];
		repeat
			while t[i]<m do inc(i);
			while t[j]>m do dec(j);
			if i<=j then
				Begin
					doi(t[i],t[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if i<r then qsort(i,r);
		if j>l then qsort(l,j);
	End;
//---------------------------------------------------------
Procedure build;
	Var i,j,k:longint;
	Begin
		qsort(1,n);
		for i:=1 to n-1 do
			for j:=i+1 to n do
				Begin
					k:=tim(t[i]+t[j],1,n);
					if k>0 then
						Begin
							a[i,k]:=true;
							a[j,k]:=true;
						End;
				End;
	End;
//---------------------------------------------------------
Procedure DFS(u:longint);
	Var v:longint;
	Begin
		b[u]:=true;
		for v:=1 to n do
			if (not b[v]) and (a[u,v]) then DFS(v);
		L[k]:=u; dec(k);
	End;
//---------------------------------------------------------
Procedure topo;
	Var i,j,dmax,u,v:longint;
	Begin
		fillchar(d,sizeof(d),0);
		k:=n; dmax:=0;
		for i:=1 to n do
			if not b[i] then DFS(i);
		for i:=1 to n-1 do
			for j:=i+1 to n do
				Begin
					u:=L[i]; v:=L[j];
					if (a[u,v]) and (d[v]<d[u]+1) then
						Begin
							d[v]:=d[u]+1;
							dmax:=max(dmax, d[v]);
						End;
				End;
		xuat(dmax+1);
	End;
//=========================================================
BEGIN
	docfile;
	build;
	topo;
END.