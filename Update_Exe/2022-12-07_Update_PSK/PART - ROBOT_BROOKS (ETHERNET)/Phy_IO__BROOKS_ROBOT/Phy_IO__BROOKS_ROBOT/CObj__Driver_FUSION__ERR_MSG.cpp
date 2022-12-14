#include "StdAfx.h"
#include "CObj__Driver_FUSION.h"


//------------------------------------------------------------------------------------
CString CObj__Driver_FUSION
::Get__Fusion_Error_Msg_Of_Error_Code(const int err_code)
{
	CString err_msg;

	err_msg.Format("Error_Code : %1d", err_code);
	err_msg += "\n";

	switch(err_code)
	{
		// Code Description
		case 0x80041080:
			err_msg += "FFU returned error.";
			break;
		case 0x80041081:
			err_msg += "Failed to find the expected customer attribute.";
			break;
		case 0x80041082:
			err_msg += "Command has been aborted.";
			break;
		case 0x80041083:
			err_msg += "Resource is busy.";
			err_msg += "\n";
			err_msg += "Previously issued command has not finished.";
			err_msg += "\n";
			err_msg += "  a. Wait for the currently executing command to complete (_DNE) before issuing a new command.";
			break;
		case 0x80041084:
			err_msg += "Workspace version is not compatible.";
			break;
		case 0x80041085: 
			err_msg += "Reference to external item is not assigned.";
			break;
		case 0x80041086: 
			err_msg += "File was not a valid backup.";
			break;
		case 0x80041089: 
			err_msg += "Tried to use a component that is not configured.";
			break;
		case 0x8004108a:
			err_msg += "Value is above the maximum for this parameter.";
			err_msg += "\n";
			err_msg += "Value is outside the acceptable range for this parameter.";
			err_msg += "\n";
			err_msg += "The various alternatives are used to specify whether the range has a tolerance, a minimum or a maximum.";
			err_msg += "\n";
			err_msg += "  a. Taught position is too far from nominal position";
			err_msg += "\n";
			err_msg += "  b. Aligner edge sensor value is out of range.";
			err_msg += "\n";
			err_msg += "  c. Request robot or station index is out of range";
			err_msg += "\n";
			err_msg += "  d. Move offset is too large";
			break;
		case 0x8004108b:
			err_msg += "Value is below minimum for this parameter.";
			err_msg += "\n";
			err_msg += "Value is outside the acceptable range for this parameter.";
			err_msg += "\n";
			err_msg += "The various alternatives are used to specify whether the range has a tolerance, a minimum, or a maximum.";
			err_msg += "\n";
			err_msg += "  a. Aligner edge sensor value is out of range.";
			err_msg += "\n";
			err_msg += "  b. Request robot or station index is out of range.";
			err_msg += "\n";
			err_msg += "  c. Taught position is too far from nominal position.";
			err_msg += "\n";
			err_msg += "  d. Move offset is too large.";
			break;			
		case 0x8004108c: 
			err_msg += "Failed to copy an item.";
			break;
		case 0x8004108d: 
			err_msg += "Failed to create an item.";
			break;
		case 0x8004108e: 
			err_msg += "Facility Item has failed.";
			break;
		case 0x8004108f:
			err_msg += "Failed to find item";
			err_msg += "\n";
			err_msg += "  a. Device name used in command does not match name or recognized by the system";
			err_msg += "\n";
			err_msg += "    Resolution: Check for correct command syntax and number of arguments in it.";
			err_msg += "\n";
			err_msg += "  b. The data sent by the host was corrupted during transmission.";
			err_msg += "\n";
			err_msg += "    Resolution: Re-send the command.";
			err_msg += "\n";
			err_msg += "  c. Multi-mode is disabled, and the command sent by host with task ID.";
			err_msg += "\n";
			err_msg += "    Resolution: if multi-mode is needed type in the command terminal $$$";
			err_msg += "\n";
			err_msg += "    multi_mode True";
			break;
		case 0x80041090:
			err_msg += "Unimplemented function called.";
			break;
		case 0x80041094:
			err_msg += "The item has timed out";
			err_msg += "\n";
			err_msg += "This error indicates that the robot or some other device was waiting for an event to occur.";
			err_msg += "\n";
			err_msg += "  a. Robot or other device is waiting for an input(s) to reach a certain state(s).";
			err_msg += "\n";
			err_msg += "    Examples:";
			err_msg += "\n";
			err_msg += "      i. End-effector gripper waiting for input to change.";
			err_msg += "\n";
			err_msg += "	  ii. End-effector wafer presence sensor waiting for input to change";
			err_msg += "\n";
			err_msg += "	  iii. Interlock waiting for input to change";
			err_msg += "\n";
			err_msg += "	  iv. Generic I/O device waiting for input to change";
			err_msg += "\n";
			err_msg += "	  v. Data capture mechanism waiting for trigger event";
			err_msg += "\n";
			err_msg += "  b. Robot waiting for position to reach a desired state or value. Examples:";
			err_msg += "\n";
			err_msg += "    i. Robot waiting for move to complete";
			err_msg += "\n";
			err_msg += "	ii. Robot waiting for position to be safe";
			err_msg += "\n";
			err_msg += "	iii. Robot waiting for position to reach certain value";
			break;
		case 0x80041097:
			err_msg += "Value is outside the acceptable range for this parameter."; 
			err_msg += "\n";
			err_msg += "The various alternatives are used to specify whether the range has a tolerance, a minimum, or a maximum.";
			err_msg += "\n";
			err_msg += "  a. Aligner edge sensor value is out of range.";
			err_msg += "\n";
			err_msg += "  b. Request robot or station index is out of range.";
			err_msg += "\n";
			err_msg += "  c. Taught position is too far from nominal position.";
			err_msg += "\n";
			err_msg += "  d. Move offset is too large.";
			break;
		case 0x800410ad:
			err_msg += "Failed to queue a user work item in the thread pool object.";
			break;
		case 0x800410ae:
			err_msg += "Object can't be parent of or have a reference to itself.";
			break;
		case 0x800410af:
			err_msg += "Control already held.";
			err_msg += "\n";
			err_msg += "This error indicates that another user or host has control of the system.";
			err_msg += "\n";
			err_msg += "  a. Check whether another Fusion Service application is open and has control already.";
			err_msg += "\n";
			err_msg += "    Release control from or close the other application.";
			break;
		case 0x800410b1:
			err_msg += "Control is required for this method call.";
			err_msg += "\n";
			err_msg += "This error indicates that the user needs to have control of the system before the command can be executed.";
			err_msg += "\n";
			err_msg += "  a. Check whether any Fusion Service application is open and has control already.";
			err_msg += "\n";
			err_msg += "    Release control from or close the application.";
			break;
		case 0x800410b6: 
			err_msg += "An item with that name or ID already exists.";
			break;
		case 0x800410c4: 
			err_msg += "More than one robot present, must select robot.";
			break;
		case 0x800410c5: 
			err_msg += "No node selected.";
			break;
		case 0x800410c8: 
			err_msg += "New password and confirm password do not match.";
			err_msg += "\n";
			err_msg += "Password change failed.";
			break;
		case 0x800410cb: 
			err_msg += "Cannot set value, argument provided is read-only.";
			break;
		case 0x800410cf: 
			err_msg += "The object is a singleton."; 
			err_msg += "\n";
			err_msg += "You are not allowed to create more than instance of the object.";
			break;
		case 0x800410d0: 
			err_msg += "Cannot transfer ownership when busy.";
			break;
		case 0x800410d1:
			err_msg += "Controller Exception: Unhandled Software Exception.";
			err_msg += "\n";
			err_msg += "This is a generic error code if no other error code is assigned.";
			err_msg += "\n";
			err_msg += "Write a short summary to duplicate the issue and contact Brooks Automation.";
			break;
		case 0x800410d3: 
			err_msg += "Unknown version mode.";
			break;
		case 0x800410e6: 
			err_msg += "Object name must be specified.";
			break;
		case 0x800410e8: 
			err_msg += "Password and confirm password do not match.";
			err_msg += "\n";
			err_msg += "New user account creation failed.";
			break;
		case 0x800410ed: 
			err_msg += "No server connection.";
			break;
		case 0x800410ef: 
			err_msg += "The Step Element was already registered to another running Step,";
			err_msg += "\n";
			err_msg += "Do not share Step Elements which execute in parallel.";
			break;
		case 0x800410f2: 
			err_msg += "File was not found.";
			break;
		case 0x800410f6:
			err_msg += "Failed the state of the item is not allowed.";
			break;
		case 0x800410fd:
			err_msg += "Program/Macro stack overflow.";
			break;
		case 0x800410fe:
			err_msg += "The thread is still active.";
			break;

		// Operational Exception
		case 0x80041100:
			err_msg += "Failed to acquire the object from the specified device.";
			break;
		case 0x80041101: 
			err_msg += "Failed to enable the specified device.";
			break;
		case 0x80041102: 
			err_msg += "External device interface is not active.";
			err_msg += "\n";
			err_msg += "Initialize the device before attempting to communicate.";
			break;
		case 0x80041103: 
			err_msg += "Unknown Response received from external device.";
			break;
		case 0x80041104:
			err_msg += "Interlock violated.";
			err_msg += "\n";
			err_msg += "  a. An attempt was made to access a station while the interlock was not valid.";
			err_msg += "\n";
			err_msg += "    i. Verify that the station’s interlock input was in the correct state.";
			err_msg += "\n";
			err_msg += "	ii. Verify that the station’s interlock input is functioning properly.";
			err_msg += "\n";
			err_msg += "  b. A command was sent to open an isolation valve while the interlock was not valid.";
			err_msg += "\n";
			err_msg += "    i. Verify that the valve’s interlock input was in the correct state.";
			err_msg += "\n";
			err_msg += "    ii. Verify that the valve’s interlock input is functioning properly.";
			err_msg += "\n";
			err_msg += "  c. A command was sent to clear the robot extend bit while it was extended into the station.";
			err_msg += "\n";
			err_msg += "    i. Verify that the robot was at a safe position when the bit was cleared.";
			err_msg += "\n";
			err_msg += "    ii. Verify that the robot extend bit is functioning properly.";
			err_msg += "\n";
			err_msg += "    iii. Verify that the station safe zone is setup properly for the robot.";
			break;			
		case 0x80041105: 
			err_msg += "The specified device is unavailable.";
			break;
		case 0x80041106: 
			err_msg += "This device or operation has not been calibrated.";
			break;
		case 0x80041107: 
			err_msg += "The device was left in an incorrect state and can not execute commands ";
			err_msg += "\n";
			err_msg += "without being initialized with the initialize resource command.";
			break;
		case 0x80041108: 
			err_msg += "Commutation Not Ready Exception.";
			break;
		case 0x80041109:
			err_msg += "Requested operation is illegal while in this state.";
			err_msg += "\n";
			err_msg += "Requested operation requires robot or device be in a certain state before starting.";
			err_msg += "\n";
			err_msg += "An operation was attempted when the robot or device had not been prepared.";
			err_msg += "\n";
			err_msg += "  a. Operation may require end-effector be unoccupied or occupied before starting.";
			err_msg += "\n";
			err_msg += "  b. Attempted to reconfigure data capture mechanism while trigger was active.";
			err_msg += "\n";
			err_msg += "  c. Attempted to execute sequence to a previous step or state.";
			break;
		case 0x8004110a:
			err_msg += "The Quality of the data is not GOOD.";
			err_msg += "\n";
			err_msg += "  a. The I/O device is not connected or online - Ensure I/O device has power, is connected, and is online.";
			err_msg += "\n";
			err_msg += "  b. Robot position values are not updating properly.";
			break;
		case 0x8004110b:
			err_msg += "This Sequence is not in a partially executed state, cannot continue execution of sequence.";
			err_msg += "\n";
			err_msg += "  a. Partial sequence execution failed because resource or sequence was not in the correct state.";
			break;
		case 0x8004110c: 
			err_msg += "The Sequence cannot be executed with this partial run type.";
			break;
		case 0x80041112: 
			err_msg += "Resource Adapter Not Set.";
			break;
		case 0x80041113: 
			err_msg += "Unknown IO ID.";
			break;
		case 0x80041117: 
			err_msg += "Robot position exceeded maximum off path recovery.";
			break;
		case 0x80041119: 
			err_msg += "Condition evaluation failed.";
			break;
		case 0x8004111a:
			err_msg += "Condition Failed.";
			err_msg += "\n";
			err_msg += "  a. I/O device is not initialized.";
			err_msg += "\n";
			err_msg += "    Ensure that all I/O devices are initialized before attempting the operation.";
			break;

		case 0x8004111c:
			err_msg += "Failed to connect to the specified device.";
			err_msg += "\n";
			err_msg += "This error indicates that communication with the device does not exist.";
			err_msg += "\n";
			err_msg += "  a. A command was sent to set or clear an output bit when the device was offline.";
			err_msg += "\n";
			err_msg += "    i. Ensure that all devices (robots and I/O external nodes) have been initialized.";
			err_msg += "\n";
			err_msg += "    ii. Stop Fusion and Start it again.";
			err_msg += "\n";
			err_msg += "  b. A connection to Fusion supervisor was lost.";
			err_msg += "\n";
			err_msg += "    i. Re-open the Fusion Service application";
			err_msg += "\n";
			err_msg += "    ii. Stop Fusion and Start it again.";
			err_msg += "\n";
			err_msg += "  c. Fire wire communication issue.";
			err_msg += "\n";
			err_msg += "    i. Ensure fire wire communication cables are not damaged and connections are seated properly.";
			err_msg += "\n";
			err_msg += "    ii. Make sure 24v DC power is on.";
			err_msg += "\n";
			err_msg += "  d. Make sure the external devices such as LPM FFU etc… are on.";
			err_msg += "\n";
			err_msg += "  e. The serial port is not available.";
			err_msg += "\n";
			err_msg += "    i. Shut down Fusion controller and start it again.";
			err_msg += "\n";
			err_msg += "    ii. Select another serial port.";
			break;
		case 0x8004111d:
			err_msg += "Failed to disconnect from the specific device.";
			break;
		case 0x8004111e:
			err_msg += "The End Effectors Gripper was not in the process of Gripping.";
			break;
		case 0x8004111f:
			err_msg += "Can't allocate input.";
			break;
		case 0x80041120:
			err_msg += "The Gripper Controller is incorrectly configured.";
			break;
		case 0x80041121:
			err_msg += "Device not initialized.";
			err_msg += "\n";
			err_msg += "This error indicates that the user attempted to execute an operation"; 
			err_msg += "\n";
			err_msg += "that requires the device to	be initialized.";
			break;
		case 0x80041122:
			err_msg += "External device interface error.";
			err_msg += "\n";
			err_msg += "This error indicates that an external device reported an error"; 
			err_msg += "\n";
			err_msg += "that is not covered by other error codes."; 
			err_msg += "\n";
			err_msg += "For example, an Aculigner uses this error code to report low level errors.";
			err_msg += "\n";
			err_msg += "The secondary error code contains the device specific error code."; 
			err_msg += "\n";
			err_msg += "See the device’s help documentation for more information.";
			break;
		case 0x80041124:
			err_msg += "Failed to read from the specific device.";
			break;
		case 0x80041125:
			err_msg += "The End Effectors Gripper was not in the process of Releasing.";
			break;
		case 0x80041126:
			err_msg += "The specified operation is not supported.";
			break;
		case 0x80041127:
			err_msg += "Failed to write to the specific device.";
			break;
		case 0x80041128:
			err_msg += "Sub Category has reached the maximum number of specific error codes.";
			break;
		case 0x8004112a:
			err_msg += "The Acquire-Release Controller is incorrectly configured.";
			break;
		case 0x8004112b:
			err_msg += "The IO Controller is incorrectly configured.";
			break;
		case 0x8004112c:
			err_msg += "Sequence thrown Exception.";
			err_msg += "\n";
			err_msg += "This error indicates that a sequence executed an error step."; 
			err_msg += "\n";
			err_msg += "Error steps can be added to customize sequences."; 
			err_msg += "\n";
			err_msg += "The sequence and step names are reported with the error code to indicate which error occurred.";
			break;
		
		// Configuration Exception
		case 0x80041180:
			err_msg += "Invalid Index Spacing.";
			break;
		case 0x80041181:
		    err_msg += "There is either no \'fusionExternalAdapter\' entry in the hosts file or the IP Address is not local to this machine.";
			err_msg += "\n";
			err_msg += "Please correct the hosts file and then restart the server";
			break;
		case 0x80041182:
			err_msg += "A Step inside of the Sequence was not properly configured.";
			break;
		case 0x80041183:
			err_msg += "This Sequence is not available! Check resource list.";
			break;
		case 0x80041184:
			err_msg += "This Object has not been properly configured by user.";
			break;
		case 0x80041186:
			err_msg += "Configuration error, some properties of this Condition Step were not filled in.";
			break;
		case 0x80041187:
			err_msg += "Condition Failed.";
			break;
		case 0x80041189: 
			err_msg += "Bad Interlock Object.";
			break;
		case 0x8004118a: 
			err_msg += "No teaching available.";
			break;
		case 0x8004118b: 
			err_msg += "Trajectory active.";
			break;

		// Command Interpreter Exception
		case 0x80041200:
			err_msg += "A syntax error was found.";
			err_msg += "\n";
			err_msg += "The syntax of the command was invalid.";
			err_msg += "\n";
			err_msg += "  a. Check command syntax for conformance with Fusion command protocol.";
			break;
		case 0x80041201: 
		    err_msg += "Command does not exist for the specific device.";
			err_msg += "\n";
			err_msg += "The requested command does not exist.";
			break;
		case 0x80041202:
			err_msg += "Wrong number of arguments.";
			err_msg += "\n";
			err_msg += "The command does not have the correct number of arguments.";
			err_msg += "\n";
			err_msg += "Type help, resource and the command for correct syntax example.";
			break;
		case 0x80041203: 
		    err_msg += "Not apparent which item to use.";
			break;
		case 0x80041208: 
		    err_msg += "Command Interpreter is already connected to another client.";
			break;
		case 0x8004120e: 
		    err_msg += "Invalid checksum.";
			break;
		case 0x80041212: 
			err_msg += "Invalid Type.";
			break;
		case 0x8004121f: 
		    err_msg += "Cannot parse command string.";
			break;
		case 0x80041221: 
		    err_msg += "Command Interpreter is in serial communication mode.";
			break;
		case 0x80041222:
			err_msg += "Task is busy and has not started.";
			err_msg += "\n";
			err_msg += "The command was sent on a task ID that was already in use.";
			err_msg += "\n";
			err_msg += "  a. Check whether the last command sent on the same task ID completed.";
			break;
		case 0x80041224: 
		    err_msg += "This type cannot be convert.";
			break;
		case 0x80041225:
			err_msg += "Connection is closed.";
			break;
		case 0x80041226:
			err_msg += "Stream is closed.";
			break;
		case 0x80041228:
			err_msg += "Execution was halted.";
			break;
		case 0x8004122e:
			err_msg += "No stream available.";
			break;

		// Motion Exception
		case 0x80041280: 
			err_msg += "The axis is not safe.";
			err_msg += "\n";
			err_msg += "This error indicates that the specified aligner axis is not in a position that is safe for the requested operation.";
			err_msg += "\n";
			err_msg += "This error will only occur if the aligner was moved manually.";
			break;
		case 0x80041281:
			err_msg += "Unable to move device or robot until it has been calibrated or homed, please calibrate device before continuing.";
			err_msg += "\n";
			err_msg += "  a. This error indicates that the robot or device has not been calibrated.";
			err_msg += "\n";
			err_msg += "    Attempt to operate robot failed.";
			err_msg += "\n";
			err_msg += "  b. Initialize the robot before attempting to operate.";
			err_msg += "\n";
			err_msg += "  c. Attempt to re-zero the robot failed.";
			err_msg += "\n";
			err_msg += "  d. Initialize the robot before attempting to re-zero motors.";
			break;
		case 0x80041282:
			err_msg += "The specified move is not valid for this Robot.";
			err_msg += "\n";
			err_msg += "This error indicates that the requested move can not be executed.";
			err_msg += "\n";
			err_msg += "  a. Move sent and caused the need of robot handedness change, resulted in unsafe motion.";
			err_msg += "\n";
			err_msg += "  b. Manually move the robot to its safe position and then initialize it.";
			err_msg += "\n";
			err_msg += "  c. Check teaching at current station.";
			err_msg += "\n";
			err_msg += "  d. Make sure the Robot Zero position is correct.";
			break;
		case 0x80041283: 
			err_msg += "No data to plot.";
			break;
		case 0x80041284: 
			err_msg += "Base Move Not Found.";
			break;
		case 0x80041285: 
			err_msg += "Joints already defined.";
			break;
		case 0x80041286:
			err_msg += "Move not allowed in Manual Control mode.";
			err_msg += "\n";
			err_msg += "  a. Uncheck the Hand Locate check box if Jog Control window is open.";
			err_msg += "\n";
			err_msg += "  b. Re-initialize of Home the robot.";
			break;
		case 0x80041287: 
			err_msg += "Unable to move device or robot until it has been calibrated or homed.";
			err_msg += "\n";
			err_msg += "Please calibrate device before tuning.";
			err_msg += "\n";
			err_msg += "Robot motors have not been calibrated / referenced."; 
			err_msg += "\n";
			err_msg += "Robot position is not valid. Initialize or Home robot to resolve.";
			break;	
		case 0x80041288: 
			err_msg += "No data yet collected.";
			break;
		case 0x80041289: 
			err_msg += "Path Tracker should not be enabled while tracking.";
			break;
		case 0x8004128a: 
			err_msg += "Jog Mode is not valid for this operation.";
			break;
		case 0x8004128b: 
			err_msg += "Move not allowed in Manual Control mode.";
			break;
		case 0x8004128c: 
			err_msg += "An Amplifier Generated Fault has occur.";
			break;
		case 0x8004128d: 
			err_msg += "Motor has not been enabled, and is currently offline.";
			break;
		case 0x8004128e: 
			err_msg += "Approaching singularity.";
			break;
		case 0x8004128f: 
			err_msg += "Bad desired buffer size.";
			break;
		case 0x80041290: 
			err_msg += "Cartesian motion not supported.";
			break;
		case 0x80041291: 
			err_msg += "Circ buffer overflow.";
			break;
		case 0x80041292: 
			err_msg += "Circ buffer underflow.";
			break;
		case 0x80041293: 
			err_msg += "Motor Feedback has been lost, Encoder Error.";
			break;
		case 0x80041294: 
			err_msg += "Hard tracking following error.";
			err_msg += "\n";
			err_msg += "Refer to Chapter 5 Motion Engine Error Codes of this document for additional information.";
			break;
		case 0x80041295: 
			err_msg += "Illegal configuration change.";
			break;
		case 0x80041296: 
			err_msg += "Illegal encoder quadrature state.";
			break;
		case 0x80041297: 
			err_msg += "Illegal frame type.";
			break;
		case 0x80041298: 
			err_msg += "Invalid orientation.";
			break;
		case 0x80041299:
			err_msg += "Joint out of range.";
			err_msg += "\n";
			err_msg += "This error indicates that one or more of the joint is beyond the defined joint limit.";
			err_msg += "\n";
			err_msg += "  a. Check teaching position of current station.";
			err_msg += "\n";
			err_msg += "  b. Wrist position outside defined range during homing.";
			err_msg += "\n";
			err_msg += "    i. Move the robot manually to its safe position.";
			err_msg += "\n";
			err_msg += "   ii. Check the joint position of the robot by opening the Jog control button.";
			err_msg += "\n";
			err_msg += "  iii. If either wrist is outside of the joint range (approx +/-180 deg),"; 
			err_msg += "\n";
			err_msg += "	   manually unwrap the wrist until it is inside the range.";
			err_msg += "\n";
			err_msg += "   iv. Attempt to home the robot again.";
			break;
		case 0x8004129a: 
			err_msg += "Out of reach.";
			break;
		case 0x8004129b:
			err_msg += "Over travel.";
			err_msg += "\n";
			err_msg += "This error indicates that the current position is beyond the reach of the robot.";
			err_msg += "\n";
			err_msg += "  a. If teaching, review teaching procedure and nominal setup for the tool.";
			err_msg += "\n";
			err_msg += "    Ensure that robot is not beyond joint limits before attempting to teach.";
			err_msg += "\n";
			err_msg += "  b. If unable to teach, ensure that robot is zeroed properly.";
			break;
		case 0x8004129c: 
			err_msg += "Robot move pending.";
			break;
		case 0x8004129d: 
			err_msg += "Servo hardware error. Robot must be servo before attempting to move.";
			break;
		case 0x8004129e: 
			err_msg += "Settling timeout.";
			break;
		case 0x8004129f: 
			err_msg += "Move End Position (or Teach Position) is Too Close to Robot Singular Position.";
			break;
		case 0x800412a0: 
			err_msg += "Trajectory disabled.";
			break;
		case 0x800412a1: 
			err_msg += "Illegal State: Robot E-stop active.";
			break;
		case 0x800412a2: 
			err_msg += "Motor power failure.";
			break;
		case 0x800412a3: 
			err_msg += "Illegal state: Motor is currently enabled.";
			break;
		case 0x800412a4: 
			err_msg += "Unable to process command while trajectory generator is active.";
			break;
		case 0x800412a5: 
			err_msg += "Resource unsafe. Command ignored.";
			break;
		case 0x800412a6:
			err_msg += "This straight line Cartesian move not allowed as it violates the safe exclusion zone.";
			err_msg += "\n";
			err_msg += "This error indicates that the requested move cannot be executed.";
			err_msg += "\n";
			err_msg += "  a. Move sent to robot would have resulted in unsafe motion of the arm.";
			err_msg += "\n";
			err_msg += "    i. For aligners (or other stations with pick or place offsets),";
			err_msg += "\n";
			err_msg += "	  this error may occur from time to time if the motion profile setup is marginal.";
			err_msg += "\n";
			err_msg += "   ii. If the station was re-taught, this error may occur if the motion profile setup is marginal.";
			break;
		case 0x800412a7:
			err_msg += "Generic Motion Control Exception: See trace log for more information.";
			err_msg += "\n";
			err_msg += "This is a generic motion error which can be caused by several conditions.";
			err_msg += "\n";
			err_msg += "  a. Robot does not have motor power (48 V) enabled";
			err_msg += "\n";
			err_msg += "    1. Check that all hardware interlocks are safe (doors, e-stop signals, cabling to FCC).";
			err_msg += "\n";
			err_msg += "    2. Check that the FCC does not have a red light fault";
			err_msg += "\n";
			err_msg += "      i. FCC faults indicate a hardware interlock wiring or signal problem and can only be recovered by power cycling the FCC.";
			err_msg += "\n";
			err_msg += "     ii. Install jumpers to check FCC internal 	integrity. Reconnect system cabling after FCC is validated.";
			err_msg += "\n";
			err_msg += "    iii. Check interlock wiring integrity.";
			err_msg += "\n";
			err_msg += "    3. Verify the correct application ID is loaded";
			err_msg += "\n";
			err_msg += "  b. Move was attempted when robot was not servo";
			err_msg += "\n";
			err_msg += "    1. Robot may have hard-tracked during previous motion but the error reported when the next move is sent.";
			err_msg += "\n";
			err_msg += "	  Check log files for additional error messages.";
			err_msg += "\n";
			err_msg += "    2. Robot had been servo-off before command was sent.";
			err_msg += "\n";
			err_msg += "  c. Slip ring problem may cause loosing fire wire communication to the amplifiers";
			err_msg += "\n";
			err_msg += "  d. See chapter 5 - Motion Engine Error Codes for additional information on the secondary error code."; 
			break;
		case 0x800412A8:
			err_msg += "Robot is not in safe zone.";
			err_msg += "\n";
			err_msg += "This error indicates that the robot is not safe for the operation.";
			err_msg += "\n";
			err_msg += "The robot safe zone is defined as a tolerance around its home position."; 
			err_msg += "\n";
			err_msg += "Home position is defined as a position where we can jog T1, 360 degrees with wafer on the EE and without hitting any obstacle.";
			err_msg += "\n";
			err_msg += "  a. Error reported while teaching.";
			err_msg += "\n";
			err_msg += "    1. Old WS were the RetractUp move is not defined as a joint safe move and causing the robot not to be inside its safe zone."; 
			err_msg += "\n";
			err_msg += "	  Modification of WS is needed. contact Brooks engineering.";
			err_msg += "\n";
			err_msg += "  b. Error reported during PickFrom or PlaceTo.";
			err_msg += "\n";
			err_msg += "    1. Attempted to move robot starting from a non-safe position.";
			err_msg += "\n";
			err_msg += "Typically this would occur after a previous error left the robot at a non-retracted position."; 
			err_msg += "\n";
			err_msg += "Home robot and reexecute the command.";
			break;
		case 0x800412a9: 
			err_msg += "Failed to find sequence move object in resource configuration.";
			break;
		case 0x800412aa: 
			err_msg += "Move too short for number of samples.";
			break;

		case 0x800412ab:
			err_msg += "The type of Move is not supported by this Robot.";
			break;
		case 0x800412ac: 
		    err_msg += "Logic Power Failure.";
			break;
		case 0x800412ad: 
		    err_msg += "Motor Current Limit has been exceeded.";
			break;
		case 0x800412ae: 
			err_msg += "Amplifier Current (Torque) Limit has been exceeded.";
			break;
		case 0x800412af:
			err_msg += "Motor over Temperature Limit has been exceeded.";
			err_msg += "\n";
			err_msg += "This error indicates that the motor temperature sensor detected higher temperature then is allowed.";
			err_msg += "\n";
			err_msg += "  a. Open covers and make sure the base fan is working properly.";
			err_msg += "\n";
			err_msg += "  b. Move robot motor by hand, making sure there is no excessive friction.";
			err_msg += "\n";
			err_msg += "  c. Amplifier command: aninxmode 3 0 (for the first half of the Amp) and";
			err_msg += "\n";
			err_msg += "    aninxmode 4 0 (for the second half of the Amp) will disable the sensor alert.";
			err_msg += "\n";
			err_msg += "  d. Please contact Brooks engineering for assistance.";
			break;
		case 0x800412b0: 
			err_msg += "Motion related Communication Failure.";
			break;
		case 0x800412b1: 
			err_msg += "Amplifier Circuit Board Temperature Limit has been exceeded.";
			break;
		case 0x800412b2: 
			err_msg += "Servo can not be enabled for this action.";
			break;
		case 0x800412b3:
			err_msg += "The F/RX Axis is not safe to move it may collide with another axis or joint.";
			err_msg += "\n";
			err_msg += "This error indicates that the robot top arm flipper is not safe for the operation.";
			err_msg += "\n";
			err_msg += "You can either jog the F joint to close as possible to 0 degrees or manually level it."; 
			err_msg += "\n";
			err_msg += "Make sure to initialize the robot after.";
			break;

		// Material Transfer Exception
		case 0x80041300: 
			err_msg += "Inappropriate or damaged material has been detected.";
			break;
		case 0x80041301:
			err_msg += "Missing Material Exception.";
			err_msg += "\n";
			err_msg += "a. The location state of either the Robot (material on EE),"; 
			err_msg += "\n";
			err_msg += "  or the Station (material on the slot) is in an Unknown state"; 
			err_msg += "\n";
			err_msg += "  (in GUI material will appear in red color).";
			err_msg += "\n";
			err_msg += "b. Check if the material is situated correctly on the EE,"; 
			err_msg += "\n";
			err_msg += "  Make sure the material presence sensor (in active edge grip or passive EE)"; 
			err_msg += "\n";
			err_msg += "  displays the correct level,"; 
			err_msg += "\n";
			err_msg += "  or the vacuum reading and Threshold / Hysteresis settings are correct.";
			err_msg += "\n";
			err_msg += "  (click here for setting table).";
			err_msg += "\n";
			err_msg += "c. Perform the command atm1 updatelocationstates"; 
			err_msg += "\n";
			err_msg += "  and the response should be Occupied or Unoccupied."; 
			err_msg += "\n";
			err_msg += "  Compare the results with what you see on the EE.";
			err_msg += "\n";
			err_msg += "d. Using Service GUI > Robots > End Effector tab,";
			err_msg += "\n";
			err_msg += "  Check for proper wafer presence sensor operation and state,"; 
			err_msg += "\n";
			err_msg += "  toggle the manual control for proper solenoid operations,"; 
			err_msg += "\n";
			err_msg += "  and grip reading and settings.";
			break;
		case 0x80041302:
			err_msg += "Unexpected material was detected at the specified location.";  
			err_msg += "\n";
			err_msg += "If you are currently running in Material-Less mode remove all material from the tool before cycling"; 
			err_msg += "\n";
			err_msg += "  a. Remove material from the source and updatelocationstates."; 
			err_msg += "\n";
			err_msg += "  b. If you run in material less mode,";  
			err_msg += "\n";
			err_msg += "    then remove any material from the robot and stations (material holders) and try again."; 
			break;
		case 0x80041303:
			err_msg += "Improperly Placed Material Exception."; 
			err_msg += "\n";
			err_msg += "  a. Manually attend the station."; 
			err_msg += "\n";
			err_msg += "  b. Check for cross slotted material, slip-out material, or duplicate material."; 
			err_msg += "\n";
			err_msg += "  c. When mapping, correctly placed material is when a certain height"; 
			err_msg += "\n";
			err_msg += "    and thickness are measured. Run the calibration procedure."; 
			err_msg += "\n";
			err_msg += "  d. Could also be misclassified double slot wafers."; 
			break;	
		case 0x80041304:
			err_msg += "Multiple Material Exception."; 
			break;
		case 0x80041305:
			err_msg += "Material Transfer Exception: The location has an Acquire Material Error."; 
			err_msg += "\n";
			err_msg += "  a. Verify there is a material on the slot you try to pick from."; 
			err_msg += "\n";
			err_msg += "  b. Make sure your teaching position is in the correct height for the wafer to rest on the EE."; 
			err_msg += "\n";
			err_msg += "  c. Make sure the plunger (in an active edge grip) is actuating."; 
			err_msg += "\n";
			err_msg += "  d. Make sure the material presence sensor (in active edge grip or passive EE)"; 
			err_msg += "\n";
			err_msg += "    displays the correct detection level (<1000)."; 
			err_msg += "\n";
			err_msg += "  e. With vacuum EE, check for correct vacuum pressure going into the robot,"; 
			err_msg += "\n";
			err_msg += "    vacuum reading and Threshold / Hysteresis settings for wafer detection."; 
			err_msg += "\n";
		  	err_msg += "    (Click for vacuum setting table)"; 
			err_msg += "\n";
			err_msg += "  f. Active gripper has over traveled, (usually indicates poor teaching),";  
			err_msg += "\n";
			err_msg += "    also check that pick was not performed with an offset,";  
			err_msg += "\n";
			err_msg += "	Hardware flag settings got loose,";  
			err_msg += "\n";
			err_msg += "	or a smaller / broken wafer in diameter."; 
			err_msg += "\n";
			err_msg += "  g. Using Service GUI > Robots > End Effector tab, Check for proper wafer"; 
			err_msg += "\n";
			err_msg += "    presence sensor operation and state,"; 
			err_msg += "\n";
			err_msg += "	toggle the manual control for proper solenoid operations,";  
			err_msg += "\n";
			err_msg += "	and grip reading and settings."; 
			break;
		case 0x80041306: 
			err_msg += "Material Transfer Exception: "; 
			err_msg += "\n";
			err_msg += "  Transfer attempted when the location state is already receiving."; 
			break;
		case 0x80041307:
			err_msg += "The location has a prior Release Material Error."; 
			err_msg += "\n";
			err_msg += "Make sure the station teaching position is in the correct height, so when the EE moves to"; 
			err_msg += "\n";
			err_msg += "ExtendDown it does not detect any material."; 
			break;
		case 0x80041308: 
			err_msg += "Material Transfer Exception:"; 
			err_msg += "\n";
			err_msg += "  Material Transfer attempted when the location state is already Sending."; 
			break;
		case 0x80041309: 
			err_msg += "Material Transfer Exception:"; 
			err_msg += "\n";
			err_msg += "  The location state is Unknown."; 
			break;

		// Station Exception
		case 0x80041381:
			err_msg += "Index spacing too great."; 
			break;
		case 0x80041382: 
			err_msg += "Wafer map not valid."; 
			break;
		case 0x80041383: 
			err_msg += "Error while attempting to configure robot latch groups."; 
			break;
		case 0x80041384: 
			err_msg += "Mapper has not been calibrated for this station."; 
			break;
		case 0x80041385: 
			err_msg += "Error while attempting to turn on/off mapper sensors."; 
			break;
		case 0x80041386:
			err_msg += "Station being mapped is not found or reference is not set."; 
			err_msg += "\n";
			err_msg += "The station being mapped does not exist."; 
			err_msg += "\n";
			err_msg += "  a. Check the command syntax."; 
			err_msg += "\n";
			err_msg += "  b. Check the Map option in Station screen is enabled."; 
			break;
		case 0x80041387: 
			err_msg += "Attempting to map station different from one used in PrepareToMap call."; 
			break;
		case 0x80041389: 
			err_msg += "Robot reference has not been set for this mapper."; 
			break;
		case 0x8004138a: 
		    err_msg += "No latch data available No detection of material was found when performed mapping calibration."; 
			err_msg += "\n";
			err_msg += "The same will appear when running in Simulation mode and perform Calibration."; 
			break;
		case 0x8004138b: 
			err_msg += "Unexpected mapper latch data received."; 
			break;

		// Load Port Exception
		case 0x80041400: 
			err_msg += "Carrier ID read error.";
			break;
		case 0x80041401: 
			err_msg += "Pod clamping error.";
			break;
		case 0x80041402: 
			err_msg += "Load port is not in loaded state.";
			break;
		case 0x80041403: 
			err_msg += "Paddle could not reach to extend position.";
			break;
		case 0x80041404: 
			err_msg += "Paddle could not reach to down position.";
			break;
		case 0x80041405: 
			err_msg += "Paddle could not reach to up position.";
			break;
		case 0x80041406: 
			err_msg += "Paddle could not reach to retract position.";
			break;
		case 0x80041407: 
			err_msg += "Pod door locking error.";
			break;
		case 0x80041408: 
			err_msg += "Pod is not placed.";
			break;
		case 0x80041409: 
			err_msg += "Pod is not present.";
			break;
		case 0x8004140a: 
			err_msg += "Pod door unlocking error.";
			break;
		case 0x8004140b: 
			err_msg += "Safety switch is activated.";
			break;
		case 0x8004140c: 
			err_msg += "Error occur during shuttle extending out.";
			break;
		case 0x8004140d: 
			err_msg += "Error occur during shuttle retracting in.";
			break;
		case 0x8004140e: 
			err_msg += "Pod unclamping error.";
			break;
		case 0x8004140f: 
			err_msg += "Could not establish vacuum.";
			break;
		case 0x80041410: 
			err_msg += "Wafer slide out sensor is active.";
			break;
		case 0x80041411: 
			err_msg += "No valid transition points/IO states were found during mapper calibration process.";
			break;
		case 0x80041412: 
			err_msg += "Wafer protruding from slot.";
			break;
		case 0x80041415: 
			err_msg += "Carrier not detected error.";
			break;
		case 0x80041416: 
			err_msg += "Load Failed.";
			break;
		case 0x80041417: 
			err_msg += "Unload Failed.";
			break;

		// Aligner Exception
		case 0x80041480: 
			err_msg += "The Eccentricity Magnitude exceeded the range of the Edge Sensor.";
			err_msg += "\n";
			err_msg += "  a. If the wafer was slipping during the rotation,"; 
			err_msg += "\n";
			err_msg += "    clean the aligner pads or check the wafer for cleanliness.";
			err_msg += "\n";
			err_msg += "  b. Placing the wafer on the aligner in a wrong location,";
			err_msg += "\n";
			err_msg += "    or with offsets will cause this issue."; 
			err_msg += "\n";
			err_msg += "    Make sure the teaching position of the aligner is correct.";
			err_msg += "\n";
			err_msg += "  c. Allowed range for detection and correction is +- 5mm.";
			break;
		case 0x80041483: 
			err_msg += "Material aligned for incorrect resource.";
			break;
		case 0x80041487: 
			err_msg += "Fiducial Location Unknown.";
			break;
		case 0x8004148D: 
			err_msg += "Invalid Z Position.";
			break;
		case 0x80041496: 
			err_msg += "Missing or extra data identified during data collection.";
			break;
		case 0x80041499: 
			err_msg += "No Data collected during the Trace.";
			break;
		case 0x8004149c: 
			err_msg += "Move in Robot Access List not valid for Robot.";
			break;
		case 0x8004149f: 
			err_msg += "The main feature for the calibration tool was not found.";
			break;
		case 0x800414a2: 
			err_msg += "Fiducial Not Found, Curve Fit Failed.";
			break;
		case 0x800414a3: 
			err_msg += "Fiducial Not Found, Fiducial Too Shallow.";
			break;
		case 0x800414a4: 
			err_msg += "Fiducial Not Found, Insufficient Data Samples.";
			break;
		case 0x800414A5:
			err_msg += "The actual number of Fingers found does not match Theta Chuck Configuration.";
			err_msg += "\n";
			err_msg += "  a. Refer to document # 136052 to perform the Zero position procedure.";
			break;
		case 0x800414a6: 
			err_msg += "This Field Does Not Exist in this Trace Data object.";
			break;
		case 0x800414a7: 
			err_msg += "This Resource Does Not Exist in this Trace Data object.";
			break;
		case 0x800414a8: 
			err_msg += "No Data corresponding to Field.";
			break;
		case 0x800414a9: 
			err_msg += "The Resource Field combination already exists in this Trace Data object.";
			break;
		case 0x800414aa: 
			err_msg += "The actual Finger Positions do not match the Theta Chuck Configuration.";
			break;
		case 0x800414ab: 
			err_msg += "The Zero Position of the Theta Chuck is offset from the Configuration.";
			break;
		case 0x800414ad: 
			err_msg += "Fiducial Not Found, detected excessive sensor overshoot near the theta chuck fingers.";
			break;

		// Safety Exception
		case 0x80041500: 
			err_msg += "The System Control Output has not been set.";
			break;
		case 0x80041501: 
			err_msg += "The Safety Control Node is missing or has been disconnected.";
			break;
		case 0x80041502: 
			err_msg += "The Safety Control Mode is in an Error Stat.";
			break;
		case 0x80041503: 
			err_msg += "The Safety Control Mode has been halted.";
			break;

		// PlugIn Exception
		case 0x80041580: 
			err_msg += "A Plug in error was generated, type Help PlugInError with the secondary error code.";
			break;


		default:
			err_msg += "Check Error Manual ...";
			break;
	}

	err_msg += "\n";
	return err_msg;
}

