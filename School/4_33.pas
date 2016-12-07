Const fi='4_33.inp';
      fo='4_33.out';
Var a:array[1..100000] of integer;
    n,k:integer;
//--------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do read(f,a[i]);
        close(f);
   End;
//--------------------------------
Procedure xuat(x:integer);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//--------------------------------
Procedure doi(var x,y:integer);
   Var t:integer;
   Begin
        t:=y;
        y:=x;
        x:=t;
   End;
//--------------------------------
Procedure qsort(l,r:integer);
   Var i,j,x:integer;
   Begin
        i:=l;j:=r;
        x:=a[(i+j) div 2];
        repeat
              while a[i]<x do inc(i);
              while a[j]>x do dec(j);
              if i<=j then
                 Begin
                      doi(a[i],a[j]);
                      inc(i);dec(j);
                 End;
        until i>j;
        if i<r then qsort(i,r);
        if j>l then qsort(l,j);
   End;
//--------------------------------
Procedure solve;
   Var i:integer;
   Begin
        qsort(1,n);
        xuat(a[k]);
   End;
//================================
BEGIN
     docfile;
     solve;
END.
