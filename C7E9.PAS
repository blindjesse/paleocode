program tictactoe (input,output);
uses
 crt;
type
 boardtype = array [1..3,1..3] of char;
var
 board:boardtype;
{-------------------------------------------------------------------------}
procedure drawboard(board:boardtype);
var
 x,y,nbr,lnbr:integer;
begin
 x:=25;
 y:=6;
 gotoxy(x,y);
 writeln ('      ',#179,'   ',#179);
 inc(y);
 gotoxy(x,y);
 writeln ('   ',#196,#196,#196,#197,#196,#196,#196,#197,#196,#196,#196);
 inc(y);
 gotoxy(x,y);
 writeln ('      ',#179,'   ',#179);
 inc(y);
 gotoxy(x,y);
 writeln ('   ',#196,#196,#196,#197,#196,#196,#196,#197,#196,#196,#196);
 inc(y);
 gotoxy(x,y);
 writeln ('      ',#179,'   ',#179);
 inc(y);
 x:=25;
 y:=6;
 for lnbr:= 1 to 3 do
  begin
   gotoxy (x,y);
   for nbr:=1 to 3 do
    begin
     write (board[nbr,lnbr]);
     x:=x+2;
    end;
   inc(y);
  end;
end;
{-------------------------------------------------------------------------}
procedure playgame(var board:boardtype);
var
 row,column:integer;
begin
 writeln ('Your turn, buddy boy!');
 write ('Enter a column (from 1-3): ');
 readln (column);
 write ('Enter a row (from 1-3): ');
 readln (row);
 board[column,row]:='X';
end;
{-------------------------------------------------------------------------}
begin
 clrscr;
 writeln ('     T I C ':35);
 writeln ('      TAC':33);
 writeln ('     T O E':34);
 writeln ('          The object of this game is to get three in a row!');
 writeln ('                   X is you12345678901wxlet''s go!');
 drawboard(board);
 playgame (board);
 drawboard(board);

 readln;
end.