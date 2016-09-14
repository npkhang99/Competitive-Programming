Const fi='Topo.inp';
      fo='Topo.out';
Type contro=^node;
     node=Record
        Ind_:integer;
        next:contro;
     End;
     phantu=Record
        count:integer;
        next:contro;
     End;
Var a:array[1..1000] of phantu;
    b:array[1..1000] of boolean;
    tt:array[1..1000] of integer;
    n,m:integer;
//---------------------------------------------------------
Procedure add(Var p:contro; x:integer);
    Var q,q1:contro;
    Begin
        q1:=p;
        if q1=nil then
            Begin
                new(q);
                q^.ind_:=x;
                q^.next:=nil;
                p:=q;
            End
        else Begin
                while q1^.next<>nil do q1:=q1^.next;
                new(q);
                q^.ind_:=x;
                q^.next:=nil;
                p^.next:=q;
             End;
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,u,v:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=1 to m do
            Begin
                readln(f,u,v);
                add(a[u].next,v);
                inc(a[v].count);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var i:integer;
    Begin
        for i:=1 to n do
            write(tt[i],' ');
    End;
//---------------------------------------------------------
Function rong:boolean;
    Var i:integer;
    Begin
        for i:=1 to n do
            if not b[i] then exit(false);
        exit(true);
    End;
//---------------------------------------------------------
Function tim:integer;
    Var i:integer;
    Begin
        for i:=1 to n do
            if (not b[i]) and (a[i].count=0) then exit(i);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var d:integer;
        q:contro;
    Begin
        fillchar(b,sizeof(b),0);
        fillchar(tt,sizeof(tt),0);
        d:=0;
        while not rong do
            Begin
                inc(d); tt[d]:=tim; b[tt[d]]:=true; q:=a[tt[d]].next;
                while q<>nil do
                    Begin
                        dec(a[q^.ind_].count);
                        q:=q^.next;
                    End;
            End;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.