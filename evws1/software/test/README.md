# evws1/software/atmega324p_u

## Gnu Debugger Support (gdb)

qSupported:multiprocess+;swbreak+;hwbreak+;qRelocInsn+;fork-events+;vfork-events+;exec-events+;vContSupported+;QThreadEvents+;no-resumed+;xmlRegisters=i386
vMustReplyEmpty
Hg0
qTStatus
?
qfThreadInfo
qL1200000000000000000
Hc-1
qC
qAttached
qOffsets

### Init for non-stop mode

``bash
$ avr-gdb -b 115200 dist/atmega324p_u1.elf
GNU gdb (GDB) 7.11.1
...
(gdb) set non-stop on
(gdb) target remote /dev/ttyUSB0
Remote debugging using /dev/ttyUSB0
Remote server does not support stopping threads
(gdb)
```

```usbdump
13992.072459 -->  32: $qSupported:multiprocess+;swbrea
13992.072463 -->  32: k+;hwbreak+;qRelocInsn+;fork-eve
13992.072507 -->  32: nts+;vfork-events+;exec-events+;
13992.072544 -->  32: vContSupported+;QThreadEvents+;n
13992.075347 -->  13: o-resumed+#df
13992.086892 <--   1: +
13992.096482 <--  27: $PacketSize=96;QNonStop+#27
13992.096592 -->   1: +
13992.096628 -->  19: $vMustReplyEmpty#3a
13992.100262 <--   1: +
13992.103291 <--   4: $#00
13992.103374 -->   1: +
13992.103399 -->   7: $Hg0#df
13992.108029 <--   7: +$OK#9a
13992.108086 -->   1: +
13992.108120 -->  14: $QNonStop:1#8d
13992.111501 <--   1: +
13992.114204 <--   6: $OK#9a
13992.114252 -->   1: +
13992.114264 -->  16: $qfThreadInfo#bb
13992.117634 <--   1: +
13992.120690 <--   6: $m1#9e
13992.120727 -->   1: +
13992.120737 -->  16: $qsThreadInfo#c8
13992.124157 <--   1: +
13992.127174 <--   5: $l#6c
13992.127209 -->   1: +
13992.127223 -->  13: $qAttached#8f
13992.130641 <--   1: +
13992.132982 <--   5: $1#31
13992.133027 -->   1: +
13992.133063 -->  12: $qTStatus#49
13992.136032 <--   1: +
13992.139459 <--  16: $T0;tnotrun:0#43
13992.139520 -->   1: +
13992.139539 -->   8: $qTfV#81
13992.144248 <--   5: +$#00
13992.144317 -->   1: +
13992.144333 -->   5: $?#3f
13992.148671 <--   7: +$OK#9a
13992.148721 -->   1: +
13992.148741 -->  10: $vCont?#49
13992.153850 <--   5: +$#00
13992.153967 -->   1: +