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
 ## Begin mergesort
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-64, arg($r0.3:s32,$r0.4:s32)
mergesort::
.trace 9
	c0    add $r0.1 = $r0.1, (-0x40)
	c0    cmpeq $b0.0 = $r0.3, $r0.4   ## bblock 0, line 11,  t207(I1),  t66,  t67
;;								## 0
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t53
;;								## 1
	c0    brf $b0.0, L0?3   ## bblock 0, line 11,  t207(I1)
;;								## 2
.return ret()
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 15, line 12,  t54,  ?2.1?2auto_size(I32),  t53
;;								## 3
.trace 10
L0?3:
	c0    add $r0.7 = $r0.4, $r0.3   ## bblock 1, line 14,  t4,  t67,  t66
	c0    stw 0x14[$r0.1] = $r0.3  ## spill ## t66
;;								## 0
	c0    cmplt $b0.0 = $r0.7, $r0.0   ## bblock 1, line 14,  t208,  t4,  0(I32)
	c0    add $r0.9 = $r0.7, 1   ## bblock 1, line 14,  t209,  t4,  1(I32)
	c0    stw 0x18[$r0.1] = $r0.4  ## spill ## t67
;;								## 1
	c0    slct $r0.9 = $b0.0, $r0.9, $r0.7   ## bblock 1, line 14,  t210,  t208,  t209,  t4
;;								## 2
	c0    shr $r0.4 = $r0.9, 1   ## bblock 1, line 14,  t69,  t210,  1(I32)
;;								## 3
.call mergesort, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = mergesort   ## bblock 1, line 16,  raddr(mergesort)(P32),  t66,  t69
	c0    stw 0x1c[$r0.1] = $r0.4  ## spill ## t69
;;								## 4
	c0    ldw $r0.7 = 0x1c[$r0.1]  ## restore ## t69
;;								## 5
	c0    ldw $r0.4 = 0x18[$r0.1]  ## restore ## t67
	      xnop 1
;;								## 7
	c0    add $r0.3 = $r0.7, 1   ## bblock 2, line 17,  t9,  t69,  1(SI32)
;;								## 8
.call mergesort, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = mergesort   ## bblock 2, line 17,  raddr(mergesort)(P32),  t9,  t67
	c0    stw 0x20[$r0.1] = $r0.3  ## spill ## t9
;;								## 9
	c0    ldw $r0.4 = 0x1c[$r0.1]  ## restore ## t69
;;								## 10
	c0    ldw $r0.18 = 0x14[$r0.1]  ## restore ## t66
;;								## 11
	c0    ldw $r0.19 = 0x18[$r0.1]  ## restore ## t67
;;								## 12
	c0    sub $r0.7 = $r0.0, $r0.4   ## bblock 3, line 0,  t165,  0(I32),  t69
	c0    sh2add $r0.5 = $r0.4, ((A + 0) + 4)   ## bblock 3, line 0,  t143,  t69,  (addr(A?1.0)(P32) + 0x4(I32))(P32)
	c0    ldw $r0.9 = 0x20[$r0.1]  ## restore ## t9
;;								## 13
	c0    sh2add $r0.10 = $r0.18, (B + 0)   ## bblock 3, line 0,  t141,  t66,  addr(B?1.0)(P32)
	c0    add $r0.6 = $r0.18, $r0.7   ## bblock 3, line 0,  t145,  t66,  t165
;;								## 14
	c0    sub $r0.4 = $r0.0, $r0.19   ## bblock 3, line 0,  t180,  0(I32),  t67
	c0    sub $r0.7 = 3, $r0.19   ## bblock 3, line 0,  t147,  3(I32),  t67
	c0    sh2add $r0.3 = $r0.18, (A + 0)   ## bblock 3, line 0,  t142,  t66,  addr(A?1.0)(P32)
;;								## 15
	c0    add $r0.8 = $r0.9, $r0.4   ## bblock 3, line 0,  t144,  t9,  t180
	c0    add $r0.2 = $r0.18, $r0.7   ## bblock 3, line 0,  t146,  t66,  t147
