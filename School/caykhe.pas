Uses math;
Const fi='caykhe.inp';
      fo='caykhe.out';
Var a,b:array[1..1000] of integer;
    L:array[0..1001,0..1001] of integer;
    n,m:integer;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do readln(f,a[i],b[i]);
        close(f);
   End;
//-------------------------------
Procedure solve;
   Var i,j:longint;
   Begin
        fillchar(l,sizeof(l),0);
        for i:=1 to m do
            if b[1]<=i then L[1,i]:=a[1]
            else L[1,i]:=0;
        for i:=2 to n do
            for j:=1 to m do
                if b[i]<=j then L[i,j]:=max(a[i]+L[i-1,j-b[i]],L[i-1,j])
                else L[i,j]:=L[i-1,j];
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
       i,j,d:integer;
       s,st:string;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,L[n,m]);
        i:=n;j:=m;d:=0;s:='';
        while i>0 do
              Begin
                   if L[i-1,j]<>L[i,j] then
                      Begin
                           inc(d);
                           str(i,st);
                           s:=' '+st+s;
                           j:=j-b[i];
                      End;
                   dec(i);
              End;
        write(f,d,s);
        Close(f);
   End;
//===============================
BEGIN
     docfile;
     solve;
     xuat;
END.
