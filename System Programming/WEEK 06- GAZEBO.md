<h1 align="center"> SYSTEM PROGRAMMING WEEK 06 </h1>
<h2 align="center"> GAZEBO </h2>
<h5 align="right"> -- by Jeremy Zhang @ Johns Hopkins University</h5>


---

# I. Gazebo

Dynamic Simulation that gazebo relies on

-  __[Open Dynamic Engine](https://www.ode.org/)__  

- __[Bullet Real-time Physics](https://pybullet.org/wordpress/)__ 

gazebo is independent, it just behaves well on ROS

gazebo message in ROS is based on client-service system in ROS.

Rviz is a visualization process, it doesn't provide any dynamics simulation, which normally done by gazebo.

```bash
1. gzserver #  start the gazebo server to process the dynamics of the system
2. gzclient
3. gazebo # this command is just a visualization part
```

For any robotics projects, it's better to perform some simulation first.

You are allowed to create plugins to start along with gazebo so that you can put some sensor data in it 

```bash
rosrun gazebo_ros
rosrun gezebo ros_service
```

simply just run gazebo means you start a gazebo that runs in its own workspace, it has nothing to do with ROS. If you want to catch the messages that come from gazebo, You gotta rosrun the gazebo node to do that.

ROS knows nothing about the geometries you have in gazebo. You have to create a urdf for that model on your own.



joint_state_publisher_gui won't work for gazebo, which means you cannot adjust the model through slide bars in joint_state_publisher_gui. But you can make that happen through some kinda APIs.