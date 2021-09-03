program threedee (input,output);
uses
 font;
var
 color,rehor,revert,nbr,lcv:integer;
 r,a,b,hor,vert:real;
begin
 randomize;
 asm
  mov ax, 13h;
  int 10h;
 end;
 r:=0;
 for nbr:=1 to 30 do
  begin
   vert:=100;
   hor:=100;
   a:=1;
   color:=random(16);
   b:=0;
   r:=r+5;
   while a<50 do
    begin
     hor:=100+r*sin(a);
     vert:=160+r*cos(a);
     revert:=round(vert);
     rehor:=round(hor);
     mem[$a000:((rehor)*320)+(revert)]:=color;
     a:=a+1;
     repeat until port[$3da] and 8=8;
    end;
  end;
 readln;
 asm
  mov ax, 3h;
  int 10h;
 end;
end.