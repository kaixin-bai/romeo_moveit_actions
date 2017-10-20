/*
 * Copyright 2016 SoftBank Robotics Europe
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef OBJPROCESSING_HPP
#define OBJPROCESSING_HPP

#include <boost/scoped_ptr.hpp>

// ROS
#include <ros/ros.h>

#include <actionlib/client/simple_action_client.h>

#include <object_recognition_msgs/GetObjectInformation.h>
#include <object_recognition_msgs/ObjectRecognitionAction.h>

namespace moveit_simple_actions
{

class Objprocessing
{
public:
  Objprocessing(ros::NodeHandle *nh_);

  //get the object's mesh from the DB
  std::vector <shape_msgs::Mesh> getMeshFromDB(object_recognition_msgs::ObjectType type);

  //detect objects
  bool triggerObjectDetection();

protected:
  ros::NodeHandle *nh_;

  std::string mesh_srv_name;

  const std::string OBJECT_RECOGNITION_ACTION;

  std::string target_frame;
  std::string depth_frame_id;

  //! Client for getting the mesh for a database object
  ros::ServiceClient get_model_mesh_srv_;

  ros::Subscriber object_recognition_subscriber_;
  boost::scoped_ptr<actionlib::SimpleActionClient<object_recognition_msgs::ObjectRecognitionAction> > object_recognition_client_;

  bool found_srv_obj_info;
  bool found_object_recognition_client_;
};

}

#endif // OBJPROCESSING_HPP
