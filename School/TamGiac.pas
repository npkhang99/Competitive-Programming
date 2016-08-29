Const fi='TamGiac.inp';
	  fo='TamGiac.out';
Type diem=Record
		x,y:real;
		tt:integer;
	 End;
Var a,b,c:array[1..1000] of diem;
	L,tr,head:array[1..1000000] of integer;
	n:integer;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			Begin
				with a[i] do read(f,x,y);
				with b[i] do read(f,x,y);
				with c[i] do read(f,x,y);
				a[i].tt:=i; b[i].tt:=i; c[i].tt:=i;
				readln(f);
			End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(vt:integer);
	Var f:text;
		i:integer;
	Begin
		assign(f,fo);
		rewrite(f);
		write(vt);
		writeln(f,L[vt]);
		for i:=head[vt]+1 to head[vt+1] do
			write(f,tr[i],' ');
		close(f);
	End;
//---------------------------------------------------------
Function dt(a,b,c:diem):real;
	Begin
		dt:=abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
	End;
//---------------------------------------------------------
Function ktra(i,j,x:integer):boolean;
	Var s,s1,s2,s3:real;
	Begin
		s:=dt(a[i],b[i],c[i]);
		case x of 1:Begin
						s1:=dt(a[i],b[i],a[j]);
						s2:=dt(a[i],c[i],a[j]);
						s3:=dt(c[i],b[i],a[j]);
						exit((s1+s2+s3) = s);
					End;
				  2:Begin
						s1:=dt(a[i],b[i],b[j]);
						s2:=dt(a[i],c[i],b[j]);
						s3:=dt(c[i],b[i],b[j]);
						exit((s1+s2+s3) = s);
					End;
				  3:Begin
						s1:=dt(a[i],b[i],c[j]);
						s2:=dt(a[i],c[i],c[j]);
						s3:=dt(c[i],b[i],c[j]);
						exit((s1+s2+s3) = s);
				    End;
		End;
	End;
//---------------------------------------------------------
Function ok(i,j:integer):boolean;
	Var	x:byte;
	Begin
		for x:=1 to 3 do
			if not ktra(i,j,x) then exit(false);
		exit(true);
	End;
//---------------------------------------------------------
Procedure doi(Var a,b:diem);
	Var t:diem;
	Begin
		t:=a;
		a:=b;
		b:=t;
	End;
//---------------------------------------------------------
Procedure QSort(l,r:integer);
	Var i,j:integer;
		x:real;
	Begin
		i:=l; j:=r; x:=dt(a[(i+j) div 2], b[(i+j) div 2], c[(i+j) div 2]);
		repeat
			while dt(a[i], b[i], c[i])<x do inc(i);
			while dt(a[j], b[j], c[j])>x do dec(j);
			if i<=j then
				Begin
					doi(a[i],a[j]);
					doi(b[i],b[j]);
					doi(c[i],c[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if i<r then QSort(i,r);
		if j>l then QSort(l,j);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,k,Lmax,vt:integer;
	Begin
		QSort(1,n);
		k:=0; vt:=0; Lmax:=0;
		for i:=1 to n do
			Begin
				head[i]:=k;
				for j:=1 to i do
					if (ok(i,j)) then
						Begin
							inc(k);
							tr[k]:=a[j].tt;
						End;
				L[i]:=k-L[i-1];
				if L[i]>Lmax then
					Begin
						vt:=i;
						Lmax:=L[i];
					End;
			End;
		head[n+1]:=k;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.