Const fi='CREATION.inp';
      fo='CREATION.out';
Var a:array[0..100,0..100] of integer;
    b:array[1..100] of integer;
    c:array[1..100] of boolean;
    p,m,n:integer;
//------------------------------
Procedure son(l,t,r,b,x:integer);
   Var i,j:integer;
   Begin
        c[x]:=true;
        for i:=l to r-1 do
            for j:=t to b-1 do
                a[i,j]:=x;
   End;
//------------------------------
Procedure docfile;
   Var f:text;
       i,l,t,r,b,x:integer;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,p,n,m);
        fillchar(c,sizeof(c),false);
        for i:=1 to p do
            Begin
                 readln(f,l,t,r,b,x);
                 son(l,t,r,b,x);
            End;
        close(f);
   End;
//------------------------------
Procedure xuat(t:integer);
   Var f:text;
       i:integer;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,t);
        for i:=1 to p do
            if c[i] then writeln(f,i,' ',b[i]);
        close(f);
   End;
//------------------------------
Procedure solve;
   Var i,j,d,t:integer;
   Begin
        fillchar(b,sizeof(b),0);
        for i:=1 to n do
            for j:=1 to m do
                if a[i,j]>0 then inc(b[a[i,j]]);
        t:=0;
        for i:=1 to p do
            if (c[i]) and (b[i]=0) then
               Begin
                    inc(t);
                    C[i]:=false;
               End;
        xuat(t);
   End;
//==============================
BEGIN
     docfile;
     solve;
END.
