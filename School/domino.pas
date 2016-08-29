Const fi='domino.inp';
      fo='domino.out';
Type domino=record
        tren,duoi,tong1,tong2:shortint;
     End;
     mang=array[1..20] of domino;
Var a:mang;
    n,t:shortint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:shortint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        t:=0;
        for i:=1 to n do
            with a[i] do
                 Begin
                      readln(f,tren,duoi);
                      tong1:=tren-duoi;
                      tong2:=-tong1;
                      t:=t+tong1;
                 End;
        close(f);
   End;
//-------------------------------
Procedure xuat(x,y:byte);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x,' ',y);
        close(f);
   End;
//-------------------------------
Procedure doi(x,y:domino);
   Var tam:domino;
   Begin
        tam:=y;
        y:=x;
        x:=tam;
   End;
//-------------------------------
Procedure qsort(var a:mang;l,r:shortint);
   Var i,j,x:shortint;
   Begin
        i:=l;j:=r;
        x:=a[(i+j) div 2].tong2;
        repeat
              while a[i].tong2>x do inc(i);
              while a[j].tong2<x do dec(j);
              if i<=j then
                 Begin
                      doi(a[i],a[j]);
                      inc(i);dec(j);
                 End;
        until i>j;
        if i<r then qsort(a,i,r);
        if j>l then qsort(a,l,j);
   End;
//-------------------------------
Procedure solve;
   Var i,d,x,y:shortint;
   Begin
        qsort(a,1,n);
        d:=0;
        for i:=1 to n do
          if a[i].tong2>0 then
            Begin
                 x:=a[i].tong1;
                 y:=a[i].tong2;
                 if abs(t-x+y)<abs(t) then
                    Begin
                         inc(d);
                         t:=t-x+y;
                    End;
            End;
        xuat(abs(t),d);
   End;
//===============================
BEGIN
     docfile;
     solve;
END.