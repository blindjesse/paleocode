program SHA;
uses
 crt;
const
 size=32;
type
 pow = array[1..8] of word;
 bytemap = array[0..7] of byte;       {holds the mapping of a single byte}
 vrtype = array [1..size] of byte;    {holds constants used in algorithm}
 word32 = array [1..4] of byte;       {holds a double word!}
 mesgtype = array[1..16] of word32;   {holds a message to hash}
 hashtype = array[1..160] of byte;    {holds the hashed message}
 charhash = array[1..20] of byte;     {holds the characters of the hash}
const
 power:pow=(1,2,4,16,32,64,128,256);
 aa:vrtype=(0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1);
 bb:vrtype=(1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1);
 cc:vrtype=(1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0);
 dd:vrtype=(0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0);
 ee:vrtype=(1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0);
 kwen:vrtype=(0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1);
 kfor:vrtype=(0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1);
 ksix:vrtype=(1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0);
 kate:vrtype=(1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,0,0,1);

 msg:mesgtype=((1,2,3,4),(5,6,7,8),(2,0,1,2),(3,4,5,6),(7,8,9,0),(1,2,3,4),
                (5,6,7,8),(9,0,1,2),(3,5,7,6),(71,8,29,0),(1,2,3,4),(5,6,7,8),
                (9,1,0,2),(2,4,5,2),(0,0,0,0),(0,0,0,56));
var
 nbr:integer;
 wt:word32;
 charred:charhash;
 kvar,ret,temp,a,b,c,d,e:vrtype;
 hash:hashtype;
{--------------------------------------------------------------------}
procedure add(var aa,bb,cc,dd,ee:vrtype; var a,b,c,d,e:vrtype);
var
 count,int,nbr,lcv:integer;
 temp2,temp:vrtype;
begin
 for count := 1 to 5 do
  begin
   case count of
   1:begin
      temp2:=aa;
      temp:=a;
     end;
   2:begin
      temp2:=bb;
      temp:=b;
     end;
   3:begin
      temp2:=cc;
      temp:=c;
     end;
   4:begin
      temp2:=dd;
      temp:=d;
     end;
   5:begin
      temp2:=ee;
      temp:=e;
     end;
   end; {case}
   for nbr:= size downto 1 do
    begin
     temp2[nbr]:=temp[nbr]+temp2[nbr];
    end;
   for nbr:= size downto 1 do
    while temp2[nbr] >= 2 do
     begin
      inc(temp2[nbr-1]);
      temp2[nbr]:=temp2[nbr]-2;
     end;
   case count of
    1:aa:=temp2;
    2:bb:=temp2;
    3:cc:=temp2;
    4:dd:=temp2;
    5:ee:=temp2;
   end;
  end;
end;
{--------------------------------------------------------------------}
procedure getmessage(var msg:mesgtype);
{pre: msg.txt is a message to be hashed
 post: returns an array holding the message}
const
 blank:word32=(0,0,0,0);
 length:word32=(0,0,0,56);
var
 nbr,lcv:integer;
 mseg:file of char;
 charact:char;
 temp:byte;
begin
 assign(mseg,'c:\turbo\proj\euclid.pas');
 reset(mseg);
 for nbr:= 1 to 14 do
  for lcv:=1 to 4 do
   begin
    read(mseg,charact);
    temp:=ord(charact);
    msg[nbr][lcv]:=temp;
  end;
end;
{--------------------------------------------------------------------}
procedure bitgetter(bitter:byte; var byte:bytemap);
{pre: receives an integer
 post: returns the integer in an array}
var
nbr,temp:integer;
begin
 for nbr:= 0 to 7 do
  byte[nbr]:=0;
 for nbr:=0 to 7 do
  begin
   temp:=(bitter and power[nbr]);
   if temp = power[nbr] then
    byte[nbr]:=1;
  end;
end;
{--------------------------------------------------------------------------}
procedure shiftleft ( var toshift:vrtype;num:integer);
{pre: gets a number
 post: shifts the number left num places}
var
 nbr,lcv:integer;
begin
 for nbr:=1 to num do
  begin
   for lcv:=1 to size do
    if lcv+1 > size then
     toshift[lcv]:= 0
     else
      toshift[lcv]:=toshift[lcv+1];
  end;
end;
{--------------------------------------------------------------------------}
procedure onetwenty(x,y,z:vrtype; var back:vrtype);
{function for operations 1-20}
var
 nbr:integer;
begin
 for nbr:= 1 to size do
   back[nbr]:= (x[nbr] and y[nbr]) or (not x[nbr] and z[nbr]);
end;
{--------------------------------------------------------------------------}
procedure twoforsixate(x,y,z:vrtype; var back:vrtype);
{function for operations 20..40 and 60..80}
var
 nbr:integer;
