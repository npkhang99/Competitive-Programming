Const fi='';
      fo='';
Type diem=Record
        x,y,tt:longint;
        goc:real;
     End;
Var a:array[1..100000] of diem;
    n:longint;
//---------------------------------------------------------
Procedure docfile;
    Var f:text;
        i:longint;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            with a[i] do readln(f,x,y);
        close(f);
    End;
//---------------------------------------------------------
Function Angle(P1,P2:diem):real;
    Var dx,dy,ax,ay,c:real;
    Begin
        dx:=p2.x-p1.x;
        dy:=p2.y-p1.y;
        ax:=Abs(dx);
        ay:=Abs(dy);
        if (dy=0) and (dx = 0) then exit(0);
        if (dy>0) and (dx = 0) then exit (pi/2);
        if (dy=0) and (dx < 0) then exit (pi);
        if (dy<0) and (dx = 0) then exit(pi*3/2);
        if (dy=0) and (dx > 0) then exit(0);
        c:= arctan(ay/ax);
        if (dx>0) and (dy>0) then exit(c);
        if (dx<0) and (dy>0) then exit(pi-c);
        if (dx<0) and (dy<0) then exit(pi+c);
        if (dx>0) and (dy<0) then exit(2*pi-c);
    End;
//---------------------------------------------------------
Procedure tim;
    Var i:longint;
    Begin
        x0:=maxlongint; y0:=maxlongint;
        for i:=1 to n do
            with a[i] do
                if y=y0 then
                    Begin
                        if x<x0 then x0:=x;
                    End
                else if y<y0 then
                        Begin
                            x0:=x; y0:=y;
                        End;
    End;
//---------------------------------------------------------
Procedure doitruc;
    Var i:longint;
    Begin
        for i:=1 to n do
            with a[i] do
                Begin
                    x:=x-x0; y:=y-y0;
                    if (y=0) and (x=0) then cotg:=maxlongint+1
                    else if (y=0) and (x>0) then cotg:=maxlongint
                    else if (y=0) and (x<0) then cotg:=-maxlongint
                    else cotg:=x/y;
                End;
    End;
//---------------------------------------------------------
Procedure Swap(Var d1,d2:diem);
    Var t:diem;
    Begin
        t:=d1;
        d1:=d2;
        d2:=t;
    End;
//---------------------------------------------------------
Procedure qsort(l,r:longint);
    Var i,j:longint;
        m:real;
    Begin
        i:=l; j:=r; m:=a[i + random(j-i+1)].goc;
        
    End;
//---------------------------------------------------------
Procedure xuly;
    Var
    Begin
        
    End;
//=========================================================
BEGIN
    docfile;
    xuly;
END.