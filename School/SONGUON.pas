Const fi='SONGUON.inp';
      fo='SONGUON.out';
Var N,M:string[200];
//------------------------------
Procedure docfile;
   Var f:text;
   Begin
        assign(f,fi);
        reset(f);
        read(f,n);
        close(f);
   End;
//------------------------------
Procedure xuat(x:string);
   Var f:text;
   Begin
        assign(f,fo);
        rewrite(f);
        write(f,x);
        close(f);
   End;
//------------------------------
Function tru(a:string;b:integer):string;
   Var nho,x,y,tam:byte;
       t:string;
   Begin
        nho:=0;t:='';
        while a<>'' do
              Begin
                   x:=ord(a[length(a)])-48;
                   y:=b mod 10;
                   if x<(y+nho) then
                      Begin
                           tam:=10-(y+nho)+x;
                           nho:=1;
                      End
                   else Begin
                             tam:=x-(y+nho);
                             nho:=0;
                        End;
                   t:=char(tam+48)+t;
                   delete(a,length(a),1);
                   b:=b div 10;
              End;
        exit(t);
   End;
//------------------------------
Function tong(a:string):integer;
   Begin
        tong:=0;
        while a<>'' do
              Begin
                   tong:=tong+(ord(a[1])-48);
                   delete(a,1,1);
              End;
   End;
//------------------------------
Procedure Songuon;
   Var S,x:integer;
   Begin
        for S:=length(n)*9 downto 1 do
            Begin
                 M:=tru(N,s);
                 if tong(M)=S then
                    Begin
                         xuat(M);
                         halt;
                    End;
            End;
   End;
//==============================
BEGIN
     docfile;
     Songuon;
     xuat('0');
END.
