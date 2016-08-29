Uses math;
Const fi='CODE.INP';
      fo='CODE.OUT';
Var a:array[0..1000000000] of boolean;
    n:longint;
//--------------------------------
Procedure docfile;
   Var f:text;
       x:qword;
   Begin
        assign(f,fi);
        reset(f);
        fillchar(a,sizeof(a),false);
        n:=0;
        while not eof(f) do
              Begin
                   read(f,x);
                   n:=max(n,x);
                   a[x]:=true;
              End;
        close(f);
   End;
//--------------------------------
Procedure xuat(x:qword);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
        halt;
   End;
//--------------------------------
Procedure solve;
   Var i:longint;
   begin
        for i:=1 to n do
            if not a[i] then xuat(i);
   End;
//================================
BEGIN
     docfile;
     solve;
END.