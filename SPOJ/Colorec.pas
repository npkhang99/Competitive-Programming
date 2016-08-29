// SPOJ submission 15808174 (PAS fpc) plaintext list. Status: AC, problem COLOREC, contest SPOJVN. By mansblacks (Khang), 2015-12-08 09:28:19.
Uses Math;
Const maxN=209;
Var a:array[-maxN..maxN,-maxN..maxN] of byte;
	dem:array[1..15] of longint;
	n,ymin,ymax,xmax,xmin:longint;
//---------------------------------------------------------
Function cal(c:integer):integer;
	Begin
		case c of 1:exit(1);
				  2:exit(2);
				  3:exit(4);
				  4:exit(8);
			End;
	End;
//---------------------------------------------------------
Procedure doc;
	Var x,y,i,c:longint;
		f:text;
	Begin
		assign(f,'');reset(f);
		fillchar(a,sizeof(a),0);
		readln(f,n);
		ymin:=maxint; ymax:=-maxint; xmin:=ymin; xmax:=ymax;
		for i:=1 to n do
			Begin
				readln(f,x,y,c);
				a[x,y]:=cal(c);
				ymin:=min(ymin, y); ymax:=max(ymax, y);
				xmin:=min(xmin, x); xmax:=max(xmax, x);
			End;
		//writeln(xmin,' ',xmax,' ',ymin,' ',ymax);
		close(f);
	End;
//---------------------------------------------------------
Procedure xuly;
	Var x,y1,y2:integer;
		count,d:longint;
	Begin
		d:=0;
		for y1:=ymin to ymax-1 do
			for y2:=y1+1 to ymax do
				Begin
					fillchar(dem,sizeof(dem),0);
					for x:=xmin to xmax do
						inc(dem[a[x,y1]+a[x,y2]]);
					inc(d, dem[3]*dem[12]+dem[5]*dem[10]+dem[9]*dem[6]);
				End;
		write(d);
	End;
//---------------------------------------------------------
BEGIN
	doc;
	xuly;
END.