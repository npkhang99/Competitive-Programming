Uses Math;
Const fi='Catgo.inp';
      fo='Catgo.out';
Var L:array[1..100000] of longint;
    n,maxL,m,maxM:longint;
//-------------------------------
Procedure Docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        maxL:=0;
        readln(f,n,m);
        for i:=1 to n do
            Begin
                 readln(f,L[i]);
                 maxL:=max(maxL,L[i]);
            End;
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
Function tong(X:longint):longint;
   Var i:longint;
   Begin
        tong:=0;
        for i:=1 to n do
            tong:=tong+(L[i] div x);
   End;
//-------------------------------
Procedure catgo(d,c:longint);
   Var x,tongM:longint;
   Begin
        if d>c then
           Begin
                xuat(maxM);
                halt;
           End;
        x:=(d+c) div 2;
        tongM:=tong(x);
        if tongM=M then
           Begin
                maxM:=max(x,maxM);
                catgo(x+1,c);
           End
        else if tongM>M then catgo(x+1,c)
        else catgo(d,x-1);
   End;
//===============================
BEGIN
     docfile;
     maxM:=0;
     catgo(1,maxL);
END.