;;								## 16
.trace 1
L1?3:
	c0    cmple $b0.0 = $r0.2, 3   ## bblock 4, line 22,  t211(I1),  t146,  3(SI32)
	c0    cmpgt $r0.9 = $r0.8, $r0.0   ## [spec] bblock 9, line 24,  t102(I1),  t144,  0(SI32)
	c0    cmpgt $r0.7 = $r0.6, $r0.0   ## [spec] bblock 9, line 24,  t103(I1),  t145,  0(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 9, line 24, t86, t142
;;								## 0
	c0    ldw.d $r0.11 = 0[$r0.5]   ## [spec] bblock 9, line 24, t87, t143
	c0    cmple $b0.1 = $r0.2, 2   ## [spec] bblock 12, line 22-1,  t216(I1),  t146,  2(SI32)
	c0    cmpgt $r0.12 = $r0.8, $r0.0   ## [spec] bblock 27, line 24-1,  t75(I1),  t144,  0(SI32)
	c0    cmple $b0.2 = $r0.2, 1   ## [spec] bblock 29, line 22-2,  t224(I1),  t146,  1(SI32)
;;								## 1
	c0    ldw.d $r0.13 = 0[$r0.5]   ## [spec] bblock 27, line 24-1, t28, t143
	c0    cmpgt $r0.14 = $r0.8, $r0.0   ## [spec] bblock 21, line 24-2,  t91(I1),  t144,  0(SI32)
	c0    cmple $b0.0 = $r0.2, $r0.0   ## [spec] bblock 23, line 22-3,  t221(I1),  t146,  0(SI32)
	c0    brf $b0.0, L2?3   ## bblock 4, line 22,  t211(I1)
;;								## 2
	c0    ldw.d $r0.15 = 0[$r0.5]   ## [spec] bblock 21, line 24-2, t85, t143
	c0    cmpgt $r0.16 = $r0.8, $r0.0   ## [spec] bblock 13, line 24-3,  t101(I1),  t144,  0(SI32)
;;								## 3
	c0    cmpgt $r0.11 = $r0.4, $r0.11   ## bblock 9, line 24,  t88(I1),  t86,  t87
	c0    ldw.d $r0.17 = 0[$r0.5]   ## [spec] bblock 13, line 24-3, t97, t143
;;								## 4
	c0    norl $r0.7 = $r0.7, $r0.11   ## bblock 9, line 24,  t82(I1),  t103(I1),  t88(I1)
;;								## 5
	c0    norl $b0.3 = $r0.9, $r0.7   ## bblock 9, line 24,  t215(I1),  t102(I1),  t82(I1)
	      xnop 1
;;								## 7
	c0    br $b0.3, L3?3   ## bblock 9, line 24,  t215(I1)
;;								## 8
	c0    stw 0[$r0.10] = $r0.4   ## bblock 14, line 26, t141, t86
	c0    add $r0.6 = $r0.6, 1   ## bblock 14, line 0,  t145,  t145,  1(I32)
	c0    add $r0.3 = $r0.3, 4   ## bblock 14, line 0,  t142,  t142,  4(I32)
	c0    brf $b0.1, L4?3   ## bblock 12, line 22-1,  t216(I1)
;;								## 9
L5?3:
	c0    cmpgt $r0.7 = $r0.6, $r0.0   ## bblock 27, line 24-1,  t73(I1),  t145,  0(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 27, line 24-1, t25, t142
	      xnop 2
;;								## 12
	c0    cmpgt $r0.13 = $r0.4, $r0.13   ## bblock 27, line 24-1,  t74(I1),  t25,  t28
;;								## 13
	c0    norl $r0.7 = $r0.7, $r0.13   ## bblock 27, line 24-1,  t76(I1),  t73(I1),  t74(I1)
;;								## 14
	c0    norl $b0.1 = $r0.12, $r0.7   ## bblock 27, line 24-1,  t223(I1),  t75(I1),  t76(I1)
	      xnop 1
