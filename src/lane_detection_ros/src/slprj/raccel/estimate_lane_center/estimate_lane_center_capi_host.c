#include "estimate_lane_center_capi_host.h"
static estimate_lane_center_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        estimate_lane_center_host_InitializeDataMapInfo(&(root), "estimate_lane_center");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
