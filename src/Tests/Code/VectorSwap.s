 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /opt/vex -S -fmm=modelo.fmm -fno-xnop"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-96, arg()
main::
.trace 3
	c0    add $r0.1 = $r0.1, (-0x60)
	c0    mov $r0.5 = (~0x7)   ## bblock 0, line 0,  t31,  (~0x7)(I32)
;;								## 0
	c0    add $r0.6 = $r0.1, 0x28   ## bblock 0, line 3,  t0,  t9,  offset(a?1.2)=0x28(P32)
	c0    mov $r0.3 = $r0.1   ## bblock 0, line 4,  t1,  t9
;;								## 1
	c0    mov $r0.2 = $r0.6   ## bblock 0, line 3,  t29,  t0
	c0    mov $r0.4 = $r0.3   ## bblock 0, line 4,  t30,  t1
;;								## 2
.trace 1
L0?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 1, line 8, t6, t29
	c0    cmplt $b0.0 = $r0.5, $r0.0   ## bblock 1, line 7-2,  t54(I1),  t31,  0(SI32)
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 8, line 0,  t31,  t31,  4(I32)
;;								## 0
	c0    ldw $r0.6 = 4[$r0.2]   ## bblock 1, line 8-1, t24, t29
;;								## 1
	c0    ldw.d $r0.7 = 8[$r0.2]   ## [spec] bblock 8, line 8-2, t22, t29
;;								## 2
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 8, line 8-3, t20, t29
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 8, line 0,  t29,  t29,  16(I32)
;;								## 3
	c0    stw 0[$r0.4] = $r0.3   ## bblock 1, line 8, t30, t6
;;								## 4
	c0    stw 4[$r0.4] = $r0.6   ## bblock 1, line 8-1, t30, t24
	c0    brf $b0.0, L1?3   ## bblock 1, line 7-2,  t54(I1)
;;								## 5
	c0    stw 8[$r0.4] = $r0.7   ## bblock 8, line 8-2, t30, t22
;;								## 6
	c0    stw 12[$r0.4] = $r0.8   ## bblock 8, line 8-3, t30, t20
	c0    add $r0.4 = $r0.4, 16   ## bblock 8, line 0,  t30,  t30,  16(I32)
	c0    goto L0?3 ## goto
;;								## 7
.trace 4
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x60), $l0.0   ## bblock 2, line 10,  t9,  ?2.1?2auto_size(I32),  t8
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.endp
.section .bss
.section .data
.equ _?1PACKET.2, 0x0
.equ _?1PACKET.1, 0x28
.section .data
.section .text
.equ ?2.1?2auto_size, 0x60
 ## End main
.section .bss
.section .data
.section .data
.section .text
