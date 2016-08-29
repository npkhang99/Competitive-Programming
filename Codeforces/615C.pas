Type position=Record
        be,en:integer;
     End;
Var s,ss,t:ansistring;
    n:integer;
    a:array[1..2109] of position;
//---------------------------------------------------------
Function min(a,b:integer):integer;
    Begin
        if a>b then exit(a);
        exit(b);
    End;
//---------------------------------------------------------
Procedure check;
    Var e:array['a'..'z'] of boolean;
        i:integer;
    Begin
        fillchar(e,sizeof(e),false);
        for i:=1 to length(s) do e[s[i]]:=true;
        for i:=1 to length(t) do
            if e[t[i]]=false then
                Begin
                    write('-1'); halt;
                End;
    End;
//---------------------------------------------------------
Procedure init;
    Var i:integer;
    Begin
        ss:=''; n:=0; t:=t+'0';
        for i:=length(s) downto 1 do ss:=ss+s[i];
    End;
//---------------------------------------------------------
Procedure xuly;
    Var l,r,long,s1,s2:integer;
        temp:ansistring;
        found:boolean;
    Begin
        r:=1; temp:='';
        while r<=length(t)-1 do
            Begin
                l:=r; r:=l; inc(n); temp:='';
                repeat
                    found:=false;
                    temp:=temp+t[r];
                    s1:=pos(temp,s);
                    s2:=pos(temp,ss);
                    if ((s1>0) or (s2>0)) and (r<=length(t)) then found:=true;
                    if not found then
                        Begin
                            delete(temp,length(temp),1);
                            if long=1 then
                                Begin
                                    s1:=pos(temp,s);
                                    a[n].be:=s1; a[n].en:=s1+length(temp)-1;
                                    break;
                                End;
                            s2:=pos(temp,ss);
                            a[n].be:=length(s)-s2+1;
                            a[n].en:=length(s)-s2-length(temp)+2;
                            break;
                        End;
                    if s1>0 then long:=1
                    else long:=2;
                    inc(r);
                until found=false;
            End;
    End;
//---------------------------------------------------------
Procedure xuat;
    Var i:integer;
    Begin
        writeln(n);
        for i:=1 to n do
            with a[i] do writeln(be,' ',en);
    End;
//---------------------------------------------------------
BEGIN
    readln(s); readln(t);
    check;
    init;
    xuly;
    xuat;
END.
