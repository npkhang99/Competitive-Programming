var x,k             : int64;
    sx,r            : string;
    sobit1,n        : longint;
    f               : array[1..61,0..60,false..true] of int64;

procedure chuanbi;
BEGIN
    sx:=''; 
    sobit1:=0;
    for i:=1 to n do BEGIN
        sx:=char(x mod 2+48) + sx;
        if x mod 2 = 1 then inc(sobit1);
        x:=x div 2;

    end;
    r:=sx;
end;

function tinh(i,c:longint; ok:boolean): int64;
var min, v :char;
    sl     :int64;
BEGIN
    if f[i][c][ok] >-1 then exit(f[i][c][ok]);

    if (i>n) exit(ord((c=0) and (ok)));

    if ok then min:='0'
    else min:=sx[i];

    sl:=0;
    for v:=min to '1' do 
        sl:=sl + tinh(i+1,c+ord(v='1'), ok or (v>sx[i]));
    f[i][c][ok] := sl;
    exit(sl);
end;

procedure lankq(i,c:longint; ok:boolean);
var min, v :char;
    sl     :int64;
BEGIN
    if (i>n) exit;

    if ok then min:='0'
    else min:=sx[i];

    for v:=min to '1' do begin 
        sl:=tinh(i+1,c+ord(v='1'), ok or (v>sx[i]));
        if (sl<k) k:=k-sl
        else begin
                r[i]:=v;
                lankq(i+1,c+ord(v='1'), ok or (v>sx[i]));
                break;
        end;
    end;
end;

procedure ghikq;
begin
    r2:=0;
    for i:=1 to n do r2:=r2 * 2 + ord(r[i]) - 48;
    if r2<=trunc(1e15) then writeln(r2)
    else writeln(-1);
end;

BEGIN
    readln(x);
    //chuyen x sang dang nhi phan
    n:=60;
    chuanbi;

    fillchar(f,sizeof(f),255);

    if (tinh(1,0,false))<k) then writeln(-1)
    else begin
            lankq(1,0,false);
            ghikq;
    end;

END.
