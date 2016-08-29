uses sysutils;
var n,test:longint;
	st:string;

Function toString(x:longint):string;
	Begin
		if(x<10) then exit('0'+chr(x+48));
		toString:='';
		while(x>0) do
			Begin
				toString:=chr(x mod 10 + 48) + toString;
				x:=x div 10;
			End;
	End;

BEGIN
	readln(n);
	for test:=1 to n do
		Begin
			st:=toString(test);
			st:='TEST'+st;
			CreateDir(st);
		End;
END.