//--- Nguyen Phuc Khang . 10 Tin
Const fi='ghep.inp';
      fo='ghep.out';
Type mang=array[1..1000] of integer;
Var a,b,c:mang;
    n:integer;
//--------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        readln(f);
        for i:=1 to n do read(f,b[i]);
        close(f);
   End;
//--------------------------------
Procedure xuat;
   Var f:text;
       i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do write(f,c[i],' ');
        close(f);
   End;
//--------------------------------
Procedure doi(var x,y:integer);
   Var t:integer;
   Begin
        t:=x;
        x:=y;
        y:=t;
   End;
//-------------------------------
procedure qsort(var a:mang;l,r:longint);
   Var i,j,x:longint;
   Begin
        i:=l;j:=r;
        x:=a[(i+j) div 2];
        repeat
              while a[i]<x do inc(i);
              while a[j]>x do dec(j);
              if i<=j then
                 Begin
                      doi(a[i],a[j]);
                      inc(i);
                      dec(j);
                 End;
        until i>j;
        if i<r then qsort(a,i,r);
        if j>l then qsort(a,l,j);
   End;
//--------------------------------
Procedure solve;
   Var i:integer;
   Begin
        for i:=1 to n do c[i]:=a[i]+b[i];
        xuat;
   End;
//================================
BEGIN
     docfile;
     qsort(a,1,n);
     qsort(b,1,n);
     solve;
END.
