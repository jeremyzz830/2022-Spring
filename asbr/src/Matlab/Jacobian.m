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

w(1)={[0;0;1]};
q(1)={[0;0;l0]};
w(2)={[0;1;0]};
q(2)={[0;l1;0]};
w(3)={[0;0;1]};
q(3)={[0;-l3;l2]};
joint = [ q1; q2; q3 ];
g_st0 = [-0.0015    0.9999    0.0113, 0.914;
        -1.0000   -0.0014   -0.0085 , 0.108;
        -0.0085   -0.0113    0.9999, 0.293;
        0 0 0 1];

    
syms xi_prime;
    

xi_prime_hat=inv(g_st0)*expxitheta(-w{3},q{3},joint(3))*...
    [hat(w{3}),-hat(w{3})*q{3};[0,0,0],0]*...
    expxitheta(w{3},q{3},joint(3))*g_st0;
xi_prime(1:3,3)=xi_prime_hat(1:3,4);
xi_prime(4:6,3)=dehat(xi_prime_hat(1:3,1:3));

xi_prime_hat = inv(g_st0)*expxitheta(-w{3},q{3},joint(3))*...
    expxitheta(-w{2},q{2},joint(2))*...
    [hat(w{2}),-hat(w{2})*q{2};[0,0,0],0]*...
    expxitheta(-w{2},q{2},joint(2))*...
    expxitheta(w{3},q{3},joint(3))*g_st0;
xi_prime(1:3,2)=xi_prime_hat(1:3,4);
xi_prime(4:6,2)=dehat(xi_prime_hat(1:3,1:3));

xi_prime_hat = inv(g_st0)*expxitheta(-w{3},q{3},joint(3))*...
    expxitheta(-w{2},q{2},joint(2))*...
    expxitheta(-w{1},q{1},joint(1))*...
    [hat(w{1}),-hat(w{1})*q{1};[0,0,0],0]*...
    expxitheta(-w{1},q{1},joint(1))*...
    expxitheta(-w{2},q{2},joint(2))*...
    expxitheta(w{3},q{3},joint(3))*g_st0;
xi_prime(1:3,1)=xi_prime_hat(1:3,4);
xi_prime(4:6,1)=dehat(xi_prime_hat(1:3,1:3));

vpa(xi_prime,4)




    