Uses math;
Const fi='Minmax.inp';
      fo='Minmax.out';
Var a:array[1..100000000] of integer;
    n,amin,amax:integer;
//----------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
    End;
//----------------------------------------------------------
Procedure try(l,r:integer;var amin,amax:integer);
    Var amin1,amax1,amin2,amax2:integer;
    Begin
        if l=r then
            Begin
                amin:=a[l];
                amax:=a[l];
            End
        else Begin
                try(l,(l+r) div 2,amin1,amax1);
                try((l+r) div 2+1,r,amin2,amax2);
                amin:=min(amin1,amin2);
                amax:=max(amax1,amax2);
             End;
    End;
//----------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,amax,' ',amin);
        close(f);
    End;
//==========================================================
BEGIN
    docfile;
    amin:=maxint;amax:=-maxint;
    try(1,n,amin,amax);
    xuat;
END.
