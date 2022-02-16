function result = expxitheta(omega,q,theta)
v = -cross(omega,q);

omegahat = SKEW3(omega);

xihat = [ omegahat, v; 0  0  0  0];

result = eye(4) + theta * xihat + ( 1 - cos(theta)) * ((xihat)^2)...
                + ( theta - sin(theta)) * (xihat)^3;

end

function skew = SKEW3(x)

% calculate the exponential map for given vector x

skew = [ 0 -x(3) x(2); x(3) 0 -x(1); -x(2) x(1) 0];

end
