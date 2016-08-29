Uses math;
Const fi='BONUS.inp';
      fo='BONUS.out';
      infty=2147483648;
Var a:array[1..1000,1..1000] of longint;
    n,k:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
       i,j:longint;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do
            Begin
                 for j:=1 to n do read(f,a[i,j]);
                 readln(f);
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
Procedure BONUS;
   Var b:array[0..1000,0..1000] of longint;
       i,j,maxt,t,i1,j1:longint;
   Begin
        fillchar(b,sizeof(b),0);
        maxt:=-infty;
        for i:=1 to n do
            for j:=1 to n do
                B[i,j]:=b[i-1,j]+b[i,j-1]+a[i,j]-b[i-1,j-1];
        for i:=1 to n-k+1 do
            for j:=1 to n-k+1 do
                Begin
                     i1:=i+k-1;j1:=j+k-1;
                     t:=b[i1,j1]-b[i1,j-1]-b[i-1,j1]+b[i-1,j-1];
                     maxt:=max(maxt,t);
                End;
        xuat(maxt);
   End;
//===============================
BEGIN
     docfile;
     BONUS;
END.
