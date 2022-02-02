#include <week01/publisher.hpp>

rsp::publisher::publisher(ros::NodeHandle& nh){

    pub = nh.advertise<std_msgs::String>("headline",10);

}

rsp::publisher::~publisher(){}

void rsp::publisher::publish(){

    std_msgs::String s;
    s.data = "Breaking news!";

    pub.publish( s );
}