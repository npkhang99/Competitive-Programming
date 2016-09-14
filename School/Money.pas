Const fi='Money.inp';
      fo='Money.out';
Var a:array[1..100] of integer;
    L,sl,t:array[0..100,0..100000] of longint;
    n,m:longint;
    f:text;
//---------------------------------------------------------
Procedure docfile;
    Var i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do 
            Begin
                read(f,a[i]);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure trace(i,j:integer);
    Begin
        if (i>0) and (j>0) then
            Begin
                if L[i,j]=l[i+1,j] then trace(i+1,j)
                else Begin
                        writeln(f,i,' ',sl[i,j]);
                        trace(i+1,j-sl[i,j]*a[i]);
                     End;
            End;
    End;
//---------------------------------------------------------
Procedure xuat;
    Begin
        assign(f,fo);
        rewrite(f);
        if L[1,m]=m then
            Begin
                writeln(f,t[1,m]);
                trace(1,m);
            End
        else write(f,'0');
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,k,max,s:longint;
    Begin
        fillchar(L,sizeof(L),0);
        fillchar(sl,sizeof(sl),0);
        fillchar(t,sizeof(t),0);
        for i:=n downto 1 do
            for j:=1 to m do
                Begin
                    max:=L[i+1,j];
                    s:=0;
                    for k:=0 to j div a[i] do
                        if L[i+1,j-k*a[i]]+k*a[i] > max then
                            Begin
                                max:=L[i+1,j-k*a[i]]+k*a[i];
                                s:=k;
                            End;
                    L[i,j]:=max;
                    sl[i,j]:=s;
                    t[i,j]:=t[i+1,j-s*a[i]] + s;
                End;
        xuat;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.