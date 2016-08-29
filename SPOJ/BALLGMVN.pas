Type diem=Record
		x,y:longint;
		cotg:real;
		tt:longint;
	 End;
	 mang=array[0..1009] of diem;
Var g,r:mang;
	n:longint;
//---------------------------------------------------------
Procedure doc;
	Var i:longint;
	Begin
		readln(n);
		for i:=1 to n do
			with g[i] do
				Begin
					readln(x,y);
					tt:=i;
				End;
		for i:=1 to n do
			with r[i] do
				Begin
					readln(x,y);
					tt:=n+i;
				End;
	End;
//---------------------------------------------------------
Procedure swap(Var i,j:longint; Var a:mang);
	Var t:diem;
	Begin
		t:=a[i]; a[i]:=a[j]; a[j]:=t;
		inc(i); dec(j);
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint; Var a:mang);
	Var i,j:longint;
		m:real;
	Begin
		i:=l; j:=r; m:=a[i+random(j-i+1)].cotg;
		repeat
			while a[i].cotg<m do inc(i);
			while a[j].cotg>m do dec(j);
			if i<=j then swap(i,j,a);
		until i>j;
		if l<j then qsort(l,j,a);
		if i<r then qsort(i,r,a);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,u,v:longint;
	Begin
		//bi xanh lam goc
		for i:=1 to n do
			Begin
				for j:=1 to n do
					Begin
						u:=r[j].x-g[i].x;
						v:=r[j].y-g[i].y;
						if v=0 then r[j].cotg:=maxlongint
						else r[j].cotg:=u/v;
					End;
				qsort(1,n,r);
				for j:=1 to n-1 do
					if r[j].cotg=r[j+1].cotg then
						Begin
							write(r[i].tt,' ',r[j+1].tt,' ',g[i].tt);
							halt;
						End;
			End;
		//bi do lam goc
		for i:=1 to n do
			Begin
				for j:=1 to n do
					Begin
						u:=g[j].x-r[i].x;
						v:=g[j].y-r[i].y;
						if v=0 then g[j].cotg:=maxlongint
						else g[j].cotg:=u/v;
					End;
				qsort(1,n,g);
				for j:=1 to n-1 do
					if g[j].cotg=g[j+1].cotg then
						Begin
							write(g[i].tt,' ',g[j+1].tt,' ',r[i].tt);
							halt;
						End;
			End;
		write('-1');
	End;
//---------------------------------------------------------
BEGIN
	randomize;
	doc;
	xuly;
END.