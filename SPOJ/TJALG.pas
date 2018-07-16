Type DynamicArray = array of longint;

Var adj, rev:array[0..100009] of DynamicArray;
    mark:array[0..100009] of longint;
    s:DynamicArray;
    n,m:longint;

Procedure insert(var a:DynamicArray; t:longint);
var x:longint;
Begin
    x := length(a);
    SetLength(a, x+1);
    a[x] := t;
End;

Procedure doc();
Var i,x,y:longint;
Begin
    read(n,m);
    for i:=1 to m do begin
        read(x,y);
        insert(adj[x], y);
        insert(rev[y], x);
    end;
End;

Procedure Kosaraju(u,pass:longint);
Var a:DynamicArray;
    i,v:longint;
Begin
    mark[u] := 1;
    if pass = 1 then a := adj[u]
    else a := rev[u];

    for i:=0 to length(a)-1 do begin
        v := a[i];
        if mark[v] = -1 then Kosaraju(v,pass);
    end;
    insert(s,u);
End;

Procedure main();
var i,scc:longint;
Begin
    scc := 0; SetLength(s,0);
    fillchar(mark, sizeof(mark), 255);
    for i:=1 to n do
        if mark[i] = -1 then Kosaraju(i, 1);

    fillchar(mark, sizeof(mark), 255);
    for i:=n-1 downto 0 do
        if mark[s[i]] = -1 then begin
            inc(scc);
            Kosaraju(s[i], 2);
        end;

    writeln(scc);
End;

BEGIN
    doc();
    main();
END.
 
