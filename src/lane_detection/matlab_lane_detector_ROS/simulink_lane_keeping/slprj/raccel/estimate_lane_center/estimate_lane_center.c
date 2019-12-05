#include "__cf_estimate_lane_center.h"
#include "rt_logging_mmi.h"
#include "estimate_lane_center_capi.h"
#include <math.h>
#include "estimate_lane_center.h"
#include "estimate_lane_center_private.h"
#include "estimate_lane_center_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.2 (R2019b) 18-Jul-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//estimate_lane_center//estimate_lane_center_Jpattern.mat" ;
const int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void aqqbul4v4o ( cq0vplcfh1 * localB , l0nzjqgucp * localDW ,
nbsqgueugp * localP ) { localDW -> hugbkegs0r = localP ->
Delay_4_InitialCondition ; localDW -> g5en32gyko = localP ->
Delay_3_InitialCondition ; localDW -> oogjy025cs = localP ->
Delay_2_InitialCondition ; localDW -> hv2024htj2 = localP ->
Delay_1_InitialCondition ; localB -> jjdqfkhq4b = localP ->
Merge_1_InitialOutput ; localB -> ns2ckjnnn3 = localP ->
Merge_2_InitialOutput ; localB -> lbbgw3vile = localP ->
Merge_3_InitialOutput ; localB -> kzoecgydrt = localP ->
Merge_4_InitialOutput ; } void dqp3ofd3v4 ( real_T kmrarnehrf , real_T
epejdbwhc0 , real_T dnhmhlbbyn , real_T nunu5o4sxm , real_T lxd5ye5exe ,
real_T kzqsfkqbfw , real_T ixn1g5dict , real_T dps5afzpuy , real_T ghnmm1cg2p
, real_T mryxnhaej1 , real_T dhfu3ha2qp , cq0vplcfh1 * localB , l0nzjqgucp *
localDW , nbsqgueugp * localP ) { real_T tmp ; if ( ( kmrarnehrf > 0.0 ) && (
epejdbwhc0 > 0.0 ) ) { localB -> jjdqfkhq4b = localP -> Gain_Gain * localB ->
gkprg3ghe5 ; localB -> ns2ckjnnn3 = localP -> Gain1_Gain * localB ->
p02tzwdudt ; localB -> lbbgw3vile = localP -> Gain2_Gain * localB ->
nex4eio1fy ; localB -> kzoecgydrt = localP -> Gain3_Gain * localB ->
a3kgai34ad ; localDW -> l4h0aggw4z = 4 ; } else if ( kmrarnehrf > 0.0 ) {
localB -> lbbgw3vile = kzqsfkqbfw ; localB -> jjdqfkhq4b = lxd5ye5exe /
localB -> gvthkz4uqd ; localB -> ns2ckjnnn3 = nunu5o4sxm / localB ->
mlekluhdty ; localB -> kzoecgydrt = ixn1g5dict - localP ->
HalfLaneWidthEstimate1_Value ; localDW -> gvcnio4hhw = 4 ; } else if (
epejdbwhc0 > 0.0 ) { localB -> lbbgw3vile = mryxnhaej1 ; localB -> jjdqfkhq4b
= ghnmm1cg2p / localB -> birpkjwmgk ; localB -> ns2ckjnnn3 = dps5afzpuy /
localB -> fhuclp2kjb ; localB -> kzoecgydrt = dhfu3ha2qp + localP ->
HalfLaneWidthEstimate1_Value_kslaxjeuqc ; localDW -> ilow50ohwe = 4 ; } else
{ localB -> jjdqfkhq4b = localDW -> hv2024htj2 ; localB -> ns2ckjnnn3 =
localDW -> oogjy025cs ; localB -> lbbgw3vile = localDW -> g5en32gyko ; localB
-> kzoecgydrt = localDW -> hugbkegs0r ; localDW -> iq513e4hqe = 4 ; } if ( -
localB -> ns2ckjnnn3 > localP -> Saturation3_UpperSat ) { localB ->
bhdadxzzzu = localP -> Saturation3_UpperSat ; } else if ( - localB ->
ns2ckjnnn3 < localP -> Saturation3_LowerSat ) { localB -> bhdadxzzzu = localP
-> Saturation3_LowerSat ; } else { localB -> bhdadxzzzu = - localB ->
ns2ckjnnn3 ; } if ( - localB -> jjdqfkhq4b > localP -> Saturation2_UpperSat )
{ tmp = localP -> Saturation2_UpperSat ; } else if ( - localB -> jjdqfkhq4b <
localP -> Saturation2_LowerSat ) { tmp = localP -> Saturation2_LowerSat ; }
else { tmp = - localB -> jjdqfkhq4b ; } localB -> gvsf1mrxed = localB ->
bhdadxzzzu * dnhmhlbbyn * localP -> Gain_Gain_j0wlcuxobx + tmp ; if ( localB
-> lbbgw3vile > localP -> Saturation1_UpperSat ) { localB -> b1op4qu4du =
localP -> Saturation1_UpperSat ; } else if ( localB -> lbbgw3vile < localP ->
Saturation1_LowerSat ) { localB -> b1op4qu4du = localP ->
Saturation1_LowerSat ; } else { localB -> b1op4qu4du = localB -> lbbgw3vile ;
} if ( localB -> kzoecgydrt > localP -> Saturation_UpperSat ) { localB ->
n4ys51bjpp = localP -> Saturation_UpperSat ; } else if ( localB -> kzoecgydrt
< localP -> Saturation_LowerSat ) { localB -> n4ys51bjpp = localP ->
Saturation_LowerSat ; } else { localB -> n4ys51bjpp = localB -> kzoecgydrt ;
} } void dqp3ofd3v4TID1 ( real_T nunu5o4sxm , real_T lxd5ye5exe , real_T
kzqsfkqbfw , real_T ixn1g5dict , real_T dps5afzpuy , real_T ghnmm1cg2p ,
real_T mryxnhaej1 , real_T dhfu3ha2qp , cq0vplcfh1 * localB , nbsqgueugp *
localP ) { localB -> gvthkz4uqd = localP -> Constant_Value - lxd5ye5exe *
localP -> HalfLaneWidthEstimate_Value ; localB -> mlekluhdty = localB ->
gvthkz4uqd * localB -> gvthkz4uqd ; localB -> gkprg3ghe5 = lxd5ye5exe +
ghnmm1cg2p ; localB -> p02tzwdudt = nunu5o4sxm + dps5afzpuy ; localB ->
nex4eio1fy = kzqsfkqbfw + mryxnhaej1 ; localB -> a3kgai34ad = ixn1g5dict +
dhfu3ha2qp ; localB -> birpkjwmgk = ghnmm1cg2p * localP ->
HalfLaneWidthEstimate_Value_fad045x02c + localP -> Constant_Value_cijpjtu1ez
; localB -> fhuclp2kjb = localB -> birpkjwmgk * localB -> birpkjwmgk ; } void
g4ozclgfz2 ( cq0vplcfh1 * localB , l0nzjqgucp * localDW ) { localDW ->
hugbkegs0r = localB -> kzoecgydrt ; localDW -> g5en32gyko = localB ->
lbbgw3vile ; localDW -> oogjy025cs = localB -> ns2ckjnnn3 ; localDW ->
hv2024htj2 = localB -> jjdqfkhq4b ; } void MdlInitialize ( void ) {
aqqbul4v4o ( & rtB . dqp3ofd3v44 , & rtDW . dqp3ofd3v44 , & rtP . dqp3ofd3v44
) ; } void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "estimate_lane_center/Estimate Lane Center" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 1 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. m3l1vijl4e . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ec63c912-6519-4bbc-a0d2-be67182bf511" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . m3l1vijl4e . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . m3l1vijl4e . AQHandles , "0.2" , 0.2
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . m3l1vijl4e . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
m3l1vijl4e . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
m3l1vijl4e . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
m3l1vijl4e . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"0.2" , 0.2 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 2 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 2 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . m3l1vijl4e . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"estimate_lane_center/Estimate Lane Center" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 2 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. dngafahvjf . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"0be8f14a-9823-46d5-83d6-95db14e3d3fe" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . dngafahvjf . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . dngafahvjf . AQHandles , "0.2" , 0.2
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . dngafahvjf . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dngafahvjf . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
dngafahvjf . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
dngafahvjf . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "lateral_deviation" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"double" , "" , "0.2" , 0.2 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"lateral_deviation" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 3 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 3 , "lateral_deviation" ) ; }
if ( rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval =
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; }
else { loggingInterval = sdiGetLoggingIntervals ( rt_dataMapInfo . mmi .
InstanceMap . fullPath ) ; datasetName = "" ; } accessor = rtwGetAccessor (
signalDescriptor , loggingInterval ) ; rtwAddR2Client ( accessor ,
signalDescriptor , slioCatalogue , datasetName , 1 ) ; rtDW . dngafahvjf .
SlioLTF = accessor ; } } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"estimate_lane_center/Estimate Lane Center" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 3 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. feismhumih . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d6dead54-218a-4a2c-b1a2-70d883d33995" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . feismhumih . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . feismhumih . AQHandles , "0.2" , 0.2
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . feismhumih . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
feismhumih . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
feismhumih . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
feismhumih . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "relative_yaw_angle" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"double" , "" , "0.2" , 0.2 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"relative_yaw_angle" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 4 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center" , 4 , "relative_yaw_angle" ) ; }
if ( rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval =
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; }
else { loggingInterval = sdiGetLoggingIntervals ( rt_dataMapInfo . mmi .
InstanceMap . fullPath ) ; datasetName = "" ; } accessor = rtwGetAccessor (
signalDescriptor , loggingInterval ) ; rtwAddR2Client ( accessor ,
signalDescriptor , slioCatalogue , datasetName , 1 ) ; rtDW . feismhumih .
SlioLTF = accessor ; } } } } MdlInitialize ( ) ; } void MdlOutputs ( int_T
tid ) { srClearBC ( rtDW . dqp3ofd3v44 . l4h0aggw4z ) ; srClearBC ( rtDW .
dqp3ofd3v44 . gvcnio4hhw ) ; srClearBC ( rtDW . dqp3ofd3v44 . ilow50ohwe ) ;
srClearBC ( rtDW . dqp3ofd3v44 . iq513e4hqe ) ; dqp3ofd3v4 ( rtP .
Constant_Value , rtP . Constant1_Value , rtP . Constant2_Value , rtP .
Constant3_Value , rtP . Constant4_Value , rtP . Constant5_Value , rtP .
Constant6_Value , rtP . Constant7_Value , rtP . Constant8_Value , rtP .
Constant9_Value , rtP . Constant10_Value , & rtB . dqp3ofd3v44 , & rtDW .
dqp3ofd3v44 , & rtP . dqp3ofd3v44 ) ; { if ( ( rtDW . m3l1vijl4e . AQHandles
|| rtDW . m3l1vijl4e . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . m3l1vijl4e . AQHandles , rtDW . m3l1vijl4e .
SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . dqp3ofd3v44 .
gvsf1mrxed + 0 ) ; } } { if ( ( rtDW . dngafahvjf . AQHandles || rtDW .
dngafahvjf . SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal (
rtDW . dngafahvjf . AQHandles , rtDW . dngafahvjf . SlioLTF , 0 ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . dqp3ofd3v44 . n4ys51bjpp + 0 )
; } } { if ( ( rtDW . feismhumih . AQHandles || rtDW . feismhumih . SlioLTF )
&& ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . feismhumih .
AQHandles , rtDW . feismhumih . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , (
char * ) & rtB . dqp3ofd3v44 . b1op4qu4du + 0 ) ; } } UNUSED_PARAMETER ( tid
) ; } void MdlOutputsTID1 ( int_T tid ) { dqp3ofd3v4TID1 ( rtP .
Constant3_Value , rtP . Constant4_Value , rtP . Constant5_Value , rtP .
Constant6_Value , rtP . Constant7_Value , rtP . Constant8_Value , rtP .
Constant9_Value , rtP . Constant10_Value , & rtB . dqp3ofd3v44 , & rtP .
dqp3ofd3v44 ) ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
g4ozclgfz2 ( & rtB . dqp3ofd3v44 , & rtDW . dqp3ofd3v44 ) ; UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlTerminate ( void ) { { if ( rtDW . m3l1vijl4e . AQHandles ) {
sdiTerminateStreaming ( & rtDW . m3l1vijl4e . AQHandles ) ; } if ( rtDW .
m3l1vijl4e . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . m3l1vijl4e .
SlioLTF ) ; } } { if ( rtDW . dngafahvjf . AQHandles ) {
sdiTerminateStreaming ( & rtDW . dngafahvjf . AQHandles ) ; } if ( rtDW .
dngafahvjf . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . dngafahvjf .
SlioLTF ) ; } } { if ( rtDW . feismhumih . AQHandles ) {
sdiTerminateStreaming ( & rtDW . feismhumih . AQHandles ) ; } if ( rtDW .
feismhumih . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . feismhumih .
SlioLTF ) ; } } if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 75 ) ;
ssSetNumBlockIO ( rtS , 20 ) ; ssSetNumBlockParams ( rtS , 38 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.2 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2983954583U ) ; ssSetChecksumVal ( rtS , 1 ,
126668576U ) ; ssSetChecksumVal ( rtS , 2 , 2892194270U ) ; ssSetChecksumVal
( rtS , 3 , 4245245358U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
estimate_lane_center_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"estimate_lane_center" ) ; ssSetPath ( rtS , "estimate_lane_center" ) ;
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ; ssSetStepSize ( rtS
, 0.2 ) ; ssSetFixedStepSize ( rtS , 0.2 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT ( ssGetRTWLogInfo ( rtS )
, "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal
( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 4 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo )
; ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver (
rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2983954583U ) ; ssSetChecksumVal ( rtS , 1 , 126668576U ) ; ssSetChecksumVal
( rtS , 2 , 2892194270U ) ; ssSetChecksumVal ( rtS , 3 , 4245245358U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 7 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . dqp3ofd3v44 . gvcnio4hhw ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . dqp3ofd3v44 . l4h0aggw4z ; systemRan [ 3 ] = (
sysRanDType * ) & rtDW . dqp3ofd3v44 . iq513e4hqe ; systemRan [ 4 ] = (
sysRanDType * ) & rtDW . dqp3ofd3v44 . ilow50ohwe ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
