Uses Math;
Const fi='Thanchu.inp';
	  fo='Thanchu.out';
Var L:array[0..1000,0..1000] of longint;
	s,s1,s2:ansistring;
	l1,r1,l2,r2:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		read(f,l1,r1,l2,r2);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x:longint);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x);
		close(f);
	End;
//---------------------------------------------------------
Procedure tao;
	Var ch:byte;
	Begin
		ch:=ord('a');
		s:='a';
		while length(s)<max(r1,r2) do
			Begin
				inc(ch);
				s:=s+char(ch)+s;
			End;
	End;
//---------------------------------------------------------
Procedure chung;
	Var i,j:longint;
	Begin
		s1:=copy(s,l1,r1-l1+1);
		s2:=copy(s,l2,r2-l2+1);
		for i:=1 to length(s1) do
			for j:=1 to length(s2) do
				if s1[i]=s2[j] then L[i,j]:=L[i-1,j-1]+1
				else L[i,j]:=max(L[i-1,j] , L[i,j-1]);
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		fillchar(L,sizeof(L),0);
		tao;
		chung;
		xuat(L[length(s1), length(s2)]);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.