// SPOJ submission 14779950 (PAS fpc) plaintext list. Status: AC, problem QBTICKET, contest SPOJVN. By mansblacks (Khang), 2015-07-30 05:20:51.
Uses math;
Const maxc=999999999999999;
Var a,t:array[1..100000] of int64;
    L,C:array[1..3] of int64;
    n,s,f:longint;
//---------------------------------------------------------
Procedure doc;
   Var i:longint;
   Begin
       read(L[1],L[2],L[3],C[1],C[2],C[3]);
       read(n);
       read(s,f);
       a[1]:=0;
       for i:=2 to n do read(a[i]);
   End;
//---------------------------------------------------------
Function tien(i,j:longint):int64;
   Var kc:longint;
   Begin
       kc:=a[i]-a[j];
       if kc<=L[1] then exit(C[1])
       else if kc<=L[2] then exit(C[2])
       else exit(C[3]);
   End;
//---------------------------------------------------------
Procedure xuly;
   Var i,j:longint;
   Begin
       t[s]:=0;
       for i:=s+1 to f do
           Begin
               t[i]:=maxc;
               j:=i-1;
               while (j>=s) and (a[i]-a[j]<=L[3]) do
                   Begin
                       t[i]:=min(t[i],t[j]+tien(i,j));
                       dec(j);
                   End;
           End;
       write(t[f]);
   End;
//=========================================================
BEGIN
    doc;
    xuly;
END.
 
