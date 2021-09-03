program font (input,output);
uses
 graph,crt;
type
  letterow = packed array [1..8] of integer;
  rowpixels = array [1..5] of integer;
  rowchar = array [1..5] of char;
  ltrnbrtype = array [1..8,1..5] of integer;
  ltrvartype = array [1..8,1..5] of char;
  picture=  array [0..14,0..24] of integer;
const
bigtree:picture=((0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0),
 (0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0),
 (0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0),
 (0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0),
 (0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0),
 (0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0),
 (1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0),
 (0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0),
 (0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0));
 a:letterow=(14,17,17,31,17,17,17,0);
 b:letterow=(30,17,17,30,17,17,30,0);
 c:letterow=(14,17,16,16,16,17,14,0);
 d:letterow=(28,18,17,17,17,18,28,0);
 e:letterow=(31,16,16,30,16,16,31,0);
 f:letterow=(31,16,16,30,16,16,16,0);
 g:letterow=(14,17,16,16,19,17,15,0);
 h:letterow=(17,17,17,31,17,17,17,0);
 i:letterow=(14,4,4,4,4,4,14,0);
 j:letterow=(1,1,1,1,17,17,14,0);
 k:letterow=(17,18,20,24,20,18,17,0);
 l:letterow=(16,16,16,16,16,16,31,0);
 m:letterow=(17,27,21,21,17,17,17,0);
 n:letterow=(17,17,25,21,19,17,17,0);
 o:letterow=(14,17,17,17,17,17,14,0);
 p:letterow=(30,17,17,30,16,16,16,0);
 q:letterow=(14,17,17,17,21,18,13,0);
 r:letterow=(30,17,17,30,20,18,17,0);
 s:letterow=(14,17,16,14,1,17,14,0);
 t:letterow=(31,4,4,4,4,4,4,0);
 u:letterow=(17,17,17,17,17,17,14,0);
 v:letterow=(17,17,17,10,10,4,4,0);
 w:letterow=(17,17,17,21,21,27,17,0);
 x:letterow=(17,17,10,4,10,17,17,0);
 y:letterow=(17,17,10,4,4,4,4,0);
 z:letterow=(31,1,2,4,8,16,31,0);
 la:letterow=(0,0,14,1,15,17,15,0);
 lb:letterow=(16,16,30,17,17,17,30,0);
 lc:letterow=(0,0,15,16,16,16,15,0);
 ld:letterow=(1,1,15,17,17,17,15,0);
 le:letterow=(0,0,14,17,31,16,14,0);
 lf:letterow=(4,10,8,28,8,8,8,0);
 lg:letterow=(0,0,14,17,17,15,1,14);
 lh:letterow=(16,16,30,17,17,17,17,0);
 li:letterow=(4,0,12,4,4,4,14,0);
 lj:letterow=(4,0,12,4,4,4,18,12);
 lk:letterow=(16,16,18,20,24,20,18,0);
 ll:letterow=(12,4,4,4,4,4,14,0);
 lm:letterow=(0,0,26,21,21,21,17,0);
 ln:letterow=(0,0,30,17,17,17,17,0);
 lo:letterow=(0,0,14,17,17,17,14,0);
 lp:letterow=(0,0,30,17,17,30,16,16);
 lq:letterow=(0,0,15,17,17,15,1,1);
 lr:letterow=(0,0,23,24,16,16,16,0);
 ls:letterow=(0,0,15,16,14,1,30,0);
 lt:letterow=(8,8,28,8,8,10,4,0);
 lu:letterow=(0,0,17,17,17,17,15,0);
 lv:letterow=(0,0,17,17,17,10,4,0);
 lw:letterow=(0,0,17,17,21,21,10,0);
 lx:letterow=(0,0,17,21,4,21,17,0);
 ly:letterow=(0,0,17,17,17,15,1,14);
 lz:letterow=(0,0,31,2,4,8,31,0);
 spc:letterow=(0,0,0,0,0,0,0,0);
 x0:letterow=(14,17,17,21,17,17,14,0);
 x1:letterow=(4,12,4,4,4,4,14,0);
 x2:letterow=(14,17,1,6,8,16,31,0);
 x3:letterow=(14,17,1,14,1,17,14,0);
 x4:letterow=(2,6,10,18,31,2,2,0);
 x5:letterow=(31,16,30,1,1,17,14,0);
 x6:letterow=(6,8,16,30,17,17,14,0);
 x7:letterow=(31,1,2,4,8,8,8,0);
 x8:letterow=(14,17,17,14,17,17,14,0);
 x9:letterow=(14,17,17,15,1,2,12,0);
 tree:letterow=(4,4,14,14,31,31,4,14);
