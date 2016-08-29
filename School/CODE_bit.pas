Uses math;
Const fi='CODE.INP';
      fo='CODE.OUT';
Var a:array[0..125000000] of byte;
    n:longint;
//--------------------------------
Procedure batbit(Var x:byte;q:byte);
   Begin
        x:=(1 shl q) or x;
   End;
//--------------------------------
Function laybit(x,q:byte):byte;
   Begin
        laybit:=((1 shl q) and x) shr q;
   End;
//--------------------------------
Procedure docfile;
   Var f:text;
       x,i:longint;
   Begin
        assign(f,fi);
        reset(f);
        fillchar(a,sizeof(a),0);
        n:=0;
        while not eof(f) do
              Begin
                   read(f,x);
                   n:=max(n,x);
                   batbit(a[x div 8],x mod 8);
              End;
        close(f);
   End;
//--------------------------------
Procedure xuat(x:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
        halt;
   End;
//--------------------------------
Procedure solve;
   Var i,j:longint;
   begin
        for i:=0 to n do
            for j:=0 to 7 do
                if laybit(a[i],j)=0 then xuat(i*8+j);
   End;
//================================
BEGIN
     docfile;
     solve;
END.