Const fi='BoBa.inp';
      fo='BoBa.out';
Type diem=Record
        x,y:integer;
     End;
Var a:array[1..100] of diem;
    n,d:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j:integer;
        ch:char;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        d:=0;
        for i:=1 to n do
            Begin
                for j:=1 to n do
                    Begin
                        read(f,ch);
                        if ch in ['A'..'Z'] then
                            Begin
                                inc(d);
                                a[d].x:=i;
                                a[d].y:=j;
                            End;
                    End;
                readln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Function tinh(a,b,c:diem):real;
    Begin
        tinh:=abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,k,t:integer;
    Begin
        t:=0;
        for i:=1 to d-2 do
            for j:=i+1 to d-1 do
                for k:=j+1 to d do
                    if tinh(a[i],a[j],a[k])=0 then inc(t);
        xuat(t);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
