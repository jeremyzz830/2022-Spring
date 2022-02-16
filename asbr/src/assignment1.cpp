/**
   EN.601.463/663
   Assignment #1 

   Cartesian trajectory generation
   
 */
#include "assignment1.hpp"

// Compute the forward kinematics (position and orientation)
// input: the joints angles
// output: the 4x4 homogeneous transformation
void ForwardKinematics( double q1, double q2, double q3, double E[4][4] ){
  
  // TODO
  // Fill the values of the forward kinematics (homogeneous matrix E)
	double E_temp[4][4] = {{   sin(q1)*(cos(q3) + (3*sin(q3))/2000) - cos(q1)*((17*sin(q2))/2000 + cos(q2)*((3*cos(q3))/2000 - sin(q3))),   sin(q1)*((7*cos(q3))/5000 - (9999*sin(q3))/10000) - cos(q1)*((113*sin(q2))/10000 - cos(q2)*((9999*cos(q3))/10000 + (7*sin(q3))/5000)), sin(q1)*((17*cos(q3))/2000 - (113*sin(q3))/10000) + cos(q1)*((9999*sin(q2))/10000 + cos(q2)*((113*cos(q3))/10000 + (17*sin(q3))/2000)), cos(q1)*((293*sin(q2))/1000 + cos(q2)*((457*cos(q3))/500 - (2277*sin(q3))/10000)) - sin(q1)*((2277*cos(q3))/10000 + (457*sin(q3))/500 - 1197/10000)},
{- cos(q1)*(cos(q3) + (3*sin(q3))/2000) - sin(q1)*((17*sin(q2))/2000 + cos(q2)*((3*cos(q3))/2000 - sin(q3))), - cos(q1)*((7*cos(q3))/5000 - (9999*sin(q3))/10000) - sin(q1)*((113*sin(q2))/10000 - cos(q2)*((9999*cos(q3))/10000 + (7*sin(q3))/5000)), sin(q1)*((9999*sin(q2))/10000 + cos(q2)*((113*cos(q3))/10000 + (17*sin(q3))/2000)) - cos(q1)*((17*cos(q3))/2000 - (113*sin(q3))/10000), cos(q1)*((2277*cos(q3))/10000 + (457*sin(q3))/500 - 1197/10000) + sin(q1)*((293*sin(q2))/1000 + cos(q2)*((457*cos(q3))/500 - (2277*sin(q3))/10000))},
{sin(q2)*((3*cos(q3))/2000 - sin(q3)) - (17*cos(q2))/2000, - (113*cos(q2))/10000 - sin(q2)*((9999*cos(q3))/10000 + (7*sin(q3))/5000), (9999*cos(q2))/10000 - sin(q2)*((113*cos(q3))/10000 + (17*sin(q3))/2000), (293*cos(q2))/1000 - sin(q2)*((457*cos(q3))/500 - (2277*sin(q3))/10000)}
{0,0,0,1}};

for( int i = 0; i <= 3; i++){

	for( int j = 0; j <= 3; j++){
		E[i][j] = E_temp[i][j];		
	}
}
  
}

