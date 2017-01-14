Uses Math;
Const fi='Squid.inp';
      fo='Squid.out';
Var G,X:array[1..100000] of longint;
    n,k,maxX,Muc:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do
            Begin
                 readln(f,G[i],X[i]);
                 maxX:=max(maxX,X[i]);
            End;
        close(f);
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,Muc);
        close(f);
   End;
//-------------------------------
Function tong(kc:longint):int64;
   Var i:longint;
   Begin
        tong:=0;
        for i:=1 to n do
            if abs(X[i]-kc)<=k then tong:=tong+G[i];
   End;
//-------------------------------
Procedure Squid(l,r:longint);
   Var tongM,kc:int64;
   Begin
        if l>r then exit;
        kc:=(l+r) div 2;
        tongM:=tong(kc);
        Muc:=Max(Muc,tongM);
        Squid(kc+1,r);
        Squid(l,kc-1);
   End;
//===============================
BEGIN
     docfile;
     Muc:=0;
     Squid(1,maxX);
     xuat;
END.
