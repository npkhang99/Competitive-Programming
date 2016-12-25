Var a:array[1..500] of integer;
    s1,s2,s:string;
//---------------------------------------------------------
Procedure xuat;
    Var i:integer;
    Begin
        for i:=1 to length(s) do write(a[i]);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,n,ss1,ss2:integer;
    Begin
        n:=length(s);
        i:=0; ss1:=1; ss2:=1;
        while i<n do
            Begin
                inc(i);
                if s[i]=s1[ss1] then
                    Begin
                        inc(ss1);
                        a[i]:=1;
                    End
                else if s[i]=s2[ss2] then
                        Begin
                            inc(ss2);
                            a[i]:=2;
                        End
                else Begin
                        dec(i);
                        if a[i]=2 then dec(ss2);
                        if a[i]=1 then dec(ss1);
                        while (a[i]=2) or ((a[i]=1) and (s[i]<>s2[ss2])) do
                            Begin
                                dec(i);
                                if a[i]=2 then dec(ss2);
                                if a[i]=1 then dec(ss1);
                            End;
                        a[i]:=2;
                        inc(ss2);
                     End;
            End;
    End;
//---------------------------------------------------------
BEGIN
    readln(s1); readln(s2); readln(s);
    xuly;
    xuat;
END.