// Compute the inverse of the forward kinematics (position and orientation)
// input: the joints angles
// output: the 4x4 homogeneous transformation
void ForwardKinematicsInverse( double q1, double q2, double q3, double E[4][4] ){

  // TODO
  // Fill the values of the inverse of the forward kinematics (homogeneous matrix E)

double E_temp[4][4] = {{ (99992770000*cos(q3)*sin(q1))/100000205217 - (848333000*cos(q1)*sin(q2))/100000205217 + (149591000*sin(q1)*sin(q3))/100000205217 - (149591000*cos(q1)*cos(q2)*cos(q3))/100000205217 + (99992770000*cos(q1)*cos(q2)*sin(q3))/100000205217,  (99992770000*cos(q2)*sin(q1)*sin(q3))/100000205217 - (149591000*cos(q1)*sin(q3))/100000205217 - (848333000*sin(q1)*sin(q2))/100000205217 - (149591000*cos(q2)*cos(q3)*sin(q1))/100000205217 - (99992770000*cos(q1)*cos(q3))/100000205217,    (149591000*cos(q3)*sin(q2))/100000205217 - (848333000*cos(q2))/100000205217 - (99992770000*sin(q2)*sin(q3))/100000205217, 23153641472/100000205217 - (19895603*sin(q3))/111111339130 - (1329903841*cos(q3))/11111133913},{(140380000*cos(q3)*sin(q1))/100000205217 - (1131275000*cos(q1)*sin(q2))/100000205217 - (99997225000*sin(q1)*sin(q3))/100000205217 + (99997225000*cos(q1)*cos(q2)*cos(q3))/100000205217 + (140380000*cos(q1)*cos(q2)*sin(q3))/100000205217, (99997225000*cos(q1)*sin(q3))/100000205217 - (140380000*cos(q1)*cos(q3))/100000205217 - (1131275000*sin(q1)*sin(q2))/100000205217 + (99997225000*cos(q2)*cos(q3)*sin(q1))/100000205217 + (140380000*cos(q2)*sin(q1)*sin(q3))/100000205217, - (1131275000*cos(q2))/100000205217 - (99997225000*cos(q3)*sin(q2))/100000205217 - (140380000*sin(q2)*sin(q3))/100000205217,   (2659926185*sin(q3))/22222267826 - (1867054*cos(q3))/11111133913 - 91034035549/100000205217},{        (33330070000*cos(q1)*sin(q2))/33333401739 + (283870000*cos(q3)*sin(q1))/33333401739 - (376270000*sin(q1)*sin(q3))/33333401739 + (376270000*cos(q1)*cos(q2)*cos(q3))/33333401739 + (283870000*cos(q1)*cos(q2)*sin(q3))/33333401739,         (376270000*cos(q1)*sin(q3))/33333401739 - (283870000*cos(q1)*cos(q3))/33333401739 + (33330070000*sin(q1)*sin(q2))/33333401739 + (376270000*cos(q2)*cos(q3)*sin(q1))/33333401739 + (283870000*cos(q2)*sin(q1)*sin(q3))/33333401739,       (33330070000*cos(q2))/33333401739 - (376270000*cos(q3)*sin(q2))/33333401739 - (283870000*sin(q2)*sin(q3))/33333401739,     (15013173*sin(q3))/11111133913 - (11326413*cos(q3))/11111133913 - 10044984091/33333401739},{0,0,0,1}                                                                                                                                                                                                                                  
};

for( int i = 0; i <= 3; i++){

	for( int j = 0; j <= 3; j++){
		E[i][j] = E_temp[i][j];		
	}
}
}

// Compute the Adjoint transformation inverse matrix
// input E: the rotation/translation between the base and the hand frame
//          (as computed by the forward kinematics)
// output Ad: the 6x6 adjoint transformation inverse matrix
void AdjointTransformationInverse( double E[4][4], double Ad[6][6] ){

  // TODO
  // Compute the Adjoint Transformation Inverse A^-1
	double r00, r01, r02, r10, r11, r12, r20, r21, r22;
	double p1, p2, p3;
	r00 = E[0][0]; r01 = E[0][1]; r02 = E[0][2];
	r10 = E[1][0]; r11 = E[1][1]; r12 = E[1][2];
	r20 = E[2][0]; r21 = E[2][1]; r22 = E[2][2];
	p1 = E[0][3]; p2 = E[1][3]; p3 = E[2][3];


double Ad_temp[6][6] = {{ r00, r10, r20, p2*r20 - p3*r10, p3*r00 - p1*r20, p1*r10 - p2*r00},
{ r01, r11, r21, p2*r21 - p3*r11, p3*r01 - p1*r21, p1*r11 - p2*r01},
{ r02, r12, r22, p2*r22 - p3*r12, p3*r02 - p1*r22, p1*r12 - p2*r02},
{   0,   0,   0,             r00,             r10,             r20},
{   0,   0,   0,             r01,             r11,             r21},
{   0,   0,   0,             r02,             r12,             r22}};


for( int i = 0; i <= 5; i++){

	for( int j = 0; j <= 5; j++){
		Ad[i][j] = Ad_temp[i][j];		
	}
}

  
}

// Compute and return the Jacobian of the robot given the current joint 
// positions
// input: the joints angles
// output: the 6x3 Jacobian (position only)
void Jacobian( double q1, double q2, double q3, double J[6][3] ){
  
  // TODO
  // Fill the values of the Jacobian matrix J

}

