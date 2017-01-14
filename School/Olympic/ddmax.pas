Uses Math;
Const fi='ddmax.inp';
      fo='ddmax.out';
Var a:array[1..100000] of longint;
    n:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        close(f);
   End;
//-------------------------------
Procedure xuat(x:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//-------------------------------
Procedure solve;
   Var i:longint;
       dmax,d,t,vt:int64;
       b:array[0..1000000] of int64;
   Begin
        dmax:=0;
        b[0]:=0;
        for i:=1 to n do
            if (b[i-1]+a[i]>B[i-1]) or (b[i-1]+a[i]>0) then b[i]:=b[i-1]+a[i]
        d:=0;
        for i:=1 to n do
            if (b[i-1]+a[i]=b[i]) then
               Begin
                    inc(d);
                    t:=i;
               End
            else Begin
                      if (d>dmax) and (b[t]>0) then dmax:=d;
                      d:=0;
                 End;
        xuat(dmax);
   End;
//===============================
BEGIN
     docfile;
     solve;
END.
