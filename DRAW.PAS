program screendraw (input,output);
uses
 crt;
type
    scrptr = ^scrtype;
    scrtype = array [0..199,0..319] of byte;
var
 save:scrtype;
 scr2:scrptr;
 x,y,color,lcv,nbr,rehor,revert:integer;
{--------------------------------------------------------}
procedure rk; assembler;
asm
  xor ax,ax
  int 16h
end;
{==============================================================}
begin
  asm
     mov ax,13h
     int 10h
  end;
  new(scr2);
  for x:=0 to 199 do
      for y:=0 to 319 do
          scr2^[x,y]:=0;
  for x:=191 to 255 do begin
      port [968]:=x;
      port [969]:=x-191;
      port [969]:=x-191;
      port [969]:=x-191;
  end;
  rehor:=0;
  revert:=0;
  move(scr2^,ptr($a000,0000)^,64000);
  repeat
    color:=(ord(readkey));
    case color of
     28: rehor:=rehor+1;
     29: rehor:=rehor-1;
     30: revert:=revert+1;
     31: revert:=revert+1;
     end; {case}
     if  (color<>28) and (color<>29) and (color<>30) and (color<>31) then
      begin
       color:=color-48;
       scr2^[revert,rehor]:=color;
      end;
   move(scr2^,ptr($a000,0000)^,64000);
{  for x:=0 to 199 do
      for y:=0 to 319 do
          scr2^[x,y]:=0;
 }  until color=27;
   readln;
  dispose(scr2);
  rk;
end.