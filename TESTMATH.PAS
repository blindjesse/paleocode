uses
 binmath,crt;
var
 add1,add2,total:probintype;
 neg:boolean;
 nbr:integer;
begin
 for nbr:=1 to maxprd do
  begin
   add1[nbr]:=ord(readkey)-48;
   write(add1[nbr],' ');
  end;
 writeln;
 for nbr:=1 to maxprd do
  begin
   add2[nbr]:=ord(readkey)-48;
   write(add2[nbr],' ');
  end;
 writeln;
 binmult(add1,add2,total);
 if not neg then
  for nbr:= 1 to maxprd do
   write(total[nbr],' ')
  else
   writeln('neg');
 readln;
end.