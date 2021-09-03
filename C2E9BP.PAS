Program sushi (input,output);
 {Jesse Anderson
  8/26/95
  c1e15}
uses
 crt,printer;
var
 nbrpieces:Integer;
 time:Real;
const
 joghour=240;
 sushicalories=120;
begin
 clrscr;
 Writeln (lst,'How many pieces of sushi? ');
 Readln (nbrpieces);
 Writeln (lst);
 time:=(nbrpieces*sushicalories)/joghour;
 Writeln (lst,'You will have to jog ',time:4:2,' hours');
 Writeln (lst);
end.


