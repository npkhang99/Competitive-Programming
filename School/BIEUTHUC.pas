Const fi='BIEUTHUC.INP';
      fo='BIEUTHUC.OUT';
      dau:array[1..4] of char=('-','+',':','x');
//------------------------------
Function TimDau(bt:string):integer;
   Var d,i,j:integer;
   Begin
        d:=0;
        for i:=1 to 4 do
            for j:=length(bt) downto 1 do
                Begin
                     if bt[j]=')' then inc(d)
                     else if bt[j]='(' then dec(d);
                     if (bt[j]=dau[i]) and (d=0) then exit(j);
                End;
        exit(0);
   End;
//------------------------------
Procedure XoaNgoac(Var bt:string);
   Var d,i:integer;
   Begin
        if bt[1]='(' then
           Begin
                d:=1;
                for i:=2 to length(bt) do
                    if bt[i]='(' then inc(d)
                    else if bt[i]=')' then
                         Begin
                              dec(d);
                              if (d=0) and (i=length(bt)) then
                                 Begin
                                      delete(bt,1,1);
                                      delete(bt,length(bt),1);
                                 End
                              else if d=0 then exit;
                         End;
           End;
   End;
//------------------------------
Function tinh(a,b:string;c:char):string;
   Var x,y,kt,kq:integer;
       t:string;
   Begin
        val(a,x,kt);
        val(b,y,kt);
        case c of '-':kq:=x-y;
                  '+':kq:=x+y;
                  'x':kq:=x*y;
                  ':':kq:=x div y;
        end;
        str(kq,t);
        exit(t);
   End;
//------------------------------
Function gtri(bt:string):string;
   Var bt1,bt2:string;
       v:integer;
   Begin
        XoaNgoac(bt);
        v:=TimDau(bt);
        if v=0 then exit(bt)
        else Begin
                  bt1:=copy(bt,1,v-1);
                  bt2:=copy(bt,v+1,length(bt)-v);
                  if bt1='' then bt1:='0';
                  gtri:=tinh(gtri(bt1),gtri(bt2),bt[v]);
             End;
   End;
//------------------------------
Procedure docfile;
   Var f1,f2:text;
       st:string;
       n,i:integer;
   Begin
        assign(f1,fi);
        assign(f2,fo);
        reset(f1);
        rewrite(f2);
        readln(f1,n);
        for i:=1 to n do
            Begin
                 readln(f1,st);
                 writeln(f2,gtri(st));
            End;
        close(f1);
        close(f2);
   End;
//==============================
BEGIN
     docfile;
END.
