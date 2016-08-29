Const fi='Merge.inp';
      fo='Merge.out';
Type mang=array[1..1000] of integer;
Var a,b,c:mang;
    n,m:integer;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do read(f,a[i]);
        readln(f);
        for i:=1 to m do read(f,b[i]);
        close(f);
   End;
//-------------------------------
Procedure swap(var x,y:integer);
   Var tam:integer;
   Begin
        tam:=x;
        x:=y;
        y:=tam;
   End;
//-----------------------------
Procedure sort(var a:mang;x:integer);
   Var i,j,t:integer;
   Begin
        for i:=1 to x-1 do
            for j:=i+1 to x do
                if a[i]>a[j] then swap(a[i],a[j]);
   End;
//-------------------------------
Procedure MergeSort;
   Var i,j,k:integer;
   Begin
        k:=1;i:=1;j:=1;
        while (i<=n) and (j<=m) do
              Begin
                   if a[i]<b[j] then
                      Begin
                           c[k]:=a[i];
                           inc(i);
                      End
                   else Begin
                             c[k]:=b[j];
                             inc(j);
                        End;
                   inc(k);
              End;
        if i<n then
           for k:=k to m+n do
               Begin
                    c[k]:=a[i];
                    inc(i);
               End
        else if j<m then
                for k:=k to m+n do
                    Begin
                         c[k]:=b[j];
                         inc(j);
                    End;
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
       i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to m+n do write(f,c[i],' ');
        close(f);
   End;
//===============================
BEGIN
     docfile;
     sort(a,n);
     sort(b,m);
     MergeSort;
     xuat;
END.
