#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"


void chatterCallback(const std_msgs::Bool msg)
{
  if (msg.data)
    ROS_INFO("Great,Keep Going Bro");
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "jackal");

  ros::NodeHandle jackal;

  
  ros::Subscriber sub = jackal.subscribe("husky_msg", 1000, chatterCallback);

  ros::spin();

  return 0;
}