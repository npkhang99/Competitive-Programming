// SPOJ submission 14763429 (PAS fpc) plaintext list. Status: AC, problem LATGACH, contest SPOJVN. By mansblacks (Khang), 2015-07-28 04:32:42.
Var    b:array[1..100] of integer;
    n:integer;
//---------------------------------------------------------
Function cong(s1,s2:string):string;
    Var x,y,t,nho:integer;
        s:string;
    Begin
        nho:=0;cong:='';
        while length(s1)<length(s2) do s1:='0'+s1;
        while length(s2)<length(s1) do s2:='0'+s2;
        repeat
            x:=ord(s1[length(s1)])-48;
            y:=ord(s2[length(s2)])-48;
            t:=(x+y+nho) mod 10;
            nho:=(x+y+nho) div 10;
            str(t,s);cong:=s+cong;
            delete(s1,length(s1),1);
            delete(s2,length(s2),1);
        until s1='';
        if nho>0 then
            Begin
                str(nho,s);
                cong:=s+cong;
            End;
    End;
{//---------------------------------------------------------
Function fibo(j:integer):string;
    Begin
        if j<2 then fibo:='1'
        else fibo:=cong(fibo(j-1),fibo(j-2));
    End;}
//---------------------------------------------------------
Procedure xuly;
    Var i,max:integer;
        a:array[0..100] of string;
    Begin
        readln(n);max:=0;a[0]:='1';a[1]:='1';
        for i:=1 to n do 
            Begin
                readln(b[i]);
                if max<b[i] then max:=b[i];
            End;
        for i:=2 to max do a[i]:=cong(a[i-1],a[i-2]);
        for i:=1 to n do writeln(a[b[i]]);
//            writeln(fibo(b[i]))
    End;
//=========================================================
BEGIN
    xuly;
END.