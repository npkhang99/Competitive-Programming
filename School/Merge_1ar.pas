Uses crt;
Type mang=array[1..1000] of integer;
Var a,b:mang;
    n,m:integer;
//-----------------------------
Procedure nhap;
   Var i:integer;
   Begin
        write('Nhap N: ');readln(n);
        for i:=1 to n do
            Begin
                a[i]:=random(50)-random(30);
                write(a[i],' ');
            End;
        writeln;
        writeln('--------------------------------------------');
        m:=n;n:=n div 2;
   End;
//-----------------------------
Procedure sort(var a:mang;x,y:integer);
   Var i,j,t:integer;
   Begin
        for i:=x to y-1 do
            for j:=i+1 to y do
                if a[i]>a[j] then
                   Begin
                        t:=a[j];
                        a[j]:=a[i];
                        a[i]:=t;
                   End;
   End;
//-----------------------------
Procedure merge;
   Var i,j,k:integer;
   Begin
        k:=1;i:=1;j:=n+1;
        while (i<=n) and (j<=m) do
              Begin
                   if a[i]<a[j] then
                      Begin
                           b[k]:=a[i];
                           inc(i);
                      End
                   else Begin
                             b[k]:=a[j];
                             inc(j);
                        End;
                   inc(k);
              End;
        for k:=k to m do
            Begin
                 b[k]:=a[j];
                 inc(j);
            End;
   End;
//-----------------------------
Procedure xuat;
   Var i:integer;
   Begin
        for i:=1 to m do write(b[i],' ');
   End;
//=============================
BEGIN
     clrscr;
     nhap;
     sort(a,1,n);
     sort(a,n div 2+1,m);
     merge;
     xuat;
     readln;
END.
