// Bellman-Ford algorithm
// NOTE: Code nay chi su dung cho do thi co huong
Type canh=Record
        u,v,val:integer;
     End;
Var a:array[1..10000] of canh;
    d,tr:array[1..1000] of integer;
    n,m,s:integer;
//---------------------------------------------------------
Procedure docfile;
    Var i:integer;
    Begin
        readln(n,m,s);
        for i:=1 to m do
            with a[i] do read(u,v,val);
    End;
//---------------------------------------------------------
Procedure ddi(i:integer);
    Begin
        if i>0 then
            Begin
                ddi(tr[i]);
                write(i,' ');
            End;
    End;
//---------------------------------------------------------
Procedure khoigan;
    Var i:integer;
    Begin
        fillchar(tr,sizeof(tr),0);
        for i:=1 to n do
            d[i]:=maxint;
        d[s]:=0;
    End;
//---------------------------------------------------------
Function co(e:canh):boolean;
    Begin
        with e do
            Begin
                if d[v]>d[u]+val then
                    Begin
                        d[v]:=d[u]+val;
                        tr[v]:=u;
                        exit(true);
                    End;
                exit(false);
            End;
    End;
//---------------------------------------------------------
Procedure BellmanFord;
    Var k,i:integer;
        ok,chu_trinh_am:boolean;
    Begin
        khoigan;
        for k:=1 to n-1 do
            Begin
                ok:=false;
                for i:=1 to m do
                    if co(a[i]) then ok:=true;
                if ok=false then break;
            End;

        chu_trinh_am := false;
        for i:=1 to m do
            if co(a[i]) then chu_trinh_am := true;

        if chu_trinh_am then
            writeln('Do thi ton tai chu trinh am');
        else for i:=1 to n do
                writeln(s,' -> ',i,' = ',d[i]);
    End;
//=========================================================
BEGIN
    docfile;
    BellmanFord;
END.

{
// Do thi co canh am nhung khong co chu trinh am
5 5 1
1 2 1
1 3 10
2 4 2
3 4 -10
4 5 3

// Do thi co chu trinh am
3 3 1
1 2 1000
2 3 15
3 2 -42
}
