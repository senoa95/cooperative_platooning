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
model_S ; void gonwrwsnce ( pl2abai0sd * localB , nliga4imox * localDW ,
adfesqiczr * localP ) { localDW -> eckz3pxwzc = localP ->
Delay_4_InitialCondition ; localDW -> f5zwivgby1 = localP ->
Delay_3_InitialCondition ; localDW -> cvvezosg3d = localP ->
Delay_2_InitialCondition ; localDW -> o03k3dg52b = localP ->
Delay_1_InitialCondition ; localB -> dlphfoumb0 = localP ->
Merge_2_InitialOutput ; localB -> j0y3qvbbhb = localP ->
Merge_1_InitialOutput ; localB -> g34esawosi = localP ->
Merge_3_InitialOutput ; localB -> kdicdcckls = localP ->
Merge_4_InitialOutput ; } void k3pph0iicy ( real32_T ofkpnj22vl , real32_T
iguzlk4ygi , real_T iz50heejrg , real32_T keinvhkzrq , real32_T pw1t1c4zoa ,
real32_T aowty2yztt , real32_T bxzqixm1oj , real32_T fxmxxecp0m , real32_T
bmd2wsedby , real32_T hrgfr3gxc2 , real32_T cug1lliigd , pl2abai0sd * localB
, nliga4imox * localDW , adfesqiczr * localP ) { real_T f2rhhct1bk ; real32_T
ogvkpkmxmc ; if ( ( ofkpnj22vl > 0.0F ) && ( iguzlk4ygi > 0.0F ) ) { localB
-> j0y3qvbbhb = localP -> Gain_Gain_csudgssrcg * localB -> jev0d0au1k ;
localB -> dlphfoumb0 = localP -> Gain1_Gain * localB -> pyt3nna2lj ; localB
-> g34esawosi = localP -> Gain2_Gain * localB -> ov5lcbuchn ; localB ->
kdicdcckls = localP -> Gain3_Gain * localB -> c0xy4zpqv1 ; localDW ->
mwbiwkoruj = 4 ; } else if ( ofkpnj22vl > 0.0F ) { localB -> g34esawosi =
aowty2yztt ; localB -> j0y3qvbbhb = pw1t1c4zoa / localB -> oc05twylps ;
localB -> dlphfoumb0 = keinvhkzrq / localB -> ggudjvgpuu ; localB ->
kdicdcckls = bxzqixm1oj - localP -> HalfLaneWidthEstimate1_Value ; localDW ->
gppbpgjejo = 4 ; } else if ( iguzlk4ygi > 0.0F ) { localB -> g34esawosi =
hrgfr3gxc2 ; localB -> j0y3qvbbhb = bmd2wsedby / localB -> e53ulgorx1 ;
localB -> dlphfoumb0 = fxmxxecp0m / localB -> fh2jemzwct ; localB ->
kdicdcckls = cug1lliigd + localP -> HalfLaneWidthEstimate1_Value_kccholnvrj ;
localDW -> o40mjycyzi = 4 ; } else { localB -> j0y3qvbbhb = localDW ->
o03k3dg52b ; localB -> dlphfoumb0 = localDW -> cvvezosg3d ; localB ->
g34esawosi = localDW -> f5zwivgby1 ; localB -> kdicdcckls = localDW ->
eckz3pxwzc ; localDW -> gsiekacha1 = 4 ; } if ( - localB -> dlphfoumb0 >
localP -> Saturation3_UpperSat ) { localB -> dkaupoobjr = localP ->
Saturation3_UpperSat ; } else if ( - localB -> dlphfoumb0 < localP ->
Saturation3_LowerSat ) { localB -> dkaupoobjr = localP ->
Saturation3_LowerSat ; } else { localB -> dkaupoobjr = - localB -> dlphfoumb0
; } f2rhhct1bk = localB -> dkaupoobjr * iz50heejrg ; if ( - localB ->
j0y3qvbbhb > localP -> Saturation2_UpperSat ) { ogvkpkmxmc = localP ->
Saturation2_UpperSat ; } else if ( - localB -> j0y3qvbbhb < localP ->
Saturation2_LowerSat ) { ogvkpkmxmc = localP -> Saturation2_LowerSat ; } else
{ ogvkpkmxmc = - localB -> j0y3qvbbhb ; } localB -> icvqtrbbcd [ 0 ] = localP
-> Gain_Gain [ 0 ] * f2rhhct1bk + ogvkpkmxmc ; localB -> icvqtrbbcd [ 1 ] =
localP -> Gain_Gain [ 1 ] * f2rhhct1bk + ogvkpkmxmc ; localB -> icvqtrbbcd [
2 ] = localP -> Gain_Gain [ 2 ] * f2rhhct1bk + ogvkpkmxmc ; if ( localB ->
g34esawosi > localP -> Saturation1_UpperSat ) { localB -> oqjwvlopf5 = localP
-> Saturation1_UpperSat ; } else if ( localB -> g34esawosi < localP ->
Saturation1_LowerSat ) { localB -> oqjwvlopf5 = localP ->
Saturation1_LowerSat ; } else { localB -> oqjwvlopf5 = localB -> g34esawosi ;
} if ( localB -> kdicdcckls > localP -> Saturation_UpperSat ) { localB ->
mvxqr2bcws = localP -> Saturation_UpperSat ; } else if ( localB -> kdicdcckls
< localP -> Saturation_LowerSat ) { localB -> mvxqr2bcws = localP ->
Saturation_LowerSat ; } else { localB -> mvxqr2bcws = localB -> kdicdcckls ;
} } void k3pph0iicyTID1 ( real32_T keinvhkzrq , real32_T pw1t1c4zoa ,
real32_T aowty2yztt , real32_T bxzqixm1oj , real32_T fxmxxecp0m , real32_T
bmd2wsedby , real32_T hrgfr3gxc2 , real32_T cug1lliigd , pl2abai0sd * localB
, adfesqiczr * localP ) { localB -> oc05twylps = localP -> Constant_Value -
pw1t1c4zoa * localP -> HalfLaneWidthEstimate_Value ; localB -> ggudjvgpuu =
localB -> oc05twylps * localB -> oc05twylps ; localB -> jev0d0au1k =
pw1t1c4zoa + bmd2wsedby ; localB -> pyt3nna2lj = keinvhkzrq + fxmxxecp0m ;
localB -> ov5lcbuchn = aowty2yztt + hrgfr3gxc2 ; localB -> c0xy4zpqv1 =
bxzqixm1oj + cug1lliigd ; localB -> e53ulgorx1 = bmd2wsedby * localP ->
HalfLaneWidthEstimate_Value_amvyq0ozrf + localP -> Constant_Value_jgqntcaric
; localB -> fh2jemzwct = localB -> e53ulgorx1 * localB -> e53ulgorx1 ; } void
a41okf55me ( pl2abai0sd * localB , nliga4imox * localDW ) { localDW ->
eckz3pxwzc = localB -> kdicdcckls ; localDW -> f5zwivgby1 = localB ->
g34esawosi ; localDW -> cvvezosg3d = localB -> dlphfoumb0 ; localDW ->
o03k3dg52b = localB -> j0y3qvbbhb ; } void MdlInitialize ( void ) {
gonwrwsnce ( & rtB . k3pph0iicyb , & rtDW . k3pph0iicyb , & rtP . k3pph0iicyb
) ; gonwrwsnce ( & rtB . e0dg4qnjc3 , & rtDW . e0dg4qnjc3 , & rtP .
e0dg4qnjc3 ) ; } void MdlStart ( void ) { { void * * slioCatalogueAddr =
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
; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 1 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. m3l1vijl4e . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"1e9afbf6-0d11-41dc-8532-d0180f62dee2" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . m3l1vijl4e . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . m3l1vijl4e . AQHandles , "0.1" , 0.1
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
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 3 } ; rtwAddLeafNode (
0 , "" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
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
} } } } { static int_T rt_ToWksWidths [ ] = { 3 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 3
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "estimate_lane_center/To Workspace3" ;
rtDW . i10vows2kx . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "center_curvature" , 1 , 0 , 1 , 0.1 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . i10vows2kx .
LoggedData == ( NULL ) ) return ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "lateral_deviation" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"estimate_lane_center/Estimate Lane Center" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 2 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. dngafahvjf . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"e11bfbbc-47d6-43fb-baf8-89a15872a45d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . dngafahvjf . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . dngafahvjf . AQHandles , "0.1" , 0.1
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
1 , "lateral_deviation" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"single" , "" , "0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; }
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
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 3 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. feismhumih . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"361caf56-7390-4ae1-b12a-21bbc9e001a3" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . feismhumih . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . feismhumih . AQHandles , "0.1" , 0.1
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
1 , "relative_yaw_angle" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"single" , "" , "0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; }
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
SlioLTF = accessor ; } } } } { static int_T rt_ToWksWidths [ ] = { 1 } ;
static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 1 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace" ; rtDW . kovwqq2md4 . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_curvature_derivative" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . kovwqq2md4 . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "relative_yaw_angle" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace1" ; rtDW . g2ldytnxfq . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_relative_yaw_angle" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . g2ldytnxfq . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "lateral_deviation" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace2" ; rtDW . ok2p2lv0ek . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_lateral_deviation" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . ok2p2lv0ek . LoggedData == ( NULL ) )
return ; } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "estimate_lane_center/Estimate Lane Center1" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 1 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. a3kpjsykfj . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"2f8fcdef-7178-4757-9830-7eca2a9c1923" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . a3kpjsykfj . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . a3kpjsykfj . AQHandles , "0.1" , 0.1
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . a3kpjsykfj . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
a3kpjsykfj . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
a3kpjsykfj . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
a3kpjsykfj . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 3 } ; rtwAddLeafNode (
0 , "" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 2 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 2 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . a3kpjsykfj . SlioLTF = accessor ;
} } } } { static int_T rt_ToWksWidths [ ] = { 3 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 3
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo rt_ToWksSignalInfo =
{ 1 , rt_ToWksWidths , rt_ToWksNumDimensions , rt_ToWksDimensions ,
rt_ToWksIsVarDims , rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize ,
rt_ToWksDataTypeIds , rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "estimate_lane_center/To Workspace7" ;
rtDW . dnvh1kcj2i . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "center_curvature1" , 1 , 0 , 1 , 0.1 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . dnvh1kcj2i .
LoggedData == ( NULL ) ) return ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
{ sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars
( "lateral_deviation" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"estimate_lane_center/Estimate Lane Center1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"lateral_deviation" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 2 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. jshekjjwkp . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"54d37fd5-cbc6-44bb-b154-ee255bb0df02" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . jshekjjwkp . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . jshekjjwkp . AQHandles , "0.1" , 0.1
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . jshekjjwkp . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
jshekjjwkp . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
jshekjjwkp . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
jshekjjwkp . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
1 , "lateral_deviation" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"single" , "" , "0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"lateral_deviation" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 3 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 3 , "lateral_deviation" ) ; }
if ( rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval =
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; }
else { loggingInterval = sdiGetLoggingIntervals ( rt_dataMapInfo . mmi .
InstanceMap . fullPath ) ; datasetName = "" ; } accessor = rtwGetAccessor (
signalDescriptor , loggingInterval ) ; rtwAddR2Client ( accessor ,
signalDescriptor , slioCatalogue , datasetName , 1 ) ; rtDW . jshekjjwkp .
SlioLTF = accessor ; } } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"estimate_lane_center/Estimate Lane Center1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"relative_yaw_angle" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_SINGLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 3 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. fg10l0wasa . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ac849179-5e5c-4695-ba5f-2eb2fc5c3737" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . fg10l0wasa . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . fg10l0wasa . AQHandles , "0.1" , 0.1
, ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . fg10l0wasa . AQHandles
, ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
fg10l0wasa . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
fg10l0wasa . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
fg10l0wasa . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
1 , "relative_yaw_angle" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 ,
"single" , "" , "0.1" , 0.1 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"relative_yaw_angle" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 4 , 0 , slioCatalogue , ( NULL
) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) {
sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"estimate_lane_center/Estimate Lane Center1" , 4 , "relative_yaw_angle" ) ; }
if ( rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval =
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; }
else { loggingInterval = sdiGetLoggingIntervals ( rt_dataMapInfo . mmi .
InstanceMap . fullPath ) ; datasetName = "" ; } accessor = rtwGetAccessor (
signalDescriptor , loggingInterval ) ; rtwAddR2Client ( accessor ,
signalDescriptor , slioCatalogue , datasetName , 1 ) ; rtDW . fg10l0wasa .
SlioLTF = accessor ; } } } } { static int_T rt_ToWksWidths [ ] = { 1 } ;
static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 1 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace4" ; rtDW . panzj3fxix . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_curvature_derivative1" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . panzj3fxix . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "relative_yaw_angle" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace5" ; rtDW . nutfnhr4zj . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_relative_yaw_angle1" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . nutfnhr4zj . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 1 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 1
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_SINGLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "lateral_deviation" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"estimate_lane_center/To Workspace6" ; rtDW . bmwwkwthwc . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"center_lateral_deviation1" , 1 , 0 , 1 , 0.1 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . bmwwkwthwc . LoggedData == ( NULL ) )
return ; } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { srClearBC (
rtDW . k3pph0iicyb . mwbiwkoruj ) ; srClearBC ( rtDW . k3pph0iicyb .
gppbpgjejo ) ; srClearBC ( rtDW . k3pph0iicyb . o40mjycyzi ) ; srClearBC (
rtDW . k3pph0iicyb . gsiekacha1 ) ; k3pph0iicy ( rtP . left_strength , rtP .
right_strength , rtP . Constant_Value , rtP . left_curvature_rate , rtP .
left_curvature , rtP . left_relative_yaw_angle , rtP . left_lateral_deviation
, rtP . right_curvature_rate , rtP . right_curvature , rtP .
right_relative_yaw_angle , rtP . right_lateral_deviation , & rtB .
k3pph0iicyb , & rtDW . k3pph0iicyb , & rtP . k3pph0iicyb ) ; { if ( ( rtDW .
m3l1vijl4e . AQHandles || rtDW . m3l1vijl4e . SlioLTF ) && ssGetLogOutput (
rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . m3l1vijl4e . AQHandles , rtDW .
m3l1vijl4e . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
k3pph0iicyb . icvqtrbbcd [ 0 ] + 0 ) ; } } { double locTime = ssGetTaskTime (
rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval
( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . i10vows2kx .
LoggedData , & locTime , & rtB . k3pph0iicyb . icvqtrbbcd [ 0 ] ) ; } } } } {
if ( ( rtDW . dngafahvjf . AQHandles || rtDW . dngafahvjf . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . dngafahvjf .
AQHandles , rtDW . dngafahvjf . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , (
char * ) & rtB . k3pph0iicyb . mvxqr2bcws + 0 ) ; } } { if ( ( rtDW .
feismhumih . AQHandles || rtDW . feismhumih . SlioLTF ) && ssGetLogOutput (
rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . feismhumih . AQHandles , rtDW .
feismhumih . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
k3pph0iicyb . oqjwvlopf5 + 0 ) ; } } { double locTime = ssGetTaskTime ( rtS ,
0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . kovwqq2md4 .
LoggedData , & locTime , & rtB . k3pph0iicyb . dkaupoobjr ) ; } } } } {
double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . g2ldytnxfq . LoggedData , & locTime , & rtB .
k3pph0iicyb . oqjwvlopf5 ) ; } } } } { double locTime = ssGetTaskTime ( rtS ,
0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ok2p2lv0ek .
LoggedData , & locTime , & rtB . k3pph0iicyb . mvxqr2bcws ) ; } } } }
k3pph0iicy ( rtP . left_strength , rtP . right_strength , rtP .
Constant11_Value , rtP . left_curvature_rate , rtP . left_curvature , rtP .
left_relative_yaw_angle , rtP . left_lateral_deviation , rtP .
right_curvature_rate , rtP . right_curvature , rtP . right_relative_yaw_angle
, rtP . right_lateral_deviation , & rtB . e0dg4qnjc3 , & rtDW . e0dg4qnjc3 ,
& rtP . e0dg4qnjc3 ) ; { if ( ( rtDW . a3kpjsykfj . AQHandles || rtDW .
a3kpjsykfj . SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal (
rtDW . a3kpjsykfj . AQHandles , rtDW . a3kpjsykfj . SlioLTF , 0 ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . e0dg4qnjc3 . icvqtrbbcd [ 0 ]
+ 0 ) ; } } { double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . dnvh1kcj2i .
LoggedData , & locTime , & rtB . e0dg4qnjc3 . icvqtrbbcd [ 0 ] ) ; } } } } {
if ( ( rtDW . jshekjjwkp . AQHandles || rtDW . jshekjjwkp . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . jshekjjwkp .
AQHandles , rtDW . jshekjjwkp . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , (
char * ) & rtB . e0dg4qnjc3 . mvxqr2bcws + 0 ) ; } } { if ( ( rtDW .
fg10l0wasa . AQHandles || rtDW . fg10l0wasa . SlioLTF ) && ssGetLogOutput (
rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . fg10l0wasa . AQHandles , rtDW .
fg10l0wasa . SlioLTF , 0 , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
e0dg4qnjc3 . oqjwvlopf5 + 0 ) ; } } { double locTime = ssGetTaskTime ( rtS ,
0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . panzj3fxix .
LoggedData , & locTime , & rtB . e0dg4qnjc3 . dkaupoobjr ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . nutfnhr4zj . LoggedData , & locTime , & rtB .
e0dg4qnjc3 . oqjwvlopf5 ) ; } } } } { double locTime = ssGetTaskTime ( rtS ,
0 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . bmwwkwthwc .
LoggedData , & locTime , & rtB . e0dg4qnjc3 . mvxqr2bcws ) ; } } } }
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID1 ( int_T tid ) {
k3pph0iicyTID1 ( rtP . left_curvature_rate , rtP . left_curvature , rtP .
left_relative_yaw_angle , rtP . left_lateral_deviation , rtP .
right_curvature_rate , rtP . right_curvature , rtP . right_relative_yaw_angle
, rtP . right_lateral_deviation , & rtB . k3pph0iicyb , & rtP . k3pph0iicyb )
; k3pph0iicyTID1 ( rtP . left_curvature_rate , rtP . left_curvature , rtP .
left_relative_yaw_angle , rtP . left_lateral_deviation , rtP .
right_curvature_rate , rtP . right_curvature , rtP . right_relative_yaw_angle
, rtP . right_lateral_deviation , & rtB . e0dg4qnjc3 , & rtP . e0dg4qnjc3 ) ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { a41okf55me ( &
rtB . k3pph0iicyb , & rtDW . k3pph0iicyb ) ; a41okf55me ( & rtB . e0dg4qnjc3
, & rtDW . e0dg4qnjc3 ) ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { { if
( rtDW . m3l1vijl4e . AQHandles ) { sdiTerminateStreaming ( & rtDW .
m3l1vijl4e . AQHandles ) ; } if ( rtDW . m3l1vijl4e . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . m3l1vijl4e . SlioLTF ) ; } } { if ( rtDW
. dngafahvjf . AQHandles ) { sdiTerminateStreaming ( & rtDW . dngafahvjf .
AQHandles ) ; } if ( rtDW . dngafahvjf . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . dngafahvjf . SlioLTF ) ; } } { if ( rtDW
. feismhumih . AQHandles ) { sdiTerminateStreaming ( & rtDW . feismhumih .
AQHandles ) ; } if ( rtDW . feismhumih . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . feismhumih . SlioLTF ) ; } } { if ( rtDW
. a3kpjsykfj . AQHandles ) { sdiTerminateStreaming ( & rtDW . a3kpjsykfj .
AQHandles ) ; } if ( rtDW . a3kpjsykfj . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . a3kpjsykfj . SlioLTF ) ; } } { if ( rtDW
. jshekjjwkp . AQHandles ) { sdiTerminateStreaming ( & rtDW . jshekjjwkp .
AQHandles ) ; } if ( rtDW . jshekjjwkp . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . jshekjjwkp . SlioLTF ) ; } } { if ( rtDW
. fg10l0wasa . AQHandles ) { sdiTerminateStreaming ( & rtDW . fg10l0wasa .
AQHandles ) ; } if ( rtDW . fg10l0wasa . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . fg10l0wasa . SlioLTF ) ; } } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 98 ) ;
ssSetNumBlockIO ( rtS , 40 ) ; ssSetNumBlockParams ( rtS , 70 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1266430929U ) ; ssSetChecksumVal ( rtS , 1 ,
2926641344U ) ; ssSetChecksumVal ( rtS , 2 , 2919994738U ) ; ssSetChecksumVal
( rtS , 3 , 3380208096U ) ; }
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
ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 0.1 ) ; ssSetStepSize ( rtS ,
0.1 ) ; ssSetFixedStepSize ( rtS , 0.1 ) ; { static RTWLogInfo
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
1266430929U ) ; ssSetChecksumVal ( rtS , 1 , 2926641344U ) ; ssSetChecksumVal
( rtS , 2 , 2919994738U ) ; ssSetChecksumVal ( rtS , 3 , 3380208096U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 13 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = (
sysRanDType * ) & rtDW . k3pph0iicyb . gppbpgjejo ; systemRan [ 2 ] = (
sysRanDType * ) & rtDW . k3pph0iicyb . mwbiwkoruj ; systemRan [ 3 ] = (
sysRanDType * ) & rtDW . k3pph0iicyb . gsiekacha1 ; systemRan [ 4 ] = (
sysRanDType * ) & rtDW . k3pph0iicyb . o40mjycyzi ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = (
sysRanDType * ) & rtDW . e0dg4qnjc3 . gppbpgjejo ; systemRan [ 8 ] = (
sysRanDType * ) & rtDW . e0dg4qnjc3 . mwbiwkoruj ; systemRan [ 9 ] = (
sysRanDType * ) & rtDW . e0dg4qnjc3 . gsiekacha1 ; systemRan [ 10 ] = (
sysRanDType * ) & rtDW . e0dg4qnjc3 . o40mjycyzi ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
