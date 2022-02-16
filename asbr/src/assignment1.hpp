
#include <tf/transform_datatypes.h>

void ForwardKinematics( double q1, double q2, double q3, double E[4][4] );
void ForwardKinematicsInverse( double q1, double q2, double q3, double E[4][4] );
void AdjointTransformationInverse( double E[4][4], double Ad[6][6] );
void Jacobian( double q1, double q2, double q3, double J[6][3] );

