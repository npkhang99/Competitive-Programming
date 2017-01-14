Uses Math;
Const fi='Nguoitho.inp';
      fo='Nguoitho.out';
Var a,L,U:array[0..100,0..100] of integer;
    n,m:integer;
    f:text;
//------------------------------
Procedure docfile;
   Var i,j:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
             Begin
                  for j:=1 to m do read(f,a[i,j]);
                  readln(f);
             End;
        close(f);
   End;
//------------------------------
Procedure ddi(i,j:integer);
   Begin
        if (i>0) and (j>0) then
           Begin
                ddi(i-1,j-U[i,j]);
                write(f,U[i,j],' ');
           End;
   End;
//------------------------------
Procedure xuat(x:integer);
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,x);
        ddi(n,m);
        close(f);
   End;
//------------------------------
Procedure Tinh(k,v:integer);
   Var t,i,x,y:integer;
   Begin
        x:=L[k-1,v];
        y:=0;
        for i:=1 to v do
            Begin
                 t:=A[k,i]+L[k-1,v-i];
                 if t>x then
                    Begin
                         x:=t;
                         y:=i;
                    End;
            End;
        L[k,v]:=x;
        U[k,v]:=y;
   End;
//------------------------------
Procedure Nguoitho;
   Var k,v:integer;
   Begin
        fillchar(L,sizeof(L),0);
        for k:=1 to n do
            for v:=1 to m do
                if k=1 then
                   Begin
                        U[1,v]:=v;
                        L[1,v]:=A[1,v];
                   End
                Else Tinh(k,v);
        xuat(L[n,m]);
   End;
//==============================
BEGIN
     docfile;
     Nguoitho;
END.
