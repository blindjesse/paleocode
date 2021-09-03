Program pop (Input,Output);
 {Jesse Anderson
  September 11, 1995
  c3e3a}
Uses
 crt, printer;
var
 hours,
 extra:Integer;
 wages,total,extrattl:Real;
begin
 clrscr;
 Write ('Enter hours worked: ');
 Write (lst,'Enter hours worked:  ');
 Readln (hours);
 Writeln (lst,hours);
 Writeln (lst);
 Write ('Enter hourly rate: ');
 Write (lst,'Enter hourly rate:$ ');
 Readln (wages);
 Writeln (lst,wages:5:2);
 Writeln (lst);
 If hours > 40 then
  begin
   extra:=hours-40;
   extrattl:=(extra)*(1.5*wages)
  end;
 total:=extrattl + ((hours - extra) * wages);
 Writeln ('Wages earned = $',total:7:2);
 Writeln (lst,'Wages earned = $',total:7:2);
 Writeln (lst);
end.

