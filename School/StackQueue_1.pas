Const fi='DFS.inp';
      fo='DFS.out';
Var a:array[1..100,1..100] of integer;
    s:array[1..100] of integer;
    c:array[1..100] of boolean;
    n,p:integer;
    f:text;
//------------------------------------------------
Procedure docfile;
   Var f:text;
       i,j:integer;
   Begin
        assign(f,fi);
        reset(f);
        for i:=1 to n do
            BEgin
                 for j:=1 to n do read(f,a[i,j]);
                 readln(f);
            End;
        close(f);
   End;
//------------------------------------------------
Function rong:boolean;
   Begin
        exit(p=0);
   End;
//------------------------------------------------
Procedure Push(x:integer);
   Begin
        p:=p+1;
        S[p]:=x;
   End;
//------------------------------------------------
Function Pop:integer;
   Begin
        pop:=s[p];
        p:=p-1;
   End;
//------------------------------------------------
Procedure DFS_dq(v:integer); //De_Quy
   Var w:integer;
   Begin
        write(f,v);C[v]:=true;
        for w:=1 to n do
            if (w<>v) and (c[w]=false) then DFS_dq(w);
   End;
//------------------------------------------------
Procedure DFS; //Khu_De_Quy
   Var v,w:integer;
   Begin
        write(f,v);
        c[v]:=true;
        Push(v);
        While not rong do
              Begin
                   v:=pop;
                   for w:=1 to n do
                       if (w<>v) and (c[w]=false) then
                          Begin
                               write(f,w);
                               C[w]:=true;
                               Push(w);
                          End;
              End;
   End;
//================================================
BEGIN
     docfile;
     fillchar(c,sizeof(c),false);
     p:=0;
     assign(f,fo);
     rewrite(f);
     DFS_dq(1);
     writeln(f);
     DFS;
     close(f);
END.