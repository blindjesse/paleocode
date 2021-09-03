program font (input,output);
uses
 crt;
type
  graphic = array [1..255] of char;
  letterow = array [32..127,1..8] of integer;
  ltrnbrtype = array [1..8,1..5] of integer;
  ltrvartype = array [1..8,1..5] of char;
  name= array [1..5] of char;
var
 jesse:name;
 current:char;
 horiz,vertiz,spc,ycoord,xcoord,ltr,color:integer;
 rehor,revert,r,a:real;
 lettrass:ltrnbrtype;
 lcv,nbr:integer;
{-------------------------------------------------------------------------}
  procedure assignletter ( ltr:integer; var intarray:ltrnbrtype;
                             yval:integer);
  type
   rowtype = array [0..31, 1..5 ] of char;
  const
   xval=0;
{32}u:letterow=  ((0,0,0,0,0,0,0,0),
   (4,4,4,4,0,4,0,0),
   (10,10,10,0,0,0,0,0),
   (10,10,31,10,31,10,10,0),
   (4,15,20,14,5,30,4,0),
   (24,25,2,4,8,19,3,0),
   (8,20,20,8,21,18,13,0),
   (4,4,0,0,0,0,0,0),
   (2,4,8,8,8,4,2,0),
   (8,4,2,2,2,4,8,0),
   (0,10,4,31,4,10,0,0),
   (0,4,4,31,4,4,0,0),
   (0,0,0,0,12,12,4,8),
   (0,0,0,31,0,0,0,0),
   (0,0,0,0,0,0,24,24),
   (0,1,2,4,8,16,0,0),
   (14,17,17,21,17,17,14,0),
   (4,12,4,4,4,4,14,0),
   (14,17,1,6,8,16,31,0),
   (14,17,1,14,1,17,14,0),
   (2,6,10,18,31,2,2,0),
   (31,16,30,1,1,17,14,0),
   (6,8,16,30,17,17,14,0),
   (31,1,2,4,8,8,8,0),
   (14,17,17,14,17,17,14,0),
   (14,17,17,15,1,2,12,0),
   (0,12,12,0,12,12,0,0),
   (0,12,12,0,12,12,4,8),
   (2,4,8,16,8,4,2,0),
   (0,0,31,0,31,0,0,0),
   (16,8,4,2,4,8,16,0),
   (14,17,1,2,4,0,4,0),
   (14,17,21,23,23,20,16,15),
   (14,17,17,31,17,17,17,0),
   (30,17,17,30,17,17,30,0),
   (14,17,16,16,16,17,14,0),
   (28,18,17,17,17,18,28,0),
   (31,16,16,30,16,16,31,0),
   (31,16,16,30,16,16,16,0),
   (14,17,16,16,19,17,15,0),
   (17,17,17,31,17,17,17,0),
   (14,4,4,4,4,4,14,0),
   (1,1,1,1,17,17,14,0),
   (17,18,20,24,20,18,17,0),
   (16,16,16,16,16,16,31,0),
   (17,27,21,21,17,17,17,0),
   (17,17,25,21,19,17,17,0),
   (14,17,17,17,17,17,14,0),
   (30,17,17,30,16,16,16,0),
   (14,17,17,17,21,18,13,0),
   (30,17,17,30,20,18,17,0),
   (14,17,16,14,1,17,14,0),
   (31,4,4,4,4,4,4,0),
   (17,17,17,17,17,17,14,0),
   (17,17,17,10,10,4,4,0),
   (17,17,17,21,21,27,17,0),
   (17,17,10,4,10,17,17,0),
   (17,17,10,4,4,4,4,0),
   (31,1,2,4,8,16,31,0),
   (14,8,8,8,8,8,14,0),
   (0,16,8,4,2,1,0,0),
   (14,2,2,2,2,2,14,0),
   (4,10,17,0,0,0,0,0),
   (0,0,0,0,0,0,0,31),
   (8,8,4,0,0,0,0,0),
   (0,0,14,1,15,17,15,0),
   (16,16,30,17,17,17,30,0),
   (0,0,15,16,16,16,15,0),
   (1,1,15,17,17,17,15,0),
   (0,0,14,17,31,16,14,0),
   (4,10,8,28,8,8,8,0),
   (0,0,14,17,17,15,1,14),
   (16,16,30,17,17,17,17,0),
   (4,0,12,4,4,4,14,0),
   (4,0,12,4,4,4,20,12),
   (16,16,18,20,24,20,18,0),
   (12,4,4,4,4,4,14,0),
   (0,0,26,21,21,21,17,0),
   (0,0,30,17,17,17,17,0),
   (0,0,14,17,17,17,14,0),
   (0,0,30,17,17,30,16,16),
   (0,0,15,17,17,15,1,1),
   (0,0,23,24,16,16,16,0),
   (0,0,15,16,14,1,30,0),
   (8,8,28,8,8,10,4,0),
   (0,0,17,17,17,17,15,0),
   (0,0,17,17,17,10,4,0),
   (0,0,17,17,21,21,10,0),
   (0,0,17,14,4,14,17,0),
   (0,0,17,17,17,15,1,14),
   (0,0,31,2,4,8,31,0),
   (6,8,8,16,8,8,6,0),
   (4,4,4,4,4,4,4,0),
   (12,2,2,1,2,2,12,0),
   (1,14,16,0,0,0,0,0),
   (0,0,0,0,0,0,0,0));

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
 {.................................................................}
  for rowcount:=1 to 8 do
   for columncount:= 1 to 5 do
     xory[rowcount,columncount]:= rows[u[ltr,rowcount],columncount];
  for xnbr := 1 to 8 do
   for ynbr := 1 to 5 do
    begin
     if xory[xnbr,ynbr] = 'x' then
       intarray[xnbr,ynbr]:= xval
     else  intarray[xnbr,ynbr] := yval
    end;
  end;
{-------------------------------------------------------------------------}
procedure screenwrite (var lettrass:ltrnbrtype;
                         rehor:integer; revert:integer);
var
 height,width:integer;
begin
   for height := 1 to 8 do
     for width := 1 to 5 do
     mem[$a000:((revert+height)*320)+(rehor+width)]:=lettrass[height,width];
end;
{==========================================================================}
begin
 a:=0;
 r:=50;
 asm
  mov ax, 13h;
  int 10h;
 end;
 ycoord:=100;
 xcoord:=100;
 jesse:='JESSE';
 repeat
 for nbr:=1 to 5 do
   begin
    horiz:=round(rehor);
    vertiz:=round(revert);
    a:=0;
    while a<6.28318 do
     begin
      a:=a+0.15;
      r:=r-0.1;
      rehor:=(ycoord+(r*sin(a)));
      revert:=(xcoord+(r*cos(a)));
      horiz:=round(rehor);
      vertiz:=round(revert);
      assignletter(ord(jesse[nbr]),lettrass,13);
      screenwrite(lettrass,horiz,vertiz);
      repeat until port[$3da] and 8=8;
      assignletter(32,lettrass,13);
      screenwrite(lettrass,horiz,vertiz);
     end;
  end;
  until r=0;
   screenwrite(lettrass,horiz,vertiz);
   assignletter(ord(jesse[nbr]),lettrass,4);
   repeat until port[$3da] and 8=8;
 asm
  mov ax, 3h;
  int 10h;
 end;

end.
