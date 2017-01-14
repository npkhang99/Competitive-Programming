Const fi='Ba_Lan.inp';
      fo='Ba_Lan.out';
Type Phtu=Record
        gtri:integer;
        dau:boolean;
     End;
Var bt:array[1..1000] of Phtu;
    S:array[1..1000] of integer;
    n,l:integer;
//---------------------------------------------------
Procedure docfile;
   Var f:text;
       st:string;
       x,i,t:integer;
   Begin
        assign(f,fi);
        reset(f);
        read(f,st);
        n:=1;t:=0;
        for i:=1 to length(st) do
            if st[i]<>' ' then
               if not (st[i] in ['0'..'9']) then
                  Begin
                       case st[i] of '+':bt[n].gtri:=1;
                                     '-':bt[n].gtri:=2;
                                     '*':bt[n].gtri:=3;
                                     '/':bt[n].gtri:=4;
                       End;
                       bt[n].dau:=true;
                  End
               else Begin
                         x:=(ord(st[i])-48);
                         t:=t*10+x;
                         bt[n].gtri:=t;
                         bt[n].dau:=false;
                    End
            else Begin
                      t:=0;
                      inc(n);
                 End;
        close(f);
   End;
//---------------------------------------------------
Procedure xuat(x:integer);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//---------------------------------------------------
Procedure Push(x:integer);
   Begin
        inc(l);
        S[l]:=X;
   End;
//---------------------------------------------------
Function POP:integer;
   Begin
        POP:=S[l];
        dec(l);
   End;
//---------------------------------------------------
Function tinh(a,b,dau:integer):integer;
   Begin
        Case dau of 1:exit(a+b);
                    2:exit(a-b);
                    3:exit(a*b);
                    4:exit(a div b);
        End;
   End;
//---------------------------------------------------
Procedure DinhGia;
   Var i,x,T,b,a:integer;
   Begin
        l:=0;
        for i:=1 to n do
            with bt[i] do
                 Begin
                      x:=gtri;
                      if not dau then push(x)
                      else Begin
                                b:=pop;a:=pop;
                                T:=tinh(a,b,x);
                                push(T);
                           End;
                 End;
        xuat(S[1]);
   End;
//===================================================
BEGIN
     docfile;
     DinhGia;
END.
