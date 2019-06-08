/* */

#include <ignition/math/Pose3.hh>
#include "gazebo/physics/physics.hh"
#include "gazebo/common/common.hh"
#include "gazebo/gazebo.hh"
#include "ros/ros.h"
#include "std_msgs/Bool.h"

#include <thread>
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"

using namespace std;

namespace gazebo
{

class LmazePlugin : public WorldPlugin {

	private: 
		std::unique_ptr<ros::NodeHandle> rosNode;
		ros::Subscriber rosSub;
		ros::Subscriber rosSub1;
		ros::Subscriber rosSub2;

		ros::CallbackQueue rosQueue;
		ros::CallbackQueue rosQueue1;
		ros::CallbackQueue rosQueue2;

		thread rosQueueThread;
		thread rosQueueThread1;
		thread rosQueueThread2;

	public :
	    int MAZE_SIZE = 0;
	    double cradius = 0.006;
	    float scaleX = 0.05;
	    float scaleY = 0.05;
	    float groundOffset;
	int goal_i = -1;
	int goal_j = -1;
	    float floorHeight = 0.025; 		// should be equal to z axis scaling of cube for Wall Model; currently "0.05"
	    float floorThickness = 0.001; 	// should be equal to z axis scaling of cube for floor Model; currently "0.0155"
	    bool goalRandom = False;
	    physics::WorldPtr World;
	    physics::ModelPtr Model;
		
	    std::string maze_filename = "/homes/gkumar/rl/PrivateModelDevelopment4/sample_labyrinth_maze.mz";
	
	void rnd();
	    void Load(physics::WorldPtr _parent, sdf::ElementPtr _sdf);
	    void loadSDF(/*sdf::ElementPtr base_link*/);

	    void OnReset(const std_msgs::Bool::ConstPtr& msg);
	    void OnReset1(const std_msgs::Bool::ConstPtr& msg);

	    void OnPause(const std_msgs::Bool::ConstPtr& msg);

	    void QueueThread() ;
	    void QueueThread1() ;
	    void QueueThread2() ;

		std::string drawJointSphere();
	    std::string drawBasement(std::string pose);
	    std::string drawBaseBoard(std::string pose);
	    std::string drawKinObj(std::string pose);
	    std::string drawCylObj(std::string pose);


		ros::NodeHandle nh;
		ros::Publisher pub;
};
}

