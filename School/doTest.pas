Const root='D:\Study\De 13-12-2015\Tests\';
      name='FRIENDS';
Var numb,n,m:longint;
//---------------------------------------------------------
Function cal(i:longint):longint;
    Begin
        if i=0 then exit(1)
        else cal:=10*cal(i-1);
    End;
//---------------------------------------------------------
Procedure create_test_input;
    Var i,val1,val2,j,k,d:longint;
        f:text;
        path,s:string;
    Begin
        for i:=0 to numb-1 do
            Begin
                if i<10 then s:='0'+char(i+48)
                else s:=char((i div 10)+48)+char((i mod 10)+48);
                path:=root+'TEST'+s;
                assign(f,path+'\'+name+'.inp');
                rewrite(f);
                case i of 0: k:=10;
                          1: k:=50;
                          2: k:=100;
                          3: k:=500;
                          4: k:=1000;
                        End;
                d:=random(1000000 mod (cal(5-abs(i-4))*10))+1;
                writeln(f,k,' ',d);
                for j:=1 to k do
                    Begin
                        val1:=random(cal(i+2));
                        val2:=random(cal(i+2))+1;
                        writeln(f,val1,' ',val2);
                    End;
                close(f);
            End;
    End;
//---------------------------------------------------------
Procedure create_folder;
    Var f:text;
        i:longint;
        s:string;
    Begin
        assign(f,root+'folders.txt');rewrite(f);
        for i:=0 to numb-1 do
            Begin
                if i<10 then s:='0'+char(i+48)
                else s:=char((i div 10)+48)+char((i mod 10)+48);
                writeln(f,'TEST'+s);
            End;
        close(f);
    End;
//---------------------------------------------------------
BEGIN
    randomize;
    read(numb,n,m);
    //create_folder;
    create_test_input;
END.