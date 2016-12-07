Const fi='TSP.inp';
      fo='TSP.out';
Var a:array[1..100,1..100] of integer;
    b:array[1..100] of boolean;
    c,d:array[1..100] of integer;
    n,tmin:integer;
//----------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                for j:=1 to n do read(f,a[i,j]);
                readln(f);
            End;
        close(f);
    End;
//----------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,tmin);
        for i:=1 to n do write(f,d[i],' ');
        write(f,'1');
        close(f);
    End;
//----------------------------------------------------------
Procedure ktra(t:integer);
    Begin
        if (a[c[n],1] > 0) and (t+a[c[n],1] < tmin) then 
            Begin
                d:=c;tmin:=t+a[c[n],1];
            End;
    End;
//----------------------------------------------------------
Procedure TSP(i,t:integer);
    Var j:integer;
    Begin
        if (t>=tmin) then exit;
        if i>n then ktra(t)
        else for j:=1 to n do
                if (a[c[i-1],j] > 0) and (not b[j]) then
                    Begin
                        c[i]:=j;b[j]:=true;
                        TSP(i+1 , t+a[c[i-1],j]);
                        b[j]:=false;
                    End;
    End;
//==========================================================
BEGIN
    docfile;
    fillchar(b,sizeof(b),false);
    tmin:=maxint;c[1]:=1;b[1]:=true;
    TSP(2,0);
    xuat;
END.
