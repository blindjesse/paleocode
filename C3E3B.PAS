Program pop2 (Input,Output);
 {Jesse Anderson
  September 12, 1995
  c3e3b}
Uses
 crt, printer;
var
 hours,
 extra:Integer;
 taxes, wages, total, extrattl:Real;
 exempt:Char;
begin
 clrscr;
 Write ('Enter hours worked: ');
 Write (lst,'Enter hours worked: ');
 Readln (hours);
 Writeln (lst,hours);
 Writeln (lst);
 Write ('Enter hourly rate:$ ');
 Write (lst,'Enter hourly rate:$ ');
 Readln (wages);
 Writeln (lst,wages:6:2);
 Writeln (lst);
 Write ('Exempt (Y/N)? ');
 Write (lst,'Exempt (Y/N)? ');
 Readln (exempt);
 Writeln (lst,exempt);
 Writeln (lst);
 If hours > 40 then
  begin
   extra:=hours-40;
   extrattl:=(extra)*(1.5*wages)
  end;
 total:=extrattl + ((hours - extra) * wages);
 Writeln ('Wages earned = $', total:7:2);
 Writeln (lst,'Wages earned = $', total:7:2);
 Writeln (lst);
 If Upcase (exempt) = 'Y' then
  begin
   Writeln ('NO TAXES DEDUCTED');
   Writeln (lst,'NO TAXES DEDUCTED');
   Writeln (lst);
  end
 else
  begin
   taxes:=0.18 * total;
   Writeln ('Taxes deducted = $', taxes:6:2);
   Writeln (lst,'Taxes deducted = $', taxes:6:2);
   Writeln (lst);
   total:=total-taxes;
   Writeln ('Wages after taxes = $', total:6:2);
   Writeln (lst,'Wages after taxes = $', total:6:2);
   Writeln (lst);
  end;
end.

