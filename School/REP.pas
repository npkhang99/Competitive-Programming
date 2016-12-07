Const fi='REP.inp';
      fo='REP.out';
Type doan=Record
        x,y:longint;
     End;
Var a:array[1..100000] of doan;
    L:array[1..200000] of longint;
    n,k:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do readln(f,x,y);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,k);
        for i:=1 to n do write(f,L[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure swap(Var x,y:doan);
    Var t:doan;
    Begin
        t:=x;
        x:=y;
        y:=t;
    End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
    Var i,j,m:longint;
    Begin
        i:=l; j:=r; m:=a[i + random(j-i+1)].y;
        repeat
            while a[i].y<m do inc(i);
            while a[j].y>m do dec(j);
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
    Var i:longint;
    Begin
        qsort(1,n);
        k:=2; L[1]:=a[1].y-1; L[2]:=a[1].y;
        for i:=2 to n do
            with a[i] do
                if L[k]<x then
                    Begin
                        inc(k); L[k]:=y-1;
                        inc(k); L[k]:=y;
                    End
                else if (L[k-1]<x) and (x<=L[k]) and (L[k]<=y) then
                        Begin
                            inc(k); L[k]:=y;
                        End;
    End;
//=========================================================
BEGIN
    randomize;
    docfile;
    xuly;
    xuat;
END.
