// SPOJ submission 15929637 (PAS fpc) plaintext list. Status: AC, problem LIS, contest SPOJVN. By mansblacks (Khang), 2015-12-24 07:03:33.
Const fi='';
{    11
    3 4 -1 5 8 2 3 12 7 9 10    }
      fo='';
      n_=100009;
Type int=longint;
     bool=boolean;
Var a:array[0..n_] of int;    // source array
    t:array[0..n_] of int;    // temporary store the last index of the LIS of length(i)
    tr:array[0..n_] of int;    // index of the previous element of i-th element in LIS
    b:array[0..n_] of bool;
    n:int;
//---------------------------------------------------------
Procedure getData();
    Var f:text;
        i:int;
    Begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        for i:=1 to n do
            Begin
                read(f,a[i]);
                tr[i]:=0;
                b[i]:=false;
            End;
        close(f);
    End;
//---------------------------------------------------------
Procedure printResult(result:int);
    Var f:Text;
        i:int;
    Begin
        assign(f,fo);
        rewrite(f);
        writeln(f,result);
        close(f);
    End;
//---------------------------------------------------------
Procedure LIS();
    Var i,j,leng,l,r:int;
    Begin
        t[1]:=1; leng:=1;
        for i:=2 to n do
            Begin
                if (a[i]>a[t[leng]]) then // check if the i-th element is greater than the last element of current LIS
                    Begin
                        inc(leng);
                        t[leng]:=i;
                        tr[i]:=t[leng-1];
                        continue;
                    End;
                // find the range of T[l..r] which contains the index of the last element that lower than a[i]
                l:=1; r:=leng; j:=(l+r) div 2;
                while (l <> j) and (r<>j) do
                    Begin
                        if(a[i]<=a[t[j]]) then r:=j
                        else l:=j;
                        j:=(l+r) div 2;
                    End;
                // find the first one
                for j:=l to r do
                    if (a[i]<=a[t[j]]) then
                        Begin
                            tr[i]:=t[j-1];
                            t[j]:=i;
                            break;
                        End;
            End;
        printResult(leng);
    End;
//---------------------------------------------------------
BEGIN
    getData();
    LIS();
END.
