Const fi='LICH.INP';
      fo='LICH.OUT';
Var a:array[1..100] of integer;
    b:array[1..100] of boolean;
    n,c,d:integer;
//--------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        readln(f,d,c);
        for i:=1 to n do
            Begin
                 read(f,a[i]);
            End;
        close(f);
   End;
//---------------------------------
Procedure xuat(x,y:integer);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,x);
        writeln(f,y);
        close(f);
   End;
//---------------------------------
Procedure doi(var x,y:integer);
   Var t:integer;
   Begin
        t:=y;
        y:=x;
        x:=t;
   End;
//---------------------------------
Procedure qsort(l,r:integer);
   Var i,j,x:integer;
   Begin
        i:=l;j:=r;
        x:=a[(l+r) div 2];
        repeat
              while a[i]>x do inc(i);
              while a[j]<x do dec(j);
              if i<=j then
                 Begin
                      doi(a[i],a[j]);
                      inc(i);dec(j);
                 End;
        until i>j;
        if i<r then qsort(i,r);
        if j>d then qsort(d,j);
   End;
//---------------------------------
Function di(x:integer):integer;
   Begin
        if x=0 then di:=0
        else if x>10 then di:=sqr(x-10)
        else di:=-c;
   End;
//---------------------------------
Procedure greedy;
   Var i,j,dem,x,du:integer;
   Begin
        qsort(1,n);
        fillchar(b,sizeof(b),false);
        dem:=0;du:=0;
        for i:=1 to n do
          if (not b[i]) then
            Begin
                 x:=d;
                 x:=x-a[i];b[i]:=true;
                 for j:=i+1 to n do
                     if (x-a[j]>=0) and (not b[j]) then
                        Begin
                             b[j]:=true;
                             x:=x-a[j];
                        End;
                 inc(dem);
                 du:=du+di(x);
            End;
            xuat(dem,du);
   End;
//================================
BEGIN
     docfile;
     greedy;
END.