;;								## 16
	c0    br $b0.1, L6?3   ## bblock 27, line 24-1,  t223(I1)
;;								## 17
	c0    stw 4[$r0.10] = $r0.4   ## bblock 30, line 26-1, t141, t25
	c0    add $r0.6 = $r0.6, 1   ## bblock 30, line 0,  t145,  t145,  1(I32)
	c0    add $r0.3 = $r0.3, 4   ## bblock 30, line 0,  t142,  t142,  4(I32)
	c0    brf $b0.2, L7?3   ## bblock 29, line 22-2,  t224(I1)
;;								## 18
L8?3:
	c0    cmpgt $r0.7 = $r0.6, $r0.0   ## bblock 21, line 24-2,  t90(I1),  t145,  0(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 21, line 24-2, t89, t142
	      xnop 2
;;								## 21
	c0    cmpgt $r0.15 = $r0.4, $r0.15   ## bblock 21, line 24-2,  t84(I1),  t89,  t85
;;								## 22
	c0    norl $r0.7 = $r0.7, $r0.15   ## bblock 21, line 24-2,  t83(I1),  t90(I1),  t84(I1)
;;								## 23
	c0    norl $b0.1 = $r0.14, $r0.7   ## bblock 21, line 24-2,  t220(I1),  t91(I1),  t83(I1)
	      xnop 1
;;								## 25
	c0    br $b0.1, L9?3   ## bblock 21, line 24-2,  t220(I1)
;;								## 26
	c0    stw 8[$r0.10] = $r0.4   ## bblock 24, line 26-2, t141, t89
	c0    add $r0.6 = $r0.6, 1   ## bblock 24, line 0,  t145,  t145,  1(I32)
	c0    add $r0.3 = $r0.3, 4   ## bblock 24, line 0,  t142,  t142,  4(I32)
	c0    brf $b0.0, L10?3   ## bblock 23, line 22-3,  t221(I1)
;;								## 27
L11?3:
	c0    cmpgt $r0.7 = $r0.6, $r0.0   ## bblock 13, line 24-3,  t100(I1),  t145,  0(SI32)
	c0    ldw.d $r0.4 = 0[$r0.3]   ## [spec] bblock 13, line 24-3, t99, t142
	      xnop 2
;;								## 30
	c0    cmpgt $r0.17 = $r0.4, $r0.17   ## bblock 13, line 24-3,  t94(I1),  t99,  t97
;;								## 31
	c0    norl $r0.7 = $r0.7, $r0.17   ## bblock 13, line 24-3,  t93(I1),  t100(I1),  t94(I1)
;;								## 32
	c0    norl $b0.0 = $r0.16, $r0.7   ## bblock 13, line 24-3,  t218(I1),  t101(I1),  t93(I1)
	      xnop 1
;;								## 34
	c0    br $b0.0, L12?3   ## bblock 13, line 24-3,  t218(I1)
;;								## 35
	c0    stw 12[$r0.10] = $r0.4   ## bblock 18, line 26-3, t141, t99
	c0    add $r0.6 = $r0.6, 1   ## bblock 18, line 0,  t145,  t145,  1(I32)
	c0    add $r0.3 = $r0.3, 4   ## bblock 18, line 0,  t142,  t142,  4(I32)
	c0    add $r0.2 = $r0.2, 4   ## bblock 17, line 0,  t146,  t146,  4(I32)
;;								## 36
L13?3:
	c0    add $r0.10 = $r0.10, 16   ## bblock 17, line 0,  t141,  t141,  16(I32)
	c0    goto L1?3 ## goto
;;								## 37
.trace 8
L12?3:
	c0    ldw $r0.4 = 0[$r0.5]   ## bblock 16, line 31-3, t92, t143
	c0    add $r0.8 = $r0.8, 1   ## bblock 16, line 0,  t144,  t144,  1(I32)
	c0    add $r0.5 = $r0.5, 4   ## bblock 16, line 0,  t143,  t143,  4(I32)
	c0    add $r0.2 = $r0.2, 4   ## bblock 17, line 0,  t146,  t146,  4(I32)
	      xnop 2
