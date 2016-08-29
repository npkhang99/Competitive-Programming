Uses math;
Const fi='chatcay.inp';
      fo='chatcay.out';
Var v,c:array[1..1000] of integer;
    n,w:integer;
//------------------------------
Procedure docfile;
   Var f:text;
       i:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,w);
        for i:=1 to n do readln(f,v[i],c[i]);
        close(f);
   End;
//------------------------------
Procedure xuat(x:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//------------------------------
Procedure chatcay;
   Var L:array[0..1000,0..1000] of longint;
       i,j:integer;
   Begin
        fillchar(L,sizeof(L),0);
        for i:=1 to n do
            for j:=1 to w do
                if j>=v[i] then L[i,j]:=max(L[i-1,j-v[i]]+c[i],L[i-1,j])
                else L[i,j]:=L[i-1,j];
        xuat(L[n,w]);
   End;
//==============================
BEGIN
     docfile;
     chatcay;
END.