Const n=8;
      m=9;
      dx:array[1..4] of shortint=();
      dy:array[1..4] of shortint=();
Type ma=Record
        x,y:integer;
     End;
Var a:array[1..1000,1..1000] of shortint;
    Queue:array[1..1000] of ma;
    l,r:integer;
//---------------------------------------------------------
Procedure xuat;
    Var i,j:integer;
    Begin
        for i:=1 to n do
            Begin
                for j:=1 to m do write(a[i,j],' ');
                writeln;
            End;
    End;
//---------------------------------------------------------
Procedure khoitao;
    Var i,j:integer;
    Begin
        for i:=1 to n do
            for j:=1 to m do
                a[i,j]:=-1;
        l:=1; r:=4;
        with Queue[1] do
            Begin
                x:=n; y:=1; a[x,y]:=0;
            End;
        with Queue[2] do
            Begin
                x:=n; y:=2; a[x,y]:=0;
            End;
        with Queue[3] do
            Begin
                x:=n-1; y:=1; a[x,y]:=0;
            End;
        with Queue[4] do
            Begin
                x:=n-1; y:=2; a[x,y]:=0;
            End;
    End;
//---------------------------------------------------------
Function rong:boolean;
    Begin
        exit(l>r);
    End;
//---------------------------------------------------------
Function pop:ma;
    Begin
        pop:=Queue[l];
        inc(l);
    End;
//---------------------------------------------------------
Procedure push(u,v:integer);
    Begin
        inc(r);
        Queue[r].x:=u;
        Queue[r].y:=v;
    End;
//---------------------------------------------------------
Procedure BFS;
    Var u,v,i,s,t:integer;
        tam:ma;
    Begin
        khoitao;
        while not rong do
            Begin
                tam:=pop;
                s:=tam.x; t:=tam.y;
                for i:=1 to 4 do
                    Begin
                        u:=s+dx[i]; v:=t+dy[i];
                        if a[u,v]=-1 then
                            Begin
                                push(u,v);
                                a[u,v]:=1-a[s,t];
                            End;
                    End;
            End;
    End;
//=========================================================
BEGIN
    BFS;
    xuat;
END.
