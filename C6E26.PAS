program Mankala (input,output);
uses
 crt;
type
 manktype = array [1..7] of integer;
var
 player1,player2:manktype;
 tile,tile2,count:integer;
{--------------------------------------------------------------------}
procedure nbrassign (var player1:manktype;var player2:manktype);
var
 count:integer;
begin
 for count := 1 to 7 do
  begin
   player1[count]:=3;
   player2[count]:=3;
  end;
 player1[1]:=0;
 player2[7]:=0;
end;
{---------------------------------------------------------------------}
procedure turn(var player1:manktype;var player2:manktype;
                   tile:integer;var again:boolean);
begin
 for count := 1 to player1[tile] do
   player1[count + tile] := player1[count + tile]  + 1;
   if player1[count+tile] = player1[7] then
     again:=true;
   if player1[count+tile] = 1 then
    player1[1] := (player1[1] + player2[count + tile]);
 player1[tile]:=0;
end;
{=====================================================================}
begin
 clrscr;
 nbrassign(player1,player2);
 write('Player 1, pick a tile from 1 to 6: ');
 readln (tile);
 turn(player1,player2,tile);
 write('Player 2, pick a tile from 1 to 6: ');
 readln (tile);
 turn(player2,player1,tile);
end.