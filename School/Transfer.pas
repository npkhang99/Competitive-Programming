Uses math;
Const fi='Transfer.inp';
      fo='Transfer.out';
Type ngua=record
        d,c,val,tt:longint;
     End;
     noiloan=record
        kc,gt:longint;
     End;
Var a:array[1..100000] of ngua;
    b:array[0..100000] of noiloan;
    tr:array[1..100000] of longint;
    n,maxx:longint;
    fx:text;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        maxx:=0;
        for i:=1 to n do
            with a[i] do 
                Begin
                    readln(f,d,c);
                    val:=c-d;b[i].gt:=val;tt:=i;b[i].kc:=c;
                    maxx:=max(maxx,val);
                End;
        close(f);
    End;
//---------------------------------------------------------
Procedure ddi(i:integer);
    Begin
        if tr[i]>0 then
            Begin
                write(fx,a[i].tt,' ');
                ddi(tr[i]);
            End
        else write(fx,a[i].tt,' ');
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Begin
        assign(fx,fo);
        rewrite(fx);
        writeln(fx,maxx);
        ddi(x);
        close(fx);
    End;
//---------------------------------------------------------
Procedure doi(var x,y:ngua);
    Var tam:ngua;
    Begin
        tam:=y;
        y:=x;
        x:=tam;
    End;
//---------------------------------------------------------
Procedure QSort(l,r:longint);
    Var m,i,j:longint;
        tam:noiloan;
    Begin
        i:=l;j:=r;m:=a[(i+j) div 2].c;
        repeat
            while a[i].c<m do inc(i);
            while a[j].c>m do dec(j);
            if i<=j then
                Begin
                    doi(a[i],a[j]);
                    tam:=b[j];b[j]:=b[i];b[i]:=tam;
                    inc(i);dec(j);
                End;
        until i>j;
        if i<r then QSort(i,r);
        if l<j then QSort(l,j);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,vt:longint;
    Begin
        QSort(1,n);
        fillchar(tr,sizeof(tr),0);
        for i:=2 to n do
            for j:=1 to i-1 do
                if ((a[i].d>=a[j].c) or (a[i].c<=a[j].d)) and (b[i].gt<=b[j].gt+a[i].val) {and (a[i].c>b[i].kc)} then
                    Begin
                        b[i].gt:=b[j].gt+a[i].val;tr[i]:=j;b[i].kc:=a[i].c;
                        if b[i].gt>maxx then
                            Begin
                                maxx:=b[i].gt;
                                vt:=i;
                            End;
                    End;
        xuat(vt);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.