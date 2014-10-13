#ifndef DWL_Robot_H
#define DWL_Robot_H

#include <behavior/MotorPrimitives.h>
#include <utils/utils.h>
#include <fstream>
#include <yaml-cpp/yaml.h>


namespace dwl
{

namespace robot
{

enum QuadrupeLegID {LF, RF, LH, RH};
enum HumanoidLegID {L, R};

/**
 * @class Robot
 * @brief Class for defining the properties of the robot
 */
class Robot
{
	public:
		/** @brief Constructor function */
		Robot();

		/** @brief Destructor function */
		~Robot();

		/**
		 * @brief Gets the body motor primitives
		 * @return behavior::MotorPrimitives& Returns the body motor primitives
		 */
		behavior::MotorPrimitives& getBodyMotorPrimitive();

		void read(std::string filepath);

		/**
		 * @brief Sets the current pose of the robot
		 * @param dwl::Pose pose Current pose
		 */
		void setCurrentPose(Pose pose);

		/**
		 * @brief Sets the current contacts of the robot
		 * @param std::vector<dwl::Contact> contacts Contact positions
		 */
		void setCurrentContacts(std::vector<Contact> contacts);

		/**
		 * @brief Sets the pattern of locomotion of the robot
		 * @param std::vector<int> pattern Sequence of leg movements according to the current leg
		 */
		void setPatternOfLocomotion(std::vector<int> pattern);

		/**
		 * @brief Gets current pose of the robot
		 * @return dwl::Pose Returns the current pose of the robot
		 */
		Pose getCurrentPose();

		/**
		 * @brief Gets the current contact positions
		 * @return std::vector<Contact> Returns the set of current contacts
		 */
		std::vector<Contact> getCurrentContacts();

		/**
		 * @brief Gets the body area
		 * @return dwl::Area Return the body area of the robot
		 */
		Area getBodyArea();

		/**
		 * @brief Gets the nominal stance of the robot
		 * @param Eigen::Vector3d action Action to execute
		 * @return std::vector<Eigen::Vector3d> Returns the nominal stance of the robot
		 */
		std::vector<Eigen::Vector3d> getNominalStance(Eigen::Vector3d action);

		/**
		 * @brief Gets the pattern of locomotion of the robot
		 * @return std::vector<int> Returns the pattern of locomotion
		 */
		std::vector<int> getPatternOfLocomotion();

		/**
		 * @brief Gets the stance areas
		 * @param Eigen::Vector3d action Action to execute
		 * @return std::vector<SearchArea> Returns the stance areas
		 */
		std::vector<SearchArea> getFootstepSearchAreas(Eigen::Vector3d action);

		/**
		 * @brief Gets the expected ground according to the nominal stance
		 * @param int leg_id Leg id
		 * @return std::vector<double> Returns the expected ground according to the nominal stance of the leg
		 */
		double getExpectedGround(int leg_id);

		/**
		 * @brief Gets the leg work-areas for evaluation of potential collisions
		 * @return std::vector<SearchArea> Returns the leg work-areas
		 */
		std::vector<SearchArea> getLegWorkAreas();

		/** @brief Gets the number of legs of the robot */
		double getNumberOfLegs();


	protected:
		/** @brief Current pose of the robot */
		Pose current_pose_;

		/** @brief Current contacts of the robot */
		std::vector<Contact> current_contacts_;

		/** @brief Pointer to the body motor primitives */
		behavior::MotorPrimitives* body_behavior_;


		ContactID end_effectors_;
		SearchArea footstep_window_;


		/** @brief Vector of footstep search areas */
		std::vector<SearchArea> footstep_search_areas_;

		/** @brief Vector of the body area */
		Area body_area_;

		/** @brief Vector of the nominal stance */
		std::vector<Eigen::Vector3d> nominal_stance_;

		/** @brief Pattern of locomotion */
		std::vector<int> pattern_locomotion_;

		/** @brief Number of legs */
		double number_legs_;
		double number_end_effectors_;

		/** @brief Size of the stance area */
		//double stance_size_;

		/** @brief Leg work-areas */
		std::vector<SearchArea> leg_areas_;

		/** @brief Estimated ground from the body frame */
		double estimated_ground_from_body_;

		/** @brief The last past leg */
		int last_past_leg_;
};

} //@namespace robot
} //@namespace dwl

#endif
