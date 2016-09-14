Const fi='FibiStr.inp';
      fo='FibiStr.out';
Var s,f,f1,f2:ansistring;
    d:array[1..90] of int64;
    n,tr,k:integer;
//---------------------------------------------------------
Function tim:int64;
    Var j:int64;
    Begin
        
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,dau,cuoi,them:int64;
    Begin
        f1:='B'; f2:='A';
        if f1=s then d[1]:=1;
        if f2=s then d[2]:=2;
        for i:=3 to n do
            Begin
                d[i]:=d[i-1]+d[i-2];
                f:=f1+f2;
                them:=0;
                if length(f)>=length(s) then
                    them:=tim;
                d[i]:=d[i]+them;
                f:=f1; f1:=f2;
            End;
    End;
//---------------------------------------------------------
Procedure docfile;
    Var ff1,ff2:text;
    Begin
        assign(ff1,fi); assign(ff2,fo);
        reset(ff1); rewrite(ff2);
        while not eof(ff) do
            Begin
                readln(f,n,s);
                writeln(f,d[n]);
            End;
        close(ff1); close(ff2);
    End;
//=========================================================
BEGIN
    docfile;
END.