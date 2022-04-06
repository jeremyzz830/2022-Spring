#include <ros/ros.h>
#include <geometry_msgs/WrenchStamped.h>
#include <rtt/TaskContext.hpp>
#include <rtt_sensor.hpp>/OutputPort>

class rtt_sensor : public RTT::TaskContext {

private:
    RTT:OutputPort<geometry_msgs::WrenchStamped> port_msr_wrench;

public:

    rtt_sensor( const std::string& name);
    ~rtt_sensor();

    virtual bool configureHook();
    virtual bool startHook();

    virtual void updateHook();

    virtual void stopHook();
    virtual void cleanupHook();

};
