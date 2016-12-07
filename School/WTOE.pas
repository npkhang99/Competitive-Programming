Uses math;
Const fi='WTOE.inp';
      fo='WTOE.out';
      maxMN=100;
Type arr=array[0..maxMN+1,0..maxMN+1] of longint;
Var a,b:arr;
    f:text;
    n,m:integer;
//--------------------------------
Procedure docfile;
   Var i,j:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
            Begin
                 for j:=1 to m do read(f,a[i,j]);
                 readln(F);
            End;
        close(f);
   End;
//--------------------------------
Procedure xuat(x,vt:longint);
   Var D:array[1..100] of integer;
       i,j,t:longint;
   Begin
        writeln(f,x);
        i:=vt;j:=m;t:=x;
        repeat
              D[j]:=i;
              t:=t-a[i,j];
              if t=B[i-1,j-1] then dec(i)
              else if t=B[i+1,j-1] then inc(i);
              dec(j);
        until j=0;
        write(f,D[1]);
        for i:=2 to m do write(f,' ',D[i]);
   End;
//--------------------------------
Procedure WTOE;
   Var i,j,t1,t2,t3,vt,ln:longint;
   Begin
        fillchar(b,sizeof(b),0);
        ln:=-maxlongint;
        for i:=1 to n do
            for j:=1 to m do
                Begin
                     t1:=b[j-1,i-1]+a[j,i];
                     t2:=b[j,i-1]+a[j,i];
                     t3:=b[j+1,i-1]+a[j,i];
                     b[j,i]:=max(t1,max(t2,t3));
                     if b[j,i]>ln then
                        Begin
                             ln:=b[j,i];
                             vt:=j;
                        End;
                End;
        xuat(ln,vt);
   End;
//================================
BEGIN
     docfile;
     assign(f,fo);
     rewrite(f);
     WTOE;
     close(f);
END.
