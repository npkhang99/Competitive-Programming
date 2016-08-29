Const fi='HoaHoc.inp';
	  fo='HoaHoc.out';
	  dau:array[1..2] of char=('+','x');
Var ct:ansistring;
//---------------------------------------------------------
Function bt_dai_so:ansistring;
	Var i:integer;
		s:ansistring;
	Begin
		s:='';
		for i:=1 to length(ct) do
			Begin
				case ct[i] of 'C': s:=s+'12';
							  'H': s:=s+'1';
							  'O': s:=s+'16';
							  '2': s:=s+'x2';
							  '3': s:=s+'x3';
							  '4': s:=s+'x4';
							  '5': s:=s+'x5';
							  '6': s:=s+'x6';
							  '7': s:=s+'x7';
							  '8': s:=s+'x8';
							  '9': s:=s+'x9';
							  '(': s:=s+'(';
							  ')': s:=s+')';
				End;
				if (i<length(ct)) and 
				   ((ct[i+1] in ['A'..'Z']) or (ct[i+1]='(')) and 
				   ((s[length(s)] in ['1'..'9']) or (s[length(s)]=')'))
					then s:=s+'+';
			End;
		exit(s);
	End;
//---------------------------------------------------------
Procedure docfile;
	Var f:text;
	Begin
		assign(f,fi);
		reset(f);
		read(f,ct);
		ct:=bt_dai_so;
		close(f);
	End;
//---------------------------------------------------------
Procedure ngoac(Var s:ansistring);
	Var i,d:integer;
	Begin
		if (s[1]='(') and (s[length(s)]=')') then
			Begin
				d:=0;
				for i:=1 to length(s) do
					Begin
						if s[i]='(' then inc(d);
						if s[i]=')' then dec(d);
						if (i<length(s)) and (d=0) then exit;
					End;
				if d=0 then
					Begin
						delete(s,1,1); delete(s,length(s),1);
					End;
			End;
	End;
//---------------------------------------------------------
Function find(s:ansistring):integer;
	Var i,j,ng:integer;
	Begin
		for i:=1 to 2 do
			Begin
				ng:=0;
				for j:=1 to length(s) do
					Begin
						if s[j]='(' then inc(ng);
						if s[j]=')' then dec(ng);
						if (ng=0) and (s[j]=dau[i]) then exit(j);
					End;
			End;
		exit(0);
	End;
//---------------------------------------------------------
Function cal(x,y:integer; dau:char):integer;
	Begin
		cal:=0;
		case dau of '+':exit(x+y);
					'x':exit(x*y);
		End;
	End;
//---------------------------------------------------------
Function value(s:ansistring):integer;
	Var x1,x2:ansistring;
		d:integer;
	Begin
		ngoac(s);
		d:=find(s);
		if d=0 then
			Begin
				val(s,value,d);
			End
		else Begin
				x1:=copy(s,1,d-1); x2:=copy(s,d+1,length(s));
				exit(cal(value(x1),value(x2),s[d]));
			 End;
	End;
//---------------------------------------------------------
Procedure xuat;
	Var f:text;
		d:integer;
	Begin
		assign(f,fo);
		rewrite(f);
		write(f,value(ct)); write(ct);
		close(f);
	End;
//---------------------------------------------------------
BEGIN
	docfile;
	xuat;
END.