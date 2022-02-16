clear;
syms r00 r01 r02 r10 r11 r12 r20 r21 r22 p1 p2 p3 real;

R = [r00 r01 r02; r10 r11 r12; r20 r21 r22];

phat = [ 0 -p3 p2; p3 0 -p1; -p2 p1 0];

adg = [ R' -R'*phat; zeros(3) R']