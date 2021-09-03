Program sumof (Input,Output);
 {Jesse Anderson
  September 8,1995
  c3e5}
uses
 crt,printer;
var
 sum,
 nbr,
 start,
 endnbr:Integer;
begin
 Write ('Enter starting number: ');
 Readln (start);
 Write ('Enter ending number: ');
 Readln (endnbr);
 nbr:=start;
 sum:=0;
 for nbr:= start to endnbr do
  begin
   nbr:=nbr + 1;
   sum:= sum + nbr
  end
 Writeln ('The sum of integers from ',(start), ' to ',(endnbr),' is ',(sum));
end.

