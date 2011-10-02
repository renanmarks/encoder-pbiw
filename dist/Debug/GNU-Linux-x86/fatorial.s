 ## Target: VEX 1 cluster (big endian)
.comment ""
.comment "Copyright (C) 1990-2010 Hewlett-Packard Company"
.comment "VEX C compiler version 3.43 (20110131 release)"
.comment ""
.comment "-dir /opt/vex -S"
.sversion 3.43
.rta 2
.section .bss
.align 32
.section .data
.align 32
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=0, arg()
main::
.trace 4
	      ## auto_size == 0
	c0    mov $r0.8 = 3   ## bblock 0, line 0,  t30,  3(I32)
	c0    mov $r0.9 = 4   ## bblock 0, line 0,  t29,  4(I32)
;;								## 0
	c0    mov $r0.3 = 1   ## bblock 0, line 6,  t18,  1(SI32)
	c0    mov $r0.2 = 1   ## bblock 0, line 6,  t19,  1(SI32)
	c0    mov $r0.7 = 1   ## bblock 0, line 0,  t20,  1(I32)
	c0    mov $r0.6 = 2   ## bblock 0, line 0,  t31,  2(I32)
;;								## 1
.trace 1
L0?3:
	c0    mpylu $r0.4 = $r0.2, $r0.3   ## bblock 1, line 9,  t41,  t19,  t18
	c0    mpyhs $r0.5 = $r0.2, $r0.3   ## bblock 1, line 9,  t42,  t19,  t18
	c0    cmpleu $b0.0 = $r0.8, 10   ## bblock 1, line 8-2,  t45(I1),  t30,  10(SI32)
;;								## 0
	c0    mpylu $r0.10 = $r0.6, $r0.7   ## bblock 1, line 9-1,  t43,  t31,  t20
	c0    mpyhs $r0.11 = $r0.6, $r0.7   ## bblock 1, line 9-1,  t44,  t31,  t20
;;								## 1
	c0    add $r0.4 = $r0.4, $r0.5   ## bblock 1, line 9,  t23,  t41,  t42
	c0    mpylu $r0.5 = $r0.2, $r0.3   ## [spec] bblock 8, line 9-2,  t47,  t19,  t18
	c0    mpyhs $r0.3 = $r0.2, $r0.3   ## [spec] bblock 8, line 9-2,  t48,  t19,  t18
	c0    add $r0.2 = $r0.2, 4   ## [spec] bblock 8, line 8-3,  t19,  t19,  4(SI32)
;;								## 2
	c0    add $r0.10 = $r0.10, $r0.11   ## bblock 1, line 9-1,  t27,  t43,  t44
	c0    mpylu $r0.11 = $r0.9, $r0.7   ## [spec] bblock 8, line 9-3,  t52,  t29,  t20
	c0    mpyhs $r0.7 = $r0.9, $r0.7   ## [spec] bblock 8, line 9-3,  t53,  t29,  t20
	c0    brf $b0.0, L1?3   ## bblock 1, line 8-2,  t45(I1)
;;								## 3
	c0    add $r0.5 = $r0.5, $r0.3   ## bblock 8, line 9-2,  t46,  t47,  t48
	c0    add $r0.9 = $r0.9, 4   ## bblock 8, line 0,  t29,  t29,  4(I32)
;;								## 4
	c0    mpylu $r0.4 = $r0.5, $r0.8   ## bblock 8, line 9-2,  t49,  t46,  t30
	c0    mpyhs $r0.5 = $r0.5, $r0.8   ## bblock 8, line 9-2,  t50,  t46,  t30
	c0    add $r0.11 = $r0.11, $r0.7   ## bblock 8, line 9-3,  t51,  t52,  t53
	c0    add $r0.8 = $r0.8, 4   ## bblock 8, line 0,  t30,  t30,  4(I32)
;;								## 5
	c0    mpylu $r0.10 = $r0.11, $r0.6   ## bblock 8, line 9-3,  t54,  t51,  t31
	c0    mpyhs $r0.11 = $r0.11, $r0.6   ## bblock 8, line 9-3,  t55,  t51,  t31
	c0    add $r0.6 = $r0.6, 4   ## bblock 8, line 0,  t31,  t31,  4(I32)
;;								## 6
	c0    add $r0.3 = $r0.4, $r0.5   ## bblock 8, line 9-2,  t18,  t49,  t50
;;								## 7
	c0    add $r0.7 = $r0.10, $r0.11   ## bblock 8, line 9-3,  t20,  t54,  t55
	c0    goto L0?3 ## goto
;;								## 8
.trace 3
L1?3:
	c0    mpylu $r0.2 = $r0.4, $r0.10   ## bblock 9, line 0,  t56,  t23,  t27
	c0    mpyhs $r0.4 = $r0.4, $r0.10   ## bblock 9, line 0,  t57,  t23,  t27
	      xnop 1
;;								## 1
.return ret($r0.3:s32)
	c0    add $r0.3 = $r0.2, $r0.4   ## bblock 9, line 0,  t21,  t56,  t57
	c0    return $r0.1 = $r0.1, (LABEL + 0xf + 0x1), $l0.0   ## bblock 9, line 13,  t8,  ?2.1?2auto_size(I32),  t7
;;								## 2
.endp
.section .bss
.section .data
.section .data
.section .text
.equ ?2.1?2auto_size, 0x0
 ## End main
.section .bss
.section .data
.section .data
.section .text