var
 lcv,nbr,color,pos,count,shove,height,width,device,mode:integer;
 xory:ltrnbrtype;
 lettrass,blank:ltrvartype;
{-------------------------------------------------------------------------}
  procedure assignletter (var letter:letterow;var intarray:ltrnbrtype;
                            var yval:integer);
  type
   rowtype = array [0..31, 1..5 ] of char;
  const
   xval=0;
  var
      xory:ltrvartype;
      x,y:char;
      columncount,rowcount,row,column,row1,row2,row3,row4,row5:integer;
      xnbr,ynbr:integer;
      rows:rowtype;
  begin
    for row := 0 to 31 do
      for column:= 1 to 5 do
        rows[row,column]:='x';
    for row1 := 16 to 31 do
     rows[row1,1]:='y';
    for row2 := 8 to 31 do
     begin
       rows[row2,2] := 'y';
       if row2 = 15 then
        row2:=row2+8;
     end;
    for row3 := 4 to 31 do
     begin
       rows[row3,3]:='y';
       if (row3=7) or (row3=15) or (row3=23) then
        row3:=row3+4;
     end;
    for row4:=2 to 31 do
     begin
        rows[row4,4]:='y';
         if (row4=3) or (row4=7) or (row4=11) or (row4=15) or (row4=19)
         or (row4=23) or (row4=27) then
           row4:=row4+2;
     end;
    for row5:= 0 to 31 do
     if odd(row5) then
      rows[row5,5]:='y';
  for rowcount:=1 to 8 do
   for columncount:= 1 to 5 do
     xory[rowcount,columncount]:= rows[letter[rowcount],columncount];
  for xnbr := 1 to 8 do
   for ynbr := 1 to 5 do
    begin;
     if xory[xnbr,ynbr] = 'x' then
       intarray[xnbr,ynbr]:= xval
     else  intarray[xnbr,ynbr] := yval;
     yval:=random(256);
    end;
  end;
{-------------------------------------------------------------------------}
procedure screenwrite (var lettrass:ltrnbrtype;
                        var rehor:integer;var revert:integer);
var
 height,width:integer;
begin
   for height := 0 to 14 do
     for width := 0 to 24 do
     mem[$a000:((revert+height)*320)+(rehor+width)]:=lettrass[height,width];
end;
{--------------------------------------------------------------------}
procedure intorows (user:picture;chared:ltrvartype);
var
 nbr,lcv,row:integer;
begin
 for row :=0 to 14 do
  for nbr:=0 to 24 do
   begin
     if user[row,nbr]=0 then
       chared[row,nbr]:='x' else
       chared[row,nbr]:='y';
   end;
end;
{-------------------------------------------------------------------------}
procedure pictureassign(lettrass:ltrvartype; xory:ltrnbrtype);
var
 xnbr,ynbr,xval,yval:integer;
begin
  for xnbr := 0 to 24 do
   for ynbr := 0 to 5 do
    begin;
     if lettrass[xnbr,ynbr] = 'x' then
       xory[xnbr,ynbr]:= xval
     else  xory[xnbr,ynbr] := yval;
     yval:=random(256);
    end;
  end;
{==========================================================================}
begin
 randomize;
 asm
  mov ax, 13h;
  int 10h;
 end;
 color:=0;
 shove:=0;
 pos:=0;
   readln;
 intorows(bigtree,lettrass);
 pictureassign(lettrass,xory);
 screenwrite(xory,shove,pos);
 asm
  mov ax, 3h;
  int 10h;
 end;
end.
