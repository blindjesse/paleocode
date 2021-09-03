program coins (input,output);
 {Jesse Anderson
  8/26/95
  c1e15}
uses
 crt;
var
 change,
 qnbr,
 dnbr,
 nnbr,
 pnbr:Integer;
const
 quarter=25;
 dime=10;
 nickel=5;
 penny=1;
begin;
 clrscr;
 Write ('Enter the amount of change in cents: ');
 Readln (change);
 Writeln;
 qnbr:=change div quarter;
 dnbr:=change mod quarter div dime;
 nnbr:=change mod (dnbr * dime) div nickel;
 pnbr:=change mod (nnbr * nickel) div penny;
 Writeln ('Quarters: ', qnbr);
 Writeln;
 Writeln ('Dimes: ', dnbr);
 Writeln;
 Writeln ('Nickels: ',nnbr);
 Writeln;
 Writeln ('Pennies: ', pnbr);
end.


