program coins (input,output);
 {Jesse Anderson
  8/26/95
  c1e15}
uses
 crt,printer;
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
 Writeln (lst,'Enter the amount of change in cents: ');
 Readln (change);
 Writeln (lst);
 qnbr:=change div quarter;
 dnbr:=change mod quarter div dime;
 nnbr:=change mod (dnbr * dime) div nickel;
 pnbr:=change mod (nnbr * nickel) div penny;
 Writeln (lst,'Quarters: ', qnbr);
 Writeln (lst);
 Writeln (lst,'Dimes: ', dnbr);
 Writeln (lst);
 Writeln (lst,'Nickels: ',nnbr);
 Writeln (lst);
 Writeln (lst,'Pennies: ', pnbr);
 Writeln (lst);
end.


