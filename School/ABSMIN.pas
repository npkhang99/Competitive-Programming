Uses Math;
Const fi='ABSMIN.inp';
      fo='ABSMIN.out';
Type so=Record
        val:longint;
        tt:boolean;
     End;
Var a:array[1..200000] of so;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                read(f,a[i].val);
                a[i].tt:=true;
            End;
        readln(f);
        for i:=n+1 to 2*n do
            Begin
                read(f,a[i].val);
                a[i].tt:=false;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure doi(Var x,y:so);
    Var tam:so;
    Begin
        tam:=x;
        x:=y;
        y:=tam;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:longint);
    Var i,j,m:longint;
    Begin
        i:=l; j:=r; m:=a[(i+j) div 2].val;
        repeat
            while a[i].val<m do inc(i);
            while a[j].val>m do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    inc(i); dec(j);
                End;
        until i>j;
        if l<j then QSort(l,j);
        if i<r then QSort(i,r);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,absmin:longint;
    Begin
        QSort(1,2*n);
        absmin:=maxlongint;
        for i:=1 to 2*n-1 do
            if (a[i].tt xor a[i+1].tt) then
                Begin
                    absmin:=min(absmin, abs(a[i].val - a[i+1].val));
                    if absmin=0 then break;
                End;
        write(absmin);
        xuat(absmin);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
