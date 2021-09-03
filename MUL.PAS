program bigmult;
uses
 crt;
const
 maxmultsize=10;
 maxprodsize=2*maxmultsize;
type
 mult = array [1..maxmultsize] of byte;
 product = array [1..maxprodsize] of integer;
var
 mult1,mult2:mult;
 temp,prod:product;
 nbr,lcv:integer;
 int:byte;
begin
 for nbr:=1 to 10 do
  begin
   readln(int);
   mult1[nbr]:=int;
   mult2[nbr]:=mult1[nbr];
  end;
 for nbr:= maxmultsize downto 1 do
  for lcv:= maxmultsize downto 1 do
   prod[nbr+maxmultsize]:=mult1[lcv]*mult2[nbr]+prod[nbr+maxmultsize];
{ for nbr:= 1 to 20 do
  write(prod[nbr],' ');
 }
  for lcv := maxprodsize downto 1 do
   begin
    prod[lcv-1]:=prod[lcv-1] + prod[lcv] div 10;
{    write(prod[lcv-1],' ');
    writeln(prod[lcv]);
 }   prod[lcv]:=prod[lcv] mod 10;
  {  write(prod[lcv-1],' ');
    writeln(prod[lcv]);
    readln;
   }end;
 for nbr:= 1 to 20 do
  write(prod[nbr],' ');
 readln;
end.