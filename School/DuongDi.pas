Const fi='DuongDi.inp';
      fo='DuongDi.out';
      infty=maxint;
      maxN=1000;
Var T,D:array[1..maxN,1..maxN] of integer;
    m,n,u,v:integer;
//--------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j,d1,d2:integer;
    Begin
         assign(f,fi);
         reset(f);
         readln(f,m,n,u,v);
         for i:=1 to n do
             for j:=1 to n do
                 if i=j then D[i,j]:=0
                 else D[i,j]:=infty;
         for i:=1 to m do
             Begin
                  readln(f,d1,d2,D[d1,d2]);
                  T[d1,d2]:=0;
             End;
         close(f);
    End;
//--------------------------------------------------
Procedure FLoyd;
   Var i,j,k:integer;
   Begin
        for k:=1 to n do
            for i:=1 to n do
                for j:=1 to n do
                    if D[i,j]>D[i,k]+D[k,j] then
                       Begin
                            D[i,j]:=D[i,k]+D[k,j];
                            T[i,j]:=k;
                       End;
   End;
//--------------------------------------------------
Function ddi(u,v:integer):string;
   Var k:integer;
       st:string;
   Begin
        if T[u,v]<>0 then
           Begin
                k:=T[u,v];
                str(k,st);
                exit(ddi(u,k)+st+ddi(k,v));
           End
        else exit(' ');
   End;
//--------------------------------------------------
Procedure xuat;
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,D[u,v]);
        write(f,u,ddi(u,v),v);
        close(f);
   End;
//==================================================
BEGIN
     docfile;
     FLoyd;
     xuat;
END.