;;								## 2
	c0    stw 12[$r0.10] = $r0.4   ## bblock 16, line 31-3, t141, t92
	c0    goto L13?3 ## goto
;;								## 3
.trace 16
L10?3:
	c0    sub $r0.19 = 3, $r0.19   ## bblock 5, line 0,  t115,  3(I32),  t67
	c0    sh2add $r0.5 = $r0.18, (A + 0)   ## bblock 5, line 0,  t113,  t66,  addr(A?1.0)(P32)
;;								## 0
	c0    add $r0.4 = $r0.18, $r0.19   ## bblock 5, line 0,  t114,  t66,  t115
	c0    sh2add $r0.2 = $r0.18, (B + 0)   ## bblock 5, line 0,  t112,  t66,  addr(B?1.0)(P32)
;;								## 1
.trace 2
L14?3:
	c0    cmple $b0.0 = $r0.4, 3   ## bblock 6, line 35,  t212(I1),  t114,  3(SI32)
	c0    ldw.d $r0.3 = 0[$r0.2]   ## [spec] bblock 8, line 36, t50, t112
	c0    cmple $b0.1 = $r0.4, 2   ## [spec] bblock 8, line 35-1,  t213(I1),  t114,  2(SI32)
	c0    cmple $b0.2 = $r0.4, 1   ## [spec] bblock 40, line 35-2,  t226(I1),  t114,  1(SI32)
;;								## 0
	c0    ldw.d $r0.6 = 4[$r0.2]   ## [spec] bblock 40, line 36-1, t107, t112
	c0    cmple $b0.3 = $r0.4, $r0.0   ## [spec] bblock 37, line 35-3,  t225(I1),  t114,  0(SI32)
	c0    add $r0.4 = $r0.4, 4   ## [spec] bblock 34, line 0,  t114,  t114,  4(I32)
;;								## 1
	c0    ldw.d $r0.7 = 8[$r0.2]   ## [spec] bblock 37, line 36-2, t105, t112
	c0    brf $b0.0, L15?3   ## bblock 6, line 35,  t212(I1)
;;								## 2
	c0    ldw.d $r0.8 = 12[$r0.2]   ## [spec] bblock 34, line 36-3, t104, t112
	c0    add $r0.2 = $r0.2, 16   ## [spec] bblock 34, line 0,  t112,  t112,  16(I32)
;;								## 3
	c0    stw 0[$r0.5] = $r0.3   ## bblock 8, line 36, t113, t50
	c0    brf $b0.1, L16?3   ## bblock 8, line 35-1,  t213(I1)
;;								## 4
	c0    stw 4[$r0.5] = $r0.6   ## bblock 40, line 36-1, t113, t107
	c0    brf $b0.2, L17?3   ## bblock 40, line 35-2,  t226(I1)
;;								## 5
	c0    stw 8[$r0.5] = $r0.7   ## bblock 37, line 36-2, t113, t105
	c0    brf $b0.3, L18?3   ## bblock 37, line 35-3,  t225(I1)
;;								## 6
	c0    stw 12[$r0.5] = $r0.8   ## bblock 34, line 36-3, t113, t104
	c0    add $r0.5 = $r0.5, 16   ## bblock 34, line 0,  t113,  t113,  16(I32)
	c0    goto L14?3 ## goto
;;								## 7
.trace 19
L18?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t53
	      xnop 2
;;								## 2
	c0    goto L19?3 ## goto
;;								## 3
.trace 18
L17?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t53
	      xnop 2
;;								## 2
	c0    goto L19?3 ## goto
;;								## 3
.trace 15
L16?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t53
	      xnop 2
;;								## 2
	c0    goto L19?3 ## goto
;;								## 3
.trace 12
L15?3:
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t53
	      xnop 3
