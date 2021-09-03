program randbreak (input,output,diskfile);
var
 diskfile:text;
 nbr,seed:integer;
begin
 assign (diskfile, 'c:\random.txt');
 rewrite(diskfile);
 for seed:= 0 to maxint do
   begin
    randseed:=seed;
    for nbr:= 1 to 100 do
f     write(diskfile,random:0:5);
   end;
end.