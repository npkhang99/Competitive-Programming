Uses DOS,crt;
Type mang=array[0..2000000] of longint;
Const fo='timesort.log';
Var a,b:mang;
    h1,h2,p1,p2,s1,s2,ss1,ss2:word;
    x,y,z,t:integer;
	time: qword;
	n:longint;
    f:text;
//------------------------------
Function toString(x:integer):string;
	Var st:string;
	Begin
		if x<10 then exit('0'+chr(x+48));
		exit(chr(x div 10 + 48) + chr(x mod 10+48));
	End;
//------------------------------
Procedure revalue;
   Var i:longint;
   Begin
        for i:=1 to n do b[i]:=a[i];
   End;
//------------------------------
Procedure rand;
   Var i:longint;
   Begin
        for i:=1 to n do a[i]:=random(1000000)-random(1000000);
   End;
//------------------------------
Procedure SelectSort;
   Var i,j,tam:longint;
   Begin
        writeln(f,'-------------------------------------');
        writeln(f,'Select Sort:');
        writeln('Select Sort: ');
        gettime(h1,p1,s1,ss1);
        writeln('Select Sort BEGIN!  ',tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        write(f,tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        write('SORTING...');
        for i:=1 to n-1 do
            for j:=i+1 to n do
                if b[i]>b[j] then
                   Begin
                        tam:=b[j];
                        b[j]:=b[i];
                        b[i]:=tam;
                   End;
        gettime(h2,p2,s2,ss2);
        time:=(ss2+s2*100+p2*6000+h2*360000) - (ss1+s1*100+p1*6000+h1*360000);
        x:=time div 360000;
		dec(time,(time div 360000)*360000);
        y:=time div 6000;
		dec(time,(time div 6000)*6000);
        z:=time div 100;
		dec(time,(time div 100)*100);
        t:=time;
        gotoxy(1,7);writeln('Select Sort DONE!   ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,' - ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,tostring(x),':',tostring(y),':',tostring(z),'.',tostring(t));
   End;
//------------------------------
Procedure InsertSort;
   Var i,j,tam:longint;
   Begin
        revalue;
        writeln(f,'-------------------------------------');
        writeln(f,'Insert Sort:');
        writeln('Insert Sort: ');
        gettime(h1,p1,s1,ss1);
        writeln('Insert Sort BEGIN!  ',tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        write('SORTING...');
        write(f,tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        for i:=2 to n do
            Begin
                 tam:=b[i];
                 j:=i;
                 While ((j>1) and (b[j-1]>tam)) do
                       Begin
                            b[j]:=b[j-1];
                            dec(j);
                       End;
                 b[j]:=tam;
            End;
        gettime(h2,p2,s2,ss2);
        time:=(ss2+s2*100+p2*6000+h2*360000) - (ss1+s1*100+p1*6000+h1*360000);
        x:=time div 360000;
		dec(time,(time div 360000)*360000);
        y:=time div 6000;
		dec(time,(time div 6000)*6000);
        z:=time div 100;
		dec(time,(time div 100)*100);
        t:=time;
        gotoxy(1,11);writeln('Insert Sort DONE!   ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,' - ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,tostring(x),':',tostring(y),':',tostring(z),'.',tostring(t));
   End;
//------------------------------
Procedure BubbleSort;
   Var i,j,tam:longint;
   Begin
        revalue;
        writeln(f,'-------------------------------------');
        writeln(f,'Bubble Sort:');
        writeln('Bubble Sort: ');
        gettime(h1,p1,s1,ss1);
        writeln('Bubble Sort BEGIN!  ',tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        write('SORTING...');
        write(f,tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        for i:=2 to n do
            for j:=n downto i do
                if b[j]<b[j-1] then
                   Begin
                        tam:=b[j-1];
                        b[j-1]:=b[j];
                        b[j]:=tam;
                   End;
        gettime(h2,p2,s2,ss2);
        time:=(ss2+s2*100+p2*6000+h2*360000) - (ss1+s1*100+p1*6000+h1*360000);
        x:=time div 360000;
		dec(time,(time div 360000)*360000);
        y:=time div 6000;
		dec(time,(time div 6000)*6000);
        z:=time div 100;
		dec(time,(time div 100)*100);
        t:=time;
        gotoxy(1,15);writeln('Bubble Sort DONE!   ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,' - ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,tostring(x),':',tostring(y),':',tostring(z),'.',tostring(t));
   End;
//------------------------------
Procedure QSort(l,r:longint);
   Var m,i,j,tam:longint;
   Begin
        m:=b[(l+r) div 2];
        i:=l;
        j:=r;
        Repeat
              While b[i]<m do inc(i);
              While b[j]>m do dec(j);
              If i<=j then
                 Begin
                      tam:=b[j];
                      b[j]:=b[i];
                      b[i]:=tam;
                      inc(i);
                      dec(j);
                 End;
        Until i>j;
        if j>l then QSort(l,j);
        if i<r then QSort(i,r);
   End;
//------------------------------
Procedure QuickSort;
   Begin
        revalue;
        writeln(f,'-------------------------------------');
        writeln(f,'Quick Sort:');
        writeln('Quick Sort: ');
        gettime(h1,p1,s1,ss1);
        writeln('Quick Sort BEGIN!   ',tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        write('SORTING...');
        write(f,tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
        QSort(1,n);
        gettime(h2,p2,s2,ss2);
		time:=(ss2+s2*100+p2*6000+h2*360000) - (ss1+s1*100+p1*6000+h1*360000);
        x:=time div 360000;
		dec(time,(time div 360000)*360000);
        y:=time div 6000;
		dec(time,(time div 6000)*6000);
        z:=time div 100;
		dec(time,(time div 100)*100);
        t:=time;
        gotoxy(1,19);writeln('Quick Sort DONE!    ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,' - ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
        writeln(f,tostring(x),':',tostring(y),':',tostring(z),'.',tostring(t));
   End;
//==============================
BEGIN
	 clrscr;
	 write('Input the number of element(s): '); readln(n);
     clrscr;
     randomize;
     assign(f,fo);
     rewrite(f);
	 writeln(n,' element(s)');
     writeln(f,'With ',n,' element(s):');
     writeln('STATUS:');
     gettime(h1,p1,s1,ss1);
     writeln('BEGIN! ',tostring(h1),':',tostring(p1),':',tostring(s1),'.',tostring(ss1));
     rand;
     writeln('===================================================');
     SelectSort;
     writeln('---------------------------------------------------');
     InsertSort;
     writeln('---------------------------------------------------');
     BubbleSort;
     writeln('---------------------------------------------------');
     QuickSort;
     writeln('===================================================');
     writeln('All DONE! ',tostring(h2),':',tostring(p2),':',tostring(s2),'.',tostring(ss2));
     close(f);
END.
