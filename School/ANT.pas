Const fi='ANT.inp';
	  fo='ANT.out';
	  dx:array[1..4] of shortint=(-1,0,1,0);
	  dy:array[1..4] of shortint=(0,1,0,-1);
Type diem=Record
		x,y,s:longint;
	 End;
Var a:array[-1001..1001,-1001..1001] of byte;
	Q:array[1..2000000] of diem;
	n,c,d:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i,x,y:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,c,n);
		fillchar(a,sizeof(a),0);
		for i:=1 to 1001 do
			Begin
				a[1001,i]:=1;
				a[-1001,i]:=1;
				a[i,1001]:=1;
				a[i,-1001]:=1;
			End;
		for i:=1 to c do
			Begin
				readln(f,x,y);
				a[x,y]:=1;
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,d);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var l,r,u,v,vtx,vty,dd,i:longint;
	Begin
		l:=1; r:=1; Q[1].x:=0; Q[1].y:=0; Q[1].s:=0; d:=1; a[0,0]:=1;
		while (l<=r) do
			Begin
				vtx:=Q[l].x; vty:=Q[l].y; dd:=Q[l].s; inc(l);
				for i:=1 to 4 do
					Begin
						u:=vtx+dx[i];
						v:=vty+dy[i];
						if (a[u,v]=0) and (dd+1<=n) then
							Begin
								a[u,v]:=1;
								inc(d); inc(r);
								Q[r].x:=u;
								Q[r].y:=v;
								Q[r].s:=dd+1;
							End;
					End;
			End;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
	xuat;
END.