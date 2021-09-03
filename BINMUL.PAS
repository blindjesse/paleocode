program binult;
type
 mulbintype = array [1..2] of integer;
 probintype = array [1..4] of integer;
 anstype = array [1..4] of integer;
var
 lcv,nbr:integer;
 mul1,mul2:mulbintype;
 prod:probintype;
 ans:anstype;
 spc,int:integer;
begin
 for nbr:=1 to 2 do
  begin
   readln(int);
   mul1[nbr]:=int;
  end;
  mul2:=mul1;
 for lcv:= 2 downto 1 do
  for nbr:= 2 downto 1 do
   begin
    spc:=nbr+2-lcv;
    prod[spc]:=prod[spc] + (mul1[nbr] and mul2[lcv]);
   end;
 for nbr:=1 to 4 do
  begin
   write(prod[nbr],' ');
  end;
 writeln;
 for nbr:= 4 downto 1 do
  case prod[nbr] of
    2: begin
       inc(prod[nbr-1]);
       prod[nbr]:=prod[nbr]-2;
       end;
   end;
 for nbr:=1 to 4 do
  begin
   write(prod[nbr],' ');
  end;
 readln;
end.

