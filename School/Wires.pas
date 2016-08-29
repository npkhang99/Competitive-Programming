Const fi='Wires.inp';
      fo='Wires.out';
Var L:array[1..100000] of longint;
    n,k,lmax,max:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        Lmax:=0;
        for i:=1 to n do
            Begin
                 readln(f,L[i]);
                 if L[i]>Lmax then Lmax:=l[i];
            End;
        close(f);
   End;
//-------------------------------
Procedure xuat(a:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,a);
        close(f);
   End;
//-------------------------------
Function tong(a:longint):int64;
   Var i:longint;
   Begin
        tong:=0;
        for i:=1 to n do tong:=tong+(L[i] div a);
   End;
//-------------------------------
Procedure Wires(d,c:longint);
   Var x:longint;
       ktong:int64;	
   Begin
        if d>c then
           Begin
                if max>0 then xuat(max)
                else xuat(0);
                halt;
           End;
        x:=(d+c) div 2;
        ktong:=tong(x);
        if ktong=k then
           Begin
                if x>max then max:=x;
                Wires(x+1,c);
           End
        else if ktong>k then Wires(x+1,c)
        else Wires(d,x-1);
   End;
//===============================
BEGIN
     docfile;
     max:=0;
     Wires(1,Lmax);
END.
