#include "ros/ros.h"
//#include "beginner_tutorials/AddTwoInts.h"

#include "ros_tutorials_service/SrvTutorial.h"



bool calculation(ros_tutorials_service::SrvTutorial::Request &req, ros_tutorials_service::SrvTutorial::Response &res)
{
// 서비스요청시받은 a와 b 값을더하여서비스응답값에저장한다
res.result = req.a + req.b;

// 서비스요청에사용된 a, b 값의표시및서비스응답에해당되는result 값을출력한다 ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
ROS_INFO("sending back response: %ld", (long int)res.result);

return true;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("ros_tutorial_srv", calculation);
  ROS_INFO("Ready srv server!");
  ros::spin();

  return 0;
}
