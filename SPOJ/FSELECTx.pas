uses math;
const fi='';//NEWF.inp';
      fo='';//NEWF.out';
      nmax=200000;
type bang=record
     vt,cha,chen,d:longint;
end;
var n,k,log,ans:longint;
    a:array[1..nmax] of bang;
    dd,count:array[0..nmax] of longint;
    b:array[0..nmax,0..trunc(ln(nmax)/ln(2))+1] of longint;

{----------------------------}
procedure INPUT;
var i:longint;
    f:text;
begin
  assign(f,fi); reset(f);
  read(f,n,k);
  for i:=1 to n do
    begin
      read(f,a[i].chen,a[i].cha);
      a[i].vt:=i; a[i].d:=0;
    end;
  close(f);
end;
{----------------------------}
procedure dfs(u:longint);
begin
  if a[u].d>0 then exit;
  if a[u].cha=0 then a[u].d:=1
  else
    begin
      dfs(a[u].cha);
      a[u].d:=a[a[u].cha].d+1;
    end;
end;
{----------------------------}
procedure quicksort(l,r:longint);
var i,j:longint;
    tam,x:bang;
begin
  i:=l; j:=r; x:=a[(i+j) div 2];
  repeat
    while (a[i].chen<x.chen) or ((a[i].chen=x.chen)and(a[i].d>x.d)) do inc(i);
    while (a[j].chen>x.chen) or ((a[j].chen=x.chen)and(a[j].d<x.d)) do dec(j);
    if i<=j then
      begin
        tam:=a[i];
        a[i]:=a[j];
        a[j]:=tam;
        inc(i); dec(j);
      end;
  until i>j;
  if l<j then quicksort(l,j);
  if i<r then quicksort(i,r);
end;
{----------------------------}
function getbit(i,x:longint):longint;
begin
  exit((x shr i) and 1);
end;
{----------------------------}
function LCA(u,v:longint):longint;
var tam,t,bit,k:longint;
begin
  if dd[u]<dd[v] then
    begin
      tam:=u; u:=v; v:=tam;
    end;
  if dd[u]>dd[v] then
    begin
      t:=dd[u]-dd[v];
      for bit:=log downto 0 do
        if getbit(bit,t)=1 then u:=b[u,bit];
     end;

      for k:=log downto 0 do
        if b[u,k]<>b[v,k] then
          begin
            u:=b[u,k]; v:=b[v,k];
          end
        else LCA:=b[u,k];
      if u=v then LCA:=u;
end;
{----------------------------}
function distance(u,v:longint):longint;
var x:longint;
begin
  x:=lca(u,v);
  exit(dd[u]+dd[v]-2*dd[x]);
end;
{----------------------------}
procedure solve;
var i,j,u,v,chen1:longint;
begin
  for i:=1 to n do dfs(i);  //d la muc cua i
  for i:=1 to n do dd[i]:=A[i].d;


  log:=trunc(ln(n)/ln(2))+1;
  b[0,0]:=0; //b[i,j] la to tien thu 2^j cua i
  for i:=1 to n do b[i,0]:=a[i].cha;
  for j:=1 to log do
    for i:=1 to n do b[i,j]:=b[b[i,j-1],j-1];
  quicksort(1,n);
  count[0]:=0;
  count[1]:=1; chen1:=1;
  for i:=2 to n do
    if a[i].chen=chen1 then inc(count[chen1])
    else
      begin
        chen1:=a[i].chen; count[chen1]:=1;
      end;
  for i:=2 to k do count[i]:=count[i-1]+count[i];
end;
{----------------------------}
procedure OUTPUT;
var g:text;
    i,u,v:longint;
begin
  assign(g,fo); rewrite(g);
  for i:=1 to k do
    begin
      ans:=-1;
      u:=a[count[i-1]+1].vt;
      for v:=count[i-1]+2 to count[i] do ans:=max(ans,distance(u,a[v].vt));
      writeln(g,ans);
    end;
  close(g);
end;
{----------------------------}
begin
  INPUT;
  solve;
  OUTPUT;
END.
