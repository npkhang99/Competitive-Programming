Uses Math;
Const fi='Bakice.inp';
      fo='Bakice.out';
Type toado=Record
        x,y:integer;
     End;
Var a:array[1..100,1..100] of char;
    person, chair:array[0..10000] of toado;
    ch_p, ch_c:array[1..10000] of boolean;
    dist:array[1..100000] of longint;
    n, m, num_p, num_c:integer;
//---------------------------------------------------------
Procedure per(i,j:integer);
    Begin
        inc(num_p);
        with person[num_p] do
            Begin
                x:=i; y:=j;
            End;
    End;
//---------------------------------------------------------
Procedure cha(i,j:integer);
    Begin
        inc(num_c);
        with chair[num_c] do
            Begin
                x:=i; y:=j;
            End;
    End;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i,j:integer;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        num_p:=0; num_c:=0;
        for i:=1 to n do
            Begin
                for j:=1 to m do
                    Begin
                        read(f,a[i,j]);
                        if a[i,j]='X' then per(i,j);
                        if a[i,j]='L' then cha(i,j);
                    End;
                readln(f);
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat(x:integer);
    Var f:text;
    Begin
        assign(f,fo);
        rewrite(f);
        write(f,x); write(x);
        close(f);
    End;
//---------------------------------------------------------
Function dis(t1,t2:toado; kt:longint):longint;
    Begin
        if kt=0 then exit(maxlongint)
        else exit(sqr(t1.x-t2.x)+sqr(t1.y-t2.y));
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i,j,dest,count,p,c:longint;
        best:longint;
    Begin
        fillchar(ch_p, sizeof(ch_p), false);
        ch_c:=ch_p;
        dest:=0; p:=num_p; c:=num_c;
        while (p>0) and (c>0) do
            Begin
                count :=0; best:=maxlongint;
                for i:=1 to min(num_c, num_p) do dist[i]:=0;
                for i:=1 to num_p do
                    if not ch_p[i] then
                        for j:=1 to num_c do
                            if not ch_c[j] then
                                Begin
                                    if dis(person[i], chair[j], j) < dis(person[i], chair[dist[i]], dist[i]) then
                                        dist[i]:=j;
                                    best:=min(best, dis(person[i], chair[dist[i]], dist[i]));
                                End;
                for i:=1 to min(num_c, num_p) do
                    if dis(person[i], chair[dist[i]], dist[i])=best then
                        Begin
                            ch_p[i]:=true; ch_c[dist[i]]:=true;
                            inc(count); dec(p); dec(c);
                        End;
                if count>1 then inc(dest);
            End;
        xuat(dest);
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.