#include <rtt_rsp/rtt_sensor.hpp>
#include <rtt_sensor/Component.hpp>

rtt_sensor::rtt_sensor( const std::string& name):
    RTT::TaskContext( name ),
    port_msr_wrench("Measured wrench"){

    addPort("MsrWrench", port_msr_wrench);

    std::cout<<"rtt_sensor::rtt_sensor"<< std::endl;

}

rtt_sensor::~rtt_sensor(){};

bool rtt_sensor::configureHook(){};
bool rtt_sensor::startHook(){};
void rtt_sensor::updateHook(){};
void rtt_sensor::stopHook(){};
void rtt_sensor::cleanupHook(){};

ORO_CREATE_COMPONENT