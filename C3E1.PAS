Program quicky (Input, Output);
 {Jesse Anderson
  September 6,1995
  c3e1}
uses
 crt, printer;
const
 maxwgt=60;
 maxvol=4;
var
 weight,
 length,
 width,
 height:Integer;
begin
 clrscr;
 Write ('Enter weight of package in pounds: ');
 Readln (weight);
 Write ('Enter length of package in feet: ');
 Readln (length);
 Write ('Enter width of package in feet: ');
 Readln (width);
 Write ('Enter height of package in feet: ');
 Readln (height);
 if (weight > 60) and ((length * width * height) > 4)
  then Writeln ('Package is too large and too heavy')
  else
   begin
    if weight > 60
    then Writeln ('Package is too heavy')
    else
     begin
      if (length * width * height) > 4
      then Writeln ('Package is too large');
     end;
   end
end.