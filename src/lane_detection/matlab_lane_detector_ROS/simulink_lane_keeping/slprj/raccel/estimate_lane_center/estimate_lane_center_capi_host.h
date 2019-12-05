#include "__cf_estimate_lane_center.h"
#ifndef RTW_HEADER_estimate_lane_center_cap_host_h_
#define RTW_HEADER_estimate_lane_center_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
estimate_lane_center_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void estimate_lane_center_host_InitializeDataMapInfo (
estimate_lane_center_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
