#include <ros/ros.h>
#include <std_msgs/String.h>

namespace rsp{
    // declaration of publisher class
    class publisher{
    
    private:
        ros::NodeHandle nh;
        ros::Publisher pub;

    public:
        publisher( ros::NodeHandle& nh );
        ~publisher();
        void publish();
    };
};