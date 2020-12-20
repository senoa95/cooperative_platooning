#include "__cf_estimate_lane_center.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "estimate_lane_center_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "estimate_lane_center.h"
#include "estimate_lane_center_capi.h"
#include "estimate_lane_center_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 1 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING ( "" ) , 1 , 1
, 1 , 0 , 0 } , { 2 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING (
"lateral_deviation" ) , 2 , 0 , 0 , 0 , 0 } , { 3 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING (
"relative_yaw_angle" ) , 3 , 0 , 0 , 0 , 0 } , { 4 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 5 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1" ) , TARGET_STRING ( "" ) , 1 , 1
, 1 , 0 , 0 } , { 6 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1" ) , TARGET_STRING (
"lateral_deviation" ) , 2 , 0 , 0 , 0 , 0 } , { 7 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1" ) , TARGET_STRING (
"relative_yaw_angle" ) , 3 , 0 , 0 , 0 , 0 } , { 8 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 6 , TARGET_STRING
( "estimate_lane_center/Estimate Lane Center/Center from Left" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Left"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Left"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from None" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Center from Left"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 12
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Center from Left"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Center from None"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Center from None"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 12
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from None" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Center from None"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 43 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Merge" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Merge" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 49 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Merge" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Merge" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 12 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center1/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 52 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 53 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 54 , 6 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 55 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 57 , 1 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 58 , 1 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 59 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 60 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain" )
, TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 61 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain1"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 62 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain2"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 63 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain3"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 64 , 2 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 65 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 66 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 67 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 68 , 6 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 69 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 70 , 6
, TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 72 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 73 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 74 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 4 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 76 , 4 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 77 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 78 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Preview curvature/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 79 , 12 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Left/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 80 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 81 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 7 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 83 , 7 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 84 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 85 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 86 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain1"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 87 , 12
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain2"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 88 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain3"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 89 , 8 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Add" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 90 , 8 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Add1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 91 , 8 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Add2"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 92 , 8 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Add3"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 93 , 12 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 94 , 12 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 95 , 12
, TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 96 , 12 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 97 , 12 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Right/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 98 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 99 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 100 , 10 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 101 , 10 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 102 , 12 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 103 , 12 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Preview curvature/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 104 , TARGET_STRING (
"estimate_lane_center/Constant" ) , TARGET_STRING ( "Value" ) , 1 , 0 , 0 } ,
{ 105 , TARGET_STRING ( "estimate_lane_center/Constant11" ) , TARGET_STRING (
"Value" ) , 1 , 0 , 0 } , { 106 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 107 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 111 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation2" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 114 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 116 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation1" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation2" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Saturation3" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 130 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 131 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Preview curvature/Gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 133 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Left/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Left/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 138 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Left and Right/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 140 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Center from Right/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Right/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center1/Center from Right/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center1/Preview curvature/Gain" ) ,
TARGET_STRING ( "Gain" ) , 1 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 144
, TARGET_STRING ( "left_curvature" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"left_curvature_rate" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"left_lateral_deviation" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"left_relative_yaw_angle" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"left_strength" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING ( "right_curvature" )
, 0 , 0 , 0 } , { 150 , TARGET_STRING ( "right_curvature_rate" ) , 0 , 0 , 0
} , { 151 , TARGET_STRING ( "right_lateral_deviation" ) , 0 , 0 , 0 } , { 152
, TARGET_STRING ( "right_relative_yaw_angle" ) , 0 , 0 , 0 } , { 153 ,
TARGET_STRING ( "right_strength" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . k3pph0iicyb . dkaupoobjr , & rtB
. k3pph0iicyb . icvqtrbbcd [ 0 ] , & rtB . k3pph0iicyb . mvxqr2bcws , & rtB .
k3pph0iicyb . oqjwvlopf5 , & rtB . e0dg4qnjc3 . dkaupoobjr , & rtB .
e0dg4qnjc3 . icvqtrbbcd [ 0 ] , & rtB . e0dg4qnjc3 . mvxqr2bcws , & rtB .
e0dg4qnjc3 . oqjwvlopf5 , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . mvxqr2bcws , & rtB .
k3pph0iicyb . oqjwvlopf5 , & rtB . k3pph0iicyb . dkaupoobjr , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . mvxqr2bcws , & rtB . e0dg4qnjc3 . oqjwvlopf5 , & rtB .
e0dg4qnjc3 . dkaupoobjr , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . j0y3qvbbhb , & rtB . k3pph0iicyb . dlphfoumb0 , & rtB .
k3pph0iicyb . ggudjvgpuu , & rtB . k3pph0iicyb . oc05twylps , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . jev0d0au1k , & rtB .
k3pph0iicyb . pyt3nna2lj , & rtB . k3pph0iicyb . ov5lcbuchn , & rtB .
k3pph0iicyb . c0xy4zpqv1 , & rtB . k3pph0iicyb . j0y3qvbbhb , & rtB .
k3pph0iicyb . dlphfoumb0 , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . g34esawosi , & rtB .
k3pph0iicyb . j0y3qvbbhb , & rtB . k3pph0iicyb . dlphfoumb0 , & rtB .
k3pph0iicyb . fh2jemzwct , & rtB . k3pph0iicyb . e53ulgorx1 , & rtB .
k3pph0iicyb . kdicdcckls , & rtB . k3pph0iicyb . icvqtrbbcd [ 0 ] , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . j0y3qvbbhb , & rtB .
e0dg4qnjc3 . dlphfoumb0 , & rtB . e0dg4qnjc3 . ggudjvgpuu , & rtB .
e0dg4qnjc3 . oc05twylps , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . jev0d0au1k , & rtB . e0dg4qnjc3 . pyt3nna2lj , & rtB .
e0dg4qnjc3 . ov5lcbuchn , & rtB . e0dg4qnjc3 . c0xy4zpqv1 , & rtB .
e0dg4qnjc3 . j0y3qvbbhb , & rtB . e0dg4qnjc3 . dlphfoumb0 , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . g34esawosi , & rtB . e0dg4qnjc3 . j0y3qvbbhb , & rtB .
e0dg4qnjc3 . dlphfoumb0 , & rtB . e0dg4qnjc3 . fh2jemzwct , & rtB .
e0dg4qnjc3 . e53ulgorx1 , & rtB . e0dg4qnjc3 . kdicdcckls , & rtB .
e0dg4qnjc3 . icvqtrbbcd [ 0 ] , & rtP . Constant_Value , & rtP .
Constant11_Value , & rtP . k3pph0iicyb . Saturation_UpperSat , & rtP .
k3pph0iicyb . Saturation_LowerSat , & rtP . k3pph0iicyb .
Saturation1_UpperSat , & rtP . k3pph0iicyb . Saturation1_LowerSat , & rtP .
k3pph0iicyb . Saturation2_UpperSat , & rtP . k3pph0iicyb .
Saturation2_LowerSat , & rtP . k3pph0iicyb . Saturation3_UpperSat , & rtP .
k3pph0iicyb . Saturation3_LowerSat , & rtP . e0dg4qnjc3 . Saturation_UpperSat
, & rtP . e0dg4qnjc3 . Saturation_LowerSat , & rtP . e0dg4qnjc3 .
Saturation1_UpperSat , & rtP . e0dg4qnjc3 . Saturation1_LowerSat , & rtP .
e0dg4qnjc3 . Saturation2_UpperSat , & rtP . e0dg4qnjc3 . Saturation2_LowerSat
, & rtP . e0dg4qnjc3 . Saturation3_UpperSat , & rtP . e0dg4qnjc3 .
Saturation3_LowerSat , & rtP . k3pph0iicyb . Constant_Value , & rtP .
k3pph0iicyb . HalfLaneWidthEstimate_Value , & rtP . k3pph0iicyb .
HalfLaneWidthEstimate1_Value , & rtP . k3pph0iicyb . Gain_Gain_csudgssrcg , &
rtP . k3pph0iicyb . Gain1_Gain , & rtP . k3pph0iicyb . Gain2_Gain , & rtP .
k3pph0iicyb . Gain3_Gain , & rtP . k3pph0iicyb . Constant_Value_jgqntcaric ,
& rtP . k3pph0iicyb . HalfLaneWidthEstimate_Value_amvyq0ozrf , & rtP .
k3pph0iicyb . HalfLaneWidthEstimate1_Value_kccholnvrj , & rtP . k3pph0iicyb .
Gain_Gain [ 0 ] , & rtP . e0dg4qnjc3 . Constant_Value , & rtP . e0dg4qnjc3 .
HalfLaneWidthEstimate_Value , & rtP . e0dg4qnjc3 .
HalfLaneWidthEstimate1_Value , & rtP . e0dg4qnjc3 . Gain_Gain_csudgssrcg , &
rtP . e0dg4qnjc3 . Gain1_Gain , & rtP . e0dg4qnjc3 . Gain2_Gain , & rtP .
e0dg4qnjc3 . Gain3_Gain , & rtP . e0dg4qnjc3 . Constant_Value_jgqntcaric , &
rtP . e0dg4qnjc3 . HalfLaneWidthEstimate_Value_amvyq0ozrf , & rtP .
e0dg4qnjc3 . HalfLaneWidthEstimate1_Value_kccholnvrj , & rtP . e0dg4qnjc3 .
Gain_Gain [ 0 ] , & rtP . left_curvature , & rtP . left_curvature_rate , &
rtP . left_lateral_deviation , & rtP . left_relative_yaw_angle , & rtP .
left_strength , & rtP . right_curvature , & rtP . right_curvature_rate , &
rtP . right_lateral_deviation , & rtP . right_relative_yaw_angle , & rtP .
right_strength , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "float" ,
"real32_T" , 0 , 0 , sizeof ( real32_T ) , SS_SINGLE , 0 , 0 , 0 } , {
"double" , "real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 3 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.1 , 0.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 }
, } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const
void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [
1 ] , 0 , 0 } , { ( NULL ) , ( NULL ) , 1 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 104 , ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockParameters , 40 , rtModelParameters , 10 }
, { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap ,
rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 1266430929U
, 2926641344U , 2919994738U , 3380208096U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * estimate_lane_center_GetCAPIStaticMap ( void
) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void estimate_lane_center_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion
( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void estimate_lane_center_host_InitializeDataMapInfo (
estimate_lane_center_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
