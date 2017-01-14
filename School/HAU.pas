Const fi='Hau.inp';
      fo='Hau.out';
Var a:array[1..1000,1..1000] of integer;
    b:array[1..1000] of boolean;
    c:array[-10000..10000] of boolean;
    d:array[2..2000] of boolean;
    nghiem,x:array[1..1000] of integer;
    n,tmin:integer;
//---------------------------------------------------------
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
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,tmin);
        for i:=1 to n do write(f,nghiem[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure ktra(t:integer);
    Begin
        if t<tmin then
            Begin
                tmin:=t;
                nghiem:=x;
            End;
    End;
//---------------------------------------------------------
Procedure Hau(i,t:integer);
    Var j:integer;
    Begin
        if t>=tmin then exit;
        if i>n then ktra(t)
        else for j:=1 to n do
                if (not b[j]) and (not c[i-j]) and (not d[i+j]) then
                    Begin
                        b[j]:=true;
                        c[i-j]:=true;
                        d[i+j]:=true;
                        x[i]:=j;
                        Hau(i+1 , t+a[i,j]);
                        b[j]:=false;
                        c[i-j]:=false;
                        d[i+j]:=false;
                    End;
    End;
//=========================================================
BEGIN
    docfile;
    fillchar(b,sizeof(b),false);
    fillchar(c,sizeof(c),false);
    fillchar(d,sizeof(d),false);
    tmin:=maxint;
    Hau(1,0);
    xuat;
END.
