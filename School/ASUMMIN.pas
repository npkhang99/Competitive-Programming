Const fi='ASUMMIN.inp';
      fo='ASUMMIN.out';
Type so=Record
        val,tt:longint;
        side:boolean;
     End;
Var a:array[1..200000] of so;
    n,m:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
            with a[i] do
                Begin
                    read(f,val);
                    tt:=i; side:=true;
                End;
        readln(f);
        for i:=1 to m do
            with a[n+i] do
                Begin
                    read(f,val);
                    tt:=i; side:=false; val:=-val;
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(vt:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        if a[vt].side then write(f,a[vt].tt,' ',a[vt-1].tt)
        else write(f,a[vt-1].tt,' ',a[vt].tt);
        close(f);
    End;
//---------------------------------------------------------
Procedure swap(Var x,y:so);
    Var t:so;
    Begin
        t:=x;
        x:=y;
        y:=t;
    End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
    Var i,j,x:longint;
    Begin
        i:=l; j:=r; x:=a[(i+j) div 2].val;
        repeat
            while a[i].val<x do inc(i);
            while a[j].val>x do dec(j);
            if i<=j then
                Begin
                    swap(a[i],a[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var min,i,vt:longint;
    Begin
        qsort(1,n+m);
        min:=maxlongint; vt:=0;
        for i:=2 to n+m do
            Begin
                if (abs(a[i-1].val-a[i].val)<min) and (a[i-1].side xor a[i].side) then
                    Begin
                        min:=abs(a[i-1].val-a[i].val);
                        vt:=i;
                        if min=0 then xuat(vt);
                    End;
            End;
        xuat(vt);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
