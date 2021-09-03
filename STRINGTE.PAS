procedure copy (astring:stringtype[];start,count:integer);
var
 nbr:integer;
begin
 for nbr:= 1 to count do
   astring[start+nbr]:=astring[start+count+nbr];
{-----------------------------------------------------------------------}
function pos (tofind,s :stringtype):integer;
var
 run,nbr,findnbr:integer;
 match:Boolean;
begin
  run:=0;
  match:=true;
  for nbr:=1 to length(s) do
   begin
    findnbr:0;
    while match and (run<length(tofind)) do
     begin
      run:=run+1;
      findnbr:=findnbr+1;
      if s[nbr+run]=tofind[findnbr] then
        match:=true
      else match:=false;
     end;
   end;
  if match then pos:=(nbr-run);
end
{-------------------------------------------------------------------------}
procedure delete (var s:stringtype; startpos, count:integer);
var
 nbr,nbr2:integer;
begin
 s[startpos]:=s[startpos+count];
 for nbr := 1 to count do
  s[startpos+nbr]:=s[startpos+count+nbr];
 if length(s) > startpos+nbr
  then for nbr2:= (startpos + count) to length(s) do
   s[nbr2] := s[stringlength(s)+1]
end;
{--------------------------------------------------------------------------}
{procedure stringwrite(var s:stringtype);
var
 count:integer;
begin
 for count := 0 to stringlength(s) do
  write s[count];
end;
{--------------------------------------------------------------------------}
procedure stringinsert(insertstring:stringtype; var master:stringtype
                       pos:integer);
var
 lcv,count:integer

for count:= 1 to stringlength(insertstring) do
 begin
   master[stringlength(master)+1]:=master[pos+count+stringlength(insertstring)];
   master[pos+count+stringlength(insertstring)]:=master[pos+count];
   master[pos+count]:=insertstring[count];
 end;