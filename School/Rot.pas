Uses Math, Crt;
Const fi='Rot.inp';
      fo='Rot.out';
Var a,b:array[1..1000,1..1000] of char;
    n,m,goc,cot,dong:integer;
    f:text;
//---------------------------------------------------------
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
        read(f,goc);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat90;
    Var i,j:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
            Begin
                for j:=1 to m do write(f,a[i,j]);
                writeln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure Swap(Var x,y:char);
    Var t:char;
    Begin
        t:=x;
        x:=y;
        y:=t;
    End;
//---------------------------------------------------------
Procedure swap1;
    Var t:integer;
    Begin
        t:=n;
        n:=m;
        m:=t;
    End;
//---------------------------------------------------------
Procedure quay90;
    Var i,j:integer;
    Begin
        for i:=n downto 1 do
            for j:=1 to m do
                b[j,n-i+1]:=a[i,j];
        a:=b;
        swap1;
    End;
//---------------------------------------------------------
Procedure xuat(i,j:integer);
    Begin
        while (i in [1..n]) and (j in [1..m]) do
            Begin
                write(f,a[i,j],' ');
                dec(i); inc(j);
            End;
    End;
//---------------------------------------------------------
Procedure quay45;
    Var i:integer;
    Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do
            Begin
                if i<n then write(f,' ':n-i);
                xuat(i,1); writeln(f);
            End;
        for i:=2 to m do
            Begin
                write(f,' ':i-1);
                xuat(n,i); writeln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var q90,q45,i:integer;
    Begin
        q90:=goc div 90; q45:=goc mod 90;
        for i:=1 to q90 do quay90;
        if q45<>0 then quay45
        else xuat90;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.