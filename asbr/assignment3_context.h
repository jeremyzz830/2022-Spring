#include <ros/ros.h>
#include <moveit/planning_interface/planning_interface.h>

#include <random>

MOVEIT_CLASS_FORWARD( CS436Context );

class CS436Context : public planning_interface::PlanningContext {

public:

  typedef double weight;
  typedef std::size_t index;
  typedef std::vector<double> vertex;
  typedef std::vector<vertex> path;

  CS436Context( const robot_model::RobotModelConstPtr& model, 
		const std::string &name, 
		const std::string& group, 
		const ros::NodeHandle &nh = ros::NodeHandle("~") );
  virtual ~CS436Context();

  virtual bool solve( planning_interface::MotionPlanResponse &res );
  virtual bool solve( planning_interface::MotionPlanDetailedResponse &res );

  virtual void clear();
  virtual bool terminate();

  /**
     Utility method
     Determine if a configuration collides with obstacles.

     \input q Robot configuration
     \return True if the robot collides with an obstacle. False otherwise.
  */
  bool is_colliding( const vertex& q ) const;

  /**
     Utility method
     Interpolate between two configurations.

     \input qA The first configuration
     \input qB The second configuration
     \input t The interpolation parameter t=[0,1]
     \return The interpolated configuration
  */
  vertex interpolate( const vertex& qA, const vertex& qB, double t );

  /**
     TODO

     Sample a configuration according to a probability density function provided by the 
     configuration weights.

     \input weights A vector of weights. w[i] is the weight of ith configuration
     \return The index of the randomly chosen configuration
  */
  index select_config_from_tree( const std::vector<weight>& w );
  
  /**
     TODO

     Create a random sample. The returned vertex represents a collision-free
     configuration (i.e. 6 joints) of the robot.
     \return  A collision-free configuration
  */
  vertex sample_nearby( const vertex& q );

  /**
     TODO

     Determine if a straight line path is collision-free between two configurations.
     \input q_near The first configuration
     \input q_rand The second configuration
     \return True if the path is collision-free. False otherwise.
  */
  bool is_local_path_collision_free( const vertex& q, const vertex& q_rand );
  
  /**
     TODO
     
     Once the goal configuration has been added to the tree. Search the tree to find and return the 
     path between the root (q_init) and the goal (q_goal).
     \input q_init The root configuration
     \input q_goal The goal configuration
     \return The path (a sequence of configurations) between q_init and q_goal.
  */
  path search_path( const std::vector<vertex>& V,
		    const index& idx_init,
		    const index& idx_goal );

  /**
     TODO
     
     This is the main RRT algorithm that adds vertices/edges to a tree and searches for a path.
     \input q_init The initial configuration
     \input q_goal The goal configuration
     \return The path between q_init and q_goal
  */
  path est( const vertex& q_init, const vertex& q_goal );
  
 protected:

  robot_model::RobotModelConstPtr robotmodel;

};

