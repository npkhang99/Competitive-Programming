Const fi='BaoLoi.inp';
	  fo='BaoLoi.out';
Type diem=Record
		x,y:real;
		cotg:real;
	 End;
Var a:array[1..1000001] of diem;
	st,c:array[1..1000001] of longint;
	n,r,k:longint;
	x0,y0:real;
//---------------------------------------------------------
Function dttg(d1,d2,d3:diem):real;
	Begin
		dttg:=((d2.x-d1.x) * (d2.y+d1.y)) + 
			  ((d3.x-d2.x) * (d3.y+d2.y)) +
			  ((d1.x-d3.x) * (d1.y+d3.y));
	End;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			with a[i] do readln(f,x,y);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
		i:longint;
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,r-1);
		for i:=1 to r-1 do
			with a[st[i]] do writeln(f,(x+x0):0:3,' ',(y+y0):0:3);
		close(f);
	End;
//---------------------------------------------------------
Procedure tim;
	Var i:longint;
	Begin
		x0:=maxlongint; y0:=maxlongint;
		for i:=1 to n do
			with a[i] do
				if y=y0 then
					Begin
						if x<x0 then x0:=x;
					End
				else if y<y0 then
						Begin
							x0:=x; y0:=y;
						End;
	End;
//---------------------------------------------------------
Procedure doitruc;
	Var i:longint;
	Begin
		for i:=1 to n do
			with a[i] do
				Begin
					x:=x-x0; y:=y-y0;
					if (y=0) and (x=0) then cotg:=maxlongint+1
					else if (y=0) and (x>0) then cotg:=maxlongint
					else if (y=0) and (x<0) then cotg:=-maxlongint
					else cotg:=x/y;
				End;
	End;
//---------------------------------------------------------
Procedure swap(Var t1,t2:diem);
	Var t:diem;
	Begin
		t:=t1;
		t1:=t2;
		t2:=t;
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var i,j:longint;
		m:real;
	Begin
		i:=l; j:=r; m:=a[i + random(j-i+1)].cotg;
		repeat
			while a[i].cotg>m do inc(i);
			while a[j].cotg<m do dec(j);
			if i<=j then
				Begin
					swap(a[i],a[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	End;
//---------------------------------------------------------
Function kc(i:longint):real;
	Begin
		kc:=sqrt(sqr(a[i].x) + sqr(a[i].y));
	End;
//---------------------------------------------------------
Procedure lay_max(i:longint);
	Begin
		if kc(i)>kc(c[k]) then c[k]:=i;
	End;
//---------------------------------------------------------
Procedure tim_max;
	Var i:longint;
	Begin
		k:=1; c[1]:=1;
		for i:=2 to n do
			Begin
				if a[i].cotg=a[i-1].cotg then lay_max(i)
				else if a[i].cotg<>a[i-1].cotg then
					Begin
						inc(k);
						c[k]:=i;
					End;
			End;
	End;
//---------------------------------------------------------
Function get:longint;
	Begin
		get:=st[r];
		dec(r);
	End;
//---------------------------------------------------------
Procedure put(i:longint);
	Begin
		inc(r);
		st[r]:=i;
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i:longint;
	Begin
		tim;
		doitruc;
		qsort(1,n);
		tim_max;
		c[k+1]:=1; st[1]:=c[1]; st[2]:=c[2]; r:=2;
		for i:=3 to k+1 do
			Begin
				while dttg(a[st[r-1]],a[st[r]],a[c[i]])>=0 do dec(r);
				put(c[i]);
			End;
	End;
//=========================================================
BEGIN
	randomize;
	docfile;
	xuly;
	xuat;
END.