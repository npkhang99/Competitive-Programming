Uses math;
Const fi='XL02.inp';
      fo='XL02.out';
Type chitiet=record
        val,nhom,tt,ct:integer;
     End;
Var a:array[1..10000] of chitiet;
    n,d1,d2:integer;
//----------------------------------------------------
Procedure docfile;
    Var f:text;
        i,t1,t2,x,y:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        t1:=0;t2:=0;d1:=0;d2:=0;
        for i:=1 to n do
            with a[i] do
                Begin
                    read(f,x,y);
                    t1:=t1+x;
                    t2:=max(t1,t2)+y;
                    if t1<=t2 then 
                        Begin
                            val:=t1;
                            nhom:=1;
                            inc(d1);
                            tt:=d1;
                            ct:=i;
                        End
                    else Begin
                            val:=t2;
                            nhom:=2;
                            inc(d2);
                            tt:=d2;
                            ct:=i;
                         End;
            End;
        close(f);
    End;
//----------------------------------------------------
Procedure xuat;
    Var f:text;
        i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,a[n].val);
        for i:=1 to n do write(f,a[i].ct,' ');
        close(f);
    End;
//----------------------------------------------------
Function tim(x,y:integer):integer;
    Var i:integer;
    Begin
        for i:=1 to n do
            if (x=a[i].tt) and (y=a[i].nhom) then exit(i);
    End;
//----------------------------------------------------
Procedure doi(var x,y:chitiet);
    Var tam:chitiet;
    Begin
        tam:=x;
        x:=y;
        y:=tam;
    End;
//----------------------------------------------------
Procedure QSort(l,r,tt:integer);
    Var i,j,x:integer;
    Begin
        i:=l;j:=r;x:=a[tim((i+j) div 2,tt)].val;
        repeat
            if tt=1 then
                Begin
                    while (a[tim(i,tt)].val<x) do inc(i);
                    while (a[tim(j,tt)].val>x) do dec(j);
                End
            else Begin
                    while (a[tim(i,tt)].val>x) do inc(i);
                    while (a[tim(j,tt)].val<x) do dec(j);
                 End;
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    inc(i);dec(j);
                End;
        until i>j;
        if l<j then QSort(l,j,tt);
        if r>i then QSort(i,r,tt);
    End;
//----------------------------------------------------
Procedure Johnson;
    Begin
        QSort(1,d1,1);QSort(1,d2,2);
        xuat;
    End;
//====================================================
BEGIN
    docfile;
    Johnson;
END.