{--- Nguyen Phuc Khang . 10 Tin ---}
Uses Math;
Const fi='TONGKSO.inp';
      fo='TONGKSO.out';
Var a:array[1..1000000] of integer;
    n,k,x:longint;
//------------------------------
Procedure docfile;
   Var f:text;
       i:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k,x);
        for i:=1 to n do read(f,a[i]);
        close(f);
   End;
//------------------------------
Procedure xuat(kq:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,kq);
        close(f);
   End;
//------------------------------
Procedure TONGKSO;
   Var b:array[1..1000000] of longint;
       i,kq:integer;
   Begin
        fillchar(b,sizeof(b),0);
        for i:=1 to k do
            Begin
                 b[1]:=b[1]+a[i];
                 kq:=abs(b[1]-x);
            End;
        if (k=n) or (kq=0) then
           Begin
                xuat(kq);
                halt;
           End;
        for i:=2 to n-k+1 do
            Begin
                 b[i]:=b[i-1]-a[i-1]+a[i+k-1];
                 Kq:=min(kq,abs(b[i]-x));
                 if kq=0 then
                    Begin
                         xuat(kq);
                         halt;
                    End;
            End;
        xuat(kq);
   End;
//==============================
BEGIN
     docfile;
     TONGKSO;
END.
