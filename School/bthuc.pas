Const fi='bthuc.inp';
      dau:array[1..5] of char=('+','-','x',':','^');
Var bt:string;
//--------------------------------------------------------
Procedure docfile;
    Var f:text;
    Begin
        assign(f,fi);
        reset(f);
        read(f,bt);
        close(f);
    End;
//--------------------------------------------------------
Procedure ngoac(var bt:string);
    Var d,i:integer;
    Begin
        if (bt[1]='(') and (bt[length(bt)]=')') then
            Begin
                d:=1;
                for i:=2 to length(bt) do
                    Begin
                        if bt[i]='(' then inc(d);
                        if bt[i]=')' then dec(d);
                        if d=0 then break;
                    End;
                if (d=0) and (i=length(bt)) then
                    Begin
                        delete(bt,1,1);
                        delete(bt,length(bt),1);
                    End;
            End;
    End;
//--------------------------------------------------------
Function timdau(bt:string):integer;
    Var i,d,j:integer;
    Begin
        for i:=1 to 4 do
            Begin
                d:=0;
                for j:=1 to length(bt) do
                    Begin
                        if bt[j]='(' then inc(d);
                        if bt[j]=')' then dec(d);
                        if (d=0) and (bt[j]=dau[i]) then exit(j);
                    End;
            End;
        if (d=0) then exit(0);
    End;
//--------------------------------------------------------
Function tinh(bt1,bt2:string;dau:char):string;
    Var x,y,kt,kq:integer;
    Begin
        val(bt1,x,kt);
        val(bt2,y,kt);
        case dau of '+':kq:=x+y;
                    '-':kq:=x-y;
                    'x':kq:=x*y;
                    ':':kq:=x div y;
        End;
        str(kq,tinh);
    End;
//--------------------------------------------------------
Function GTBT(bt:string):string;
    Var bt1,bt2:string;
        d:integer;
    Begin
        ngoac(bt);
        d:=timdau(bt);
        if d=0 then exit(bt)
        else Begin
                bt1:=copy(bt,1,d-1);
                bt2:=copy(bt,d+1,length(bt)-d);
                exit(tinh(GTBT(bt1),GTBT(bt2),bt[d]));
             End;
    End;
//--------------------------------------------------------
Procedure xuat;
    Begin
        write(GTBT(bt));
    End;
//========================================================
BEGIN
    docfile;
    xuat;
END.