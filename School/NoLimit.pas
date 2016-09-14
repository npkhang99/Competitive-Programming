Const fi='NoLimit.inp';
      fo='NoLimit.out';
Var n,i:longint;
    a:array[1..40] of string;
    s:string;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
    End;
//---------------------------------------------------------
Procedure swap(Var i,j:integer);
    Var t:char;
    Begin
        t:=s[i]; s[i]:=s[j]; s[j]:=t;
        inc(i); dec(j);
    End;
//---------------------------------------------------------
Procedure qsort(l,r:integer);
    Var i,j:integer;
        m:char;
    Begin
        i:=l; j:=r; m:=s[i+ random(j-i+1)];
        repeat
            while s[i]<m do inc(i);
            while s[j]>m do dec(j);
            if i<=j then swap(i,j);
        until i>j;
        if l<j then qsort(l,j);
        if i<r then qsort(i,r);
    End;
//---------------------------------------------------------
Procedure next;
    Var t:string;
        nho,x,y,i:integer;
    Begin
        nho:=0; t:='';
        for i:=length(s) downto 1 do
            Begin
                x:=ord(s[i])-48;
                y:=(x*2+nho) mod 10; nho:=(x*2+nho) div 10;
                t:=char(y+48)+t;
            End;
        t:=char(nho+48)+t;
        s:=t;
    End;
//---------------------------------------------------------
Procedure try;
    Begin
        if i<=31 then
            Begin
                a[i]:=s; inc(i); next; qsort(1,length(s));
                while s[1]='0' do delete(s,1,1);
                try;
            End;
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        if n<=30 then write(f,a[n])
        else case (n mod 6) of 1:write(f,a[25]);
                             2:write(f,a[26]);
                             3:write(f,a[27]);
                             4:write(f,a[28]);
                             5:write(f,a[29]);
                             0:write(f,a[30]);
             End;
        close(f);
    End;
//---------------------------------------------------------
BEGIN
    randomize;
    docfile;
    i:=1; s:='1';
    try;
    xuat;
END.