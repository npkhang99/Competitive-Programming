Const fi='BFS.inp';
      fo='';
Var a:array[1..100,1..100] of integer;
    c:array[1..100] of boolean;
    q:array[1..2000000] of integer;
    n,l,r:integer;
    f:text;
//------------------------------------------------
Procedure docfile;
    Var i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
            for i:=1 to n do
                Begin
                    for j:=1 to n do read(f,a[i,j]);
                    readln(f);
                End;
        close(f);
    End;
//------------------------------------------------
Function empty:boolean;
    Begin
        exit(l>r);
    End;
//------------------------------------------------
Procedure put(x:integer);
    Begin
        r:=r+1;
        q[r]:=x;
    End;
//------------------------------------------------
Function get:integer;
    Begin
        get:=q[l];
        l:=l+1;
    End;
//------------------------------------------------
Procedure BFS(v:integer);
    Var w:integer;
    Begin
        write(f,v,' ');
        c[v]:=true;
        put(v);
        while not empty do
            Begin
                v:=get;
                for w:=1 to n do
                    if (a[v,w]=1) and (c[w]=false) then
                        Begin
                            write(f,w,' ');
                            c[w]:=true;
                            put(w);
                        End;
            End;
    End;
//================================================
BEGIN
    docfile;
    assign(f,fo);
    rewrite(f);
    fillchar(c,sizeof(c),false);
    l:=1;r:=0;
    BFS(1);
    close(f);
END.
