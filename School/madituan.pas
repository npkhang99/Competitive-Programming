Uses crt;
Const dx:array[1..8] of shortint=(-2,-1,1,2,2,1,-1,-2);
      dy:array[1..8] of shortint=(-1,-2,-2,-1,1,2,2,1);
Var a:array[1..10,1..10] of integer;
    x,y,d,n:integer;
    gh:set of byte;
//--------------------------------
Procedure nhap;
   Begin
        write('Nhap do lon ban co: ');readln(n);
        write('Nhap vi tri ma: ');readln(x,y);
        fillchar(a,sizeof(a),0);
        gh:=[1..n];
        a[x,y]:=1;d:=0;
   End;
//--------------------------------
Procedure xuat;
   Var i,j:integer;
   Begin
        for i:=1 to n do
            Begin
                 for j:=1 to n do write(a[i,j]:3);
                 writeln;
            End;
        inc(d);
        writeln('-----------------------------------------------');
   End;
//--------------------------------
Function OK(x,y:integer):boolean;
   Begin
        OK:=(x in gh) and (y in gh) and (a[x,y]=0);
   End;
//--------------------------------
Procedure try(x,y,i:integer);
   Var u,v,j:integer;
   Begin
        if i>n*n then
           Begin
                xuat;
                readln;
                halt;
           End
        else for j:=1 to 8 do
                 Begin
                      u:=x+dx[j];
                      v:=y+dy[j];
                      if OK(u,v) then
                         Begin
                              a[u,v]:=i;
                              try(u,v,i+1);
                              a[u,v]:=0;
                         End;
                 End;
   End;
//================================
BEGIN
     clrscr;
     nhap;
     try(x,y,2);
     readln;
END.
