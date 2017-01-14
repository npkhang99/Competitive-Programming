Const fi='domino.inp';
      fo='domino.out';
Type domino=record
        tren,duoi,tong:shortint;
     End;
     mang=array[1..20] of domino;
Var a:mang;
    b:array[1..20] of byte;
    n,t,d:shortint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i:shortint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        t:=0;d:=0;
        for i:=1 to n do
            with a[i] do
                 Begin
                      readln(f,tren,duoi);
                      tong:=tren-duoi;
                      t:=t+tong;
                 End;
        close(f);
   End;
//-------------------------------
Procedure xuat(x,y:byte);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x,' ',y);
        close(f);
   End;
//-------------------------------
Procedure ktra;
   Var j,tam,dtam:integer;
   Begin
        tam:=t;dtam:=0;
        for j:=1 to n do
            if b[j]=1 then
               Begin
                    tam:=tam-2*a[j].tong;
                    inc(dtam);
               End;
        if abs(tam)<abs(t) then
           Begin
                t:=tam;
                d:=dtam;
           End;
        if t=0 then
           Begin
                xuat(t,d);
                halt;
           End;
   End;
//-------------------------------
Procedure Try(i:integer);
   Var j:integer;
   Begin
        if i>n then ktra
        else for j:=0 to 1 do
                 Begin
                      b[i]:=j;
                      try(i+1);
                 End;
   End;
//===============================
BEGIN
     docfile;
     try(1);
     xuat(abs(t),d);
     readln;
END.