begin
 for nbr:= 1 to size do
  back[nbr]:= x[nbr] xor y[nbr] xor z[nbr];
end;
{--------------------------------------------------------------------------}
procedure fonesixty(x,y,z:vrtype; var back:vrtype);
{function for operations 40-60}
var
 nbr:integer;
begin
 for nbr:= 1 to size do
  back[nbr]:= (x[nbr] and y[nbr]) or (x[nbr] and z[nbr]) or (y[nbr] and z[nbr]);
end;
{--------------------------------------------------------------------------}
procedure six2nine (var wt:word32; nbr:integer);
var
 lcv:integer;
begin
 for lcv:=1 to size do
   wt[nbr]:=(msg[lcv-3][nbr]) xor (msg[lcv-8][nbr]) xor (msg[lcv-16][nbr]);
end;
{--------------------------------------------------------------------------}
procedure makenorm (wt:word32; var wtnorm:vrtype);
{maps the double word into an array}
var
 nbr,lcv:integer;
 temp:bytemap;
begin
 for nbr:=1 to 4 do
  begin
   bitgetter(wt[nbr],temp);
   for lcv:=1 to 8 do
    begin
     wtnorm[lcv*nbr]:=temp[lcv];
    end;
  end;
end;
{--------------------------------------------------------------------------}
procedure normalize (var wtnorm:vrtype);
 {pre: receives a string with values over ten in any spot
  post: changes the values of ten by incrementing the next spot
  for each ten}
 {fix these using div and mod....if its greater than two than div it by two
  and put that where+-1 and mod and put that where
}var
 nbr:integer;
begin
 for nbr:= 32 downto 1 do
  while wtnorm[nbr] >= 2 do
   begin
    inc(wtnorm[nbr-1]);
    wtnorm[nbr]:=wtnorm[nbr]-2;
   end;
end;
{--------------------------------------------------------------------------}
procedure maketemp(a,ret,e,kt:vrtype; wt:word32; var temp:vrtype);
{function to make a temporary variable used in the hash}
var
 nbr:integer;
 wtnorm:vrtype;
begin
 makenorm(wt,wtnorm);
 for nbr:=1 to 32 do
  temp[nbr]:=a[nbr]+ret[nbr]+e[nbr]+kt[nbr]+wtnorm[nbr];
 normalize(temp);
end;
{--------------------------------------------------------------------------}
procedure concat(a,b,c,d,e:vrtype; var hash:hashtype);
{concatenates the hash into one array}
var
 lcv,nbr:integer;
begin
 for nbr:= 1 to 160 do
  case nbr of
   1..32:   hash[nbr]:=a[nbr];
   33..64:  hash[nbr]:=b[nbr-32];
   65..96:  hash[nbr]:=c[nbr-64];
   97..128: hash[nbr]:=d[nbr-96];
   128..160:hash[nbr]:=e[nbr-127];
  end; {case}
end;
{--------------------------------------------------------------------------}
procedure hash2char(hash:hashtype; var charred:charhash);
{converts the finished hash into an array of char}
var
 nbr,lcv:integer;
 byteo:byte;
begin
 for nbr:=1 to 20 do
  begin
   for lcv:=1 to 8 do
    if hash[nbr*lcv] = 1 then
     byteo:=byteo+power[lcv-1];
    charred[nbr]:=byteo;
  end;
end;
{--------------------------------------------------------------------}
procedure writehash(charred:charhash);
{writes the hash to a file}
var
 nbr:integer;
 hash:file of byte;
begin
 assign(hash,'c:\turbo\hashed.boy');
 rewrite(hash);
 for nbr:= 1 to 20 do
  write(hash,charred[nbr]);
end;
{--------------------------------------------------------------------------}

begin
 a:=aa;
 b:=bb;
 c:=cc;
 d:=dd;
 e:=ee;
 getmessage(msg);
for nbr:=1 to 80 do
 begin;
  case nbr of
   1..20:begin
          onetwenty(b,c,d,ret);
          kvar:=kwen;
         end;
   21..40:begin
           twoforsixate(b,c,d,ret);
           kvar:=kfor;
          end;
   41..60:begin
           fonesixty(b,c,d,ret);
           kvar:=ksix;
          end;
   61..80:begin
           twoforsixate(b,c,d,ret);
           kvar:=kate;
          end;
   end; {case}
   case nbr-1 of
    0..15:wt:=msg[nbr];
    16..79:six2nine(wt,nbr-1);
    end;
  shiftleft(a,5);
  maketemp(a,ret,e,kvar,wt,temp);
  e:=d;
  shiftleft(b,30);
  c:=b;
  b:=a;
  a:=temp;
 end;
  add(aa,bb,cc,dd,ee,a,b,c,d,e);
  concat(aa,bb,cc,dd,ee,hash);
  hash2char(hash,charred);
  writehash(charred);
end.