program opening (input,output);
uses
 crt,font;
type
 ltrsave= array [0..255] of integer;
var
 fontsave:ltrsave;
 ltr,color,rehor,revert,hor,vert,nbr,lcv:integer;
begin
 randomize;
 opengraph;
  repeat
   rehor:=random(321);
   revert:=random(201);
   inc(nbr);
   fontsave[nbr]:=rehor;
   ltr:=random(90)+32;
   for lcv:=1 to nbr do
    if rehor<>fontsave[lcv] then
     begin
      letterwrite(ltr,color,rehor,revert);
     end;
   color:=random(255);
  until keypressed;
 readln;
 closegraph;
end.