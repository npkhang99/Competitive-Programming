Uses math;
Const fi='SWindow.inp';
      fo='SWindow.out';
Var z:array[1..2000000] of longint;
    t,p,x:ansistring;
    n,k,m:longint;
//---------------------------------------------------------
Procedure xuat(d:longint);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,d); write(d);
        close(f);
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,t); n:=length(t);
        readln(f,p); m:=length(p);
        readln(f,k);
        if k<m then
            Begin
                xuat(0);
                halt;
            End;
        x:=p+'ƒ'+t;
        close(f);
    End;
//---------------------------------------------------------
Procedure Z_alg; 
    Var i,l,r:longint;
    Begin
        fillchar(z,sizeof(z),0);
        l:=1; r:=1;
        for i:=2 to n+m+1 { length(x) } do
            Begin
                if i<=r then
                    z[i]:=min(r-i+1, z[i-l+1]);
                while (i+z[i]<=n+m+1)and (x[z[i]+1]=x[i+z[i]]) do inc(z[i]);
                if i+z[i]-1>r then
                    Begin
                        l:=i; r:=i+z[i]-1;
                    End;
            End;
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,l,r,d,vt:longint;
    Begin
        Z_alg; l:=1; r:=1; d:=0; vt:=n-k+1;
        for i:=1 to n do
            if z[i+m+1]=m then
                Begin
                    l:=max(r, i-k+m);
                    if (l<=i) then
                        Begin
                            if (vt>l) and (vt>=i) then d:=d+i-l+1
                            else if (vt>l) and (vt<i) then d:=d+vt-l+1
                            else if vt=l then d:=d+1
                            else break;
                        End;
                    r:=i+1;
                End;
        xuat(d);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.
