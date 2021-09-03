unit aStrings;

{by Jesse, Matt, and Nick}

{----} interface {----}
uses
	CRT;
type
	StringType = array [0..255] of Char;

procedure StringLength (var AString : StringType;var actualength:byte);
procedure StringWriteLn (var AString : StringType);
procedure StringReadLn (var StringResult : StringType);
PROCEDURE CONCAT (var S1,S2:STRINGTYPE );
procedure copy (astring:stringtype;start,count:integer);
function pos (tofind,s :stringtype):integer;
procedure delete (var s:stringtype; startpos, count:integer);
procedure stringinsert(insertstring:stringtype; var master:stringtype;
                       pos:integer);

{----} implementation {----}
procedure StringLength (var AString : StringType;var actualength:byte);
begin
	actualength := 255;
	while ((actualength > 0) and (AString [actualength] = #0)) do
 		Dec (Actualength);
end;


procedure ClearStringResult(var astring:stringtype);
var
  PosT : Integer;
begin
	for PosT := 0 to 255 do
  	begin
			astring [PosT] := Chr (0);
			   end;
end;

procedure StringWriteLn (var AString : StringType);
var
	StringResult : StringType;
  PosT : Integer;
  byteresult:byte;
begin
	StringLength (AString,byteresult);
	for PosT := 0 to ByteResult do
		begin
    	Write (AString [PosT]);
		end;
	WriteLn;
end;

procedure StringReadLn (var StringResult : StringType);
var
  PosT : Integer;
begin
	PosT := 0;
  clearstringresult(stringresult);
	repeat
		StringResult [PosT] := ReadKey;
		if (not (StringResult [PosT] = Chr (13))) then
			begin
		    Write (StringResult [PosT]);
      	Inc (PosT);
      end;
  until (StringResult [PosT] = Chr (13));
  stringresult[post]:= chr(0);
	WriteLn;
end;


PROCEDURE CONCAT (var S1,S2:STRINGTYPE);
VAR
 LENGTH,NBR:INTEGER;
 s2length,byteresult:byte;
BEGIN
nbr:=0;
StringLength (S1,byteresult);
stringlength (s2,s2length);
  WHILE  (byteresult+1+nbr) <255 DO
   begin
    S1[ByteResult+1+nbr]:=S2[NBr];
    nbr:=nbr+1;
   end;
END;

procedure copy (astring:stringtype;start,count:integer);
var
 nbr:integer;
begin
 for nbr:= 1 to count do
   astring[start+nbr]:=astring[start+count+nbr];
end;
{-----------------------------------------------------------------------}
function pos (tofind,s :stringtype):integer;
var
 run,nbr,findnbr:integer;
 match:Boolean;
 byteresult:byte;
 AByteResult :Byte;
begin
  run:=0;
  match:=true;
  StringLength (S,byteresult);
  AByteResult := ByteResult;
  for nbr:=1 to AByteResult do
   begin
    findnbr:=0;
    StringLength (ToFind,byteresult);
    while match and (run<ByteResult) do
     begin
      run:=run+1;
      findnbr:=findnbr+1;
      if s[nbr+run]=tofind[findnbr] then
        match:=true
      else match:=false;
     end;
   end;
  if match then pos:=(nbr-run);
end;
{-------------------------------------------------------------------------}
procedure delete (var s:stringtype; startpos, count:integer);
var
 byteresult:byte;
 nbr,nbr2:integer;
begin
	StringLength (S,byteresult);
 s[startpos]:=s[startpos+count];
 for nbr := 1 to count do
  s[startpos+nbr]:=s[startpos+count+nbr];
 if ByteResult > startpos+nbr
  then for nbr2:= (startpos + count) to ByteResult do
   s[nbr2] := s[ByteResult+1]
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
procedure stringinsert(insertstring:stringtype; var master:stringtype;
                       pos:integer);
var
 count:integer;
 byteresult,AByteResult : Byte;
begin
StringLength (InsertString,byteresult);
AByteResult := ByteResult;
StringLength (Master,byteresult);
for count:= 0 to aByteResult do
 begin
{   master[ByteResult+1]:=master[pos+count+AByteResult];
   master[pos+count+AByteResult]:=master[pos+count];
   master[pos+count]:=insertstring[count];}
  master[pos+count]:=insertstring[pos+count];
  end;
end;

end.