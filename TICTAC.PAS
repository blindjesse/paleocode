program tictactoe (input,output);
uses
 font;
type
 ttttype= array [1..11] of char;
 intype= array [1..50] of char;
{----------------------------------------------------------------------}
procedure title;
const
 titato:ttttype=('T','i','c',' ','T','a','c',' ','T','o','e');
var
 lcv,nbr,rehor,color:integer;
 ltr:char;
 intarray:ltrnbrtype;
begin
 color:=80;
 revert:=1;
 rehor:=20;
 for nbr:= 1 to 11 do
  begin
   ltr:=titato[nbr];
   letterwrite(ltr,color,rehor,revert);
   color:=color+1;
   rehor:=rehor+6;
  end;
end;
{----------------------------------------------------------------------}
procedure instructions;
var
 nbr,lcv:integer;
const
 instructions:intype=('T','h','i','s',' ','i','s',' ','a',' ','T','i','c'
                      ' ','T','a','c',' ','T','o','e',' ','G','a','m',e');
begin
end;
{----------------------------------------------------------------------}
procedure drawboard;
const
 vertic:integer=17;
 horiz:integer=45;
var
 down,nbr,lcv,across:integer;
begin
 revert:=vertic;
 rehor:=horiz;
 for down:= 1 to 2 do
  begin
   for nbr:= 1 to 60 do
    begin
     revert:=revert+1;
     putpixel(13,rehor,revert);
    end;
  rehor:=rehor+20;
  revert:=vertic;
  end;
 revert:=vertic+22;
 for across:=1 to 2 do
  begin
  rehor:=horiz-28;
   for lcv:=1 to 80 do
    begin
     putpixel(13,rehor,revert);
     rehor:=rehor+1;
    end;
  revert:=revert+15;
  end;
end;
{=====================================================================}
begin
 opengraph;
 title;
 drawboard;
 readln;
 closegraph;
end.