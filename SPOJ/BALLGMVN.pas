Type diem=Record
        x,y:longint;
        cotg:real;
        tt:longint;
     End;
     mang=array[0..1009] of diem;
Var g,r,a:mang;
    n:longint;
//---------------------------------------------------------
Procedure doc;
    Var i:longint;
    Begin
        readln(n);
        for i:=1 to n do
            with g[i] do
                Begin
                    readln(x,y);
                    tt:=i;
                End;
        for i:=1 to n do
            with r[i] do
                Begin
                    readln(x,y);
                    tt:=n+i;
                End;
    End;
//---------------------------------------------------------
Procedure swap(Var i,j:longint);
    Var t:diem;
    Begin
        t:=a[i]; a[i]:=a[j]; a[j]:=t;
        inc(i); dec(j);
    End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
    Var i,j:longint;
        m:real;
    Begin
        i:=l; j:=r; m:=a[i+random(j-i+1)].cotg;
        repeat
            while a[i].cotg<m do inc(i);
            while a[j].cotg>m do dec(j);
            if i<=j then swap(i,j);
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,u,v:longint;
    Begin
        //bi xanh lam goc
        for i:=1 to n do
            Begin
                for j:=1 to n do
                    Begin
                        u:=r[j].x-g[i].x;
                        v:=r[j].y-g[i].y;
                        a[j].tt:=r[j].tt;
                        if v=0 then a[j].cotg:=maxlongint
                        else a[j].cotg:=u/v;
                    End;
                qsort(1,n);
                for j:=1 to n-1 do
                    if a[j].cotg=a[j+1].cotg then
                        Begin
                            writeln(a[j].tt,' ',a[j+1].tt,' ',g[i].tt);
                            halt;
                        End;
            End;
        //bi do lam goc
        for i:=1 to n do
            Begin
                for j:=1 to n do
                    Begin
                        u:=g[j].x-r[i].x;
                        v:=g[j].y-r[i].y;
                        a[j].tt:=g[j].tt;
                        if v=0 then a[j].cotg:=maxlongint
                        else a[j].cotg:=u/v;
                    End;
                qsort(1,n);
                for j:=1 to n-1 do
                    if a[j].cotg=a[j+1].cotg then
                        Begin
                            writeln(a[j].tt,' ',a[j+1].tt,' ',r[i].tt);
                            halt;
                        End;
            End;
        writeln('-1');
    End;
//---------------------------------------------------------
BEGIN
    randomize;
    doc;
    xuly;
END.
