#include "__cf_estimate_lane_center.h"
#ifndef RTW_HEADER_estimate_lane_center_private_h_
#define RTW_HEADER_estimate_lane_center_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "estimate_lane_center.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
extern void aqqbul4v4o ( cq0vplcfh1 * localB , l0nzjqgucp * localDW ,
nbsqgueugp * localP ) ; extern void g4ozclgfz2 ( cq0vplcfh1 * localB ,
l0nzjqgucp * localDW ) ; extern void dqp3ofd3v4 ( real_T kmrarnehrf , real_T
epejdbwhc0 , real_T dnhmhlbbyn , real_T nunu5o4sxm , real_T lxd5ye5exe ,
real_T kzqsfkqbfw , real_T ixn1g5dict , real_T dps5afzpuy , real_T ghnmm1cg2p
, real_T mryxnhaej1 , real_T dhfu3ha2qp , cq0vplcfh1 * localB , l0nzjqgucp *
localDW , nbsqgueugp * localP ) ; extern void dqp3ofd3v4TID1 ( real_T
nunu5o4sxm , real_T lxd5ye5exe , real_T kzqsfkqbfw , real_T ixn1g5dict ,
real_T dps5afzpuy , real_T ghnmm1cg2p , real_T mryxnhaej1 , real_T dhfu3ha2qp
, cq0vplcfh1 * localB , nbsqgueugp * localP ) ;
#if defined(MULTITASKING)
#error Model (estimate_lane_center) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
