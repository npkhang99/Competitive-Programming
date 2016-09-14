Uses Math;
Var z:array[1..1000] of longint;
    s,t,x:ansistring;
    i,n:longint;
//---------------------------------------------------------
Procedure hamZ;
    Var i,l,r:longint;
    Begin
        fillchar(z,sizeof(z),0);
        l:=1; r:=1; z[1]:=0;
        for i:=2 to n do
            Begin
                if i<=r then
                    z[i]:=min(r-i+1, z[i-l+1]);
                while (i+z[i]<=n)and (x[z[i]+1]=x[i+z[i]]) do inc(z[i]);
                if i+z[i]-1>r then
                    Begin
                        l:=i; r:=i+z[i]-1;
                    End;
            End;
    End;
//=========================================================
BEGIN
    readln(t);
    readln(s);
    x:=s+'$'+t; n:=length(x);
    hamZ;
    for i:=1 to n do write(z[i],' ');
END.