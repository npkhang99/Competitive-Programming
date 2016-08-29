Uses Math;
Const fi='SDC.inp';
	  fo='SDC.out';
Type canh=Record
		u,v,val:int64;
	 End;
Var a:array[1..10000] of canh;
	d:array[0..10000] of longint;
	n,m,x,y,dmin,dmax:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m,x,y);
		for i:=1 to m do
			with a[i] do
				readln(f,u,v,val);
		close(f);
	End;
//---------------------------------------------------------
Function tim:longint;
	Var k:longint;
	Begin
		k:=1;
		if (dmax>y) or ((dmin<x) and (dmax=y)) then exit(x-1);
		while (dmin+k<x) do
			Begin
				inc(k);
				if (dmin+k<=x) and (dmax+k>y) then exit(x-1);
			End;
		exit(k);
	End;
//---------------------------------------------------------
Procedure xuat(x:byte);
	Var f:text;
		i:longint;
		k:longint;
	Begin
		assign(f,fo);
		rewrite(f);
		if x=1 then
			Begin
				k:=tim;
				if k=x-1 then write(f,'NO')
				else Begin
						writeln(f,'YES');
						for i:=1 to n do
							write(f,d[i]+k,' ');
					 End;
			End
		else write(f,'NO');
		close(f);
	End;
//---------------------------------------------------------
Procedure khoigan;
	Var i:longint;
	Begin
		for i:=1 to m do
			d[i]:=0;
	End;
//---------------------------------------------------------
Function co(e:canh):boolean;
	Begin
		with e do
			Begin
				if d[v]>d[u]+val then
					Begin
						d[v]:=d[u]+val;
						dmax:=max(d[v],dmax);
						dmin:=min(d[v],dmin);
						exit(true);
					End;
				exit(false);
			End;
	End;
//---------------------------------------------------------
Procedure FondBellman;
	Var k,i:longint;
		ok:boolean;
	Begin
		dmax:=0; dmin:=maxlongint;
		for k:=1 to n-1 do
			Begin
				ok:=false;
				for i:=1 to m do
					if co(a[i]) then ok:=true;
				if ok=false then break;
			End;
	End;
//---------------------------------------------------------
Function am:boolean;
	Var i:longint;
	Begin
		for i:=1 to m do
			if co(a[i]) then exit(true);
		exit(false);
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		writeln(n,' ',m,' ',x,' ',y);
		khoigan;
		FondBellman;
		if not am then xuat(1)
		else xuat(0);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.