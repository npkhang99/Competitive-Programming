Var i,n:longint;
BEGIN
    read(n);
    i:=1;
    while n*i mod 360 <>0 do inc(i);
    write(i);
END.