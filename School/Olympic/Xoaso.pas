Const fi='Xoaso.inp';
      fo='Xoaso.out';
Var N,M:ansistring;
    K:longint;
//-------------------------------
Procedure docfile;
   Var f:text;
   Begin
        Assign(f,fi);
        reset(f);
        Readln(f,N);
        Readln(f,K);
        close(f);
   End;
//-------------------------------
Procedure xuat;
   Var f:text;
   Begin
        Assign(f,fo);
        rewrite(f);
        Writeln(f,M);
        close(f);
   End;
//-------------------------------
Procedure Solve;
   Var i,max,X:integer;
   Begin
        X:=K;
        Repeat
              max:=1;
              for i:=1 to X+1 do
                  if N[i]>N[max] then max:=i;
              M:=M+N[max];
              Delete(N,1,max);
              X:=X-max+1;
        Until X=0;
        M:=M+N;
   End;
//===============================
BEGIN
     docfile;
     M:='';
     Solve;
     xuat;
END.
