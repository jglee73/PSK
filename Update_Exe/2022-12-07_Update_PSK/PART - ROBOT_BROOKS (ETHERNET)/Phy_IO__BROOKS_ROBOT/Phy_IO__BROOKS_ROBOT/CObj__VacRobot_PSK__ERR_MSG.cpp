#include "StdAfx.h"
#include "CObj__VacRobot_PSK.h"


CString CObj__VacRobot_PSK
::Get__Error_Msg_Of_Error_Code(const int err_code)
{
	CString err_msg;

	err_msg.Format("Error_Code : %1d", err_code);
	err_msg += "\n";

	switch(err_code)
	{
		// Success Codes
		case 0:
			err_msg += "Command succeeded.";
			break;
		case 1:
			err_msg += "Command failed";
			break;
		case 2:
			err_msg += "MCC Error Already Displayed.";
			break;

		// Station Errors
		case 210:
			err_msg += "Not at Station.";
			break;
		case 211: 
			err_msg += "Invalid Arm type.";
			break;
		case 213: 
			err_msg += "W axis not at Home Position.";
			break;
		case 214: 
			err_msg += "WA axis not at Home Position.";
			break;
		case 215: 
			err_msg += "WB axis not at Home Position.";
			break;
		case 216: 
			err_msg += "A axis not at Home Position.";
			break;
		case 217: 
			err_msg += "S axis not at Home Position.";
			break;
		case 218: 
			err_msg += "Z axis not at Home Position.";
			break;
		case 219: 
			err_msg += "T axis not at Home Position.";
			break;
		case 220: 
			err_msg += "Radial axis not at retract position.";
			break;
		case 221: 
			err_msg += "Invalid Arm selection.";
			break;
		case 222: 
			err_msg += "Wrist axis not at unflipped position.";
			break;
		case 223: 
			err_msg += "Wrist axis not at flipped position.";
			break;
		case 224: 
			err_msg += "R and T axis must be referenced before homing this axis.";
			break;
		case 225: 
			err_msg += "Must do HOME ALL command.";
			break;
		case 226: 
			err_msg += "Wafer is present, must do HOME Z now.";
			break;
		case 227: 
			err_msg += "Robot is not at HOME position.";
			break;
		case 229: 
			err_msg += "Z Axis has been Referenced.";
			break;
		case 230: 
			err_msg += "Robot Extended to VCE.";
			break;
		case 231: 
			err_msg += "Atmospheric Robot Extended to VCE.";
			break;
		case 232: 
			err_msg += "Platform 97 Pneumatic Fault.";
			break;
		case 233: 
			err_msg += "Extend to station not enabled.";
			break;
		case 234: 
			err_msg += "Valve not closed.";
			break;
		case 240: 
			err_msg += "Unreferenced Move Duration Out of Range.";
			break;
		case 250: 
			err_msg += "No Multi-Pt move legs defined.";
			break;
		case 251: 
			err_msg += "Maximum number of Multi_Pt legs exceeded.";
			break;

		// User I/O - Command Parser Errors
		case 301: 
			err_msg += "Command argument already used.";
			err_msg += "\n";
			err_msg += "Part of a command has been duplicated (ex. GOTO N 1 N 2).";
			break;
		case 305: 
			err_msg += "Unknown command; Unrecognized command.";
			err_msg += "\n";
			err_msg += "An optional parameter is missing or the command was entered incorrectly.";
			break;
		case 306: 
			err_msg += "Value out of range.";
			break;
		case 309: 
			err_msg += "Command not supported.";
			err_msg += "\n";
			err_msg += "The command was recognized, but is not supported. Check the Application Number.";
			break;
		case 350: 
			err_msg += "Parser error, bad node in parse tree.";
			break;
		case 351: 
			err_msg += "Parser error, stack overflow.";
			break;
		case 352: 
			err_msg += "Parser error, no memory available.";
			break;
		case 353: 
			err_msg += "Unexpected mail to UIO task";
			break;
		case 390: 
			err_msg += "Checksum is invalid.";
			err_msg += "\n";
			err_msg += "Enter the command EEPROM RESET.";
			break;
		case 391: 
			err_msg += "No display handler found for this task.";
			break;

		// Station Setup Errors
		case 402: 
			err_msg += "Bad slot number.";
			break;
		case 405: 
			err_msg += "Bad Lower Position.";
			break;
		case 406: 
			err_msg += "Bad Pitch.";
			err_msg += "\n";
			err_msg += "The entered Pitch value yields an invalid value when multiplied by the number of slots.";
			break;
		case 407: 
			err_msg += "Bad T Position.";
			err_msg += "\n";
			err_msg += "Enter a theta position within the range of 0 to 360000, where 360000 represents 360 degrees.";
			err_msg += "\n";
			err_msg += "Robot theta positions are represented in millidegrees.";
			err_msg += "\n";
			err_msg += "1 degree of robot travel equals 1000 units. (T > 360° or T < 0°).";
			break;
		case 408: 
			err_msg += "Bad R Position.";
			err_msg += "\n";
			err_msg += "Value is either too small or too large for the arm to reach or an attempt was made to drive arm past its limits.";
			err_msg += "\n";
			err_msg += "Enter a radial position within the range of the radial home position and the maximum extension of the arm.";
			err_msg += "\n";
			err_msg += "The radial home position and maximum extension will vary depending on the size of the arm.";
			err_msg += "\n";
			err_msg += "Robot radial positions are represented in microns.";
			err_msg += "\n";
			err_msg += "Thus, 1 mm of robot travel equals 1000 units.";
			break;
		case 409: 
			err_msg += "Bad Z Position.";
			err_msg += "\n";
			err_msg += "Value is either too small or too large for the arm to reach or an attempt was made to drive the	arm past its limits.";
			err_msg += "\n";
			err_msg += "Enter a Z position within the range of 0 to the maximum Z height.";
			err_msg += "\n";
			err_msg += "Maximum Z heights vary pending robot model.";
			err_msg += "\n";
			err_msg += "Robot Z positions are represented in microns."; 
			err_msg += "\n";
			err_msg += "Thus, 1mm of robot travel equals 1000 units.";
			err_msg += "\n";
			err_msg += "If the maximum Z height is unknown, issue the command: RQ ARMS ALL.";
			err_msg += "\n";
			err_msg += "The maximum Z height is indicated in the line “total z travel---”.";
			err_msg += "\n";
			err_msg += "The response is in meters.";
			break;
		case 410: 
			err_msg += "Bad S Position.";
			break;
		case 413: 
			err_msg += "Robot Active Wafer Centering Invalid.";
			err_msg += "\n";
			err_msg += "Cannot modify until WAF_CEN cleared.";
			err_msg += "\n";
			err_msg += "Wafer centering sensor location and delays need to be cleared before changes";
			break;
		case 414: 
			err_msg += "Push value must be Positive.";
			break;
		case 415: 
			err_msg += "Station R+PUSH value is Invalid.";
			break;
		case 416: 
			err_msg += "Station not initialized.";
			break;
		case 417: 
			err_msg += "Offset too large.";
			break;
		case 418: 
			err_msg += "Bad retract position.";
			err_msg += "\n";
			err_msg += "Invalid RTRCT2.";
			break;
		case 419: 
			err_msg += "Cannot modify STN until VIA cleared.";
			break;
		case 420: 
			err_msg += "Invalid Station Parameter.";
			break;
		case 421: 
			err_msg += "VIA point not defined.";
			break;
		case 422: 
			err_msg += "VIA point required, but not set.";
			break;
		case 423: 
			err_msg += "VIA point set, but not CURVE_MOTION Option.";
			break;
		case 424: 
			err_msg += "Bad W Unflipped Position.";
			break;
		case 425: 
			err_msg += "Bad W Flipped Position.";
			break;
		case 426: 
			err_msg += "Bad Via PosR.";
			break;
		case 427: 
			err_msg += "Bad Via PosT.";
			break;
		case 428: 
			err_msg += "Bad Station Retract Offset.";
			break;
		case 429: 
			err_msg += "Bad Station Blend PosR.";
			break;
		case 430: 
			err_msg += "Bad Station Blend PosT.";
			break;
		case 431: 
			err_msg += "Bad Station Blend PosZ.";
			break;
		case 432: 
			err_msg += "Bad Station Blend PosW.";
			break;
		case 433: 
			err_msg += "Bad Map VIA PosR.";
			break;
		case 434: 
			err_msg += "Bad Map VIA PosT.";
			break;
		case 435: 
			err_msg += "Bad W Position.";
			break;
		case 436: 
			err_msg += "Bad station Top Slot PosR.";
			break;
		case 437: 
			err_msg += "Bad station Top Slot PosT.";
			break;
		case 438: 
			err_msg += "Interpolate Slots Option required, but not set.";
			break;
		case 439: 
			err_msg += "Bad speed index. Invalid VIA parameter.";
			break;
		case 440: 
			err_msg += "Bad VIA Pos W.";
			err_msg += "\n";
			err_msg += "Interpolate Slots Option Set, but Top Slot not Taught.";
			err_msg += "\n";
			err_msg += "VIA point and final position must have the same rVal sign.";
			err_msg += "\n";
			err_msg += "During extend, the robot checks the sign of the radial value for the VIA point and final destination.";
			err_msg += "\n";
			err_msg += "If they are of different sign (one above zero and the other below), then the move is not allowed.";
			break;
		case 441: 
			err_msg += "Bad map VIA PosW.";
			break;
		case 442: 
			err_msg += "Invalid wrist type.";
			err_msg += "\n";
			err_msg += "For example, attempting to use Rotary Limited Wrist commands on a Continuous Rotational Wrist.";
			break;
		case 443: 
			err_msg += "Invalid station type.";
			break;
		case 444: 
			err_msg += "Bad Speed Index.";
			break;
		case 445: 
			err_msg += "VIA Point and Final Position must have the same rVal Sign.";
			break;
		case 446: 
			err_msg += "Invalid grip type.";
			break;
		case 447: 
			err_msg += "Bad A position.";
			break;
		case 448: 
			err_msg += "Double Move not allowed.";
			break;
		case 449: 
			err_msg += "Double Move required.";
			break;
		case 450: 
			err_msg += "Invalid Station Position, Axis Limits Exceeded.";
			break;
		case 451: 
			err_msg += "Maximum Deviation Limit Exceeded.";
			err_msg += "\n";
			err_msg += "Wafer deviation is out of the required limits.";
			err_msg += "\n";
			err_msg += "See MAX_DEV and MAX_PICK_DEV parameters.";
			break;
		case 452: 
			err_msg += "Station PUSH value not set.";
			break;
		case 453: 
			err_msg += "Station SAFETY value not set.";
			break;
		case 454: 
			err_msg += "Bad Z_WAF: value is greater than the Lower value.";
			break;
		case 455: 
			err_msg += "No Paths available.";
			break;
		case 456: 
			err_msg += "Path Point Number is out of range.";
			break;
		case 457: 
			err_msg += "Bad Path Point R position.";
			break;
		case 458: 
			err_msg += "Bad Path Point T position.";
			break;
		case 459: 
			err_msg += "Bad Path Point Z position.";
			break;
		case 460: 
			err_msg += "Bad Path Point W position.";
			break;
		case 461: 
			err_msg += "Bad Path Point WA position.";
			break;
		case 462: 
			err_msg += "Bad Path Point WB position.";
			break;
		case 463: 
			err_msg += "Bad Path Point S position.";
			break;
		case 464: 
			err_msg += "Path not initialized.";
			break;
		case 465: 
			err_msg += "Path not valid.";
			break;
		case 466: 
			err_msg += "Path not initialized.";
			break;
		case 467: 
			err_msg += "Path doesn’t have SWAP Point.";
			break;
		case 468: 
			err_msg += "Not currently on Path or at Path Station.";
			break;
		case 469: 
			err_msg += "Bad Path Swap Point.";
			break;
		case 470: 
			err_msg += "Path execution stopped at Interlock Point.";
			break;
		case 471: 
			err_msg += "Robot is not extended.";
			break;
		case 472: 
			err_msg += "Bad Path Interlock Point.";
			break;
		case 473: 
			err_msg += "Invalid AS_PREV <-> AS_NEXT usage.";
			break;
		case 474: 
			err_msg += "Bad Distance Value.";
			break;
		case 475: 
			err_msg += "Robot is not on any Path.";
			break;
		case 476: 
			err_msg += "Robot is not on this Path.";
			break;
		case 477: 
			err_msg += "Cannot backup through Swap Point.";
			break;
		case 478: 
			err_msg += "Path already exists.";
			break;
		case 479: 
			err_msg += "AS_NEXT data crosses Swap Point.";
			break;
		case 480: 
			err_msg += "AS_PREV data crosses Swap Point.";
			break;
		case 481: 
			err_msg += "No Empty Path Points.";
			break;
		case 482: 
			err_msg += "Path Point Already Exists.";
			break;
		case 483: 
			err_msg += "Cannot Clear Last Initialized Path Point.";
			err_msg += "\n";
			err_msg += "That Combination of Offsets is Not Allowed.";
			break;
		case 484: 
			err_msg += "Cannot Back-Up Beyond the Jump Point.";
			break;
		case 485: 
			err_msg += "Cannot Jump to the Specified Path.";
			break;
		case 491: 
			err_msg += "Unknown speed type.";
			break;
		case 492: 
			err_msg += "Unknown window type.";
			break;

		// Robot Internal Errors
		case 508: 
			err_msg += "Wafer sensor not defined.";
			break;
		case 509: 
			err_msg += "No Z-axis on robot.";
			err_msg += "\n";
			err_msg += "Check the Application Number.";
			err_msg += "\n";
			err_msg += "This error can also occur on the aligner if a MOV Z is commanded to a single axis aligner or";
			err_msg += "\n";
			err_msg += "an 2-axis aligner with the incorrect Application Number.";
			break;
		case 510: 
			err_msg += "No W-axis on arm.";
			err_msg += "\n";
			err_msg += "The armset does not have a Rotating Wrist.";
			break;
		case 511: 
			err_msg += "No R-axis on robot.";
			break;
		case 512: 
			err_msg += "No Articulated Wrist on Robot.";
			err_msg += "\n";
			err_msg += "For DFR: No T3 Axis on Robot.";
			break;
		case 513: 
			err_msg += "No A axis on Robot.";
			break;
		case 514: 
			err_msg += "Not a 5-axis Robot.";
			break;
		case 515: 
			err_msg += "No T3 axis on Robot.";
			break;
		case 527: 
			err_msg += "MCC communication error.";
			break;
		case 528: 
			err_msg += "MCC Queue Full.";
			break;
		case 529: 
			err_msg += "Could not calculate command ID.";
			break;
		case 550: 
			err_msg += "Station parameter out of range.";
			break;
		case 551: 
			err_msg += "Number of Iterations Exceeded.";
			break;
		case 552: 
			err_msg += "Sensor out of range.";
			break;
		case 553: 
			err_msg += "No S axis on robot.";
			break;
		case 554: 
			err_msg += "Cannot resume due to unsuccessful HALT.";
			break;
		case 555: 
			err_msg += "Cannot resume because robot not HALTED.";
			break;
		case 556: 
			err_msg += "Robot did not respond.";
			break;
		case 557: 
			err_msg += "Robot Mapping Failure.";
			break;
		case 558: 
			err_msg += "Robot unknown.";
			break;

		// Dispatcher/Communications Errors
		case 602: 
			err_msg += "Command sequencer busy.";
			err_msg += "\n";
			err_msg += "Wait for the robot or aligner to complete its last operation.";
			err_msg += "\n";
			err_msg += "If the error persists, reset the robot by issuing the RESET command or toggling power.";
			break;
		case 603: 
			err_msg += "Command halted.";
			err_msg += "\n";
			err_msg += "A HALT command was issued to stop robot or aligner motion.";
			err_msg += "\n";
			err_msg += "The robot remains referenced.";
			break;
		case 604: 
			err_msg += "CDM in control of the robot.";
			err_msg += "\n";
			err_msg += "The command issued requires control of the robot.";
			err_msg += "\n";
			err_msg += "Turn off the CDM prior to continuing.";
			break;
		case 605: 
			err_msg += "Digital I/O in control of robot.";
			err_msg += "\n";
			err_msg += "To release digital I/O control of robot, enter the command DIO STOP.";
			err_msg += "\n";
			err_msg += "Refer to DIO START/STOP for additional information.";
			break;
		case 606: 
			err_msg += "Serial I/O in control of robot.";
			err_msg += "\n";
			err_msg += "To initiate digital I/O control of robot, enter the command DIO START.";
			break;
		case 607: 
			err_msg += "MCC processor not alive.";
			err_msg += "\n";
			err_msg += "If an error occurs after a software update, enter CONFIG ROBOT APPLIC and RESET.";
			err_msg += "\n";
			err_msg += "Power cycle the robot or the aligner.";
			err_msg += "\n";
			err_msg += "Check for loose cables.";
			err_msg += "\n";
			err_msg += "Replace the Driver Board.";
			break;
		case 608: 
			err_msg += "Robot halting.";
			err_msg += "\n";
			err_msg += "A \"halt\" command has been issued to the robot which stops robot motion.";
			break;
		case 610: 
			err_msg += "Emergency stop on.";
			err_msg += "\n";
			err_msg += "The EMER_STOP interlock for the robot has been activated.";
			err_msg += "\n";
			err_msg += "Verify that a robot Emergency Stop (EMS) button has been activated and deactivate as appropriate.";
			err_msg += "\n";
			err_msg += "Check host controller software.";
			break;
		case 611: 
			err_msg += "Warning, CDM has been turned on.";
			break;
		case 612: 
			err_msg += "Warning, CDM has been turned off.";
			break;
		case 613: 
			err_msg += "UPS Battery is low.";
			err_msg += "\n";
			err_msg += "The UPS_BATTERY_SEN interlock for the robot has been activated.";
			err_msg += "\n";
			err_msg += "  • Refer to Start-up on page 6-69 for correct operation.";
			err_msg += "\n";
			err_msg += "    The PowerPak accessory is programmed using the UPS_BATTERY_SEN interlock function,";
			err_msg += "\n";
			err_msg += "    and the internal PowerPak battery voltage is less than 23.5 volts.";
			err_msg += "\n";
			err_msg += "    Recharge or replace PowerPak as appropriate.";
			err_msg += "\n";
			err_msg += "  • Check host controller software.";
			err_msg += "\n";
			err_msg += "  • Refer toOperational Interlock Related Issues on page 10-13.";
			break;
		case 614: 
			err_msg += "Liquid Detection Sensor Activated.";
			err_msg += "\n";
			err_msg += "Liquid Detected on End Effector.";
			err_msg += "\n";
			err_msg += "WAVE II 2.07: Liquid Detected in Facilities Box Reservoir.";
			break;
		case 652: 
			err_msg += "Unable to create command dispatcher.";
			break;
		case 653: 
			err_msg += "Unexpected mail received by dispatcher.";
			break;
		case 654: 
			err_msg += "Unknown command.";
			break;
		case 655: 
			err_msg += "Bad parameter passed to dispatcher.";
			break;
		case 656: 
			err_msg += "Command processing has finished.";
			break;
		case 657: 
			err_msg += "Software is not compatible with Personality Board.";
			break;
		case 658: 
			err_msg += "This command is not allowed at this time.";
			err_msg += "\n";
			err_msg += "Command conflicts with commands already executing.";
			err_msg += "\n";
			err_msg += "SET and STORE commands cannot be entered while action commands are being executed.";
			break;
		case 659: 
			err_msg += "Invalid command identifier.";
			err_msg += "\n";
			err_msg += "For example 100 LDPT A LOAD or no number LDPT A LOAD.";
			break;
		case 660: 
			err_msg += "Command identifier already in use.";
			break;
		case 661: 
			err_msg += "Out of command execution queue space.";
			break;
		case 662: 
			err_msg += "Invalid device identifier.";
			break;
		case 670: 
			err_msg += "Command not allowed in TCL ON mode.";
			break;

		// Wafer Sensor Errors
		case 700: 
			err_msg += "Wafer detected.";
			err_msg += "\n";
			err_msg += "If it is verified that a wafer is not present, verify the facility vacuum is operating at the correct specifications.";
			err_msg += "\n";
			err_msg += "Verify the Digital Pressure Sensor is set properly.";
			err_msg += "\n";
			err_msg += "Check the Vacuum Sensor.";
			break;
		case 701: 
			err_msg += "No Wafer detected.";
			break;
		case 705: 
			err_msg += "Wafer missing";
			err_msg += "\n";
			err_msg += "Ensure wafer is present in station prior to issuing PICK/PLACE/GOTO/XFER command.";
			break;
		case 706: 
			err_msg += "Wafer sensed";
			err_msg += "\n";
			err_msg += "Ensure slot in VCE or process module is empty prior to issuing PICK/PLACE/GOTO/XFER command.";
			break;
		case 710: 
			err_msg += "Slot valve closed prior to PICK, PLACE, GOTO, or XFER.";
			break;
		case 711: 
			err_msg += "Slot valve not open.";
			break;
		case 712: 
			err_msg += "Vacuum Grip Failure";
			err_msg += "\n";
			err_msg += "Occurs during a PICK operation"; 
			err_msg += "\n";
			err_msg += "  if successful vacuum gripping is NOT detected for the specified arm at the completion of the operation,";
			err_msg += "\n";
			err_msg += "  whether the arm is retracted or not.";
			err_msg += "\n";
			err_msg += "Occurs during a PLACE operation";
			err_msg += "\n";
			err_msg += "  if successful vacuum gripping is NOT detected for the specified arm prior to placing the wafer.";
			err_msg += "\n";
			err_msg += "Occurs during either the PICK or PLACE portion of a XFER operation.";
			err_msg += "\n";
			err_msg += "Occurs during a GOTO operation";
			err_msg += "\n";
			err_msg += "  if successful vacuum gripping is NOT detected for the specified arm prior to the specified motion.";
			err_msg += "\n";
			err_msg += "For the aligner, occurs after an ALGN and no wafer was present.";
			err_msg += "\n";
			err_msg += "  May also occur during a vacuum system failure of the pins or chuck.";
			err_msg += "\n";
			err_msg += "  See the aligner manual for troubleshooting.";
			break;;
		case 714: 
			err_msg += "Slow Vacuum Grip";
			err_msg += "\n";
			err_msg += "Occurs during a PICK operation";
			err_msg += "\n";
			err_msg += "  if successful vacuum gripping is NOT detected for the specified arm";
			err_msg += "\n";
			err_msg += "  when a wafer has been picked up and the robot arm is still extended,"; 
			err_msg += "\n";
			err_msg += "  but IS detected at the completion of the operation.";
			break;
		case 715: 
			err_msg += "Possible Material on Arm.";
			break;
		case 716: 
			err_msg += "Command Not Allowed While Chuck is Holding Wafer.";
			err_msg += "\n";
			err_msg += "Occurs if the user attempts to select a different wafer size after the wafer has been placed on the	aligner.";
			break;
		case 721:
			err_msg += "GRIP is not ON.";
			err_msg += "\n";
			err_msg += "Ensure wafer sensors are operating properly.";
			err_msg += "\n";
			err_msg += "Ensure slot valve is operating properly.";
			err_msg += "\n";
			err_msg += "Ensure slot valve is open prior to issuing PICK/PLACE/GOTO/XFER command.";
			err_msg += "\n";
			err_msg += "Check host controller software.";
			err_msg += "\n";
			err_msg += "Refer to Operational Interlock Related Issues on page 10-13.";
			break;
		case 722: 
			err_msg += "GRIP is OFF.";
			err_msg += "\n";
			err_msg += "Ensure wafer sensors are operating properly.";
			err_msg += "\n";
			err_msg += "Ensure slot valve is open prior to issuing PICK/PLACE/GOTO/XFER command.";
			err_msg += "\n";
			err_msg += "Check host controller software.";
			err_msg += "\n";
			err_msg += "Refer to Operational Interlock Related Issues on page 10-13.";
			break;
		case 723: 
			err_msg += "GRIP is not OFF.";
			break;
		case 724: 
			err_msg += "GRIP is at Over Travel Position.";
			break;
		case 725: 
			err_msg += "GRIP is not at Over Travel Position.";
			break;
		case 730: 
			err_msg += "Error prior to PLACE: No Wafer Sensed.";
			break;
		case 731: 
			err_msg += "Error after a PLACE: Wafer Sensed.";
			break;
		case 732: 
			err_msg += "Error after PLACE: Arm Extended and Wafer Sensed.";
			break;
		case 733: 
			err_msg += "Error prior PLACE: Wafer Sensed on Left PAN.";
			break;
		case 734: 
			err_msg += "R_MT waf sensor error on PLACE: No Wafer Sensed during Extend.";
			break;
		case 735: 
			err_msg += "R_MT wafer sensor failure.";
			break;
		case 736: 
			err_msg += "R_MT wafer sensor error on PLACE: Wafer sensed during Retract.";
			break;
		case 738: 
			err_msg += "Active option in GOTO supported for R_MT wafer sensor only.";
			break;
		case 739: 
			err_msg += "R_MT wafer sensor error: Wafer sensed on MAT_OFF move.";
			break;
		case 740: 
			err_msg += "Error prior to a PICK: Wafer Sensed.";
			break;
		case 741: 
			err_msg += "Error after a PICK: No Wafer Sensed.";
			break;
		case 742: 
			err_msg += "EX wafer sensor error prior to a PICK: No Wafer Sensed.";
			break;
		case 743: 
			err_msg += "Station Has No Wafer Sensor.";
			break;
		case 744: 
			err_msg += "R_MT wafer sensor error on PICK: Wafer Sensed during Extend.";
			break;
		case 745: 
			err_msg += "R_MT wafer sensor error on PICK: No Wafer Sensed during Retract.";
			break;
		case 749: 
			err_msg += "R_MT wafer sensor error: No Wafer Sensed on MAT_ON move.";
			break;
		case 750: 
			err_msg += "No station with wafer sensor found for Arm A.";
			break;
		case 751: 
			err_msg += "No station with wafer sensor found for Arm B.";
			break;
		case 752: 
			err_msg += "RE wafer sensor error: Wafer Sensed on MAT_OFF move.";
			break;
		case 753: 
			err_msg += "RE wafer sensor error: No Wafer Sensed on MAT_ON move.";
			break;
		case 754: 
			err_msg += "EX wafer sensor error: Wafer Sensed on MAT_OFF move.";
		case 755: 
			err_msg += "PAN vacuum initialization error.";
			break;
		case 756: 
			err_msg += "Vacuum disabled.";
			break;
		case 757: 
			err_msg += "No Vacuum Grip on Arm.";
		case 758: 
			err_msg += "Wafer Sensed on MAT_OFF move.";
		case 759: 
			err_msg += "No Wafer Sensed on MAT_ON move.";
		case 760: 
			err_msg += "Possible Material on Arm A.";
			err_msg += "\n";
			err_msg += "No Active Grip on Arm.";
			err_msg += "\n";
			err_msg += "Occurs if a GRIP ON or OFF command is attempted on an arm without Active Grip end effector.";
			break;
		case 761: 
			err_msg += "Active Grip failure.";
			err_msg += "\n";
			err_msg += "Occurs after a failed PICK or PLACE operation.";
			break;
		case 762: 
			err_msg += "EX wafer sensor error: Wafer Sensed on MAT_ON move.";
			break;
		case 770: 
			err_msg += "Wafer Position Sensor Not Defined.";
			err_msg += "\n";
			err_msg += "AWC requires at least 2 sensors.";
			err_msg += "\n";
			err_msg += "If AWC is SINGLE_SENS, this error occurs when the sensor is not defined.";
			break;
		case 771: 
			err_msg += "Invalid Wafer Position Capture Data.";
			err_msg += "\n";
			err_msg += "Invalid Amount of Sensor Data.";
			err_msg += "\n";
			err_msg += "Wafer Position Sensor 1: Invalid Number of Data.";
			err_msg += "\n";
			err_msg += "Amount of received data from any sensor is out of the exprectable range.";
			err_msg += "\n";
			err_msg += "Each Active Wafer Sensor must capture a minimum of two data points (leading edge and trailing edge)";
			err_msg += "\n";
			err_msg += "and a maximum of 20 points is allowed.";
			err_msg += "\n";
			err_msg += "This error is normally reported if a PLACE command was entered without a wafer on the end effector.";
			err_msg += "\n";
			err_msg += "Number of received transition from sensor 1 (Right) is invalid: or less than 2 or more than 20.";
			err_msg += "\n";
			err_msg += "This error code is changed in WAVE 11 1.0P.";
			break;

		case 772: 
			err_msg += "Broken wafer encountered.";
			err_msg += "\n";
			err_msg += "If this error is reported on an unbroken wafer, increase the BREAK_THR parameter.";
			break;
		case 773: 
			err_msg += "Debounce Required on Sensor 1.";
			err_msg += "\n";
			err_msg += "WAVE II 1.2P: Wafer position centering is not enabled.";
			err_msg += "\n";
			err_msg += "An AWC FIND command was issued while AWC feature was disabled.";
			break;
		case 774: 
			err_msg += "Debounce Required on Sensor 2.";
			err_msg += "\n";
			err_msg += "Sensor Data Invalid.";
			err_msg += "\n";
			err_msg += "Position readings of Active Wafer Center is not what was expected causing algorithm to fail.";
			err_msg += "\n";
			err_msg += "If AWC is set to SINGLE_SENS, the sensor has not been calibrated,";
			err_msg += "\n";
			err_msg += "  the calibration results were not stored,";
			err_msg += "\n";
			err_msg += "  or the wafer size changed without recalibrating the sensor.";
			break;
		case 775: 
			err_msg += "Wafer Centering is Not Enabled.";
			err_msg += "\n";
			err_msg += "Data received from sensor 2 (left) caused numbered error during wafer offset calculation.";
			err_msg += "\n";
			err_msg += "This error is used in WAVE II series 1.0X only.";
			break;
		case 776: 
			err_msg += "Wafer Position Sensor 2: Invalid Number of Data";
			err_msg += "\n";
			err_msg += "Number of received transitions from sensor 2 (left) is invalid: or less than 2, or more than 20.";
			err_msg += "\n";
			err_msg += "This error is removed in WAVE II 1.0P and greater.";
			break;
		case 777: 
			err_msg += "Unable to calculate wafer offsets.";
			err_msg += "\n";
			err_msg += "The AWC maximum number of iteration was exceeded during least-square fit algorithm.";
			break;
		case 778: 
			err_msg += "Error: Sensor not found.";
			err_msg += "\n";
			err_msg += "Wafer Position Sensors Not Found.";
			err_msg += "\n";
			err_msg += "Automatic AWC calibration routine to determine wafer position has failed.";
			err_msg += "\n";
			err_msg += "If AWC is set to SINGLE_SEN, the calibrated wafer is not in the center of the end effector.";
			break;

		case 779: 
			err_msg += "STRT_NR missing.";
			err_msg += "\n";
			err_msg += "Motion Option Mismatch.";
			err_msg += "\n";
			err_msg += "STRT_NR option was set to Y, but PLACE was issued without STRT_NT.";
			break;
		case 780: 
			err_msg += "Error: Sensor Range.";
			err_msg += "\n";
			err_msg += "WAVE II 1.X: Sensor Number Out of Range.";
			err_msg += "\n";
			err_msg += "User’s sensor specification is out of allowable range.";
			err_msg += "\n";
			err_msg += "The Active Wafer Centering feature supports up to four sensors (range 1-4).";
			break;
		case 781: 
			err_msg += "Retract position for Wa/Wb is not allowed (disabled).";
			break;
		case 790: 
			err_msg += "Compatibility error.";
			err_msg += "\n";
			err_msg += "Unsupported command in the current mode.";
			err_msg += "\n";
			err_msg += "Command is not supported in current Compatibility Mode.";
			err_msg += "\n";
			err_msg += "Command syntax is correct, but the command is not supported in the current Active Wafer	Centering mode.";
			break;
		case 791: 
			err_msg += "No Valid Data Available.";
			err_msg += "\n";
			err_msg += "Data is available after a PLACE to a station that has the WAF_CEN feature enabled.";
			break;

		// Configuration Errors
		case 800: 
			err_msg += "Bad configuration name.";
			err_msg += "\n";
			err_msg += "Verify application number is valid.";
			err_msg += "\n";
			err_msg += "Refer to robot Quality Report (QR) that is shipped with the robot.";
			err_msg += "\n";
			err_msg += "Check the software version (RQ VERSION) and verify it matches the application.";
			break;
		case 801: 
			err_msg += "Database checksum error.";
			err_msg += "\n";
			err_msg += "Issue an EEPROM RESET command.";
			break;
		case 802: 
			err_msg += "Application name not found.";
			break;
		case 803: 
			err_msg += "Servo not configured.";
			break;
		case 804: 
			err_msg += "Motor not configured.";
			break;
		case 805: 
			err_msg += "Illegal configuration for this command.";
			err_msg += "\n";
			err_msg += "For errors 805 to 830, re-enter the application number.";
			err_msg += "\n";
			err_msg += "If the problem persists and the error occurred after a firmware upgrade, repeat the upgrade.";
			break;
		case 810: 
			err_msg += "Cannot open Master configuration file.";
			break;
		case 811: 
			err_msg += "Cannot read from Master configuration file.";
			break;
		case 812: 
			err_msg += "Cannot open Object data file.";
			break;
		case 813: 
			err_msg += "Cannot read from Object data file.";
			break;
		case 814: 
			err_msg += "Cannot open Object master file.";
			break;
		case 815: 
			err_msg += "Cannot read from Object master file.";
			break;
		case 816: 
			err_msg += "Cannot open Current configuration file.";
			break;
		case 817: 
			err_msg += "Cannot read from Current configuration file.";
			break;
		case 818: 
			err_msg += "Cannot write to Current Configuration file.";
			break;
		case 819: 
			err_msg += "Object checksum error.";
			break;
		case 820: 
			err_msg += "Could not send generic object to MCC";
			break;
		case 821: 
			err_msg += "Object not found.";
			break;
		case 822: 
			err_msg += "Object not valid for current configuration.";
			break;
		case 823: 
			err_msg += "Bad group type.";
			break;
		case 824: 
			err_msg += "Bad group name.";
			break;
		case 825: 
			err_msg += "Group not found.";
			break;
		case 826: 
			err_msg += "Group not valid for current configuration.";
			break;
		case 827: 
			err_msg += "Configuration message to MCC timed out.";
			break;
		case 828: 
			err_msg += "Object process error. Wrong configuration??";
			break;
		case 829: 
			err_msg += "Configuration is out of date. Must do reconfig.";
			break;
		case 830: 
			err_msg += "Not configured.";
			break;
		case 831: 
			err_msg += "Object cannot be stored.";
			break;
		case 832: 
			err_msg += "Object is Read Only.";
			break;
		case 833: 
			err_msg += "Configuration does not match Camera Board.";
			err_msg += "\n";
			err_msg += "Check aligner configuration number using command RQ CONFIG";
			err_msg += "\n";
			err_msg += "and verify the number is correct against the QR.";
			err_msg += "\n";
			err_msg += "Check the aligner setting on the Camera Board using the command RQ CAMERA.";
			err_msg += "\n";
			err_msg += "Check the firmware upgrade version using the command RQ VERSION.";
			err_msg += "\n";
			err_msg += "Check these setting against the Release Notes.";
			break;
		case 834: 
			err_msg += "Camera Board Communication Failure.";
			err_msg += "\n";
			err_msg += "Verify the aligner application number is correct.";
			err_msg += "\n";
			err_msg += "Issue the command RQ CAMERA.";
			err_msg += "\n";
			err_msg += "If the response is DICE, check position of the DIP switches on the Camera Board.";
			err_msg += "\n";
			err_msg += "If the response is NO CAMERA BOARD DETECTED, check the cable between the Video board and the Camera Board.";
			err_msg += "\n";
			err_msg += "Replace the Camera Board.";
			break;
		case 835: 
			err_msg += "Cannot read parameter (generic) file.";
			break;
		case 836: 
			err_msg += "Cannot write parameter (generic) file.";
			break;
		case 837: 
			err_msg += "Failed to load all parameters (generic).";
			break;
		case 838: 
			err_msg += "Invalid parameter (generic) group name.";
			break;
		case 839: 
			err_msg += "Invalid parameter (generic) reference.";
			break;
		case 840: 
			err_msg += "Invalid parameter (generic) type reference.";
			break;
		case 841: 
			err_msg += "Invalid parameter (generic) object.";
			break;
		case 842: 
			err_msg += "Cannot create parameter (generic) file.";
			break;
		case 843: 
			err_msg += "Cannot open parameter (generic) file.";
			break;
		case 844: 
			err_msg += "Invalid parameter (generic) file.";
			break;
		case 845: 
			err_msg += "Parameter (generic) group not found.";
			break;
		case 846: 
			err_msg += "Update generic parameter files.";
			break;
		case 847: 
			err_msg += "Cannot open Neural Network Configuration File.";
			break;
		case 848: 
			err_msg += "Cannot read from Neural Network Configuration File.";
			break;
		case 849: 
			err_msg += "Cannot write to Neural Network Configuration File.";
			break;
		case 850: 
			err_msg += "End of database found.";
			break;
		case 851: 
			err_msg += "Unable to read from database.";
			break;
		case 852: 
			err_msg += "Unable to write to database.";
			break;
		case 853: 
			err_msg += "Bad database handle found.";
			break;
		case 854: 
			err_msg += "Database full.";
			break;
		case 855: 
			err_msg += "Database not initialized.";
			break;
		case 856: 
			err_msg += "CCC configuration not correct.";
			break;
		case 857: 
			err_msg += "Configuration files have different stamps.";
			break;
		case 858: 
			err_msg += "Bad database record size.";
			break;
		case 860: 
			err_msg += "Bad parameter passes to memory system.";
			break;
		case 861: 
			err_msg += "No memory available for memory system.";
			break;
		case 862: 
			err_msg += "Partition currently in use.";
			break;

		// Monitor Errors
		case 900: 
			err_msg += "CAN channel not initialized.";
			break;
		case 901: 
			err_msg += "Cannot write to CAN channel.";
			break;
		case 902: 
			err_msg += "Timeout reading from CAN channel.";
			break;
		case 910: 
			err_msg += "Robot ID module (RAM) not initialized.";
			break;
		case 911: 
			err_msg += "Cannot read data from Robot ID Module (RIM).";
			break;
		case 912: 
			err_msg += "Cannot write data to Robot ID Module (RIM).";
			break;
		case 913: 
			err_msg += "Robot ID Module (RIM) overflow.";
			break;
		case 914: 
			err_msg += "File system on robot ID Module (RIM) not initialized.";
			break;
		case 915: 
			err_msg += "RAM disk not initialized.";
			break;
		case 920: 
			err_msg += "SmartKey not initialized.";
			err_msg += "\n";
			err_msg += "WAVE II 1.2 and 2.06: Drive Parameter module not initialized.";
			err_msg += "\n";
			err_msg += "Drive does not have a RIM module, RIM is dead, no CAN card, or CAN card is not functional.";
			break;
		case 921: 
			err_msg += "Cannot write to SmartKey.";
			err_msg += "\n";
			err_msg += "WAVE II 1.2 and 2.06: Drive Parameter error.";
			err_msg += "\n";
			err_msg += "Values from the Drive do not match values from the Controller. Use the COPY DRIVE PARA";
			err_msg += "\n";
			err_msg += "  (TO/FROM) CTRL to resolve mismatch.";
			break;
		case 922: 
			err_msg += "Controller and SmartKey parameters do not match.";
			break;
		case 923: 
			err_msg += "Error, Grip not initiated.";
			err_msg += "\n";
			err_msg += "Occurs when a hardware error is detected on the CAN controller.";
			break;
		case 930: 
			err_msg += "Edge Gripper CAN controller not initialized.";
			break;
		case 931: 
			err_msg += "Cannot read data from Edge Gripper CAN controller.";
			break;
		case 932: 
			err_msg += "Cannot write data to Edge Gripper CAN controller.";
			break;
		case 950: 
			err_msg += "Unexpected mail received by monitor.";
			break;
		case 951: 
			err_msg += "No monitor resources available.";
			break;
		case 952: 
			err_msg += "Unknown monitor event type.";
			break;
		case 953: 
			err_msg += "Monitor event canceled.";
			break;
		case 954: 
			err_msg += "Event time-out occurred.";
			break;
		case 955: 
			err_msg += "Monitored event occurred.";
			break;
		case 956: 
			err_msg += "Bad monitor function received.";
			break;
		case 960: 
			err_msg += "Function call not allowed.";
			break;
		case 961: 
			err_msg += "Resource ID not found.";
			break;
		case 962: 
			err_msg += "Resource lock failed.";
			err_msg += "\n";
			err_msg += "WAVE II 1.2P: Could not lock buffer resource from gateway task.";
			break;
		case 963: 
			err_msg += "Resource unlock failed.";
			break;
		case 964: 
			err_msg += "No free resources available.";
			break;
		case 972: 
			err_msg += "Resource lock failed.";
			break;

		// I/O Mapping Errors
		case  1001: 
			err_msg += "Unknown I/O State type.";
			err_msg += "\n";
			err_msg += "Check host controller software for proper I/O state type.";
			break;
		case  1002: 
			err_msg += "Unknown I/O name.";
			err_msg += "\n";
			err_msg += "Choose a correct I/O name.";
			err_msg += "\n";
			err_msg += "A list of existing I/O names can be obtained by issuing the command RQ IO MAP ALL.";
			break;
		case 1003: 
			err_msg += "I/O name already in use.";
			err_msg += "\n";
			err_msg += "If appropriate, delete existing I/O name using the REMOVE IO command."; 
			err_msg += "\n";
			err_msg += "Choose a different I/O name.";
			break;
		case 1004: 
			err_msg += "I/O system out of memory.";
			break;
		case 1005: 
			err_msg += "Name reserved by I/O system.";
			break;
		case 1006: 
			err_msg += "Illegal number of bits for I/O type.";
			err_msg += "\n";
			err_msg += "Assign the proper number of bits for the I/O type specified.";
			break;
		case 1007: 
			err_msg += "Unknown I/O block name.";
			break;
		case 1008: 
			err_msg += "Bad I/O bitmask.";
			break;
		case 1009: 
			err_msg += "Unknown I/O type.";
			break;
		case 1010: 
			err_msg += "I/O type mismatch.";
			break;
		case 1011: 
			err_msg += "Incorrect I/O channel specified.";
			break;
		case 1012: 
			err_msg += "Bad I/O handle.";
			break;
		case 1013: 
			err_msg += "Unknown I/O state.";
			break;
		case 1014: 
			err_msg += "I/O is write only.";
			err_msg += "\n";
			err_msg += "An attempt was made to write to an output.";
			break;
		case 1015: 
			err_msg += "I/O is read only.";
			err_msg += "\n";
			err_msg += "An attempt was made to read from an input.";
			break;

		// Inclusion Zones (WorkSpace) Errors
		case 1100: 
			err_msg += "Current position not within work space.";
			break;
		case 1101: 
			err_msg += "Destination position not within work space.";
			break;
		case 1102: 
			err_msg += "Work spaces do not overlap.";
			break;
		case 1103: 
			err_msg += "Work space interlock occurred.";
			break;
		case 1104: 
			err_msg += "No more work spaces available.";
			break;
		case 1105: 
			err_msg += "The work space volume must be specified.";
			break;
		case 1106: 
			err_msg += "Radial maximum is less than radial minimum.";
			break;
		case 1107: 
			err_msg += "Theta maximum is less than theta minimum.";
			break;
		case 1108: 
			err_msg += "Z maximum is less than Z minimum.";
			break;
		case 1109: 
			err_msg += "Radial minimum is greater than stored radial max.";
			break;
		case 1110: 
			err_msg += "Radial maximum is less than stored radial min.";
			break;
		case 1111: 
			err_msg += "Theta minimum is greater than stored theta maximum.";
			break;
		case 1112: 
			err_msg += "Theta maximum is less than stored theta minimum.";
			break;
		case 1113: 
			err_msg += "Z minimum is greater than stored Z maximum.";
			break;
		case 1114: 
			err_msg += "Z maximum is less than stored Z minimum.";
			break;
		case 1115: 
			err_msg += "Work Space name does not exist.";
			break;
		case 1116: 
			err_msg += "The arm for the work space must be specified.";
			break;
		case 1117: 
			err_msg += "The work space already exists.";
			break;
		case 1118: 
			err_msg += "Invalid station number.";
			break;
		case 1119: 
			err_msg += "Reserved work space name used.";
			break;
		case 1120: 
			err_msg += "WorkSpaces do not allow material flipping.";
			break;

		// CVG Errors
		case 1200: 
			err_msg += "CVG not done initializing.";
			break;
		case 1201: 
			err_msg += "No data available from CVG.";
			break;
		case 1202: 
			err_msg += "CVG error: SYNTX ER.";
			break;
		case 1203: 
			err_msg += "CVG error: DEF SNSR.";
			break;
		case 1204: 
			err_msg += "CVG error: LO VAC V.";
			break;
		case 1205: 
			err_msg += "CVG error: HI VAC V.";
			break;
		case 1206: 
			err_msg += "CVG error: GAIN LIM.";
			break;
		case 1207: 
			err_msg += "CVG error: RANGE ER.";
			break;
		case 1208: 
			err_msg += "Unknown message received from CVG.";
			break;
		case 1209: 
			err_msg += "Bad message received from CVG.";
			break;
		case 1210: 
			err_msg += "Unexpected mail to CVG task.";
			break;
		case 1211: 
			err_msg += "CVG span value out of range.";
			break;
		case 1212: 
			err_msg += "CVG zero value out of range.";
			break;

		// Motion Command Task Errors
		case 1300: 
			err_msg += "Bad mail message received by MCC.";
			break;
		case 1301: 
			err_msg += "Motion task in bad state.";
			break;
		case 1302: 
			err_msg += "Command halted.";
			break;
		case 1303: 
			err_msg += "Motion task busy.";
			break;
		case 1304: 
			err_msg += "Hard Tracking Error.";
			break;
		case 1305: 
			err_msg += "Torque limit exceeded.";
			break;
		case 1306: 
			err_msg += "Motion error multiple breakpoints.";
			break;
		case 1307: 
			err_msg += "MCC Queue Full.";
			break;
		case 1308: 
			err_msg += "Could not calculate MCC command ID.";
			break;
		case 1309: 
			err_msg += "Dual Ported RAM lock fail.";
			break;
		case 1310: 
			err_msg += "Unable to send to MCC.";
			break;
		case 1311: 
			err_msg += "Error opening MCC code.";
			break;
		case 1312: 
			err_msg += "Error reading MCC code.";
			break;
		case 1313: 
			err_msg += "MCC task can't access DP RAM.";
			break;
		case 1314: 
			err_msg += "MCC DP RAM memory size is too small.";
			break;

		// Startup Errors
		case 1400: 
			err_msg += "Startup error, bad board type.";
			break;

		//	SIO Errors
		case 1500: 
			err_msg += "SIO character processing error.";
			break;
		case 1501: 
			err_msg += "Unknown message type at SIO.";
			break;
		case 1502: 
			err_msg += "Invalid SIO comm setting.";
			err_msg += "\n";
			err_msg += "Real Time Clock Errors";
			break;
		case 1600: 
			err_msg += "Bad date format.";
			err_msg += "\n";
			err_msg += "Enter the date using a two digit number to represent the month, day, and year."; 
			err_msg += "\n";
			err_msg += "Separate the month, day, and year using the “/” character."; 
			err_msg += "\n";
			err_msg += "For example, February 28, 1998 would be entered by issuing the command: SET DATE 02/28/98.";
			break;
		case 1601: 
			err_msg += "Bad time format.";
			err_msg += "\n";
			err_msg += "Enter the time using a two digit number to represent the hour, minute, and second."; 
			err_msg += "\n";
			err_msg += "Separate the hour, minute, and second using the “:” character."; 
			err_msg += "\n";
			err_msg += "For example, thirty minutes past noon would be entered by issuing the command: SET TIME 12:30:00.";
			break;
		case 1602: 
			err_msg += "Year out of range.";
			err_msg += "\n";
			err_msg += "Enter the year using a two digit number in the range of 00 through 99.";
			break;
		case 1603: 
			err_msg += "Month out of range.";
			err_msg += "\n";
			err_msg += "Enter the month using a two digit number in the range of 01 through 12.";
			break;
		case 1604: 
			err_msg += "Day out of range.";
			err_msg += "\n";
			err_msg += "Enter the day using a two digit number in the range of 01 through 31.";
			break;
		case 1605: 
			err_msg += "Hour out of range.";
			err_msg += "\n";
			err_msg += "Enter the hour using a two digit number in the range of 01 through 23.";
			break;
		case 1606: 
			err_msg += "Minute out of range.";
			err_msg += "\n";
			err_msg += "Enter the minute using a two digit number in the range of 01 through 59";
			break;
		case 1607: 
			err_msg += "Second out of range.";
			err_msg += "\n";
			err_msg += "Enter the second using a two digit number in the range of 01 through 59.";
			break;

		// Temperature Controller Errors
		case 1700: 
			err_msg += "No response from temp controller.";
			break;
		case 1701: 
			err_msg += "Bad response from temp controller.";
			break;
		case 1702: 
			err_msg += "Temp controller in local mode.";
			break;
		case 1703: 
			err_msg += "Serial errors from temp controller.";
			break;
		case 1704: 
			err_msg += "Checksum errors from temp controller.";
			break;
		case 1705: 
			err_msg += "Data error reported by temp controller.";
			break;
		case 1706: 
			err_msg += "Write error from temp controller.";
			break;
		case 1707: 
			err_msg += "Bad message sent to temp controller.";
			break;
		case 1708: 
			err_msg += "Temp controller still initializing.";
			break;
		case 1709: 
			err_msg += "Temp controller alarm disabled.";
			break;
		case 1710: 
			err_msg += "Temp controller not in PID mode.";
			break;
		case 1711: 
			err_msg += "Undefined error from temp controller.";
			break;
		case 1712: 
			err_msg += "Temp controller off line.";
			break;
		case 1713: 
			err_msg += "Bad mail received in temp controller.";
			break;

		// CDM Related Errors
		case 1800: 
			err_msg += "CDM already initialized.";
			break;
		case 1801: 
			err_msg += "CDM escape key entered.";
			break;
		case 1802: 
			err_msg += "CDM quit key entered.";
			break;
		case 1803: 
			err_msg += "CDM bad parameter.";
			break;
		case 1804: 
			err_msg += "CDM move aborted.";
			break;
		case 1805: 
			err_msg += "CDM Has Control of Robot.";
			break;
		case 1806: 
			err_msg += "CDM ID not recognized.";
			break;
		case 1807: 
			err_msg += "CDM Too May args for TCL Macro.";
			break;

		// Comm Port Driver
		case 1900: 
			err_msg += "Unknown serial port.";
			break;
		case 1901: 
			err_msg += "Unable to open serial port.";
			break;
		case 1902: 
			err_msg += "Unable to close serial port.";
			break;
		case 1903: 
			err_msg += "Can't allocate serial port semaphore.";
			break;
		case 1904: 
			err_msg += "Serial port overflow.";
			break;
		case 1905: 
			err_msg += "Serial port empty.";
			break;
		case 1910: 
			err_msg += "Secondary Serial Port mode.";
			break;
		case 1911: 
			err_msg += "Secondary Serial Port is busy.";
			break;
		case 1912: 
			err_msg += "Secondary Serial Port response timeout.";
			break;
		case 1920: 
			err_msg += "No serial communication with remote MCC.";
			break;

		// System Task (Kernel) Related Errors
		case 2000: 
			err_msg += "No memory available for multi-tasker.";
			break;
		case 2001: 
			err_msg += "Multi-tasking kernel error.";
			break;
		case 2002: 
			err_msg += "Bad parameter passed to multi-tasker.";
			break;
		case 2003: 
			err_msg += "Timeout occurred.";
			break;
		case 2004: 
			err_msg += "Illegal task block requested.";
			break;
		case 2005: 
			err_msg += "No resources available.";
			break;

		// Non-Volatile Memory Errors
		case 2100: 
			err_msg += "Unable to read from NonVolatile RAM.";
			break;
		case 2101: 
			err_msg += "Unable to write to NonVolatile RAM.";
			break;
		case 2102: 
			err_msg += "NonVolatile RAM overflow.";
			break;

		// Mail System Related Errors
		case 2200: 
			err_msg += "No memory available for mail system.";
			break;
		case 2201: 
			err_msg += "Bad parameter passes to mail system.";
			break;
		case 2202: 
			err_msg += "Error initializing mail system.";
			break;
		case 2203: 
			err_msg += "Unknown task ID passed to mail system.";
			break;

		// Application List Errors
		case 2500: 
			err_msg += "Unknown configuration name.";
			break;
		case 2501: 
			err_msg += "Configuration name already in list.";
			break;
		case 2502: 
			err_msg += "No more space in configuration list.";
			break;
		case 2503: 
			err_msg += "Bad configuration handle.";
			break;
		case 2504: 
			err_msg += "Configuration name too long.";
			break;
		case 2505: 
			err_msg += "Can`t change config if arms off.";
			break;

		// Device and Link Table Errors
		case 2600: 
			err_msg += "Bad Device Identifier.";
			break;
		case 2601: 
			err_msg += "Device has not been configured.";
			break;
		case 2602: 
			err_msg += "No local serial device.";
			break;
		case 2620: 
			err_msg += "Bad Link Identifier.";
			break;
		case 2621: 
			err_msg += "Link has not been configured.";
			break;
		case 2622: 
			err_msg += "Invalid command for link type.";
			break;
		case 2623: 
			err_msg += "No local serial link.";
			break;
		case 2624: 
			err_msg += "Wrong Link Type.";
			break;

		// Monitor Trace Error Codes
		case 3000: 
			err_msg += "Trace currently running.";
			break;
		case 3001: 
			err_msg += "Trace variable already set.";
			break;
		case 3002: 
			err_msg += "Trace variable not set.";
			break;
		case 3003: 
			err_msg += "Bad trace variable name.";
			break;
		case 3004: 
			err_msg += "Bad trace trigger name.";
			break;
		case 3005: 
			err_msg += "No trace variables set.";
			break;
		case 3010: 
			err_msg += "Trace error, no memory available.";
			break;
		case 3011: 
			err_msg += "Bad trace period.";
			break;

		// System Initialization and Error Log Errors
		case 4001: 
			err_msg += "Serial number not set.";
			break;
		case 4002: 
			err_msg += "System not configured.";
			break;
		case 4003: 
			err_msg += "System already born.";
			break;
		case 4004: 
			err_msg += "Operator name not set.";
			break;
		case 4005: 
			err_msg += "Message log bad record.";
			break;
		case 4006: 
			err_msg += "Message log not found.";
			break;
		case 4007: 
			err_msg += "Message log write error.";
			break;
		case 4008: 
			err_msg += "Message log seek error.";
			break;
		case 4009: 
			err_msg += "Message log read error.";
			break;
		case 4010: 
			err_msg += "Checksum error in message log.";
			break;
		case 4011: 
			err_msg += "Beginning of message log encountered.";
			break;
		case 4012: 
			err_msg += "Error log not initialized.";
			break;
		case 4013: 
			err_msg += "Time not set.";
			break;
		case 4014: 
			err_msg += "Date not set.";
			break;
		case 4015: 
			err_msg += "Calibration Factor not set.";
			break;

		// System Specific Errors
		case 4100: 
			err_msg += "Unknown valve.";
			break;
		case 4101: 
			err_msg += "Chamber pressure too low.";
			break;
		case 4102: 
			err_msg += "Chamber pressure too high.";
			break;
		case 4103: 
			err_msg += "Chamber pressure error.";
			break;
		case 4104: 
			err_msg += "Memory allocation failure.";
			break;
		case 4106: 
			err_msg += "Unexpected mail!";
			break;
		case 4107: 
			err_msg += "No system vacuum!";
			break;
		case 4108: 
			err_msg += "Light Curtain blocked.";
			break;
		case 4109: 
			err_msg += "Load Lock blocked.";
			break;
		case 4110: 
			err_msg += "Bad value encountered.";
			err_msg += "\n";
			err_msg += "DeviceNet into Brooks MISC I/O error.";
			break;
		case 4111: 
			err_msg += "Invalid event.";
			err_msg += "\n";
			err_msg += "DeviceNet into Brooks MISC I/O error.";
			break;
		case 4200: 
			err_msg += "Node does not exist.";
			err_msg += "\n";
			err_msg += "DeviceNet into Brooks MISC I/O error.";
			break;
		case 4201: 
			err_msg += "Node name already in use.";
			err_msg += "\n";
			err_msg += "DeviceNet into Brooks MISC I/O error.";
			break;
		case 4202: 
			err_msg += "Maximum node limit reached.";
			err_msg += "\n";
			err_msg += "DeviceNet into Brooks MISC I/O error.";
			break;
		case 4300: 
			err_msg += "Cannot open INFO.TCL.";
			break;
		case 4301: 
			err_msg += "Cannot find spec in INFO.TCL.";
			break;
		case 5000: 
			err_msg += "Poppet not closed.";
			break;		

		// System Vacuum Errors
		case 6000: 
			err_msg += "Lift mechanism not in lower position.";
			break;		
		case 6001: 
			err_msg += "Error reading back output.";
			break;		
		case 6002: 
			err_msg += "Error reading back rough valve output.";
			break;		
		case 6003: 
			err_msg += "Error reading back soft rough output.";
			break;		
		case 6004: 
			err_msg += "Error reading back equal valve output.";
			break;		
		case 6005: 
			err_msg += "Error reading back argon valve output.";
			break;		
		case 6006: 
			err_msg += "Error reading back lift control output.";
			break;		
		case 6007: 
			err_msg += "Error reading back slot enable output.";
			break;		
		case 6008: 
			err_msg += "Error reading back system enable output.";
			break;		
		case 6009: 
			err_msg += "Timeout while waiting on lift sensor.";
			break;		
		case 6010: 
			err_msg += "Temperature not within set point range.";
			break;		
		case 6011: 
			err_msg += "Unable to pressurize chamber.";
			break;		
		case 6012: 
			err_msg += "Unable to lower pressure to equalize range.";
			break;		
		case 6013: 
			err_msg += "Unable to lower pressure to rough range.";
			break;		

		// DeviceNet Error Codes
		case 6050: 
			err_msg += "Device net API init error";
			break;		
		case 6051: 
			err_msg += "Invalid Command!";
			break;		
		case 6052: 
			err_msg += "Invalid MAC ID";
			break;		
		case 6053: 
			err_msg += "Invalid Baud Rate!";
			break;		
		case 6054: 
			err_msg += "Duplicate MAC ID check failed!";
			break;		
		case 6055: 
			err_msg += "Duplicate Slave!";
			break;		
		case 6056: 
			err_msg += "Slave Not Found!";
			break;		
		case 6057: 
			err_msg += "Command not allowed while bus is offline!";
			break;		
		case 6058: 
			err_msg += "Command not allowed while bus is active!";
			break;		
		case 6059: 
			err_msg += "Command not allowed while bus is not offline!";
			break;		
		case 6060: 
			err_msg += "Scanner is already started!";
			break;		
		case 6061: 
			err_msg += "Scanner is already stopped!";
			break;		
		case 6062: 
			err_msg += "Scanner shutdown is in progress!";
			break;		
		case 6063: 
			err_msg += "Invalid Offset!";
			break;		
		case 6064: 
			err_msg += "Unable to go online, bus fault encountered!";
			break;		
		case 6065: 
			err_msg += "Invalid connection flags!";
			break;		
		case 6066: 
			err_msg += "Invalid Explicit buffer size!";
			break;		
		case 6067: 
			err_msg += "Strobe output size must be 1.";
			err_msg += "\n";
			err_msg += "Maximum Strobe input size 8.";
			break;		
		case 6068: 
			err_msg += "Invalid Path Offset/Length!";
			break;		
		case 6069: 
			err_msg += "Unknown Error!";
			break;		
		case 6070: 
			err_msg += "Command Timeout!";
			break;		
		case 6071: 
			err_msg += "Module initialization error.";
			break;		
		case 6072: 
			err_msg += "Bad interface ID.";
			break;		
		case 6073: 
			err_msg += "Bad arguments.";
			break;		
		case 6074: 
			err_msg += "Max device limit reached.";
			break;		
		case 6075: 
			err_msg += "The specified command failed.";
			break;		
		case 6076: 
			err_msg += "Specified command is not allowed.";
			break;		
		case 6077: 
			err_msg += "User data length does not match with device data length.";
			break;		
		case 6078: 
			err_msg += "No Ack received from device during configuration.";
			err_msg += "\n";
			err_msg += "Occurs on boot-up when the controller is unable to configure a missing DeviceNet node.";
			break;		
		case 6079: 
			err_msg += "Bad index used in sequence.";
			break;		
		case 6080: 
			err_msg += "DeviceNet Util internal error - bad parameter.";
			break;		
		case 6081: 
			err_msg += "Bad DeviceNet IO bit name.";
			break;		
		case 6082: 
			err_msg += "Command sequencer bad jump parameter.";
			break;		
		case 6083: 
			err_msg += "Command sequencer bad sequence action type.";
			break;		
		case 6084: 
			err_msg += "DeviceNet Gateway channel already in use.";
			break;		
		case 6100: 
			err_msg += "DeviceNet IO Control already initialized.";
			break;		
		case 6101: 
			err_msg += "DeviceNet IO Control, bad IO name.";
			break;		
		case 6102: 
			err_msg += "DeviceNet IO Control, invalid command parameter.";
			break;		
		case 6103: 
			err_msg += "DeviceNet IO Control, invalid sequence name.";
			break;		
		case 6104: 
			err_msg += "DeviceNet IO Control, sequence aborted by user.";
			break;		
		case 6105: 
			err_msg += "DeviceNet IO Control, device is not active.";
			break;		
		case 6106: 
			err_msg += "DeviceNet IO Control, Command sequencer busy.";
			break;		
		case 6107: 
			err_msg += "DeviceNet IO Control, generic error.";
			break;		

		// Wafer Inverter Module Errors
		case 6150: 
			err_msg += "Invalid Inverter number specified.";
			break;		
		case 6151: 
			err_msg += "Inverter not defined.";
			break;		
		case 6152: 
			err_msg += "Inverter - Unable to Ungrip.";
			break;		
		case 6153: 
			err_msg += "Inverter - Unable to move down.";
			break;		
		case 6154: 
			err_msg += "Inverter - Unable to move up.";
			break;		
		case 6155: 
			err_msg += "Inverter not at down position.";
			break;		
		case 6156: 
			err_msg += "Inverter - Unable to rotate CCW.";
			break;		
		case 6157: 
			err_msg += "Inverter - Unable to rotate CW";
			break;		
		case 6158: 
			err_msg += "Inverter - Wafer detected.";
			break;		
		case 6159: 
			err_msg += "Inverter - No wafer detected.";
			break;		
		case 6160: 
			err_msg += "Inverter - Robot is not at proper position.";
			break;		
		case 6161: 
			err_msg += "Inverter - Unable to grip.";
			break;		
		case 6162: 
			err_msg += "Inverter is not in grip position.";
			break;		
		case 6163: 
			err_msg += "Inverter not at UP position.";
			break;		
		case 6164: 
			err_msg += "Inverter station - not allowed to PICK or PLACE wafer.";
			break;		

		// Robot Motion Control Processor Errors
		case 10000: 
			err_msg += "Default debug message from the MCC.";
			break;
		case 10001: 
			err_msg += "Sync error, motor moving or encoder noisy.";
			break;
		case 10002: 
			err_msg += "MCC board memory allocation error.";
			break;
		case 10003: 
			err_msg += "MCC board unexpected event error.";
			break;
		case 10004: 
			err_msg += "MCC board, bad command state.";
			break;
		case 10005: 
			err_msg += "MCC Board Sync error, can't move motor.";
			break;
		case 10006: 
			err_msg += "MCC encoder VABS adjusted (small).";
			break;
		case 10007: 
			err_msg += "MCC board position settle error.";
			break;
		case 10008: 
			err_msg += "MCC unable to hold position.";
			break;
		case 10009: 
			err_msg += "MCC hard tracking error.";
			break;
		case 10010: 
			err_msg += "MCC soft tracking error.";
			break;
		case 10011: 
			err_msg += "Error, motor is already moving.";
			break;
		case 10012: 
			err_msg += "Error, motor is not configured.";
			break;
		case 10013: 
			err_msg += "Error, motor is not referenced.";
			break;
		case 10014: 
			err_msg += "Error, motor is already referencing.";
			break;
		case 10015: 
			err_msg += "Error, motor is currently moving.";
			break;
		case 10016: 
			err_msg += "Error, unable to calculate trajectory.";
			break;
		case 10017: 
			err_msg += "Illegal number of polls calculated.";
			break;
		case 10018: 
			err_msg += "Unable to calculate absolute position.";
			break;
		case 10019: 
			err_msg += "Error, Encoder off by many sectors.";
			break;
		case 10020: 
			err_msg += "Error, Encoder failed multiple times.";
			break;
		case 10021: 
			err_msg += "Error, Board Power Failure (Blown Fuse?).";
			break;
		case 10022: 
			err_msg += "Error, Axis overtravel limit reached.";
			break;
		case 10023: 
			err_msg += "Arm actual loc impossible, check sync zero.";
			break;
		case 10024: 
			err_msg += "Error, MCC watchdog timed out.";
			break;
		case 10025: 
			err_msg += "Error, Defective R_MT type Wafer sensor.";
			break;
		case 10026: 
			err_msg += "Error, Arm load not what expected.";
			break;
		case 10028: 
			err_msg += "Error, obstruction encounter for axis.";
			break;
		case 10029: 
			err_msg += "Error, Emergency Stop circuit is active.";
			break;
		case 10030: 
			err_msg += "Error, Excessive Current Detected.";
			break;
		case 10031: 
			err_msg += "Warning, Home Sensor position moved.";
			break;
		case 10032: 
			err_msg += "Warning, map data may be invalid.";
			break;
		case 10034: 
			err_msg += "Error, Encoder Min/Max value out of range.";
			break;
		case 10035: 
			err_msg += "Error, bad sync phase offset value.";
			break;
		case 10036: 
			err_msg += "Error, robot links are not yet defined.";
			break;
		case 10046: 
			err_msg += "Error, MCC bad hall sensor data value.";
			break;
		case 10047: 
			err_msg += "Error, MCC code date/time stamp mismatch.";
			break;
		case 10048: 
			err_msg += "Error, MCC stored code checksum incorrect.";
			break;
		case 10049: 
			err_msg += "Error, MCC code size too large to store.";
			break;
		case 10054: 
			err_msg += "Error, DPRAM bad MCC head/tail pointer.";
			break;
		case 10055: 
			err_msg += "Error, DPRAM bad SUP head/tail pointer.";
			break;
		case 10056: 
			err_msg += "Error, DPRAM bad SUP message size.";
			break;
		case 10057: 
			err_msg += "Error, Home Sensor position moved too far.";
			break;
		case 10058: 
			err_msg += "Error, Set loop mode failed.";
			break;
		case 10059: 
			err_msg += "Error, Motor Step Move timed out.";
			break;
		case 10060: 
			err_msg += "Error, Reference Failed.";
			break;

		default:
			err_msg += "Check Error Manual ...";
			break;
	}

	err_msg += "\n";
	return err_msg;
}
