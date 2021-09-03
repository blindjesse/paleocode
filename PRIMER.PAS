program primegen;
uses
 crt,binmath;
var
 fail:boolean;
 tester:probintype;
 nbr:integer;

{-----------------------------------------------------------------------}
procedure getrealrand(var realrand:probintype);

{pre: none
 post: returns a 384 digit random number from the random file
       in a probintype padded with 384 digits before}
var
 randchar:byte;
 writevar,lcv,nbr:integer;
 byteo:bytemap;
 randfile:file of byte;
begin
 writevar:=0;
 lcv:=0;
 assign(randfile,'c:\turbo\rand\comp-rc4.txt');
 reset(randfile);
 init(realrand);
 for nbr:= 1 to 48 do
  begin
   read(randfile,randchar);
   bitgetter(randchar,byteo);
   for lcv := 1 to 8 do
    realrand[4*writevar+lcv+384]:=byteo[lcv-1];
   inc(writevar,2);
  end;
 realrand[385]:=1; {make sure the number is of the required length}
 realrand[768]:=1; {make sure the number is odd}
end;
{-----------------------------------------------------------------------}
procedure getpseudorand(var pseud:probintype);
{pre: none
 post: returns a 50 digit random number from the pascal generator}
var
 nbr:integer;
begin
 for nbr:= (maxprd-50) to maxprd do
  pseud[nbr]:=random(10);
end;
{-----------------------------------------------------------------------}
procedure testsmall(num:probintype; var fail:boolean);
{pre: receives a number from getrealrand
 post: tests the number by dividing it by 3,5,7,9,11,13
 returns false if the number divides evenly into any of these}
var
 divis:probintype;
begin
 fail:=false;
 init(divis);
 nbr:=3;
 modcheck(num,divis,fail);
 while (nbr <= 9) and (not fail) do
  begin
   write('. ');
   nbr:=nbr+2;
   divis[maxprd]:=nbr;
   modcheck(num,divis,fail);
  end;
end;
{-----------------------------------------------------------------------}
procedure testlarge(num,pseudtest:probintype; var fail:boolean);
{pre: receives a number that has passed the testsmall testing
 post: tests the number against a random 50 digit number}
begin
 fail:=TRUE;
 modcheck(num,pseudtest,fail);
end;
{-----------------------------------------------------------------------}
procedure feedlarge;
var
 nbr,length,halflength:integer;
begin
 length:=random(384);
 halflength:=384-length;
 for nbr:= 1 to length do
  rndtest[halflength+nbr]:=randarray[nbr];
end;
{-----------------------------------------------------------------------}
{-----------------------------------------------------------------------}
begin
 {getrealrand(tester);    }
 clrscr;
 randomize;
 getrealrand(tester);
 testsmall(tester,fail);
 if fail then writeln('fail');
end.