CString CObj__Driver_FUSION
::Get__Motion_Secondary_Error_Msg_Of_Error_Code(const int err_code)
{
	CString err_msg;

	err_msg.Format("Motion Secondary Error Code : %1d", err_code);
	err_msg += "\n";

	switch(err_code)
	{
		// Code Description
		case 0x201: 
			err_msg += "ErrUnknownError"; 
			err_msg += "\n";
			err_msg += "Unhandled or Unknown Exception, usually not recoverable fatal failure";
			break;
		case 0x202: 
			err_msg += "ErrNotConfigured"; 
			err_msg += "\n";
			err_msg += "Robot is Not Configured";
			break;
		case 0x203: 
			err_msg += "ErrInvalidConfiguration"; 
			err_msg += "\n";
			err_msg += "Configuration value(s) may be wrong or internal software error.";
			break;
		case 0x204: 
			err_msg += "ErrNotCalibrated"; 
			err_msg += "\n";
			err_msg += "Robot is Not Calibrated";
			break;
		case 0x205: 
			err_msg += "ErrMotorOnline"; 
			err_msg += "\n";
			err_msg += "Illegal command when Motor is Online";
			break;
		case 0x206: 
			err_msg += "ErrServoEnabled"; 
			err_msg += "\n";
			err_msg += "Illegal command when Servo is Enabled";
			break;
		case 0x207: 
			err_msg += "ErrMotorOffline"; 
			err_msg += "\n";
			err_msg += "Illegal command when Motor is Offline";
			break;
		case 0x208: 
			err_msg += "ErrIllegalArgument"; 
			err_msg += "\n";
			err_msg += "Parameter(s) may be wrong because of wrong user input"; 
			err_msg += "\n";
			err_msg += "or because internal software error.";
			break;
		case 0x209: 
			err_msg += "ErrJogModeDisabled"; 
			err_msg += "\n";
			err_msg += "Attempted move when Jog mode is disabled";
			break;
		case 0x210: 
			err_msg += "ErrAbortInProgress"; 
			err_msg += "\n";
			err_msg += "Illegal command when Abort is in progress";
			break;
		case 0x21D: 
			err_msg += "ErrKinInvalidOrientation"; 
			err_msg += "\n";
			err_msg += "Wrong arm orientation or handedness or wrong move target position.";
			break;
		case 0x21E: 
			err_msg += "ErrKinTooClose"; 
			err_msg += "\n";
			err_msg += "Robot is commanded to go to singularity position.";
			break;
		case 0x21F: 
			err_msg += "ErrKinSingularity"; 
			err_msg += "\n";
			err_msg += "Robot is commanded to go to singularity position.";
			break;
		case 0x221: 
			err_msg += "ErrOutOfRange";
			err_msg += "\n";
			err_msg += "Robot kinematics or joint range check failure."; 
			err_msg += "\n";
			err_msg += "Means that something was asked to calculate or to go over mathematically reachable,"; 
			err_msg += "\n";
			err_msg += "or over configured, limits";
			break;
		case 0x222: 
			err_msg += "ErrSettlingTimeout";
			err_msg += "\n";
			err_msg += "Settling verification if the checks are not fulfilled within configured time.";
			err_msg += "\n";
			err_msg += "The first check is whether commanded velocity is 0 and the second";
			err_msg += "\n";
			err_msg += "whether actual positions and velocities are in required windows.";
			err_msg += "\n";
			err_msg += "The first check is done even if settling is not required for the given move";
			break;
		case 0x223: 
			err_msg += "ErrTrajectoryDisabled"; 
			err_msg += "\n";
			err_msg += "Move or jog command when Halting or Aborting is in progress Jog";
			err_msg += "\n";
			err_msg += "Disabled when robot is still moving";
			break;
		case 0x224: 
			err_msg += "ErrMovePending"; 
			err_msg += "\n";
			err_msg += "Move or jog command, when move leg queue is full.";
			break;
		case 0x225: 
			err_msg += "ErrKinInvalidHandedness"; 
			err_msg += "\n";
			err_msg += "Robot is commanded to invalid handedness change.";
			break;
		case 0x226: 
			err_msg += "ErrAmpReported"; 
			err_msg += "\n";
			err_msg += "Amplifier Hardware reported error";
			break;
		case 0x230: 
			err_msg += "ErrBadDesiredBuffSize"; 
			err_msg += "\n";
			err_msg += "Configuration value(s) may be wrong or internal software error";
			break;
		case 0x231: 
			err_msg += "ErrIllegalFrameType";
			err_msg += "\n";
			err_msg += "Configuration value(s) may be wrong or internal software error";
			break;
		case 0x232: 
			err_msg += "ErrTraceTimeout"; 
			err_msg += "\n";
			err_msg += "Aligner or trace data timeout.";
			break;
		case 0x233: 
			err_msg += "ErrJogModeEnabled"; 
			err_msg += "\n";
			err_msg += "Illegal move Jog Mode is Enabled";
			break;
		case 0x234: 
			err_msg += "ErrServoDisabled"; 
			err_msg += "\n";
			err_msg += "Illegal command when Servo is Disabled";
			break;
		case 0x235: 
			err_msg += "ErrEmoActive"; 
			err_msg += "\n";
			err_msg += "Illegal command when EMO state is active";
			break;
		case 0x250: 
			err_msg += "ErrDriveNetwork"; 
			err_msg += "\n";
			err_msg += "Unhandled or Unknown Network driver Exception, usually not recoverable failure";
			break;
		case 0x251: 
			err_msg += "ErrHWCommunication"; 
			err_msg += "\n";
			err_msg += "Amplifier communication error";
			break;
		case 0x252: 
			err_msg += "ErrEncoderValidator"; 
			err_msg += "\n";
			err_msg += "Amplifier feedback(encoder) error";
			break;
		case 0x253: 
			err_msg += "ErrOutOfResource"; 
			err_msg += "\n";
			err_msg += "Amplifier is out of tracing resources."; 
			err_msg += "\n";
			err_msg += "Reduce number of traced variables and try again";
			break;
		case 0x254: 
			err_msg += "ErrAmplifier"; 
			err_msg += "\n";
			err_msg += "Unknown Amplifier Error";
			break;
		case 0x255: 
			err_msg += "ErrReferencingError"; 
			err_msg += "\n";
			err_msg += "Reference strategy failure likely Amplifier related";
			break;

		default:
			err_msg += "Check Motion Eninge Secondary Error Manual ...";
			break;
	}

	err_msg += "\n";
	return err_msg;
}
