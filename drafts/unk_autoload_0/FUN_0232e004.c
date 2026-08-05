// decomp: module=unk_autoload_0 addr=0x0232e004 name=FUN_0232e004
// GHIDRA DRAFT - a reading aid, NOT a matching candidate.
// size 0x7e, thumb
// triage: noise=5 statements=29
// verify:  python tools/match.py --c <file> --func FUN_0232e004 --addr 0x0232e004 --size 0x7e --module unk_autoload_0 --version 2.0/sp1


int FUN_0232e004(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int unused2;
  undefined2 *puVar2;
  int iVar3;
  undefined4 local_24;
  
  puVar2 = (undefined2 *)(param_1 + 8);
  iVar3 = 0;
  unused2 = param_3;
  iVar1 = FUN_0232e000();
  if (0 < iVar1) {
    do {
      local_24 = CONCAT22(local_24._2_2_,*puVar2);
      iVar1 = FUN_0232df40(local_24,(ushort)puVar2[2] & 0xff,unused2,param_4);
      local_24 = CONCAT22(local_24._2_2_,puVar2[1]);
      unused2 = FUN_0232df74(local_24,(uint)((ushort)puVar2[2] >> 8),unused2,param_4);
      param_4 = unused2 + (uint)((ushort)puVar2[2] >> 8);
      if ((((iVar1 <= param_2) && (param_2 <= (int)(iVar1 + ((ushort)puVar2[2] & 0xff)))) &&
          (unused2 <= param_3)) && (param_3 <= param_4)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 3;
      iVar1 = FUN_0232e000(param_1);
    } while (iVar3 < iVar1);
  }
  return -1;
}

