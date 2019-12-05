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
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING ( "" ) , 1 , 0
, 0 , 0 , 0 } , { 2 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING (
"lateral_deviation" ) , 2 , 0 , 0 , 0 , 0 } , { 3 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center" ) , TARGET_STRING (
"relative_yaw_angle" ) , 3 , 0 , 0 , 0 , 0 } , { 4 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 6 , TARGET_STRING
( "estimate_lane_center/Estimate Lane Center/Center from Left" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Left"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 7 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Left"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 6 , TARGET_STRING
( "estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from None" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from None"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Center from Right"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Merge" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 6 ,
TARGET_STRING ( "estimate_lane_center/Estimate Lane Center/Saturation" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 6 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 1 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 31 , 1 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 32 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain" )
, TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain1"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 35 , 6
, TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain2"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain3"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 2 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 38 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add1" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 39 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 40 , 2 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Add3" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 41 , 6 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 43 , 6
, TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 44 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from None/BusConversion_InsertedFor_Out1_at_inport_0"
) , TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 6 ,
TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/BusConversion_InsertedFor_Center_at_inport_0"
) , TARGET_STRING ( "HeadingAngle" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Divide" ) ,
TARGET_STRING ( "Curvature" ) , 0 , 0 , 0 , 0 , 0 } , { 47 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Divide1" ) ,
TARGET_STRING ( "CurvatureDerivative" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 4 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Product1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 49 , 4 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 50 , 6 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Subtract1" ) ,
TARGET_STRING ( "LateralOffset" ) , 0 , 0 , 0 , 0 , 0 } , { 51 , 6 ,
TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Preview curvature/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 52 , TARGET_STRING (
"estimate_lane_center/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 53 , TARGET_STRING ( "estimate_lane_center/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"estimate_lane_center/Constant10" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 55 , TARGET_STRING ( "estimate_lane_center/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 56 , TARGET_STRING (
"estimate_lane_center/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 57 , TARGET_STRING ( "estimate_lane_center/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"estimate_lane_center/Constant5" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 59 , TARGET_STRING ( "estimate_lane_center/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"estimate_lane_center/Constant7" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 61 , TARGET_STRING ( "estimate_lane_center/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 62 , TARGET_STRING (
"estimate_lane_center/Constant9" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 }
, { 63 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 64 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 66 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation1" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 68 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation2" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 70 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Saturation3" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 72 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Left/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 74 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 76 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Left and Right/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 78 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Center from Right/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/Half Lane Width Estimate"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 80 , TARGET_STRING (
 "estimate_lane_center/Estimate Lane Center/Center from Right/Half Lane Width Estimate1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
"estimate_lane_center/Estimate Lane Center/Preview curvature/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 ,
( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dqp3ofd3v44 . bhdadxzzzu , & rtB
. dqp3ofd3v44 . gvsf1mrxed , & rtB . dqp3ofd3v44 . n4ys51bjpp , & rtB .
dqp3ofd3v44 . b1op4qu4du , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . lbbgw3vile , & rtB .
dqp3ofd3v44 . kzoecgydrt , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . lbbgw3vile , & rtB .
dqp3ofd3v44 . kzoecgydrt , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . lbbgw3vile , & rtB .
dqp3ofd3v44 . kzoecgydrt , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . lbbgw3vile , & rtB .
dqp3ofd3v44 . kzoecgydrt , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . lbbgw3vile , & rtB .
dqp3ofd3v44 . kzoecgydrt , & rtB . dqp3ofd3v44 . n4ys51bjpp , & rtB .
dqp3ofd3v44 . b1op4qu4du , & rtB . dqp3ofd3v44 . bhdadxzzzu , & rtB .
dqp3ofd3v44 . lbbgw3vile , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . mlekluhdty , & rtB .
dqp3ofd3v44 . gvthkz4uqd , & rtB . dqp3ofd3v44 . kzoecgydrt , & rtB .
dqp3ofd3v44 . jjdqfkhq4b , & rtB . dqp3ofd3v44 . ns2ckjnnn3 , & rtB .
dqp3ofd3v44 . lbbgw3vile , & rtB . dqp3ofd3v44 . kzoecgydrt , & rtB .
dqp3ofd3v44 . gkprg3ghe5 , & rtB . dqp3ofd3v44 . p02tzwdudt , & rtB .
dqp3ofd3v44 . nex4eio1fy , & rtB . dqp3ofd3v44 . a3kgai34ad , & rtB .
dqp3ofd3v44 . jjdqfkhq4b , & rtB . dqp3ofd3v44 . ns2ckjnnn3 , & rtB .
dqp3ofd3v44 . lbbgw3vile , & rtB . dqp3ofd3v44 . kzoecgydrt , & rtB .
dqp3ofd3v44 . lbbgw3vile , & rtB . dqp3ofd3v44 . jjdqfkhq4b , & rtB .
dqp3ofd3v44 . ns2ckjnnn3 , & rtB . dqp3ofd3v44 . fhuclp2kjb , & rtB .
dqp3ofd3v44 . birpkjwmgk , & rtB . dqp3ofd3v44 . kzoecgydrt , & rtB .
dqp3ofd3v44 . gvsf1mrxed , & rtP . Constant_Value , & rtP . Constant1_Value ,
& rtP . Constant10_Value , & rtP . Constant2_Value , & rtP . Constant3_Value
, & rtP . Constant4_Value , & rtP . Constant5_Value , & rtP . Constant6_Value
, & rtP . Constant7_Value , & rtP . Constant8_Value , & rtP . Constant9_Value
, & rtP . dqp3ofd3v44 . Saturation_UpperSat , & rtP . dqp3ofd3v44 .
Saturation_LowerSat , & rtP . dqp3ofd3v44 . Saturation1_UpperSat , & rtP .
dqp3ofd3v44 . Saturation1_LowerSat , & rtP . dqp3ofd3v44 .
Saturation2_UpperSat , & rtP . dqp3ofd3v44 . Saturation2_LowerSat , & rtP .
dqp3ofd3v44 . Saturation3_UpperSat , & rtP . dqp3ofd3v44 .
Saturation3_LowerSat , & rtP . dqp3ofd3v44 . Constant_Value , & rtP .
dqp3ofd3v44 . HalfLaneWidthEstimate_Value , & rtP . dqp3ofd3v44 .
HalfLaneWidthEstimate1_Value , & rtP . dqp3ofd3v44 . Gain_Gain , & rtP .
dqp3ofd3v44 . Gain1_Gain , & rtP . dqp3ofd3v44 . Gain2_Gain , & rtP .
dqp3ofd3v44 . Gain3_Gain , & rtP . dqp3ofd3v44 . Constant_Value_cijpjtu1ez ,
& rtP . dqp3ofd3v44 . HalfLaneWidthEstimate_Value_fad045x02c , & rtP .
dqp3ofd3v44 . HalfLaneWidthEstimate1_Value_kslaxjeuqc , & rtP . dqp3ofd3v44 .
Gain_Gain_j0wlcuxobx , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL )
} ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.2 , 0.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 52 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters ,
30 , rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 2983954583U , 126668576U , 2892194270U ,
4245245358U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
estimate_lane_center_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
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
