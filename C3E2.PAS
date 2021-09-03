Program cluck (Input, Output);
 {Jesse Anderson
  September 7,1995
  c3e2}
uses
 crt,printer;
const
 zerofor=0.50;
 foursix=0.45;
 sixeleven=0.40;
 elevenup=0.35;
var
 dozen,
 singles,
 eggs:Integer;
 cost:real;
begin
 clrscr;
 Write ('Enter number of eggs: ');
 Readln (eggs);
 Writeln;
 dozen:=eggs div 12;
 singles:=eggs mod 12;
 if singles = 1
  then Writeln ('Purchase: ',(dozen),' dozen and ',(singles),' extra egg')
  else Writeln ('Purchase: ',(dozen),' dozen and ',(singles),' extra eggs');
 if dozen > 11
  then
   begin
    cost:=(0.35* dozen) + (singles * (0.35/12));
    Writeln ('Your bill comes to $', cost:5:2);
   end;
 if (dozen >=6) and (dozen<11)
  then
   begin
    cost:=(0.4 * dozen) + (singles * (0.4/12));
    Writeln ('Your bill comes to $', cost:5:2);
   end;
if (dozen >=4) and (dozen < 6)
  then
   begin
    cost:=(0.45 * dozen) + (singles * (0.45/12));
    Writeln ('Your bill comes to $', cost:5:2);
   end;
if (dozen >=0) and (dozen < 4)
  then
   begin
    cost:=(0.5 * dozen) + (singles * (0.5/12));
    Writeln ('Your bill comes to $', cost:5:2);
   end;
end.


