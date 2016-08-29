Const fi='Password.inp';
	  fo='Password.out';
Var a:array[0..100000] of longint;
	st,s:ansistring;
	n,m,front,back,deviate:longint;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
		i:longint;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,st);
		read(f,s);
		n:=length(st);
		m:=length(s);
		a[0]:=0;
		for i:=1 to n do
			a[i]:=a[i-1]+(ord(st[i])-48);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat(x,y:longint);
	Var f:text;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,x,' ',y);
		write(x,' ',y);
		close(f);
		halt;
	End;
//---------------------------------------------------------
Function doan(x,y:longint):ansistring;
	Var tong:longint;
	Begin
		tong:=a[y]-a[x-1];
		str(tong,doan);
	End;
//---------------------------------------------------------
Procedure tim;
	Var i:longint;
	Begin
		i:=1;
		while st[i]=s[i] do inc(i);
		front:=i-1;
		if front=n then xuat(1,1);
		i:=length(s);
		while st[i+deviate]=s[i] do dec(i);
		back:=length(s)-i;
	End;
//---------------------------------------------------------
Function sosanh(ss1,ss2:ansistring):shortint;
	Begin
		if length(ss1)<length(ss2) then exit(1)
		else if length(ss1)>length(ss2) then exit(-1)
		else if ss1>ss2 then exit(-1)
		else if ss1<ss2 then exit(1)
		else exit(0);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var i,j,k:longint;
		s1,s2:ansistring;
	Begin
		deviate:=n-m;
		tim;
		for i:=1 to front+1 do
			for j:=0 to 5 do
				Begin
					if (i+j>m) then break;
					if m-i-j>back then continue;
					s1:=''; k:=0;
					s2:=copy(s,i,j+1);
					while (sosanh(s1,s2)>=0) and (i+k<=n) do
						Begin
							s1:=doan(i,i+k);
							if (m-i-j<=back) and (n-i-k<=back) and (m-i-j=n-i-k) and (s1=s2) then
								xuat(i,i+k);
							inc(k);
						End;
				End;
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.
