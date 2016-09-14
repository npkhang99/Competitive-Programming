Const fi='Neighbor.inp';
      fo='Neighbor.out';
Var snt:array[0..500009] of longint;
    n,a,l,r,k:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k,a);
        a:=a-1;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo); rewrite(f);
        write(l+1,' ',r+1);
        close(f);
    End;
//---------------------------------------------------------
Function modx(x:longint):longint;
    Begin
        exit((((x-1) mod n)+n) mod n);
    End;
//---------------------------------------------------------
Procedure taosnt;
    Var dd:array[0..7380000] of byte;
        i,j,dem:longint; 
    Begin
        dem:=0;
        for i:=2 to 7380000 do
            if dd[i]=0 then
                Begin
                    inc(dem);
                    snt[dem]:=i;
                    if j=dem then exit;
                    for j:=i to (n div i) do dd[i*j]:=1;
                End;
    End;
//---------------------------------------------------------
Function calup(x,p:longint):longint;
    Var t:longint;
    Begin
        if x=0 then exit(p);
        t:=p mod (n-1);
        //x:=modx(x - p div (n-1));
        if t<=x then x:=modx(x+1);
        x:=modx(x + p div (n-1));
        exit(x);
    End;
//---------------------------------------------------------
Function caldown(x,p:longint):longint;
    Var t:longint;
    Begin
        if x=p then exit(0);
        t:=p mod (n-1);
        x:=modx(x + p div (n-1));
        if t<=x then x:=modx(x+1);
        exit(x);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j:longint;
    Begin
        taosnt;
        for i:=1 to k do
            a:=calup(a,snt[i]);
        l:=modx(a-1); r:=modx(a+1);
        for i:=k downto 1 do l:=caldown(l,snt[i]);
        for i:=k downto 1 do r:=caldown(r,snt[i]);
    End;
//---------------------------------------------------------
BEGIN
    docfile;
    xuly;
    xuat;
END.