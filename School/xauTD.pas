Const fi='xauTD.inp';
	  fo='xauTD.out';
Var s1,s2:ansistring;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,s1);
		read(f,s2);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(s:string);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,s);
		close(f);
	End;

//---------------------------------------------------------
Function try(l1,r1,l2,r2:longint):boolean;
	Var a,b:longint;
	Begin
		if (odd(r1-l1+1)) or (odd(r2-l2+1)) then exit(false)
		else if r1-l1>1 then
				Begin
					a:=(r1-l1+1) div 2;
					b:=(r2-l2+1) div 2;
					exit((try(l1,a,l2,b) and try(a+1,r1,b+1,r2)) or (try(l1,a,b+1,r2) and try(a+1,r1,l1,b)));
				End
		else exit(((s1[l1]=s2[l2]) and (s1[r2]=s2[r2])) or ((s1[l1]=s2[r2]) and (s1[r1]=s2[l2])));
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		if try(1,length(s1),1,length(s2)) then xuat('YES')
		else xuat('NO');
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.