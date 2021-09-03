Program sushi (input,output);
 {Jesse Anderson
  8/26/95
  c1e15}
uses
 crt;
var
 nbrpieces:Integer;
 time:Real;
const
 joghour=240;
 sushicalories=120;
begin
 clrscr;
 Write ('How many pieces of sushi? ');
 Readln (nbrpieces);
 Writeln;
 time:=(nbrpieces*sushicalories)/joghour;
 Writeln ('You will have to jog ',time:4:2,' hours');
end.


