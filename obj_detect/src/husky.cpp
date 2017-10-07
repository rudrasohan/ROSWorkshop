#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

#include <sstream>
std_msgs::Bool response;

void chatterCallback(const std_msgs::Bool msg)
{
   if (msg.data)
    {
      ROS_INFO("Hey I Found Object 1");
      response.data = msg.data;
    }
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "husky");

  ros::NodeHandle husky;


  ros::Publisher chatter_pub = husky.advertise<std_msgs::Bool>("husky_msg", 1000);
  ros::Subscriber sub = husky.subscribe("is_obj_detected", 1000, chatterCallback);
  ros::Rate loop_rate(10);
  while (ros::ok())
  {

    chatter_pub.publish(response);
    response.data = false;
    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}