program euclid;
var
 u1,u2:integer;
{-----------------------------------------------------------------------}
procedure update (var u,v:integer; q:integer);
var
 t:integer;
begin
 t:=u-v*q;
 u:=v;
 v:=t;
end;
{-----------------------------------------------------------------------}
function alpo (u,v:integer; var u1_out, u2_out:integer):integer;
var
 u1,u3,v1,v3,q:integer;
begin
 u1:=1;
 u3:=u;
 v1:=0;
 v3:=v;
 while v3>0 do
  begin
    q:=u3 div v3;
    update(u1,v1,q);
    update(u3,v3,q);
  end;
 u1_out:=u1;
 u2_out:=(u3-u1*u) div v;
 alpo:=u3;
end;
{-----------------------------------------------------------------------}
begin
 writeln(alpo(79,3220,u1,u2));
 writeln (u1);
 writeln (u2);
 readln
end.