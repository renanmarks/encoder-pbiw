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
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg()
main::
.trace 3
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    mov $r0.6 = 2   ## bblock 0, line 0,  t30,  2(I32)
	c0    mov $r0.7 = 3   ## bblock 0, line 0,  t29,  3(I32)
;;								## 0
	c0    mov $r0.3 = $r0.1   ## bblock 0, line 3,  t0,  t9
	c0    mov $r0.4 = $r0.0   ## bblock 0, line 6,  t21,  0(SI32)
	c0    mov $r0.5 = 1   ## bblock 0, line 0,  t31,  1(I32)
;;								## 1
	c0    mov $r0.2 = $r0.3   ## bblock 0, line 3,  t32,  t0
;;								## 2
.trace 1
L0?3:
	c0    ldw $r0.3 = 0[$r0.2]   ## bblock 1, line 7, t5, t32
	c0    cmplt $b0.0 = $r0.4, 8   ## bblock 1, line 6-2,  t47(I1),  t21,  8(SI32)
;;								## 0
	c0    ldw $r0.8 = 4[$r0.2]   ## bblock 1, line 7-1, t26, t32
;;								## 1
	c0    ldw.d $r0.9 = 8[$r0.2]   ## [spec] bblock 8, line 7-2, t23, t32
;;								## 2
	c0    add $r0.3 = $r0.4, $r0.3   ## bblock 1, line 7,  t7,  t21,  t5
	c0    ldw.d $r0.10 = 12[$r0.2]   ## [spec] bblock 8, line 7-3, t20, t32
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 8, line 6-3,  t21,  t21,  4(SI32)
;;								## 3
	c0    stw 0[$r0.2] = $r0.3   ## bblock 1, line 7, t32, t7
	c0    add $r0.8 = $r0.5, $r0.8   ## bblock 1, line 7-1,  t27,  t31,  t26
	c0    add $r0.5 = $r0.5, 4   ## [spec] bblock 8, line 0,  t31,  t31,  4(I32)
;;								## 4
	c0    stw 4[$r0.2] = $r0.8   ## bblock 1, line 7-1, t32, t27
	c0    add $r0.9 = $r0.6, $r0.9   ## [spec] bblock 8, line 7-2,  t24,  t30,  t23
	c0    add $r0.6 = $r0.6, 4   ## [spec] bblock 8, line 0,  t30,  t30,  4(I32)
	c0    brf $b0.0, L1?3   ## bblock 1, line 6-2,  t47(I1)
;;								## 5
	c0    stw 8[$r0.2] = $r0.9   ## bblock 8, line 7-2, t32, t24
	c0    add $r0.10 = $r0.7, $r0.10   ## bblock 8, line 7-3,  t22,  t29,  t20
	c0    add $r0.7 = $r0.7, 4   ## bblock 8, line 0,  t29,  t29,  4(I32)
;;								## 6
	c0    stw 12[$r0.2] = $r0.10   ## bblock 8, line 7-3, t32, t22
	c0    add $r0.2 = $r0.2, 16   ## bblock 8, line 0,  t32,  t32,  16(I32)
	c0    goto L0?3 ## goto
;;								## 7
.trace 4
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 2, line 9,  t9,  ?2.1?2auto_size(I32),  t8
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.endp
.section .bss
.section .data
.equ _?1PACKET.1, 0x0
.section .data
.section .text
.equ ?2.1?2auto_size, 0x40
 ## End main
.section .bss
.section .data
.section .data
.section .text
