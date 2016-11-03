Uses math;
Type vector = Record
        x,y: real;
     End;
Const epsilon = 1E-6;
Var n:longint;
    p: array[1..1000009] of vector;
    a,b,tinhTien:vector;
    canDoiTruc:boolean;

Function tru(u,v:vector):vector;
    Var w:vector;
    Begin
        w.x := u.x - v.x;
        w.y := u.y - v.y;
        exit(w);
    End;

Function cham(u,v:vector):real;
    Begin
        exit(u.x*v.x + u.y*v.y);
    End;

Function cheo(u,v:vector):real;
    Begin
        exit(u.x*v.y - u.y*v.x);
    End;

Procedure doc;
    Var i:longint;
    Begin
        readln(n,a.x,a.y);
        for i:=1 to n do
            readln(p[i].x,p[i].y);
        p[n+1] := p[1];
    End;

Procedure timVectorTinhTien;
    Var min_x, min_y:real;
        i:longint;
    Begin
        canDoiTruc:=false;
        min_x:=100000; min_y:=100000;
        for i:=1 to n do
            with p[i] do
                Begin
                    min_x:=min(min_x,x);
                    min_y:=min(min_y,y);
                    if (x=0) or (y=0) then canDoiTruc:=true;
                End;
        tinhTien.x:=min_x-1;
        tinhTien.y:=min_y-1;
    End;

Procedure doiTruc;
    Var i:longint;
    Begin
        for i:=1 to n+1 do
            with p[i] do
                Begin
                    x:=x+tinhTien.x;
                    y:=y+tinhTien.y;
                End;
        a.x:=a.x+tinhTien.x;
        a.y:=a.y+tinhTien.y;
    End;

Function namTrenDoan(p,q:vector):boolean;
    Var u,v:vector;
    Begin
        u:=tru(p,a);
        v:=tru(q,a);
        exit(isZero(cheo(u,v),epsilon) and (cham(u,v)<=0));
    End;

Procedure taoTia;
    Var good:boolean;
        i:longint;
    Begin
        repeat
            good:=true; b.x:=random; b.y:=random;
            for i:=1 to n do
                if isZero(cheo(tru(b,a), p[i]),epsilon) then
                    Begin
                        good:=false;
                        break;
                    End;
        until good;
    End;

Function tuyenTinh(a,b,c:vector):vector;
    Var d,dx,dy:real;
        w:vector;
    Begin
        d:=cheo(a,b); dx:=cheo(c,b); dy:=cheo(a,c);
        w.x:=dx/d; w.y:=dy/d;
        exit(w);
    End;

Function cat(c,d:vector):boolean;
    Var w:vector;
    Begin
        w:=tuyenTinh(tru(b,a),tru(c,d),tru(c,a));
        exit((w.x>=0) and inRange(w.y,0,1));
    End;

Function ktra:boolean;
    Var i,dem:longint;
    Begin
        for i:=1 to n do
            if namTrenDoan(p[i],p[i+1]) then exit(true);
        taoTia;
        dem:=0;
        for i:=1 to n do
            if cat(p[i],p[i+1]) then inc(dem);
        if dem mod 2 = 1 then exit(true)
        else exit(false);
    End;

Procedure xuly;
    Var isInside:boolean;
    Begin
        isInside:=ktra;
        if isInside then writeln('YES')
        else writeln('NO');
    End;

BEGIN
    randomize;
    setExceptionMask([Low(TFPUExceptionMask)..High(TFPUExceptionMask)]);
    doc;
    timVectorTinhTien;
    if canDoiTruc then doiTruc;
    xuly;
END.
