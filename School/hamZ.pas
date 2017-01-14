Function Ham_Z_tho_thien(S: Ansistring);
    Var l,r: LongInt;
    Begin
        z[1]:=0;
        Fillchar(z,sizeof(z),0);
        for i:=2 to n do
            Begin
            while (i+z[i]<=n) and (s[z[i]+1]=s[i+z[i]]) do
                inc(z[i]);
    End;
End;

Function Ham_Z(S: Ansistring);
    Var l,r: LongInt;
    Begin
        z[1]:=0; l:=1; r:=1;
        Fillchar(z,sizeof(z),0);
        for i:=2 to n do
            Begin
                if i<=r then z[i]:=min(r-i+1,z[i-l+1]);
                while (i+z[i]<=n) and (s[z[i]+1]=s[i+z[i]]) do inc(z[i]);
                if i+z[i]-1>r then
                    Begin
                        l:=i;
                        r:=i+z[i]-1;
                    End;
            End;
End;