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
.trace 9
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    mov $r0.2 = $r0.0   ## bblock 0, line 6,  t32,  0(SI32)
	c0    mov $r0.7 = 1   ## bblock 0, line 0,  t39,  1(I32)
;;								## 0
	c0    mov $r0.4 = $r0.1   ## bblock 0, line 3,  t0,  t17
;;								## 1
	c0    mov $r0.3 = $r0.4   ## bblock 0, line 3,  t40,  t0
;;								## 2
.trace 1
L0?3:
	c0    cmplt $b0.0 = $r0.2, 10   ## bblock 1, line 6,  t49(I1),  t32,  10(SI32)
	c0    cmpeq $r0.5 = $r0.2, 1   ## [spec] bblock 3, line 22,  t30(I1),  t32,  1(SI32)
	c0    cmpeq $r0.6 = $r0.2, 2   ## [spec] bblock 3, line 22,  t31(I1),  t32,  2(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 9, line 12, t6, t40
;;								## 0
	c0    norl $b0.1 = $r0.5, $r0.6   ## [spec] bblock 3, line 22,  t50(I1),  t30(I1),  t31(I1)
	c0    cmpeq $r0.8 = $r0.2, $r0.0   ## [spec] bblock 7, line 22-1,  t28(I1),  t32,  0(I32)
	c0    cmpeq $r0.9 = $r0.2, 1   ## [spec] bblock 7, line 22-1,  t29(I1),  t32,  1(SI32)
	c0    ldw.d $r0.10 = 4[$r0.3]   ## [spec] bblock 15, line 12-1, t37, t40
;;								## 1
	c0    norl $b0.0 = $r0.8, $r0.9   ## [spec] bblock 7, line 22-1,  t52(I1),  t28(I1),  t29(I1)
	c0    brf $b0.0, L1?3   ## bblock 1, line 6,  t49(I1)
;;								## 2
	c0    mpylu $r0.5 = $r0.2, $r0.4   ## [spec] bblock 9, line 12,  t53,  t32,  t6
	c0    mpyhs $r0.6 = $r0.2, $r0.4   ## [spec] bblock 9, line 12,  t54,  t32,  t6
	c0    br $b0.1, L2?3   ## bblock 3, line 22,  t50(I1)
;;								## 3
	c0    mpylu $r0.8 = $r0.7, $r0.10   ## [spec] bblock 15, line 12-1,  t56,  t39,  t37
	c0    mpyhs $r0.9 = $r0.7, $r0.10   ## [spec] bblock 15, line 12-1,  t57,  t39,  t37
;;								## 4
	c0    add $r0.5 = $r0.5, $r0.6   ## bblock 9, line 12,  t8,  t53,  t54
;;								## 5
	c0    stw 0[$r0.3] = $r0.5   ## bblock 9, line 12, t40, t8
	c0    add $r0.8 = $r0.8, $r0.9   ## [spec] bblock 15, line 12-1,  t38,  t56,  t57
	c0    br $b0.0, L3?3   ## bblock 7, line 22-1,  t52(I1)
;;								## 6
L4?3:
	c0    stw 4[$r0.3] = $r0.8   ## bblock 15, line 12-1, t40, t38
	c0    add $r0.7 = $r0.7, 2   ## bblock 13, line 0,  t39,  t39,  2(I32)
	c0    add $r0.2 = $r0.2, 2   ## bblock 13, line 6-1,  t32,  t32,  2(SI32)
;;								## 7
L5?3:
	c0    add $r0.3 = $r0.3, 8   ## bblock 13, line 0,  t40,  t40,  8(I32)
	c0    goto L0?3 ## goto
;;								## 8
.trace 4
L3?3:
	c0    cmpeq $b0.0 = $r0.2, 4   ## bblock 11, line 22-1,  t55(I1),  t32,  4(SI32)
	c0    ldw.d $r0.4 = 4[$r0.3]   ## [spec] bblock 14, line 16-1, t35, t40
