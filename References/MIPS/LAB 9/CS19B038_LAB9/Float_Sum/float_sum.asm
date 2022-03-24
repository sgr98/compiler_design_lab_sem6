; -----------------------------------------------------------------------------
; I have read it and understood it.
; -----------------------------------------------------------------------------

        global  float_sum
        section .text
float_sum:
        xorpd   xmm0, xmm0              ; initialize the sum register to 0
        addsd   xmm0, rdi               ; Add a to 0
        addsd   xmm0, rsi               ; Add b to a
        ret                             ; return value already in xmm0