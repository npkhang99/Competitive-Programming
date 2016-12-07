//--- Nguyen Phuc Khang . 10 Tin
Const fi='sapxep.inp';
      fo='sapxep.out';
Var a:array[1..100000] of integer;
    n:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
       i:longint;
   Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do write(f,a[i],' ');
        close(f);
   End;
//-------------------------------
Procedure doi(var x,y:integer);
   Var t:integer;
   Begin
        t:=x;
        x:=y;
        y:=t;
   End;
//-------------------------------
procedure qsort(l,r:longint);
   Var i,j,x:longint;
   Begin
        i:=l;j:=r;
        x:=a[(i+j) div 2];
        repeat
              while a[i]>x do inc(i);
              while a[j]<x do dec(j);
              if i<=j then
                 Begin
                      doi(a[i],a[j]);
                      inc(i);
                      dec(j);
                 End;
        until i>j;
        if i<r then qsort(i,r);
        if j>l then qsort(l,j);
   End;
//===============================
BEGIN
     docfile;
     qsort(1,n);
     xuat;
END.