;;								## 3
L19?3:
.return ret()
	c0    return $r0.1 = $r0.1, (0x40), $l0.0   ## bblock 7, line 37,  t54,  ?2.1?2auto_size(I32),  t53
;;								## 4
.trace 7
L9?3:
	c0    ldw $r0.4 = 0[$r0.5]   ## bblock 22, line 31-2, t81, t143
	c0    add $r0.8 = $r0.8, 1   ## bblock 22, line 0,  t144,  t144,  1(I32)
	c0    add $r0.5 = $r0.5, 4   ## bblock 22, line 0,  t143,  t143,  4(I32)
;;								## 0
	c0    cmpgt $r0.16 = $r0.8, $r0.0   ## [spec] bblock 13, line 24-3,  t101(I1),  t144,  0(SI32)
	c0    ldw.d $r0.17 = 0[$r0.5]   ## [spec] bblock 13, line 24-3, t97, t143
	      xnop 1
;;								## 2
	c0    stw 8[$r0.10] = $r0.4   ## bblock 22, line 31-2, t141, t81
	c0    brf $b0.0, L10?3   ## bblock 23, line 22-3,  t221(I1)
	      ## goto
;;
	c0    goto L11?3 ## goto
;;								## 3
.trace 14
L7?3:
	c0    sub $r0.19 = 3, $r0.19   ## bblock 5, line 0,  t115,  3(I32),  t67
	c0    sh2add $r0.5 = $r0.18, (A + 0)   ## bblock 5, line 0,  t113,  t66,  addr(A?1.0)(P32)
;;								## 0
	c0    add $r0.4 = $r0.18, $r0.19   ## bblock 5, line 0,  t114,  t66,  t115
	c0    sh2add $r0.2 = $r0.18, (B + 0)   ## bblock 5, line 0,  t112,  t66,  addr(B?1.0)(P32)
	c0    goto L14?3 ## goto
;;								## 1
.trace 6
L6?3:
	c0    ldw $r0.4 = 0[$r0.5]   ## bblock 28, line 31-1, t38, t143
	c0    add $r0.8 = $r0.8, 1   ## bblock 28, line 0,  t144,  t144,  1(I32)
	c0    add $r0.5 = $r0.5, 4   ## bblock 28, line 0,  t143,  t143,  4(I32)
;;								## 0
	c0    cmpgt $r0.14 = $r0.8, $r0.0   ## [spec] bblock 21, line 24-2,  t91(I1),  t144,  0(SI32)
	c0    ldw.d $r0.15 = 0[$r0.5]   ## [spec] bblock 21, line 24-2, t85, t143
	c0    cmpgt $r0.16 = $r0.8, $r0.0   ## [spec] bblock 13, line 24-3,  t101(I1),  t144,  0(SI32)
;;								## 1
	c0    ldw.d $r0.17 = 0[$r0.5]   ## [spec] bblock 13, line 24-3, t97, t143
;;								## 2
	c0    stw 4[$r0.10] = $r0.4   ## bblock 28, line 31-1, t141, t38
	c0    brf $b0.2, L20?3   ## bblock 29, line 22-2,  t224(I1)
;;								## 3
	c0    goto L8?3 ## goto
;;								## 4
.trace 21
L20?3:
	c0    goto L7?3 ## goto
;;								## 0
.trace 13
L4?3:
	c0    sub $r0.19 = 3, $r0.19   ## bblock 5, line 0,  t115,  3(I32),  t67
	c0    sh2add $r0.5 = $r0.18, (A + 0)   ## bblock 5, line 0,  t113,  t66,  addr(A?1.0)(P32)
;;								## 0
	c0    add $r0.4 = $r0.18, $r0.19   ## bblock 5, line 0,  t114,  t66,  t115
	c0    sh2add $r0.2 = $r0.18, (B + 0)   ## bblock 5, line 0,  t112,  t66,  addr(B?1.0)(P32)
	c0    goto L14?3 ## goto
