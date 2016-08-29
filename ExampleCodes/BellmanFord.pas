Const fi='BellmanFord.inp';
Type canh=Record
		u,v,val:integer;
	 End;
Var a:array[1..100] of canh;
	d,tr:array[1..1000] of integer;
	n,m,s,t:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,m,s,t);
		for i:=1 to m do
			with a[i] do read(f,u,v,val);
		close(f);
	End;
//---------------------------------------------------------
Procedure ddi(i:integer);
	Begin
		if i>0 then
			Begin
				ddi(tr[i]);
				write(i,' ');
			End;
	End;
//---------------------------------------------------------
Procedure khoigan;
	Var i:integer;
	Begin
		fillchar(tr,sizeof(tr),0);
		for i:=1 to n do
			d[i]:=maxint;
		d[s]:=0;
	End;
//---------------------------------------------------------
Function co(e:canh):boolean;
	Begin
		with e do
			Begin
				if d[v]>d[u]+val then
					Begin
						d[v]:=d[u]+val;
						tr[v]:=u;
						exit(true);
					End;
				exit(false);
			End;
	End;
//---------------------------------------------------------
Procedure BellmanFord;
	Var k,i:integer;
		ok:boolean;
	Begin
		khoigan;
		for k:=1 to n-1 do
			Begin
				ok:=false;
				for i:=1 to m do
					if co(a[i]) then ok:=true;
				if ok=false then break;
			End;
		writeln(d[t]);
		ddi(t);
	End;
//=========================================================
BEGIN
	docfile;
	BellmanFord;
END.