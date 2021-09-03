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
 Writeln (lst,'How many slices of pizza? ');
 Readln (nbrslices);
 Writeln (lst);
 time:=(nbrslices*pizzacalories)/joghour;
 Writeln (lst,'You will have to jog ',time:4:2,' hours');
 Writeln(lst);
end.


