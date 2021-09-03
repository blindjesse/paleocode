{ Jesse Anderson
 Why is this program written in Pascal?  Quite simply, because C++ is annoying
 with its program size and the amount of memory is uses.  Write a TSR that does
 what this one does in C, and it will be ten times the size.
 For good coding, always use Pascal.
}
{$S-}
{$M 8000, 0, 512}
uses
  Crt, Dos;

type
  String8=String[8];

const
  IdStr1:String8='TP7RTSR';
  IdStr2:String8='TSRInUse';

var
 redflag:byte;
 whichstuff:byte;
 BlueFlag1,blueflag2:byte;
 Old1C:Procedure;               { Linkage To Old 1C Interrupt   }
 CPURegisters: Registers;
   { General register structure for Intr calls. }
  CursorStartLine: Byte;
    { Stores cursor shape information. }
  CursorEndLine: Byte;
    { Stores cursor shape information. }
  DiskInUse: Word;
    { Tracks INT 13 calls in progress. }
  MadeActive: Boolean;
    { TRUE if this TSR has been asked to pop up. }
  OurSP: Word;
  OurSS: Word;
    { Saved copies of our SS and SP registers. }
  PInt09: Pointer;
    { Saved address of keyboard handler. }
  PInt12: Pointer;
    { Saved address of GetMemorySize interrupt. }
  PInt1B: Pointer;
    { Ctrl-Break interrupt address. }
  PInt24: Pointer;
    { DOS Critical error handler. }
  PInt28: Pointer;
    { Saved address background task scheduler. }
  PInt1C: Pointer;
    { Saved address of timer handler. }
  PInDosFlag: ^Word;
    { Points to DOS's InDos flag. }
  SavedWindMin: Word;
   { Holds saved copy of WindMin for restoring window. }
  SavedWindMax: Word;
   { Holds saved copy of WindMax for restoring window. }
  SavedSS,
  SavedSP: Word;
   { Saves caller stack registers; must be global
   to store in fixed memory location, not on local
   stack of interrupted process. }
  SavedX,
  SavedY: Word;
 { Stores X, Y cursor prior to TSR popup }
    { for restoration when TSR goes away. }
  TempPtr: Pointer;
   { Used internally to DoUnInstall. }
  TSRInUse: Boolean;
    { Set TRUE during processing to avoid double
    activation. }

procedure TrapCriticalErrors;
assembler;
{ INT 24H }
asm
  IRET
end; { TrapCriticalErrors }

procedure CBreakCheck;
assembler;
{ INT 1BH }
asm
  IRET
end; { CBreakCheck }


procedure  DoPopUpFunction;
{ This procedure is the "guts" of the popup
  application. You can code your own application here, if
  you want. Be sure to read the text for important
  restrictions on what can be written in a TSR.
}
begin {DoPopUpFunction}
end; {DoPopUpFunction}



procedure RunPopUp;
{ Switches from system stack to TSR's stack. Calls
DoPopUpFunction to run the actual TSR application. This
keeps all the ugly details separate from the
application. Note that while the TSR is up on the
screen, and only while the TSR is up, we trap the
Ctrl-Break and DOS critical errors interrupt. We do
nothing when we see them except return, thereby ignoring
the interrupts. }
begin
 { Switch stacks. }
   asm
     CLI
   end;
   SavedSS := SSeg;
   SavedSP := SPtr;
   asm
     MOV   SS, OurSS
     MOV   SP, OurSP
     STI
   end;
   GetIntVec( $1B, PInt1B );
     { Disable Ctrl-Break checking. }
SetIntVec( $1B, @CBreakCheck );
   GetIntVec( $24, PInt24 );
     { Trap DOS critical errors. }
   SetIntVec( $24, @TrapCriticalErrors );
   DoPopUpFunction;
   SetIntVec( $24, PInt24 );
     { Reenable DOS critical error trapping. }
   SetIntVec( $1B, PInt1B );
     { Reenable Ctrl-C trapping. }
   { Restore stacks. }
   asm
     CLI
     MOV   SS, SavedSS
     MOV   SP, SavedSP
     STI
   end;
end; {RunPopUp}

function grabatt(x,y:byte):byte;
 begin
  grabatt:=(mem[$B800:(160*(y-1)+2*(x-1)+1)]);
 end;

function grabchar(x,y:byte):byte;
 begin
  grabchar:=(mem[$B800:(160*(y-1)+2*(x-1))]);
 end;

procedure ascloader(code:byte);
 begin
  asm
   mov ah,05h
   mov cl,code
   mov ch,0
   int 16h
  end;
 end;

procedure scanloader(code:byte);
 begin
  asm
   mov ah,05h
   mov cl,0
   mov ch,code
   int 16h
  end;
 end;


procedure runstuff(whichstuff:byte);
begin
 case whichstuff of
  1:begin
     scanloader(80);
     ascloader(13);
    end;
  2:begin
  scanloader(80);
     ascloader(13);
     scanloader(80);
     ascloader(13);
     scanloader(80);
     ascloader(13);
     scanloader(80);
     ascloader(13);
    end;
  3:begin
     ascloader(27);
     ascloader(27);
     ascloader(113);
     ascloader(13);
     ascloader(27);
     ascloader(27);
     ascloader(113);
    end;
  4:begin
  ascloader(27);
     scanloader(80);
     ascloader(13);
     scanloader(80);
     ascloader(13);
    end;
  5:begin
     ascloader(27);
     ascloader(27);
     ascloader(113);
    end;
  6:begin
     {6 escapes}
     ascloader(27);
     ascloader(27);
     ascloader(27);
     ascloader(27);
     ascloader(27);
     ascloader(27);
  { uninstall tsr}
     ascloader(116);
     ascloader(115);
     ascloader(114);
     ascloader(49);
     ascloader(48);
     ascloader(32);
     ascloader(47);
     ascloader(117);
     ascloader(13);
    end;

  7:begin
    end;
  end;  {case}
 end;

procedure New1C;interrupt;
begin
  if (grabatt(38,8) and 240 = 16) and (blueflag1 = 0 ) then blueflag1:=1;
  if (grabatt(38,8) and 16 = 0) and (blueflag1 = 1) then
   begin
    inc(whichstuff);
    runstuff(whichstuff);
    blueflag1:=0;
   end;
  if (grabatt(10,10) and 80 = 80  ) and (whichstuff = 3) then
   begin
    inc(whichstuff);
    runstuff(whichstuff);
   end;
  if (grabatt(30,14) and 240 = 16) and (whichstuff = 4) then
   blueflag2:=1;
  if (grabatt(30,14) and 240 = 0) and (blueflag2 = 1) then
   begin
    inc(whichstuff);
    blueflag2:=0;
    runstuff(whichstuff);
end;
  if (grabatt(10,8) and 80 = 80 ) and (whichstuff = 5) then
   begin
    inc(whichstuff);
    runstuff(whichstuff);
   end;
  Inline($9C);                          { Pushf - Push Flags            }
  Old1C;                                { Link Old 1C Procedure         }
end;

procedure BackgroundInt;
interrupt;
{ INT 28H }
{ This routine is hooked in the DOS INT 28H chain,
known variously as the DOSOK or DOSIdle interrupt. The
idea is that when applications are doing nothing except
waiting for a keystroke, they can call INT 28
repeatedly. INT 28 runs through a chain of applications
that each get a crack at running.

The keyboard interrupt handler watches for the
magic TSR popup key. Some of the time it runs the TSR
popup directly; when DOS is doing something, however, it
can't run the TSR. So, it sets a flag saying "Hey, INT
28, if you see this flag set, then do the TSR." So the
INT 28 code, here, examines the flag. If the flag is set, INT 28
knows that the TSR was activated, so it calls it now.
We can do this because DOS calls INT 28 only if it's safe
for something else to run.

}
begin
  { Call saved INT 28H handler. }
   asm
    PUSHF
    CALL PInt28
  end;
end; {BackgroundInt}

procedure DoUnInstall ( var Removed: Boolean ); forward;
{ These are "local" to OurInt12; it is safer to store them in the
TSR's global data area than to place them on the stack as
local variables. }
var
  IdStr : ^String8;
  MessageNum : Integer;

procedure OurInt12
  (_AX, BX, CX, DX, SI, DI, DS, ES, BP:Word);
interrupt;
{ INT 12H }
{ Intercepts INT 12H calls. If the ES:BX register
just happens to point to IdStr1, then the command-line
TSR program just called in. If this is the case, the
other registers could be used to pass a message to the
running TSR. Here, it's used by the running TSR to return
a pointer to another string, confirming that the TSR is
indeed running.
}

var
  DeInstallOk: Boolean;
begin
  IdStr := Ptr( ES, BX );
    { Check to see if ES:BX points to the }
    { magic ID string }
  If  IdStr^ = IdStr1  then
    MessageNum := CX
  else
  begin
    MessageNum := 0;
      { No message rcvd; this is normal DOS call. }
    asm
       pushf
       call    PInt12
       mov     _AX, ax
{ AX returns the memory size value. }
    end;
  end;
  if  MessageNum > 0   then
  { Process a message directed to this TSR. }
  begin
    case  MessageNum  of
      1:  begin
          { Returns pointer to IdStr2 indicating this
          TSR is here. }
            ES := Seg(IdStr2);
            BX := Ofs(IdStr2);
          end;
      2:  begin { Performs request to uninstall the TSR. }
            DoUnInstall (DeInstallOk);
            if         DeInstallOk  then
              CX := 0 { Report success. }
            else
              CX := 1; { Report failure. }
 end;
    end;
  end;
end; {OurInt12}



procedure DoUnInstall ( var Removed: Boolean );
begin
  { See if any TSRs have loaded in memory after us.
  If another TSR has loaded after us, then we really
  cannot safely terminate this TSR. Why? Because when they
  terminate, they may reset their interrupts to point back
  to this TSR. And if this TSR is no longer in memory,
  uh-oh... }

  Removed := True;
   GetIntVec( $28, TempPtr );
   if  TempPtr <> @BackgroundInt  then
  Removed := False;

   GetIntVec( $12, TempPtr );
   If  TempPtr <> @OurInt12  then
     Removed := False;


   if  Removed  then
   begin
     { Restore interrupts }
     SetIntVec( $28, PInt28 );
     SetIntVec( $12, PInt12 );
     SetIntVec( $1C , @Old1c);
     { Free up memory allocated to this program using
     INT 21 Func=49H "Release memory". }
     CPURegisters.AH := $49;
     CPURegisters.ES := PrefixSeg;{ Current program's PSP }
     Intr( $21, CPURegisters );
   end;
   {condos r}
   ascloader(99);
   ascloader(111);
   ascloader(110);
   ascloader(100);
   ascloader(111);
   ascloader(115);
   ascloader(32);
   ascloader(114);
   ascloader(13);
 end; {DoUnInstall}





 procedure InstallTSR (var AlreadyInstalled: Boolean );
 { Installs all interrupt handlers for this TSR. }

 var
   PSPPtr : ^Word;
   IdStr : ^String8;
 begin

   { Check to see if the TSR is already running by
   executing INT 12 with ES:BX pointing to IdStr1. If,
   after calling INT 12, ES:BX points to IdStr2, then the
   TSR is running since it must have intercepted INT 12 and
   set ES:BX to those return values. }
   blueflag1:=0;
   blueflag2:=0;
   whichstuff:=0;
   with        CPURegisters  do
   begin
     ES := Seg(IdStr1);
     BX := Ofs(IdStr1);
     CX := 1;
     Intr( $12, CPURegisters );
  IdStr := Ptr( ES, BX );
     if        IdStr^ = IdStr2  then
     begin
        AlreadyInstalled := True;
        Exit;
     end;
     { TSR hasn't been installed, so install our
     INT 12 driver. }
     asm
       cli
     end;
     GetIntVec( $12, PInt12 );
     SetIntVec( $12, @OurInt12 );
     asm
       sti
     end;
   end;
   AlreadyInstalled := False;
   MadeActive := False;
   DiskInUse := 0;

   { Check to see if TSR is already installed. }
   TSRInUse := False;

   { Deallocate DOS Environment block if not needed. }
   { Comment out this code if you need to access
     environment strings. }

  PSPPtr := Ptr( PrefixSeg, $2C );
   CPURegisters.AX := $4900;
  CPURegisters.ES := PSPPtr^;
  Intr( $21, CPURegisters);

  asm
    cli
  end;

  { Save and set INT 28H, background process interrupt. }
  GetIntVec( $28, PInt28 );
  SetIntVec( $28, @BackgroundInt );

  Getintvec($1C ,@Old1C);   { Save Old 1C Interrupt Vector        }
  Setintvec($1C ,@New1C);   { Insert Current Interurupt Procedure }

  asm
    sti
  end;

  { Initialize pointer to DOS's InDos flag. }
  { Uses INT 21H Function 34H to retrieve a pointer to the
  InDos flag. The result is returned in the ES:BX
  registers. }
  CPURegisters.AH := $34;
  Intr( $21, CPURegisters );
  PInDosFlag := Ptr( CPURegisters.ES, CPURegisters.BX );

  asm
    CLI
  end;
  { Save our SS:SP for later use. }
  OurSS := SSeg;
  OurSP := SPtr;
  asm
    STI
  end;
end; {InstallTSR}

var
  InstallError: Boolean;
  regs:registers;
begin {program}
  InstallTSR( InstallError );
  if  InstallError  then
  begin
    { This means that the TSR is already running.
      In that case, see if the command line requests
      an uninstall. }
 if  (ParamStr(1) = '/u') or (ParamStr(1) = '/U')  then
      { Send an Uninstall message to the TSR }
      with  CPURegisters  do
      begin
        ES := Seg(IdStr1);
        BX := Ofs(IdStr1);
        CX := 2;
        Intr( $12, CPURegisters );
        if  CX = 0  then
        else
        Exit;
      end
    else
  end
  else
  begin
    Keep( 0 );
     { Exit to DOS, leaving program memory-resident. }
  end;
end. {program}
