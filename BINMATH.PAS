unit binmath;
interface
const
 maxprd=768;  {store the maximum size of the numbers used}

type
 probintype = array [1..maxprd] of integer; {holds numbers}
 bytemap = array [0..7] of byte;

function power(var raiseto:integer): word;
procedure bitgetter(var bitter:byte; var byte:bytemap);
procedure init (var arry:probintype);
procedure normalize (var num:probintype);
procedure binadd (var add1,add2,total:probintype);
procedure bininc (var num:probintype; incby:integer);
procedure binsub(var num,sub,diff:probintype; var neg:boolean);
procedure binmult(var mul1,mul2,prod:probintype; var tobig:boolean);
procedure bindiv (var num,divis,ans:probintype);
procedure binmod(var num,moder,ans:probintype);
procedure modcheck(var num,divis:probintype; var even:boolean);

implementation
{--------------------------------------------------------------------}
function power(var raiseto:integer): word;
{raises two to a power}
{actually all it does is get a number.  this should be a constant array but
 some of us do things the easy way}
var
 lcv,temp:integer;
begin
 case raiseto of
  0:power:=1;
  1:power:=2;
  2:power:=4;
  3:power:=16;
  4:power:=32;
  5:power:=64;
  6:power:=128;
  7:power:=256;
 end; {case}
end;
{---------------------------------------------------------------------------}
procedure bitgetter(var bitter:byte; var byte:bytemap);
{pre: receives an integer
 post: returns the bitmapping of that integer in an array}
var
nbr,temp:integer;
begin
 for nbr:= 0 to 7 do
  byte[nbr]:=0;
 for nbr:=0 to 7 do
  begin
   temp:=(bitter and power(nbr));
   if temp = power(nbr) then
    byte[nbr]:=1;
  end;
end;
{---------------------------------------------------------------------------}
procedure init (var arry:probintype);
 {pre: receives a "var" variable
  post: turns all spaces in arry to 0}
var
 nbr:integer;
begin
 for nbr:= 1 to maxprd do
   arry[nbr]:=0;
end;
{---------------------------------------------------------------------------}
procedure normalize (var num:probintype);
 {pre: receives a string with values over ten in any spot
  post: changes the values of two by incrementing the next spot
  for each two....with 002 we would get 010}
var
 nbr:integer;
begin
 for nbr:= maxprd downto 1 do
  while num[nbr] >= 2 do
   begin
    inc(num[nbr-1]);
    num[nbr]:=num[nbr]-2;
   end;
end;
{---------------------------------------------------------------------------}
procedure binadd (var add1,add2,total:probintype);
 {pre: receives two numbers such that their total is not greater
       than the available size
  post: returns the sum of the two numbers}
var
 int,nbr,lcv:integer;
begin
 for nbr:= maxprd downto 1 do
   total[nbr]:=add1[nbr] + add2[nbr];
 normalize(total);
end;
{---------------------------------------------------------------------------}
procedure bininc (var num:probintype; incby:integer);
 {pre: receives a number not at maximum holding
  post: adds one to the number}
var
 nbr:integer;
begin
 num[maxprd]:=num[maxprd]+incby;
 normalize(num);
end;
{---------------------------------------------------------------------------}
procedure binsub(var num,sub,diff:probintype; var neg:boolean);
 { pre: receives two numbers
   post: returns the difference is the first number is greater than the
         second; else it returns true in neg}
var
 int,nbr:integer;
begin
 neg:=FALSE;
 for nbr:= maxprd downto 1 do
  begin
   if (sub[nbr]>num[nbr]) and (nbr>1)  then
    begin
     dec(num[nbr-1]);
     inc(num[nbr],2);
    end
    else if (sub[1]>num[1]) then
     neg:=TRUE;
   diff[nbr]:=num[nbr]-sub[nbr];
   end;
end;
{---------------------------------------------------------------------------}
procedure binmult(var mul1,mul2,prod:probintype; var tobig:boolean);
 {pre: receives two numbers
  post: multiplies the two numbers}
var
 spc,lcv,nbr:integer;
begin
 tobig:=false;
 for lcv:= maxprd downto 1 do
  for nbr:= maxprd downto 1 do
   begin
    spc:=nbr-(maxprd-lcv);
    if (spc<=0) and (mul1[nbr]=1) and (mul2[lcv]=1) then
     tobig:=true
     else
      if spc<=maxprd then
       prod[spc]:=prod[spc] + (mul1[nbr] and mul2[lcv]);
   end;
 for nbr:= maxprd downto 1 do
  while prod[nbr] >= 2 do
   begin
    inc(prod[nbr-1]);
    prod[nbr]:=prod[nbr]-2;
   end;
end;
{---------------------------------------------------------------------------}
procedure bindiv (var num,divis,ans:probintype);
 {pre: receives two numbers, such that the second is not
       greater than the first
  post: returns the number of times the second goes into the first}
var
 neg:boolean;
 total,tempnum:probintype;
begin
 init(ans);
 neg:=FALSE;
 repeat
    binsub(num,divis,tempnum,neg);
   if not neg then
    begin
     num:=tempnum;
     bininc(ans,1);
    end
 until neg;
 normalize(ans);
end;
{--------------------------------------------------------------------------}
procedure binmod(var num,moder:probintype; var ans:probintype);
 {pre: receives two numbers, such that the second is not
       greater than the first
  post: returns the remainder of the division of the numbers}
var
 nbr:integer;
 temp0,temp1:probintype;
 neg,tobig:boolean;
begin
 init(temp0);
 init(temp1);
 bindiv(num,moder,temp0);
 binmult(temp0,moder,temp1,tobig);
 binsub(num,temp1,ans,neg);
 normalize(ans);
end;
{---------------------------------------------------------------------------}
procedure modcheck(var num,divis:probintype; var even:boolean);
{checks to see whether a number goes evenly into another}
var
 nbr,checkint:integer;
 ans:probintype;
begin
 bindiv(num,divis,ans);
 checkint:=0;
 if (nbr <= checkint) and even then
  begin
   inc(checkint);
   checkint:=checkint+ans[nbr];
   if checkint = 0 then
    even:=TRUE else
    even:=FALSE;
  end;
end;
{---------------------------------------------------------------------------}
begin
end.