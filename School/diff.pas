uses math;
const 	fi = 'diff.inp';
		fo = 'diff.out';
		maxn = 100000;
type arr = array[1..maxn] of longint;
var a:arr;
	n,diff,maxd, mind: longint;
procedure input;
var f:text;
	i:longint;
begin
	assign(f,fi); reset(f);
	readln(f,n);
	for i:=1 to n do read(f,a[i]);
	close(f);
end;
procedure finddiff(d,c:longint; var maxd,mind, maxdiff:longint);
var m, max1, max2, min1, min2, maxdd1, maxdd2:longint;
begin
	if d=c then
	begin
		maxd:=a[d];
		mind:=a[d];
		maxdiff:=0;
	end
	else
	begin
		m:= (d+c) div 2;
		finddiff(d,m,max1, min1, maxdd1);
		finddiff(m+1,c,max2, min2, maxdd2);
		maxd:= max(max1,max2);
		mind:=min(min1,min2);
		maxdiff:=maxd-mind;
	end;
end;
procedure output;
var f:text;
begin
	assign(f,fo); rewrite(f);
	write(f,diff);
	close(f);
end;
begin
	input;
	finddiff(1,n,maxd,mind,diff);
	output;
end.
