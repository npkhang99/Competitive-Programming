Uses math;
Const fi='MEET.inp';
      fo='MEET.out';
      infty=maxint;
Var D,T:array[1..100,1..100] of integer;
    C:array[1..100] of boolean;
    n,m,u,v:integer;
//--------------------------------
Procedure Docfile;
   Var f:text;
       i,j,d1,d2:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m,u,v);
        for i:=1 to n do
            for j:=1 to n do
                Begin
                     if i<>j then D[i,j]:=infty
                     else D[i,j]:=0;
                     T[i,j]:=infty;
                End;
        for i:=1 to m do
            Begin
                 readln(f,d1,d2,D[d1,d2]);
                 T[d1,d2]:=0;
            End;
        close(f);
   End;
//--------------------------------
Procedure FLoyd;
   Var k,i,j:integer;
   Begin
        for k:=1 to n do
            for i:=1 to n do
                for j:=1 to n do
                    if D[i,k]+D[k,j]<D[i,j] then
                       Begin
                            D[i,j]:=D[i,k]+D[k,j];
                            T[i,j]:=k;
                       End;
   End;
//--------------------------------
Procedure xuat;
   Var f:text;
       t1,t2,tmin,tx1,tx2,i,x:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        tmin:=infty;tx1:=infty;tx2:=infty;x:=0;
        for i:=1 to n do
            Begin
                 t1:=D[u,i];
                 t2:=D[v,i];
                 if (t1+t2<tmin) then
                    Begin
                         tx1:=t1;
                         tx2:=t2;
                         x:=i;
                         tmin:=t1+t2;
                    End;
            End;
        if ((tx2<infty) and (tx1<infty)) then
           Begin
                write(f,x,' ',max(tx2,tx1));
                close(f);
                halt;
           End;
        write(f,'0');
        close(f);
   End;
//================================
BEGIN
     docfile;
     Floyd;
     xuat;
END.
