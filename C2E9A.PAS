Program pizza (input,output);
 {Jesse Anderson
  8/26/95
  c2e9a}
uses
 crt, printer;
var
 nbrslices:Integer;
 time:Real;
const
 joghour=240;
 pizzacalories=355;
begin
 clrscr;
 Write ('How many slices of pizza? ');
 Readln (nbrslices);
 Writeln;
 time:=(nbrslices*pizzacalories)/joghour;
 Writeln ('You will have to jog ',time:4:2,' hours');
end.


