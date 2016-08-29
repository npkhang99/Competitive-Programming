Const fi='Sort.inp';
Var a:array[1..1000000] of longint;
	n:longint;

Procedure doc;
	Var i:longint;
		f:text;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do read(f,a[i]);
		close(f);
	End;

Procedure xuat;
	Var i:longint;
	Begin
		for i:=1 to n do write(a[i],' ');
	End;

Procedure swap(var a,b:longint);
	Var t:longint;
	Begin
		t:=a;
		a:=b;
		b:=t;
	End;

Procedure qsort(l,r:longint);
	Var i,j,m:longint;
	Begin
		i:=l; j:=r; m:=a[i + random(j-i+1)];
		repeat
			while a[i]<m do inc(i);
			while a[j]>m do dec(j);
			if i<=j then
				Begin
					swap(a[i],a[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	End;

BEGIN
	randomize;
	doc;
	qsort(1,n);
	xuat;
END.