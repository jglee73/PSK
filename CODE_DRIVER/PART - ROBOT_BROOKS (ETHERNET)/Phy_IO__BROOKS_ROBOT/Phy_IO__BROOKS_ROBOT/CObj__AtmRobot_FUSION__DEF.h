#pragma once

#include "CCommon_SYSTEM.h"


// ..
#define  STR__ENABLE				"ENABLE"
#define  STR__DISABLE				"DISABLE"

#define  STR__ONLINE				"ONLINE"
#define  STR__OFFLINE				"OFFLINE"

#define  STR__HOME					"HOME"

#define  STR__ROTATE				"ROTATE"
#define  STR__EXTEND				"EXTEND"
#define  STR__RETRACT				"RETRACT"

#define  STR__NONE					"NONE"
#define  STR__EXIST					"EXIST"
#define  STR__UNKNOWN				"UNKNOWN"

#define  STR__OPEN					"OPEN"
#define  STR__CLOSE					"CLOSE"

#define  STR__YES					"YES"
#define  STR__NO					"NO"

#define  STR__CLAMP					"CLAMP"
#define  STR__UNCLAMP				"UNCLAMP"

#define  STR__LOAD					"LOAD"
#define  STR__UNLOAD				"UNLOAD"

// ..
#define  ARM_A						"A"
#define  ARM_B						"B"

// ..
#define  STR__LP1					"LP1"
#define  STR__LP2					"LP2"
#define  STR__LP3					"LP3"
#define  STR__LP4					"LP4"
#define  STR__LP5					"LP5"

#define  STR__AL1					"AL1"
#define  STR__AL2					"AL2"

#define  STR__VIS1					"VIS1"

#define  STR__LBA					"LBA"
#define  STR__LBB					"LBB"

#define  STR__BUFF1					"BUFF1"
#define  STR__BUFF2					"BUFF2"
#define  STR__FULL_BUFF				"FULL_BUFF"

#define  STR__PM1					"PM1"
#define  STR__PM2					"PM2"
#define  STR__PM3					"PM3"
#define  STR__PM4					"PM4"
#define  STR__PM5					"PM5"

#define  INT__LP1					0
#define  INT__LP2					1
#define  INT__LP3					2
#define  INT__LP4					3
#define  INT__LP5					4


// ...
// Acknowledgment- Indicates command has been received. 
// Standard response is '_ACK'.
#define _ACK                        "_ACK"

// Acknowledgment Error- Indicates command was not understood. 
// Standard response is '_NAK'.
#define _NAK                        "_NAK"

// Message- Indicates the response string is the response to a command. 
// Standard response is '_RSP'.
#define _RSP                        "_RSP"

// Error- Indicates command could not be executed. 
// Standard response is '_ERR'.
#define _ERR						"_ERR"

// Completion- Indicates command has completed. 
// Standard response is '_DNE'. 
// Format : nnn _DNE
#define _DNE                        "_DNE"

// Event- Indicates the response string is an event message.
// Standard response is '_EVN'.
#define _EVN                        "_EVN"


// ...
#define _TO__QUERY					1.0				// 1.0  sec
#define _TO__ACT					50.0			// 50.0 sec
