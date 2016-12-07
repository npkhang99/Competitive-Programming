Uses Math;
Const fi='CaoThu.inp';
      fo='CaoThu.out';
Type diem=Record
        x,y,val:int64;
     End;
Var a,s,h:array[0..200000] of int64;
    b:array[1..50000] of boolean;
    n,m:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
        c:array[1..100000] of diem;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        fillchar(h,sizeof(h),0);
        for i:=1 to m do
            Begin
                readln(f,c[i].x,c[i].y,c[i].val);
                inc(h[c[i].x]);
                inc(h[c[i].y]);
            End;
        for i:=1 to n do
            Begin
                h[i]:=h[i-1]+h[i];
                b[i]:=false;
            End;
        for i:=1 to m do
            with c[i] do
                Begin
                    a[h[x]]:=y;
                    a[h[y]]:=x;
                    s[h[x]]:=val;
                    s[h[y]]:=val;
                    dec(h[x]);
                    dec(h[y]);
                End;
        h[n+1]:=2*m;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:int64);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,k,l:longint;
        Smax:int64;
    Begin
        Smax:=0;
        for i:=1 to n do
            Begin
                b[i]:=true;
                for j:=h[i]+1 to h[i+1] do
                    if not b[a[j]] then
                        Begin
                            b[a[j]]:=true;
                            for k:=h[a[j]]+1 to h[a[j]+1] do
                                if not b[a[k]] then
                                    Begin
                                        b[a[k]]:=true;
                                        for l:=h[a[k]]+1 to h[a[k]+1] do
                                            if a[l]=i then
                                                Begin
                                                    Smax:=max(Smax,s[j]+s[k]+s[l]);
                                                    break;
                                                End;
                                        b[a[k]]:=false;
                                    End;
                            b[a[j]]:=false;
                        End;
                b[i]:=false;
            End;
        xuat(Smax);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
