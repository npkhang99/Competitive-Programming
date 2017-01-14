Uses Math;
Const fi='MaxFrame.inp';
      fo='MaxFrame.out';
Var a,s:array[0..400,0..400] of int64;
    n,m:integer;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to n do
            Begin
                for j:=1 to m do read(f,a[i,j]);
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
        write(x);
        close(f);
    End;
//---------------------------------------------------------
Procedure tao;
    Var i,j:integer;
    Begin
        fillchar(s,sizeof(s),0);
        for i:=1 to n do
            for j:=1 to m do
                s[i,j]:=s[i,j-1]+a[i,j];
    End;
//---------------------------------------------------------
Function cal(d,l,r:integer):longint;
    Begin
        cal:=s[d,r]-s[d,l-1];
    End;
//---------------------------------------------------------
Procedure xuly;
    Var c1,c2,h,count:integer;
        Smax,t,St:int64;
    Begin
        tao; Smax:=-maxlongint;
        for c2:=2 to m do
            for c1:=1 to c2-1 do
                Begin
                    count:=0;
                    for h:=1 to n do
                        Begin
                            inc(count);
                            if count=1 then t:=cal(h,c1,c2)
                            else Begin
                                    t:=t+cal(h,c1,c1)+cal(h,c2,c2);
                                    St:=t+cal(h,c1+1,c2-1);
                                    Smax:=max(Smax, St);
                                    if St<0 then
                                        Begin
                                            count:=0;
                                        End;
                                 End;
                        End;
                End;
        xuat(Smax);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
