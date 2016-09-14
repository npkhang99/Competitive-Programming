Uses Math;
Const fi='Game34.inp';
      fo='Game34.out';
      n=12;
Var a:array[1..12,1..12] of longint;
    L:array[0..12,0..12] of longint;
    c,d:array[1..12] of longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j,d,k:integer;
    Begin
        assign(f,fi);
        reset(f);
        fillchar(L,sizeof(L),0);
        d:=1; k:=0;
        for i:=1 to 5 do
            Begin
                if i mod 2=1 then
                    for j:=1 to 3 do
                        Begin
                            read(f,a[d,d+1]);
                            L[d,d+1]:=trunc(ln(a[d,d+1]) / ln(2)) +1;
                            L[d+1,d]:=L[d,d+1];
                            writeln(d,' ',d+1,' ',L[d,d+1]);
                            inc(d);
                        End;
                if i mod 2=0 then
                    Begin    
                        for j:=1 to 4 do
                            Begin
                                inc(k);
                                read(f,a[k,d+1]);
                                L[k,d+1]:=trunc(ln(a[k,d+1]) / ln(2)) +1;
                                L[d+1,k]:=L[k,d+1];
                                writeln(k,' ',d+1,' ',L[k,d+1]);
                                inc(d);
                            End;
                        d:=d-3;
                    End;
            End;
        close(f);
    End;
//---------------------------------------------------------
Function dem:longint;
    Var i:byte;
    Begin
        dem:=0;
        for i:=1 to n do
            if odd(c[i]) then inc(dem);
    End;
//---------------------------------------------------------
Procedure xoa(u:byte);
    Var v:byte;
    Begin
        
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:integer;
    Begin
        for i:=1 to n do
            case (i-1) div 4 of 0: c[i]:=L[i,i+1]+L[i,i-1]+L[i,i+4];
                                1: c[i]:=L[i,i-1]+L[i,i+1]+L[i,i-4]+L[i,i+4];
                                2: c[i]:=L[i,i-1]+L[i,i+1]+L[i,i-4];
            End;
        fillchar(d,sizeof(d),0);
        xoa(1);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.