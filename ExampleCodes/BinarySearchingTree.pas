// 13
// 50 25 75 12 35 60 85 8 18 30 39 55 68
Const fi='';
Type Pnode=^node;
     node=Record
        value:integer;
        l,r:pnode;
     End;
Var T:Pnode;
//---------------------------------------------------------
Procedure Add(Var T:Pnode; X:integer);
    Begin
        if T=nil then
            Begin
                new(T); T^.l:=nil; T^.r:=nil;
                T^.value:=x;
            End
        else if x<T^.value then Add(T^.l,X)
            else Add(T^.r,x);
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        x,n,i:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                read(f,x);
                Add(T,x);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure FrontSearch(T:Pnode);
    Begin
        if T<>nil then
            Begin
                write(T^.value,' ');
                FrontSearch(T^.l);
                FrontSearch(T^.r);
            End;
    End;
//---------------------------------------------------------
Procedure MiddleSearch(T:Pnode);
    Begin
        if T<>nil then
            Begin
                MiddleSearch(T^.l);
                write(T^.value,' ');
                MiddleSearch(T^.r);
            End;
    End;
//---------------------------------------------------------
Procedure BackSearch(T:Pnode);
    Begin
        if T<>nil then
            Begin
                BackSearch(T^.l);
                BackSearch(T^.r);
                write(T^.value,' ');
            End;
    End;
//---------------------------------------------------------
Function Search(T:Pnode; x:integer):Pnode;
    Begin
        if (T=nil) or (T^.value=x) then exit(T)
        else if x > T^.value then exit(Search(T^.r, x))
        else exit(Search(T^.l, x));
    End;
//=========================================================
BEGIN
    docfile;
    FrontSearch(T); writeln;
    MiddleSearch(T); writeln;
    BackSearch(T); writeln;
    if Search(T, 68)<>nil then writeln('YES')
    else writeln('NO');
END.
