program RSA;
uses
 binmath; {or some variation thereof that werks}
{-------------------------------------------------------------------}
procedure composite(var primea,primeb,prime:probintype);
{pre: none
 post: opens the file containing the random primes and multiplies them}

{-------------------------------------------------------------------}
procedure keyunite (primea,primeb:probintype; var e:probintype);
{pre: receives the same two primes used in composite
 post: returns the public key e, which = (primea-1)(primeb-1)}
begin
 bininc(primea,-1);
 bininc(primeb,-1);
 binmul(primea,primeb,e);
end;
{-------------------------------------------------------------------}
procedure
{-------------------------------------------------------------------}
{-------------------------------------------------------------------}
{-------------------------------------------------------------------}
{-------------------------------------------------------------------}
{-------------------------------------------------------------------}
