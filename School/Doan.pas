Uses math;
Const fi='Doan.inp';
      fo='Doan.out';
Var a:array[1..1000000] of integer;
    n,tmax:integer;
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
Procedure try(l,r:integer;var t:integer);
    Var i,t1,t2,t3:integer;
    Begin
        if l=r then t:=a[l]
        else Begin
                try(l,(l+r) div 2,t1);
                try((l+r) div 2+1,r,t2);
                t3:=0;
                for i:=l to r do t3:=t3+a[i];
                t:=max(t1,max(t2,t3));
             End;
    End;
//----------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,tmax);
        close(f);
    End;
//==========================================================
BEGIN
    docfile;
    try(1,n,tmax);
    xuat;
END.