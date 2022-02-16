clear;
clc;
syms q1 q2 q3 real;

l0=0.089159;
l1=0.135850;
l2=0.425;
l3=0.1197;
l4=0.485779;
l5=0.092989;
l6=0.212543;

%% Forward Kinematics
w(1)={[0;0;1]};
q(1)={[0;0;l0]};
w(2)={[0;1;0]};
q(2)={[0;l1;0]};
w(3)={[0;0;1]};
q(3)={[0;-l3;l2]};
joint = [ q1; q2; q3 ];

% use poe to calculate transformation for first three joint
g_st0 = [-0.0015    0.9999    0.0113, 0.914;
        -1.0000   -0.0014   -0.0085 , 0.108;
        -0.0085   -0.0113    0.9999, 0.293;
        0 0 0 1];  

g = g_st0;

for i = 3:-1:1
    
    g = expxitheta(w{i},q{i},joint(i)) * g;
    
end

result = simplify(g)
result = simplify(inv(g))