;;								## 0
;;								## 1
	c0    brf $b0.0, L6?3   ## bblock 11, line 22-1,  t55(I1)
;;								## 2
	c0    add $r0.4 = $r0.7, $r0.4   ## bblock 14, line 16-1,  t36,  t39,  t35
	c0    add $r0.2 = $r0.2, 2   ## bblock 13, line 6-1,  t32,  t32,  2(SI32)
;;								## 3
	c0    stw 4[$r0.3] = $r0.4   ## bblock 14, line 16-1, t40, t36
	c0    add $r0.7 = $r0.7, 2   ## bblock 13, line 0,  t39,  t39,  2(I32)
	c0    goto L5?3 ## goto
;;								## 4
.trace 7
L6?3:
	c0    ldw $r0.4 = 4[$r0.3]   ## bblock 12, line 20-1, t33, t40
	c0    add $r0.7 = $r0.7, 2   ## bblock 13, line 0,  t39,  t39,  2(I32)
	c0    add $r0.2 = $r0.2, 2   ## bblock 13, line 6-1,  t32,  t32,  2(SI32)
;;								## 0
;;								## 1
;;								## 2
	c0    add $r0.4 = $r0.4, 1   ## bblock 12, line 20-1,  t34,  t33,  1(SI32)
;;								## 3
	c0    stw 4[$r0.3] = $r0.4   ## bblock 12, line 20-1, t40, t34
	c0    goto L5?3 ## goto
;;								## 4
.trace 3
L2?3:
	c0    cmpeq $b0.1 = $r0.2, 5   ## bblock 5, line 22,  t51(I1),  t32,  5(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 8, line 16, t10, t40
	c0    mpylu $r0.9 = $r0.7, $r0.10   ## [spec] bblock 15, line 12-1,  t56,  t39,  t37
	c0    mpyhs $r0.11 = $r0.7, $r0.10   ## [spec] bblock 15, line 12-1,  t57,  t39,  t37
;;								## 0
;;								## 1
	c0    add $r0.8 = $r0.9, $r0.11   ## [spec] bblock 15, line 12-1,  t38,  t56,  t57
	c0    brf $b0.1, L7?3   ## bblock 5, line 22,  t51(I1)
;;								## 2
	c0    add $r0.4 = $r0.2, $r0.4   ## bblock 8, line 16,  t12,  t32,  t10
;;								## 3
	c0    stw 0[$r0.3] = $r0.4   ## bblock 8, line 16, t40, t12
	c0    br $b0.0, L3?3   ## bblock 7, line 22-1,  t52(I1)
	      ## goto
;;
	c0    goto L4?3 ## goto
;;								## 4
.trace 6
L7?3:
	c0    ldw $r0.4 = 0[$r0.3]   ## bblock 6, line 20, t14, t40
;;								## 0
;;								## 1
;;								## 2
	c0    add $r0.4 = $r0.4, 1   ## bblock 6, line 20,  t15,  t14,  1(SI32)
;;								## 3
	c0    stw 0[$r0.3] = $r0.4   ## bblock 6, line 20, t40, t15
	c0    brf $b0.0, L8?3   ## bblock 7, line 22-1,  t52(I1)
	      ## goto
;;
	c0    goto L3?3 ## goto
;;								## 4
.trace 8
L8?3:
	c0    mpylu $r0.4 = $r0.7, $r0.10   ## bblock 15, line 12-1,  t56,  t39,  t37
	c0    mpyhs $r0.9 = $r0.7, $r0.10   ## bblock 15, line 12-1,  t57,  t39,  t37
;;								## 0
;;								## 1
	c0    add $r0.8 = $r0.4, $r0.9   ## bblock 15, line 12-1,  t38,  t56,  t57
	c0    goto L4?3 ## goto
;;								## 2
.trace 10
L1?3:
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 2, line 25,  t17,  ?2.1?2auto_size(I32),  t16
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
