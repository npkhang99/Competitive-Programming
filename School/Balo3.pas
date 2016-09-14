Const fi='Balo3.inp';
      fo='Balo3.out';
Type dovat=Record
        val,v:integer;
     End;
Var a:array[1..100] of dovat;
    L,sl:array[0..100,0..1000] of longint;
    n,w:integer;
    f:text;
//---------------------------------------------------------
Procedure docfile;
    Var    i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,w);
        for i:=1 to n do
            with a[i] do readln(f,v,val);
        close(f);
    End;
//---------------------------------------------------------
Procedure trace(i,j:integer);
    Begin
        with a[i] do
            if (i>0) and (j>0) then
                Begin
                    if L[i,j]=L[i-1,j] then trace(i-1,j)
                    else Begin
                            trace(i-1,j-sl[i,j]*v);
                            writeln(f,i,' ',sl[i,j]);
                         End;
                End;
    End;
//---------------------------------------------------------
Procedure xuat;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,L[n,w]);
        trace(n,w);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,k,max,s:integer;
    Begin
        fillchar(L,sizeof(L),0);
        fillchar(sl,sizeof(sl),0);
        for i:=1 to n do
            for j:=1 to w do
                with a[i] do
                    if j>=v then
                        Begin
                            max:=L[i-1,j];
                            s:=0;
                            for k:=0 to (j div v) do
                                Begin    
                                    if L[i-1,j-k*v]+val*k > max then
                                        Begin
                                            max:=L[i-1,j-k*v]+val*k;
                                            s:=k;
                                        End;
                                End;
                            L[i,j]:=max;
                            sl[i,j]:=s;
                        End
                    else L[i,j]:=L[i-1,j];
        xuat;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.