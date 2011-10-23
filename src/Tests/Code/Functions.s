 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /opt/vex -S -fno-xnop -fmm=modelo.fmm"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32

 ## Begin Sum
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
Sum::
.trace 1
	      ## auto_size == 0
	c0    add $r0.3 = $r0.3, $r0.4   ## bblock 0, line 4,  t2,  t1,  t0
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 4,  t4,  ?2.1?2auto_size(I32),  t3
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End Sum

 ## Begin Sub
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
Sub::
.trace 1
	      ## auto_size == 0
	c0    sub $r0.3 = $r0.3, $r0.4   ## bblock 0, line 9,  t2,  t1,  t0
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 9,  t4,  ?2.2?2auto_size(I32),  t3
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.2?2auto_size, 0x0
 ## End Sub
 ## Begin RShift
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg($r0.3:s32,$r0.4:s32)
RShift::
.trace 1
	      ## auto_size == 0
	c0    shl $r0.3 = $r0.3, $r0.4   ## bblock 0, line 14,  t2,  t0,  t1
;;								## 0
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x0), $l0.0   ## bblock 0, line 14,  t4,  ?2.3?2auto_size(I32),  t3
;;								## 1
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.3?2auto_size, 0x0
 ## End RShift
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
main::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.4 = 2   ## 2(SI32)
	c0    mov $r0.3 = 5   ## 5(SI32)
;;								## 0
.call Sub, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = Sub   ## bblock 0, line 25,  raddr(Sub)(P32),  5(SI32),  2(SI32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t7
;;								## 1
	c0    mov $r0.4 = 2   ## 2(SI32)
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t1
;;								## 2
.call RShift, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = RShift   ## bblock 1, line 25,  raddr(RShift)(P32),  5(SI32),  2(SI32)
	c0    mov $r0.3 = 5   ## 5(SI32)
;;								## 3
	c0    ldw $r0.3 = 0x14[$r0.1]  ## restore ## t1
	c0    mov $r0.4 = $r0.3   ## t4
;;								## 4
;;								## 5
.call Sum, caller, arg($r0.3:s32,$r0.4:s32), ret($r0.3:s32)
	c0    call $l0.0 = Sum   ## bblock 2, line 25,  raddr(Sum)(P32),  t1,  t4
;;								## 6
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t7
;;								## 7
;;								## 8
;;								## 9
;;								## 10
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 3, line 25,  t8,  ?2.4?2auto_size(I32),  t7
;;								## 11
.endp
.section .bss
.section .data
.equ ?2.4?2scratch.0, 0x0
.equ ?2.4?2ras_p, 0x10
.equ ?2.4?2spill_p, 0x14
.section .data
.section .text
.equ ?2.4?2auto_size, 0x20
 ## End main
.section .bss
.section .data
.section .data
.section .text
.import RShift
.type RShift,@function
.import Sub
.type Sub,@function
.import Sum
.type Sum,@function
