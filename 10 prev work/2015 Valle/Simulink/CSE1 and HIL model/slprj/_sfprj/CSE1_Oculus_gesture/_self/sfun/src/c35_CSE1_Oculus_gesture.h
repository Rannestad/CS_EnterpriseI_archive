#ifndef __c35_CSE1_Oculus_gesture_h__
#define __c35_CSE1_Oculus_gesture_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_CSE1_Oculus_gestureInstanceStruct
#define typedef_SFc35_CSE1_Oculus_gestureInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_CSE1_Oculus_gesture;
} SFc35_CSE1_Oculus_gestureInstanceStruct;

#endif                                 /*typedef_SFc35_CSE1_Oculus_gestureInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_CSE1_Oculus_gesture_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c35_CSE1_Oculus_gesture_get_check_sum(mxArray *plhs[]);
extern void c35_CSE1_Oculus_gesture_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif