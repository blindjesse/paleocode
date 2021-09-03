uses crt;
type
    scrptr = ^scrtype;
    scrtype = array [0..199,0..319] of byte;

    sinptr = ^sintbl;
    sintbl = array [1..32] of real;

    cosptr = ^sintbl;
    costbl = array [1..32] of real;
var
   sint:sinptr;
   cost:cosptr;
   scr2:scrptr;
   c2,c,x,y,t:integer;
   f:real;

procedure rk; assembler;
asm
  xor ax,ax
  int 16h
end;

begin
  asm
     mov ax,13h
     int 10h
  end;
  new(sint);
  new(cosT);
  new(scr2);

  for x:=1 to 32 do
    sint^[x]:=sin(x * 0.2);
  for x:=1 to 32 do
    cost^[x]:=cos(x * 0.2);
  for x:=0 to 199 do
      for y:=0 to 319 do
          scr2^[x,y]:=0;
  for x:=191 to 255 do begin
      port [968]:=x;
      port [969]:=x-191;
      port [969]:=x-191;
      port [969]:=x-191;
  end;
  t:=1;
  f:=0;
  c2:=0;
  move(scr2^,ptr($a000,0000)^,64000);
  repeat
    while (t<32)and (not keypressed) do begin
      inc(t);
      f:=f+0.2;
      x:=(trunc((cos(sint^[t])*125)+(f*5+cos(sin (f)))+300) div 2)-160;
      y:=trunc((sin(-cost^[t])*125)+(x*sin(-cos(f)))+300) div 2;
      {if (y < 320) and (x < 199) and (x > 0) and (y >0) then} scr2^[x,y]:=10;
    end;
    move(scr2^,ptr($a000,0000)^,64000);
    for x:=0 to 199 do
        for y:=0 to 319 do
            scr2^[x,y]:=0;
    repeat until port[$3da] and 8 =8;
    if c = 255 then c:=220 else inc(c);
    t:=0;
  until keypressed;
  dispose(scr2);
  dispose(sint);
  dispose(cost);
  rk;
  asm
     mov ax,3h
     int 10h
  end;
end.