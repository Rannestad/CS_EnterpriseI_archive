#ifndef __c17_HIL_model_h__
#define __c17_HIL_model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c17_ResolvedFunctionInfo
#define typedef_c17_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c17_ResolvedFunctionInfo;

#endif                                 /*typedef_c17_ResolvedFunctionInfo*/

#ifndef typedef_SFc17_HIL_modelInstanceStruct
#define typedef_SFc17_HIL_modelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_HIL_model;
} SFc17_HIL_modelInstanceStruct;

#endif                                 /*typedef_SFc17_HIL_modelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_HIL_model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_HIL_model_get_check_sum(mxArray *plhs[]);
extern void c17_HIL_model_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
