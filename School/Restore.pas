Const fi='Restore.inp';
      fo='Restore.out';
Type stt=Record
        tr,sau:longint;
     End;
Var a:array[1..2000000] of stt;
    vt:array[0..1000000] of longint;
    dem:array[0..1000000] of stt;
    kq:array[1..200001] of longint;
    n,dau,cuoi:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        dau:=0; fillchar(vt,sizeof(vt),0);
        for i:=1 to n do
            Begin
                readln(f,a[i].tr,a[i].sau);
                inc(dem[a[i].tr].tr); inc(dem[a[i].sau].tr);
                dem[a[i].tr].sau:=1; dem[a[i].sau].sau:=2;
                vt[a[i].tr]:=i;
            End;
        for i:=1 to 1000000 do
            if (dem[i].tr=1) and (dem[i].sau=1) then dau:=i;
        close(f);
    End;
//---------------------------------------------------------
Procedure xuat;
    Var f:text;
        i:longint;
    Begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to n do write(f,kq[i],' ');
        close(f);
    End;
//---------------------------------------------------------
Procedure xuly;
    Var i:longint;
    Begin
        kq[1]:=dau; kq[2]:=a[vt[0]].sau; kq[3]:=a[vt[dau]].sau;
        for i:=2 to n-2 do
            Begin
                kq[i+2]:=a[vt[kq[i]]].sau;
            End;
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
    xuat;
END.
