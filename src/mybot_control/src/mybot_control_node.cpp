#include <ros/ros.h>
#include <geometry_msgs/Twist.h> 
#include <sensor_msgs/Range.h> 


ros::Publisher pub;
ros::Subscriber sub;

void sonarCallback1(const sensor_msgs::Range& sensor_msg)
{
  	ROS_INFO("Range from sensor is %f", sensor_msg.range);
	geometry_msgs::Twist vel_msg;

	if(sensor_msg.range<1){
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.1;
	}
	else{
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.0;
	}

	//Publish the message
	pub.publish(vel_msg);
}
void sonarCallback2(const sensor_msgs::Range& sensor_msg)
{
  	ROS_INFO("Range from sensor is %f", sensor_msg.range);
	geometry_msgs::Twist vel_msg;

	if(sensor_msg.range<1){
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.1;
	}
	else{
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.0;
	}

	//Publish the message
	pub.publish(vel_msg);
}
void sonarCallback3(const sensor_msgs::Range& sensor_msg)
{
  	ROS_INFO("Range from sensor is %f", sensor_msg.range);
	geometry_msgs::Twist vel_msg;

	if(sensor_msg.range<1){
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.1;
	}
	else{
		vel_msg.linear.x=0.1;
		vel_msg.angular.z=0.0;
	}

	//Publish the message
	pub.publish(vel_msg);
}

int main(int argc, char **argv) {
	 //Initializes ROS, and sets up a node
	 ros::init(argc, argv, "mybot_control_node");
	 ros::NodeHandle nh;

	 //Ceates the publisher, and tells it to publish
	 //to mybot/actuator topic, with a queue size of 100
	 pub = nh.advertise<geometry_msgs::Twist>("mybot/actuator/cmd_vel", 100);

	 sub = nh.subscribe("mybot/sensor/sonar1", 1000, sonarCallback1);
	 sub = nh.subscribe("mybot/sensor/sonar2", 1000, sonarCallback2);
	 sub = nh.subscribe("mybot/sensor/sonar3", 1000, sonarCallback3);



  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

/*
	 //Sets the loop to publish at a rate of 10Hz
	 ros::Rate rate(10);

	   while(ros::ok()) {
			//Declares the message to be sent
		   geometry_msgs::Twist msg;

		   msg.linear.x=0.1;
		   msg.angular.z=0.1;

		   //Publish the message
		   pub.publish(msg);

		  //Delays untill it is time to send another message
		  rate.sleep();
		 }
*/
}