Uses math;
Const fi='DAYDX.inp';
      fo='DAYDX.out';
Var a:array[1..5000] of integer;
    L:array[1..5000,1..5000] of integer;
    n:integer;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[n-i+1]);
        close(f);
   End;
//-------------------------------
Procedure solve;
   Var f:text;
       b:array[1..5000] of boolean;
       i,j:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
            for j:=1 to i do
                if i=j then L[i,j]:=1
                else L[i,j]:=0;
        for i:=n-1 downto 1 do
            for j:=i+1 to n do
                if a[i]=a[j] then L[i,j]:=L[i+1,j-1]+2
                else L[i,j]:=max(L[i+1,j],L[i,j-1]);
        writeln(f,L[1,n]);
        i:=1;j:=n;
        fillchar(b,sizeof(b),false);
        repeat
              if a[i]=a[j] then
                 Begin
                      b[i]:=true;
                      b[j]:=true;
                      inc(i);dec(j);
                 End
              else if L[i+1,j]>L[i,j-1] then inc(i)
                   else dec(j);
        until i>j;
        for i:=1 to n do
            if b[i] then write(f,a[i],' ');
        close(f);
   End;
//===============================
BEGIN
     docfile;
     solve;
END.
