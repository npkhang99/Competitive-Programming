Uses Math;
Const fi='Tourism.inp';
      fo='Tourism.out';
Type danhdau=Record
        E:boolean;
        vt:integer;
     End;
     mang=array[0..10000] of longint;
Var a,tr,tr1:mang;
    L,L1:array[0..10000] of int64;
    b:array[1..2000000] of danhdau;
    n,p,d:integer;
    f:text;
//---------------------------------------------------------
Procedure docfile;
    Var    i:dword;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        readln(f,p);
        for i:=1 to 2000000 do
            with b[i] do
                Begin
                    e:=false;
                    vt:=0;
                End;
        for i:=1 to n do 
            Begin
                read(f,a[i]);
                b[a[i]].e:=true;
                b[a[i]].vt:=i;
                tr[i]:=0;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,L[n]);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var bd,i:dword;
    Begin
        bd:=0; L[0]:=0; tr[0]:=0; d:=1; a[0]:=0;
        for i:=1 to n do
            Begin
                if abs(a[i]-bd-p)>abs(a[i-1]-bd-p) then
                    Begin
                        bd:=a[i-1];
                        tr[i]:=i-1;
                    End;
                if tr[i]=0 then tr[i]:=tr[i-1];
                L[i]:=L[tr[i]] + sqr(p-a[i]+bd);
                L1[i]:=L[i]; tr1[i]:=tr[i];
                if (a[i]-p>0) and (b[a[i]-p].e) then
                    Begin
                        if L1[i]>L1[b[a[i]-p].vt] then
                            Begin
                                L1[i]:=L1[b[a[i]-p].vt];
                                tr1[i]:=b[a[i]-p].vt;
                            End;
                    End;
            End;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.