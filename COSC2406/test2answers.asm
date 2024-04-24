; Q5
; A = -( E + F % G ) * ( B - D )
mov     ax, F 
cwd
idiv    G
mov     ax, dx
add     ax, E
neg     ax 

mov     dx, b
sub     dx, D 
imul    dx
mov     A, ax
