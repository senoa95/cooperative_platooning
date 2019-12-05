#include "__cf_estimate_lane_center.h"
#ifndef RTW_HEADER_estimate_lane_center_h_
#define RTW_HEADER_estimate_lane_center_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef estimate_lane_center_COMMON_INCLUDES_
#define estimate_lane_center_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "estimate_lane_center_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME estimate_lane_center
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (20) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T jjdqfkhq4b ; real_T ns2ckjnnn3 ; real_T bhdadxzzzu ;
real_T gvsf1mrxed ; real_T lbbgw3vile ; real_T b1op4qu4du ; real_T kzoecgydrt
; real_T n4ys51bjpp ; real_T birpkjwmgk ; real_T fhuclp2kjb ; real_T
gvthkz4uqd ; real_T mlekluhdty ; real_T gkprg3ghe5 ; real_T p02tzwdudt ;
real_T nex4eio1fy ; real_T a3kgai34ad ; } cq0vplcfh1 ; typedef struct {
real_T hugbkegs0r ; real_T g5en32gyko ; real_T oogjy025cs ; real_T hv2024htj2
; int8_T iq513e4hqe ; int8_T ilow50ohwe ; int8_T gvcnio4hhw ; int8_T
l4h0aggw4z ; } l0nzjqgucp ; typedef struct { cq0vplcfh1 dqp3ofd3v44 ; } B ;
typedef struct { struct { void * LoggedData [ 4 ] ; } hga0xjow5k ; struct {
void * AQHandles ; void * SlioLTF ; } m3l1vijl4e ; struct { void * AQHandles
; void * SlioLTF ; } dngafahvjf ; struct { void * AQHandles ; void * SlioLTF
; } feismhumih ; l0nzjqgucp dqp3ofd3v44 ; } DW ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct nbsqgueugp_ { real_T
Gain_Gain ; real_T Gain1_Gain ; real_T Gain2_Gain ; real_T Gain3_Gain ;
real_T Constant_Value ; real_T HalfLaneWidthEstimate_Value ; real_T
HalfLaneWidthEstimate1_Value ; real_T Constant_Value_cijpjtu1ez ; real_T
HalfLaneWidthEstimate_Value_fad045x02c ; real_T
HalfLaneWidthEstimate1_Value_kslaxjeuqc ; real_T Delay_4_InitialCondition ;
real_T Delay_3_InitialCondition ; real_T Delay_2_InitialCondition ; real_T
Delay_1_InitialCondition ; real_T Merge_1_InitialOutput ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T
Merge_2_InitialOutput ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Gain_Gain_j0wlcuxobx ; real_T
Merge_3_InitialOutput ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T Merge_4_InitialOutput ; real_T
Saturation_UpperSat ; real_T Saturation_LowerSat ; } ; struct P_ { real_T
Constant_Value ; real_T Constant1_Value ; real_T Constant10_Value ; real_T
Constant2_Value ; real_T Constant3_Value ; real_T Constant4_Value ; real_T
Constant5_Value ; real_T Constant6_Value ; real_T Constant7_Value ; real_T
Constant8_Value ; real_T Constant9_Value ; nbsqgueugp dqp3ofd3v44 ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
estimate_lane_center_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS
; extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ;
extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable *
gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
