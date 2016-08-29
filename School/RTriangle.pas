Const fi='RTriangle.inp';	
	  fo='RTriangle.out';
Type diem=Record
		x,y,gocpt:longint;
		c:real;
	 End;
Var a,b:array[0..1509] of diem;
	dem:array[0..10] of int64;
	n:longint;
	kq:int64;
//---------------------------------------------------------
Procedure doc;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi); reset(f);
		readln(f,n);
		for i:=1 to n do
			with b[i] do
				Begin
					readln(f,x,y);
					gocpt:=0;
				End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,fo); rewrite(f);
		write(f,kq);
		close(f);
	End;
//---------------------------------------------------------
Procedure doitruc(goc:longint);
	Var i:longint;
	Begin
		for i:=1 to n do
			Begin
				a[i].x:=b[i].x-b[goc].x;
				a[i].y:=b[i].y-b[goc].y;
			End;
	End;
//---------------------------------------------------------
Procedure quay(Var x,y:longint);
	Var t:longint;
	Begin
		t:=x; x:=y; y:=-t;
	End;
//---------------------------------------------------------
Procedure swap(Var i,j:longint);
	Var t:diem;
	Begin
		t:=a[i]; a[i]:=a[j]; a[j]:=t;
		inc(i); dec(j);
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var i,j:longint;
		m:real;
	Begin
		i:=l; j:=r; m:=a[i + random(j-i+1)].c;
		repeat
			while a[i].c<m do inc(i);
			while a[j].c>m do dec(j);
			if i<=j then swap(i,j);
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,goc,u,v:longint;
	Begin
		kq:=0;
		//xet voi "goc" la dinh cua tam giac vuong
		for goc:=1 to n do
			Begin
				doitruc(goc);
				for i:=1 to n do
					Begin
						a[i].gocpt:=0;
						u:=a[i].x; v:=a[i].y;
						if i<>goc then
							while not((u>0) and (v<=0)) do
								Begin
									quay(u,v);
									inc(a[i].gocpt);
								End;
						if i<>goc then a[i].c:=v/u
						else a[i].c:=-maxlongint;
					End;
				qsort(1,n);
				i:=3;
				while i<=n do
					Begin
						fillchar(dem,sizeof(dem),0);
						inc(dem[a[i-1].gocpt]);
						while (a[i-1].c=a[i].c) and (i<=n) do
							Begin
								inc(dem[a[i].gocpt]);
								inc(i);
							End;
						kq:=kq + dem[0]*dem[1] + dem[1]*dem[2] + dem[2]*dem[3] + dem[3]*dem[0];
						inc(i);
					End;
			End;
	End;
//---------------------------------------------------------
BEGIN
	doc;
	xuly;
	xuat;
END.