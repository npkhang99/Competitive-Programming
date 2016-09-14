Const fi='Goc.inp';
      fo='Goc.out';
Var a,b:array[1..10] of integer;
    L:array[0..359] of boolean;
    n,k:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do read(f,a[i]);
        readln(f);
        for i:=1 to k do read(f,b[i]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to k do
            if not L[b[i]] then writeln(f,'NO')
            else writeln(f,'YES');
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,h,t,m:integer;
    Begin
        fillchar(L,sizeof(L),false);
        L[0]:=true;
        for i:=0 to 360 do
            if L[i] then
                Begin
                    for j:=1 to n do
                        Begin
                            h:=1; t:=i;
                            while ((i+a[j]*h) mod 360<>t) do
                                Begin
                                    L[(i+a[j]*h) mod 360]:=true;
                                    inc(h);
                                End;
                            h:=-1; m:=abs((i+a[j]*h) div 360)+1;
                            while (((360*m)+(i+a[j]*h)) mod 360<>t) do
                                Begin
                                    m:=abs((i+a[j]*h) div 360)+1;
                                    L[((360*m)+(i+a[j]*h)) mod 360]:=true;
                                    dec(h);
                                End;
                        End;
                End;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.