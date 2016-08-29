Const fi='Stones.inp';
      fo='Stones.out';
Var a:array[0..100] of integer;
    n:byte;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:byte;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
   End;
//-------------------------------
Procedure xuat(x:integer);
   Var f:Text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//-------------------------------
Procedure solve;
   Var i,amin,vt,t:integer;
   Begin
        t:=0;
        While n>2 do
              Begin
                   amin:=maxint;vt:=0;
                   for i:=2 to n do
                       if a[i-1]+a[i]<amin then
                          Begin
                               amin:=a[i-1]+a[i];
                               vt:=i;
                          End;
                   t:=t+amin;
                   a[vt-1]:=amin;dec(n);
                   for i:=vt to n do
                       a[i]:=a[i+1];
              End;
        xuat(t+a[1]+a[2]);
   End;
//===============================
BEGIN
     docfile;
     solve;
END.