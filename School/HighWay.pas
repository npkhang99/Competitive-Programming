Const fi='HighWay.inp';
      fo='HighWay.out';
Type diem=Record
        u,v:longint;
     End;
Var a:array[1..750,1..750] of real;
    b:array[1..750] of boolean;
    c:array[1..750,1..750] of boolean;
    n,m,build:longint;
//---------------------------------------------------------
Function kc(x1,y1,x2,y2:longint):real;
    Begin
        kc:=sqrt(sqr(x1-x2)+sqr(y1-y2));
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        tam:array[1..750] of diem;
        i,j,s,t:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                readln(f,tam[i].u,tam[i].v);
                for j:=1 to i do
                    Begin
                        a[i,j]:=kc(tam[i].u, tam[i].v, tam[j].u, tam[j].v);
                        a[j,i]:=a[i,j];
                    End;
            End;
        readln(f,m);
        for i:=1 to m do
            Begin
                readln(f,s,t);
                a[s,t]:=-1;
                a[t,s]:=-1;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i,j:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,build);
        for i:=1 to n do
            for j:=1 to n do
                if c[i,j] then writeln(f,i,' ',j);
        close(f);
    End;
//---------------------------------------------------------
Procedure tim(Var u,v:longint);
    Var i,j:longint;
        min:real;
    Begin
        min:=maxint;
        for i:=1 to n do
            for j:=1 to n do
                if (a[i,j]<>0) and (a[i,j]<min) and (b[i] xor b[j]) then
                    Begin
                        u:=i; v:=j;
                        min:=a[i,j];
                    End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var d,s,t:longint;
    Begin
        fillchar(b,sizeof(b),false);
        fillchar(c,sizeof(c),false);
        d:=0; b[1]:=true;
        repeat
            tim(s,t);
            b[s]:=true; b[t]:=true; inc(d);
            if a[s,t]>0 then
                Begin
                    inc(build);
                    c[s,t]:=true;
                End;
        until d=n-1;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.