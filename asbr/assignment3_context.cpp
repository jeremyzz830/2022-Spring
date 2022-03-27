#include "assignment3_context.h"
#include <moveit_msgs/RobotTrajectory.h>
#include <moveit/planning_scene/planning_scene.h>


// utility function to test for a collision
bool CS436Context::is_colliding( const vertex& q ) const {
  moveit::core::RobotState robotstate( robotmodel );
  robotstate.setJointGroupPositions( "manipulator", q );

  if( getPlanningScene()->isStateColliding( robotstate, "manipulator", false ) )
    { return true; }
  else
    { return false; }
}

// utility function to interpolate between two configurations
CS436Context::vertex CS436Context::interpolate( const CS436Context::vertex& qA,
						const CS436Context::vertex& qB,
						double t ){
  CS436Context::vertex qt( qA.size(), 0.0 );
  for( std::size_t i=0; i<qt.size(); i++ )
    { qt[i] = ( 1.0 - t )*qA[i] + t*qB[i]; }
  return qt;
}

CS436Context::CS436Context( const robot_model::RobotModelConstPtr& robotmodel,
			    const std::string& name, 
			    const std::string& group, 
			    const ros::NodeHandle& nh ) :
  planning_interface::PlanningContext( name, group ),
  robotmodel( robotmodel ){}

CS436Context::~CS436Context(){}


// TODO
CS436Context::index CS436Context::select_config_from_tree( const std::vector<CS436Context::weight>& w ){
  CS436Context::index i;

  // TODO
  // Use the weights to return the index of a configuration in the tree
  std::discrete_distribution<double> dist{std::begin(w), std::end(w)};

  std::random_device rd;
  std::default_random_engine rand_eng{ rd() };

  i = dist(rand_eng);
  return i;
}


// TODO
CS436Context::vertex CS436Context::sample_nearby( const CS436Context::vertex& q ){
  CS436Context::vertex q_rand;

  // TODO
  // Generate a random configuration near q
  constexpr int FLOAT_MIN = 0;
  constexpr int FLOAT_MAX = 1;

  std::uniform_real_distribution<float> 

  return q_rand;
}

// TODO
bool CS436Context::is_local_path_collision_free( const CS436Context::vertex& q,
						 const CS436Context::vertex& q_rand ){
  bool collision_free;
  
  // return true/false if the local path between q and q_rand is collision free
  
  return collision_free;
}


// TODO
CS436Context::path CS436Context::search_path( const std::vector<vertex>& V,
 					      const index& idx_init,
					      const index& idx_goal ){
  CS436Context::path P;
  
  // TODO
  // find and return a path (ordered sequence of configurations) between the indices
  
  return P;
}

// TODO
CS436Context::path CS436Context::est( const CS436Context::vertex& q_init,
 				      const CS436Context::vertex& q_goal ){
  CS436Context::path P;

  // TODO implement EST algorithm and return the path (an ordered sequence of configurations).

  return P;
}

// This is the method that is called each time a plan is requested
// You should not need to modify code below this (but it's ok of you absolutely need to).
bool CS436Context::solve( planning_interface::MotionPlanResponse &res ){

  // Create a new empty trajectory
  res.trajectory_.reset(new robot_trajectory::RobotTrajectory(robotmodel, getGroupName()));
  res.trajectory_->clear();

  // copy the initial/final joints configurations to vectors qfin and qini
  // This is mainly for convenience.
  vertex q_init, q_goal;
  for( size_t i=0; i<robotmodel->getVariableCount(); i++ ){
    q_goal.push_back(request_.goal_constraints[0].joint_constraints[i].position);
    q_init.push_back(request_.start_state.joint_state.position[i]);
  }

  // start the timer
  ros::Time begin = ros::Time::now();

  path P = est( q_init, q_goal );

  // end the timer
  ros::Time end = ros::Time::now();

  // The rest is to fill in the animation. You can ignore this part.
  moveit::core::RobotState robotstate( robotmodel );
  robotstate.setJointGroupPositions( "manipulator", q_init );

  for( std::size_t i=1; i<P.size(); i++ ){
    for( double t=0.0; t<=1.0; t+=0.01 ){
      vertex q = interpolate( P[i-1], P[i], t );
      robotstate.setJointGroupPositions( "manipulator", q );
      res.trajectory_->addSuffixWayPoint( robotstate, 0.01 );
    }
  }
  
  // set the planning time
  ros::Duration duration = end-begin;
  res.planning_time_ = duration.toSec();
  res.error_code_.val = moveit_msgs::MoveItErrorCodes::SUCCESS;

  return true;
  
}

bool CS436Context::solve( planning_interface::MotionPlanDetailedResponse &res )
{ return true; }

void CS436Context::clear(){}

bool CS436Context::terminate(){return true;}
