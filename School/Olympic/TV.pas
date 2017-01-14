Uses math;
Const fi='TV.inp';
      fo='TV.out';
Type tv=record
        bdau,kthuc:integer;
     End;
     mang=array[1..10000] of tv;
     nghiem=array[1..30000,1..10000] of integer;
Var a:mang;
    b:nghiem;
    n:integer;
//---------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do
                 Begin
                      readln(f,bdau,kthuc);
                 End;
        close(f);
   End;
//---------------------------------
Procedure xuat(x,tg:integer);
   Var f:text;
       i,j,d:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,x);
        i:=1;j:=1;d:=1;
        while d<=n do
              Begin
                   if j>tg then
                      Begin
                           inc(i);j:=1;
                      End
                   else if (b[i,j]<>d) and (j<=tg) then inc(j)
                   else Begin
                             writeln(f,d,' ',i);
                             i:=1;j:=1;inc(d);
                        End;
              End;
        close(f);
   End;
//---------------------------------
Procedure solve;
   Var i,j,ln,x,ktmax:integer;
   Begin
        fillchar(b,sizeof(b),0);
        ln:=1;ktmax:=a[1].kthuc-1;
        for i:=a[1].bdau to a[1].kthuc-1 do b[ln,i]:=1;
        for i:=2 to n do
            Begin
                 x:=1;
                 ktmax:=max(ktmax,a[i].kthuc-1);
                 for j:=a[i].bdau to a[i].kthuc-1 do
                     Begin
                          while b[x,j]<>0 do inc(x);
                          b[x,j]:=i;
                     End;
                 if x>ln then ln:=x;
            End;
        xuat(ln,ktmax);
   End;
//=================================
BEGIN
     docfile;
     solve;
END.
