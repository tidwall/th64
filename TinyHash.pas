unit TinyHash;

interface

function th64(const Data: Pointer; const Len: NativeUInt; const Seed: UInt64): UInt64;

implementation

function th64(const Data: Pointer; const Len: NativeUInt; const Seed: UInt64): UInt64;
const
  R: UInt64 = $14020A57ACCED8B7;

var
  P1, P2: PByte;
  X, H: UInt64;
begin
  Result := 0;
  P1 := Data;
  P2 := P1;
  Inc(P2, Len);
  H := Seed;
  while (P1 + 8) <= P2 do
  begin
    X := PUInt64(P1)^;
    Inc(P1, 8);

    X := X * R;
    X := X shl 31 or X shr 33;
    H := H * R xor X;
    H := H shl 31 or H shr 33;
  end;
  while P1 < P2 do
  begin
    H := H * R xor P1^;
    Inc(P1);
  end;
  H := H * R + Len;
  H := H xor (H shr 31);
  H := H * R;
  H := H xor (H shr 31);
  H := H * R;
  H := H xor (H shr 31);
  H := H * R;
  Result := H;
end;

end.
