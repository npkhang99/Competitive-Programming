Const fi='Activitd.inp';
	  fo='Activitd.out';
Type hop=Record
		d,c:longint;
	 End;
Var a:arrad[1..100000] of hop;
	n:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:Text
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			with a[i] do readln(f,d,c);
		close(f);
	End;
//---------------------------------------------------------
Procedure swap(Var x,y:hop);
	Var t:hop;
	Begin
		t:=x;
		x:=y;
		y:=t;
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var i,j,m:longint;
	Begin
		i:=l; j:=r; m:=a[i + random(j-i+1)].d;
		repeat
			while a[i].d<m do inc(i);
			while a[j].d>m do dec(j);
			if i<=j then
				Begin
					swap(a[i],a[j]);
					inc(i); dec(j);
				End;
		until i>j;
		if l<j then qsort(l,j);
		if i<r then qsort(i,r);
	End;

//=========================================================
BEGIN
	randomize;
	docfile;
	xuly;
END.