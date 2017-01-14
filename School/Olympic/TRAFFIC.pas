Const fi='Traffic.inp';
      fo='Traffic.out';
Type canh=record
        u,v:integer;
     End;
Var G:array[1..1000,1..1000] of longint;
    H:array[1..1000000] of canh;
    n,k:integer;
//------------------------------
Procedure xuat(x:int64);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        if x=0 then write(f,'YES')
        else write(f,x);
        close(f);
   End;
//------------------------------
Procedure docfile;
   Var f:text;
       i,j:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to k do readln(f,h[i].u,h[i].v);
        for i:=1 to n do
            Begin
                 for j:=1 to n do read(f,g[i,j]);
                 readln(f);
            End;
        close(f);
   End;
//------------------------------
Procedure Traffic;
   Var s:int64;
   Begin

   End;
//==============================
BEGIN
     docfile;
     Traffic;
END.
