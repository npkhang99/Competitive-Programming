Uses Math;
Const fi='Build.inp';
      fo='Build.out';
Type Build=Record
        u,v,val:longint;
     End;
     Toado=Record
        x,y:integer;
     End;
     arr=array[1..2000] of byte;
Var G:array[1..2000] of Build;
    C:array[1..2000] of boolean;
    D:array[1..2000] of boolean;
    n,k:longint;
//-------------------------------
Function DoDai(c1,c2:Toado):longint;
   Begin
        DoDai:=sqr(c1.x-c2.x)+sqr(c1.y-c2.y);
   End;
//-------------------------------
Procedure docfile;
   Var f:text;
       i,j,t:integer;
       TD:array[1..2000] of toado;
   Begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        for i:=1 to n do
            with TD[i] do readln(f,x,y);
        T:=0;
        for i:=1 to n do
            for j:=1 to n do
             if i<>j then
                Begin
                     inc(t);
                     with G[t] do
                          Begin
                               u:=i;v:=j;
                               val:=DoDai(TD[i],TD[j]);
                          End;
                End;
        close(f);
   End;
//-------------------------------
Procedure xuat(x:longint);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//-------------------------------
Procedure doi(Var a,b:Build);
   Var tam:Build;
   Begin
        tam:=b;
        b:=a;
        a:=tam;
   End;
//-------------------------------
Procedure QSort(l,r:longint);
   Var i,j,x:longint;
   Begin
        i:=l;j:=r;
        x:=G[(i+j) div 2].val;
        repeat
              while G[i].val<x do inc(i);
              while G[j].val>x do dec(j);
              if i<=j then
                 Begin
                      doi(G[i],G[j]);
                      inc(i);dec(j);
                 End;
        until i>j;
        if j>l then QSort(l,j);
        if i<r then QSort(i,r);
   End;
//-------------------------------
Function ok(mang:arr):boolean;
   Var i,min:integer;
   Begin
        min:=3;max:=0;
        for i:=1 to n do
          Begin
            if min>mang[i] then
               Begin
                    min:=mang[i];
                    if min=0 then exit(true);
               End;
            if max<mang[i] then max:=mang[i];
          End;
        if (max=2) and (min=2) then exit(false);
   End;
//-------------------------------
Procedure Kruskal;
   Var i,j,s,t,min:longint;
       Tham:arr;
   Begin
        QSort(1,n*(n-1));
        min:=-1;
        for i:=1 to n do
            Begin
                 fillchar(c,sizeof(c),false);
                 fillchar(d,sizeof(d),false);
                 fillchar(tham,sizeof(tham),0);
                 T:=1;C[i]:=true;D[G[i].u]:=true;D[G[i].v]:=true;S:=G[i].val;tham[i]:=1;
                 Repeat
                       for j:=1 to (n*(n-1)) do
                           if (not C[j]) and (D[G[j].u] Xor D[G[j].v]) and (k<=G[j].val) then
                              Begin
                                   C[j]:=true;
                                   D[G[j].u]:=true;
                                   D[G[j].v]:=true;
                                   inc(T);
                                   S:=S+G[j].val;
                                   Tham[j]:=1;
                                   break;
                              End
                           else if (not C[j]) and (D[G[j].u] Xor D[G[j].v]) and (k>G[j].val) then Tham[j]:=2;
                 Until (T=N-1) or (not ok(Tham));
                 if (T=N-1) and (min<s) then min:=s;
            End;
        xuat(min);
   End;
//===============================
BEGIN
     docfile;
     Kruskal;
END.