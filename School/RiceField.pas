Const fi='RiceField.inp';
	  fo='RiceField.out';
Var a,L:array[0..100] of integer;
	b:array[0..100] of boolean;
	n,k,d:integer;
	f:text;
//---------------------------------------------------------
Procedure docfile;
	Var i,t:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,k,n);
		t:=0;
		for i:=1 to n do
			Begin
				read(f,a[i]);
				t:=t+a[i];
			End;
		a[0]:=k-t;
		close(f);
	End;
//---------------------------------------------------------
Procedure xuat;
	Var j:integer;
	Begin
		if d<=1000 then
			Begin
				inc(d);
				for j:=1 to k do write(f,L[j],' ');
				writeln(f);
				if d=1000 then
					Begin
						close(f);
						halt;
					End;
			End;
	End;
//---------------------------------------------------------
Procedure try(i:integer);
	Var j,m,o:integer;
	Begin
		if i>k then xuat
		else if i=1 then
				Begin
					for j:=1 to n do
						if not b[j] then
							Begin
								b[j]:=true;
								for m:=1 to a[j] do L[i+m-1]:=j;
								try(i+a[j]);
								b[j]:=false;
							End;
				End
		else for j:=0 to n do
				if (not b[j]) and (j>0) then
					Begin
						b[j]:=true;
						for m:=1 to a[j] do L[i+m-1]:=j;
						try(i+a[j]);
						b[j]:=false;
					End
				else if (not b[j]) and (L[i-1]<>0) then
						Begin
							for m:=a[0] downto 1 do
								Begin
									for o:=1 to m do L[i+o-1]:=0;
									a[0]:=a[0]-m;
									if a[0]=0 then b[0]:=true;
									try(i+m);
									a[0]:=a[0]+m;
									b[0]:=false;
								End;
						End;
	End;
//---------------------------------------------------------
Procedure xuly;
	Begin
		assign(f,fo);
		rewrite(f);
		d:=0;
		fillchar(L,sizeof(L),0);
		try(1);
		close(f);
	End;
//=========================================================
BEGIN
	docfile;
	xuly;
END.