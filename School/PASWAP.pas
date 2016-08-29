Uses math;
Const fi='PASWAP.inp';
	  fo='PASWAP.out';
Var a,b:array[1..100000] of integer;
	n,k,d,amin,amax:integer;
//----------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		fillchar(b,sizeof(b),0);
		readln(f,n);
		for i:=1 to n do
			Begin
				read(f,a[i]);
				inc(b[a[i]]);
			End;
		close(f);
	End;
//----------------------------------------------------------
Procedure minmax(lm,rm:integer;var amin,amax:integer);
	Var amin1,amax1,amin2,amax2:integer;
	Begin
		if lm=rm then
			Begin
				amin:=a[lm];
				amax:=a[lm];
			End
		else Begin
				minmax(lm,(lm+rm) div 2,amin1,amax1);
				minmax((lm+rm) div 2+1,rm,amin2,amax2);
				amin:=min(amin1,amin2);
				amax:=max(amax1,amax2);
			 End;
	End;
//----------------------------------------------------------
Procedure try(l,r:integer;var imax,dmax:integer);
	Var imax1,imax2,dmax1,dmax2,amin,amax,dtam,itam:integer;
	Begin
		if l=r then
			Begin
				minmax(l,r,amin,amax);
				if amin=1 then
					Begin
						imax:=l;
						dmax:=1;
					End;
			End
		else Begin
				try(l,(l+r) div 2,imax1,dmax1);
				try((l+r) div 2+1,r,imax2,dmax2);
				dmax:=max(dmax1,dmax2);
				if dmax=dmax1 then imax:=imax1
				else if dmax=dmax2 then imax:=imax2;
				minmax(l,r,amin,amax);
				if (amin=1) and (amax=r-l+1) then
					Begin
						itam:=l;
						dtam:=r-l+1;
					End;
				dmax:=max(dmax,dtam);
				if dmax=dtam then imax:=itam;
			 End;
	End;
//----------------------------------------------------------
Procedure xuat;
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		if b[1]=0 then write(f,'0')
		else Begin
				writeln(f,a[k]);
				write(f,d);
			 End;
		close(f);
	End;
//==========================================================
BEGIN
	docfile;
	d:=0;k:=0;
	if b[1]=1 then try(1,n,k,d);
	xuat;
END.