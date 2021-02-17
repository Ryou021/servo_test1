#include "ros/ros.h"
#include <std_msgs/UInt16.h>
using namespace std;

int main(int argc, char **argv){
   ros::init(argc, argv, "servo_test1_node");
   ros::NodeHandle nh;                                     //ノードハンドラ
   ros::Publisher  pub;                                    //パブリッシャ(送る側)
   ros::Rate rate(1000);                                     //ループの周期、これは10Hz
   std_msgs::UInt16 vel;                               //Twist型velの宣言
   pub= nh.advertise<std_msgs::UInt16>("servo", 1000);//パブリッシャの宣言
   int i=0;
   vel.data=7500;
   while (ros::ok()) {
          for(i=0;i++;vel.data<11500){
                 vel.data=vel.data+1;
          }
          for(i=0;i++;vel.data>3500){
                 vel.data=vel.data-1;
          }
          /*i++;
          if(i){
                 vel.data=vel.data+1;
                 if(vel.data>11500)vel.data=3500;
                 i=0;
          }*/
       pub.publish(vel);                                   //送信
       ros::spinOnce();
       rate.sleep();                                       //10hZになるまで待つ
   }
   return 0;
}