;;								## 1
.trace 5
L3?3:
	c0    ldw $r0.4 = 0[$r0.5]   ## bblock 11, line 31, t95, t143
	c0    add $r0.8 = $r0.8, 1   ## bblock 11, line 0,  t144,  t144,  1(I32)
	c0    add $r0.5 = $r0.5, 4   ## bblock 11, line 0,  t143,  t143,  4(I32)
;;								## 0
	c0    cmpgt $r0.12 = $r0.8, $r0.0   ## [spec] bblock 27, line 24-1,  t75(I1),  t144,  0(SI32)
	c0    ldw.d $r0.13 = 0[$r0.5]   ## [spec] bblock 27, line 24-1, t28, t143
	c0    cmpgt $r0.14 = $r0.8, $r0.0   ## [spec] bblock 21, line 24-2,  t91(I1),  t144,  0(SI32)
	c0    cmpgt $r0.16 = $r0.8, $r0.0   ## [spec] bblock 13, line 24-3,  t101(I1),  t144,  0(SI32)
;;								## 1
	c0    ldw.d $r0.15 = 0[$r0.5]   ## [spec] bblock 21, line 24-2, t85, t143
;;								## 2
	c0    ldw.d $r0.17 = 0[$r0.5]   ## [spec] bblock 13, line 24-3, t97, t143
;;								## 3
	c0    stw 0[$r0.10] = $r0.4   ## bblock 11, line 31, t141, t95
	c0    brf $b0.1, L21?3   ## bblock 12, line 22-1,  t216(I1)
;;								## 4
	c0    goto L5?3 ## goto
;;								## 5
.trace 20
L21?3:
	c0    goto L4?3 ## goto
;;								## 0
.trace 11
L2?3:
	c0    sub $r0.19 = 3, $r0.19   ## bblock 5, line 0,  t115,  3(I32),  t67
	c0    sh2add $r0.5 = $r0.18, (A + 0)   ## bblock 5, line 0,  t113,  t66,  addr(A?1.0)(P32)
;;								## 0
	c0    add $r0.4 = $r0.18, $r0.19   ## bblock 5, line 0,  t114,  t66,  t115
	c0    sh2add $r0.2 = $r0.18, (B + 0)   ## bblock 5, line 0,  t112,  t66,  addr(B?1.0)(P32)
	c0    goto L14?3 ## goto
;;								## 1
.endp
.section .bss
.section .data
.equ ?2.1?2scratch.0, 0x0
.equ ?2.1?2ras_p, 0x10
.equ ?2.1?2spill_p, 0x14
.section .data
.section .text
.equ ?2.1?2auto_size, 0x40
 ## End mergesort
 ## Begin main
.section .text
.proc
.entry caller, sp=$r0.1, rl=$l0.0, asize=-32, arg()
main::
.trace 1
	c0    add $r0.1 = $r0.1, (-0x20)
	c0    mov $r0.4 = 255   ## 255(SI32)
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
;;								## 0
.call mergesort, caller, arg($r0.3:s32,$r0.4:s32), ret()
	c0    call $l0.0 = mergesort   ## bblock 0, line 41,  raddr(mergesort)(P32),  0(SI32),  255(SI32)
	c0    stw 0x10[$r0.1] = $l0.0  ## spill ## t0
;;								## 1
	c0    mov $r0.3 = $r0.0   ## 0(SI32)
	c0    ldw $l0.0 = 0x10[$r0.1]  ## restore ## t0
	      xnop 3
;;								## 5
.return ret($r0.3:s32)
	c0    return $r0.1 = $r0.1, (0x20), $l0.0   ## bblock 1, line 43,  t1,  ?2.2?2auto_size(I32),  t0
;;								## 6
.endp
.section .bss
.section .data
.equ ?2.2?2scratch.0, 0x0
.equ ?2.2?2ras_p, 0x10
.section .data
.section .text
.equ ?2.2?2auto_size, 0x20
 ## End main
.section .bss
.section .data
.section .data
.comm B, 0x2625a04, 4
.comm A, 0x2625a04, 4
.section .text
.import mergesort
.type mergesort,@function
