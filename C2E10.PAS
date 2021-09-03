program Mankala (input,output);
uses
 crt;
type
 manktype = array [1..7] of integer;
var
 player1,player2:manktype;
 writecount,tile,tile2,count:integer;
{-------------------------------------------------------------------------}
procedure writematrix (var player1:manktype; var player2:manktype);
var
 count:integer;
begin
 for count := 1 to 7 do
  write (player1[count],' ');
 writeln;
 write ('Player2:   ');
 for count := 7 downto 1 do
  write (player2[count],' ');
end;
{--------------------------------------------------------------------------}
procedure nbrassign (var player1:manktype;var player2:manktype);
var
 count:integer;
begin
 for count:= 1 to 7 do
  begin
   player1[count]:=3;
   player2[count]:=3;
  end;
 player1[1]:=0;
 player2[1]:=0;
end;
{--------------------------------------------------------------------------}

PROCEDURE TURN (VAR PLAYERA:MANKTYPE;playerb:manktype;TILE:INTEGER);
VAR
 COUNT:INTEGER;
BEGIN
 FOR COUNT :=1 TO PLAYERA[TILE] DO
  begin
   PLAYERA [tiLE- count] :=PLAYERA[tILE - count] +1;
   IF PLAYERA [TILE-count]=1 THEN
     pLAYERA [1]:=(pLAYERA[1]+PLAYERB[TILE-count]);
   IF tile-count = 1 then
      playera:=playerb;
   PLAYERA [TILE]:=0;
  end;
END;
{-------------------------------------------------------------------------}

FUNCTION ENDGAME (VAR PLAYER:MANKTYPE) :BOOLEAN;
VAR
  COUNT, ENDGAMECOUNT: INTEGER;
BEGIN
	ENDGAMECOUNT :=0;
	FOR COUNT :=2 TO 6 DO
	 BEGIN
	  IF PLAYER[COUNT] = 0 THEN
	  ENDGAMECOUNT:=ENDGAMECOUNT+1;
	 END;
if endgamecount = 7 then
  endgame:=true
  else endgame:=false;
end;
{==========================================================================}
begin
  clrscr;
  writeln ('Here is the original matrix:');
  writeln ('Player1: 0 3 3 3 3 3 3 ');
  writeln ('Player2:   3 3 3 3 3 3 0');
  repeat
    writeln;
    nbrassign(player1,player2);
    write('Player 1, pick a tile from 2 to 7: ');
    readln (tile);
    turn(player1,player2,tile);
    write('Player 2, pick a tile from 1 to 6');
    readln (tile);
    tile:= 8 - tile;
    turn(player2,player1,tile);
    writematrix(player1, player2);
    writeln;
  until endgame(player1) or endgame(player2);
  if endgame(player1) then player2[1] := player2[1] + player1[1];
  if endgame(player2) then player1[1] := player1[1] + player2[1];
end.
