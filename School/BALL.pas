const f1='';//BALLGMVN.inp';
      f2='';
      nmax=1000;
type bang=record
   x,y:longint;
   end;
var
      a,b:array[0..nmax+1] of bang;
      la,lb,lnew:array[0..nmax+1] of longint;
      new:array[0..nmax+1] of real;
      n:longint;
procedure doc;
var f:text;
    i,j:longint;
begin
assign(f,f1); reset(f);
readln(f,n);
for i:=1 to n do
 begin
  readln(f,a[i].x,a[i].y);
   la[i]:=i;
  end;
 for i:=1 to n do
  begin
   readln(f,b[i].x,b[i].y);
   lb[i]:=n+i;
  end;
close(f);
end;
//============================
procedure Swap(var a,b:longint);
var tam:longint;
begin
 tam:=a;
 a:=b;
 b:=tam;
end;
//===========================
procedure sort(l,r:longint);
var i,j: longint;
   x,y:real;
begin
i:=l;
j:=r;
x:=new[(l+r) div 2];
repeat
while new[i]<x do inc(i);
while x<new[j] do dec(j);
 if i<=j then
  begin
  y:=new[i];
  new[i]:=new[j];
  new[j]:=y;
  swap(lnew[i],lnew[j]);
  inc(i);
  dec(j);
  end;
until i>j;
if l<j then sort(l,j);
if i<r then sort(i,r);
end;
//===============
procedure xuli;
var i,j,u,v:longint;
begin
for i:=1 to n do
begin
 for j:=1 to n do
   begin
    u:=a[i].x-b[j].x;
    v:=a[i].y-b[j].y;
    lnew[j]:=lb[j];
    if v=0 then
     new[j]:=maxlongint
      else
       new[j]:=u/v;
   end;
   sort(1,n);
   for j:=1 to n-1 do
    if new[j]=new[j+1] then
                        begin
                        writeln(la[i],' ',lnew[j],' ',lnew[j+1]);
                        halt;
                        end;
            end;
for i:=1 to n do
 begin
  for j:=1 to n do
   begin
   u:=b[i].x-a[j].x;
   v:=b[i].y-a[j].y;
   lnew[j]:=la[j];
    if v=0 then
     new[j]:=maxlongint
      else
       new[j]:=u/v;
   end;
   sort(1,n);
   for j:=1 to n-1 do
    if new[j]=new[j+1] then
       begin
       writeln(lb[i],' ',lnew[j],' ',lnew[j+1]);
       halt;
       end;
    end;
      
end;
//=====================================
begin
doc;
xuli;
writeln(-1);

end.