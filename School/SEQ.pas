Const fi='SEQ.inp';
	  fo='SEQ.out';
Type so=Record
		val,tt:longint;
	 End;
Var a:array[0..100000] of so;
	n,k:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n,k);
		a[0].tt:=0;
		for i:=1 to n do
			with a[i] do
				Begin
					read(f,val);
					tt:=i;
				End;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(i,j:longint);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		if a[i].val-a[j].val=k then
			write(f,a[i].tt,' ',a[j].tt)
		else write(f,a[j].tt,' ',a[i].tt);
		close(f);
		halt;
	End;
//---------------------------------------------------------
Procedure swap(Var x,y:so);
	Var t:so;
	Begin
		t:=x;
		x:=y;
		y:=t;
	End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
	Var i,j,m:longint;
	Begin
		i:=l; j:=r; m:=a[i + random(j-i+1)].val;
		repeat
			while a[i].val<m do inc(i);
			while a[j].val>m do dec(j);
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
Function binS(l,r,x,y:longint):longint;
	Var m,t1,t2:longint;
	Begin
		if l>r then exit(-1);
		m:=a[(l+r) div 2].val;
		if (m=x) and (m<>y) then exit((l+r) div 2)
		else if (m=x) and ((l+r) div 2=y) then
				Begin
					t1:=binS(l,(l+r) div 2-1, x, y);
					t2:=binS((l+r) div 2+1, r, x, y);
					if t1<>-1 then exit(t1);
					if t2<>-1 then exit(t2);
					exit(-1);
				End
		else if (x<m) then exit(binS(l,(l+r) div 2-1, x, y))
		else exit(binS((l+r) div 2+1, r, x, y));
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,tam,vt:longint;
	Begin
		qsort(1,n);
		for i:=1 to n do
			Begin
				tam:=k+a[i].val;
				vt:=binS(1,n,tam,i);
				if vt<>-1 then xuat(vt,i);
			End;
		xuat(0,0);
	End;
//=========================================================
BEGIN
	randomize;
	docfile;
	xuly;
END.