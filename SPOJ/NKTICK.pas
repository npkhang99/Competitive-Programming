// SPOJ submission 14779624 (PAS fpc) plaintext list. Status: AC, problem NKTICK, contest SPOJVN. By mansblacks (Khang), 2015-07-30 03:39:39.
Uses math;
Var a,t,r:array[0..60000] of longint;
    n:longint;
//---------------------------------------------------------
Procedure doc;
   Var i:longint;
   Begin
       readln(n);
       for i:=1 to n do read(t[i]);
       for i:=1 to n-1 do read(r[i]);
   End;
//---------------------------------------------------------
Procedure xuly;
   Var i:longint;
   Begin
       a[0]:=0; a[1]:=t[1];
       for i:=2 to n do a[i]:=min(a[i-1]+t[i] , a[i-2]+r[i-1]);
       write(a[n]);
   End;
//=========================================================
BEGIN
    doc;
    xuly;
END. 