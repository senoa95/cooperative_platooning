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
#define NBLOCKIO (40) 
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
typedef struct { real_T icvqtrbbcd [ 3 ] ; real32_T dlphfoumb0 ; real32_T
dkaupoobjr ; real32_T j0y3qvbbhb ; real32_T g34esawosi ; real32_T oqjwvlopf5
; real32_T kdicdcckls ; real32_T mvxqr2bcws ; real32_T e53ulgorx1 ; real32_T
fh2jemzwct ; real32_T oc05twylps ; real32_T ggudjvgpuu ; real32_T jev0d0au1k
; real32_T pyt3nna2lj ; real32_T ov5lcbuchn ; real32_T c0xy4zpqv1 ; }
pl2abai0sd ; typedef struct { struct { void * LoggedData ; } bv5olnepf0 ;
real32_T eckz3pxwzc ; real32_T f5zwivgby1 ; real32_T cvvezosg3d ; real32_T
o03k3dg52b ; int8_T gsiekacha1 ; int8_T o40mjycyzi ; int8_T gppbpgjejo ;
int8_T mwbiwkoruj ; } nliga4imox ; typedef struct { pl2abai0sd e0dg4qnjc3 ;
pl2abai0sd k3pph0iicyb ; } B ; typedef struct { struct { void * AQHandles ;
void * SlioLTF ; } m3l1vijl4e ; struct { void * LoggedData ; } i10vows2kx ;
struct { void * AQHandles ; void * SlioLTF ; } dngafahvjf ; struct { void *
AQHandles ; void * SlioLTF ; } feismhumih ; struct { void * LoggedData ; }
kovwqq2md4 ; struct { void * LoggedData ; } g2ldytnxfq ; struct { void *
LoggedData ; } ok2p2lv0ek ; struct { void * AQHandles ; void * SlioLTF ; }
a3kpjsykfj ; struct { void * LoggedData ; } dnvh1kcj2i ; struct { void *
AQHandles ; void * SlioLTF ; } jshekjjwkp ; struct { void * AQHandles ; void
* SlioLTF ; } fg10l0wasa ; struct { void * LoggedData ; } panzj3fxix ; struct
{ void * LoggedData ; } nutfnhr4zj ; struct { void * LoggedData ; }
bmwwkwthwc ; nliga4imox e0dg4qnjc3 ; nliga4imox k3pph0iicyb ; } DW ; typedef
struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct adfesqiczr_ {
real_T Gain_Gain [ 3 ] ; real32_T Gain_Gain_csudgssrcg ; real32_T Gain1_Gain
; real32_T Gain2_Gain ; real32_T Gain3_Gain ; real32_T Constant_Value ;
real32_T HalfLaneWidthEstimate_Value ; real32_T HalfLaneWidthEstimate1_Value
; real32_T Constant_Value_jgqntcaric ; real32_T
HalfLaneWidthEstimate_Value_amvyq0ozrf ; real32_T
HalfLaneWidthEstimate1_Value_kccholnvrj ; real32_T Delay_4_InitialCondition ;
real32_T Delay_3_InitialCondition ; real32_T Delay_2_InitialCondition ;
real32_T Delay_1_InitialCondition ; real32_T Merge_2_InitialOutput ; real32_T
Saturation3_UpperSat ; real32_T Saturation3_LowerSat ; real32_T
Merge_1_InitialOutput ; real32_T Saturation2_UpperSat ; real32_T
Saturation2_LowerSat ; real32_T Merge_3_InitialOutput ; real32_T
Saturation1_UpperSat ; real32_T Saturation1_LowerSat ; real32_T
Merge_4_InitialOutput ; real32_T Saturation_UpperSat ; real32_T
Saturation_LowerSat ; } ; struct P_ { real32_T left_curvature ; real32_T
left_curvature_rate ; real32_T left_lateral_deviation ; real32_T
left_relative_yaw_angle ; real32_T left_strength ; real32_T right_curvature ;
real32_T right_curvature_rate ; real32_T right_lateral_deviation ; real32_T
right_relative_yaw_angle ; real32_T right_strength ; real_T Constant_Value ;
real_T Constant11_Value ; adfesqiczr e0dg4qnjc3 ; adfesqiczr k3pph0iicyb ; }
; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
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
