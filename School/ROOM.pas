Const fi='ROOM.inp';
	  fo='ROOM.out';
Type room=record
		tt,bd,kt:integer;
	 End;
Var a:array[1..5000] of room;
	b:array[1..5000] of boolean;
	n:integer;
//----------------------------------------------------
Procedure docfile;
	Var f:text;
		i:integer;
	Begin
		assign(f,fi);
		reset(f);
		readln(f,n);
		for i:=1 to n do
			with a[i] do 
				Begin
					readln(f,bd,kt);
					tt:=i;
				End;
		close(f);
	End;
//----------------------------------------------------
Procedure xuat(s:integer);
	Var f:text;
		i:integer;
	Begin
		assign(f,fo);
		rewrite(f);
		writeln(f,s);
		for i:=1 to n do
			if b[i] then write(f,i,' ');
		close(f);
	End;
//----------------------------------------------------
Procedure doi(var x,y:room);
	Var tam:room;
	Begin
		tam:=x;
		x:=y;
		y:=tam;
	End;
//----------------------------------------------------
Procedure QSort(l,r:integer);
	Var i,j,x:integer;
	Begin
		i:=l;j:=r;x:=a[(i+j) div 2].kt;
		repeat
			while a[i].kt<x do inc(i);
			while a[j].kt>x do dec(j);
			if i<=j then
				Begin
					doi(a[i],a[j]);
					inc(i);dec(j);
				End;
		until i>j;
		if l<j then QSort(l,j);
		if r>i then QSort(i,r);
	End;
//----------------------------------------------------
Procedure Greedy;
	Var i,d,k:integer;
	Begin
		QSort(1,n);
		fillchar(b,sizeof(b),false);
		d:=0;k:=0;
		for i:=1 to n do
			if a[i].bd>=k then 
				Begin
					b[a[i].tt]:=true;
					inc(d);k:=a[i].kt;
				End;
		xuat(d);
	End;
//====================================================
BEGIN
	docfile;
	Greedy;
END.