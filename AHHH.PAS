unit Strings;

{----} interface {----}
uses
	CRT;
type
	StringType = array [0..255] of Char;
var
	StringResult : StringType;
  ByteResult : Byte;
  Pos : Integer;

procedure StringLength (var AString : StringType);
procedure ClearStringResult;
procedure StringWriteLn (var AString : StringType);
procedure StringReadLn;

{----} implementation {----}

procedure StringLength (var AString : StringType);
begin
	ByteResult := 255;
	while ((not (ByteResult < 0)) and (AString [ByteResult] = Chr (0))) do
  	begin
			Dec (ByteResult);
    end;
end;

procedure ClearStringResult;
begin
	for Pos := 0 to 255 do
  	begin
			StringResult [Pos] := Chr (0);
    end;
end;

procedure StringWriteLn (var AString : StringType);
begin
	StringLength (AString);
	for Pos := 0 to ByteResult do
		begin
    	Write (AString [Pos]);
		end;
	Write (Chr (13));
end;

procedure StringReadLn;
begin
	Pos := 0;
  ClearStringResult;
	repeat
		StringResult [Pos] := ReadKey;
		if (not (StringResult [Pos] = Chr (13))) then
			begin
		    Write (StringResult [Pos]);
      	Inc (Pos);
      end;
  until (StringResult [Pos] = Chr (13));
{  Write (Chr (13));}
	WriteLn;
end;

begin
end.