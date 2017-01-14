Uses math;
Const fi='GAME.inp';
      fo='GAME.out';
Var a:array[1..1000000] of longint;
    n:longint;
//--------------------------------
Procedure docfile;
   Var f:text;
       i,x:integer;
       ch:char;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                 readln(f,ch,x);
                 if ch='W' then a[i]:=x
                 else a[i]:=-x;
            End;
        close(f);
   End;
//--------------------------------
Procedure xuat(x,p,q:int64);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        if x>0 then
           Begin
                writeln(f,x);
                write(f,p,' ',q);
           End
        else write(f,'0');
        close(f);
   End;
//--------------------------------
Procedure solve;
   Var b:array[0..1000000] of int64;
       i:longint;
       maxb,p,q,s:int64;
   Begin
        b[0]:=0;
        for i:=1 to n do
            b[i]:=max(b[i-1]+a[i],a[i]);
        maxb:=b[0];q:=1;
        for i:=1 to n do
            if b[i]>maxb then
               Begin
                    maxb:=b[i];
                    q:=i;
               End;
        if maxb=0 then
           Begin
                xuat(0,0,0);
                halt;
           End;
        s:=b[q];p:=q;
        while s>0 do
              Begin
                   s:=s-a[p];
                   dec(p);
              End;
        xuat(b[q],p+1,q);
   End;
//================================
BEGIN
     docfile;
     solve;
END.
