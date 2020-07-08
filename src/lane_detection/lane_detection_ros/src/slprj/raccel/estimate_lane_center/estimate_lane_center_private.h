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
extern void gonwrwsnce ( pl2abai0sd * localB , nliga4imox * localDW ,
adfesqiczr * localP ) ; extern void a41okf55me ( pl2abai0sd * localB ,
nliga4imox * localDW ) ; extern void k3pph0iicy ( real32_T ofkpnj22vl ,
real32_T iguzlk4ygi , real_T iz50heejrg , real32_T keinvhkzrq , real32_T
pw1t1c4zoa , real32_T aowty2yztt , real32_T bxzqixm1oj , real32_T fxmxxecp0m
, real32_T bmd2wsedby , real32_T hrgfr3gxc2 , real32_T cug1lliigd ,
pl2abai0sd * localB , nliga4imox * localDW , adfesqiczr * localP ) ; extern
void k3pph0iicyTID1 ( real32_T keinvhkzrq , real32_T pw1t1c4zoa , real32_T
aowty2yztt , real32_T bxzqixm1oj , real32_T fxmxxecp0m , real32_T bmd2wsedby
, real32_T hrgfr3gxc2 , real32_T cug1lliigd , pl2abai0sd * localB ,
adfesqiczr * localP ) ;
#if defined(MULTITASKING)
#error Model (estimate_lane_center) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
