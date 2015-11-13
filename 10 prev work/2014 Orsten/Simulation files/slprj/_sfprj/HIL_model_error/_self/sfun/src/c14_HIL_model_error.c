/* Include files */

#include <stddef.h>
#include "blas.h"
#include "HIL_model_error_sfun.h"
#include "c14_HIL_model_error.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "HIL_model_error_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[9] = { "eta_s", "psi", "c", "s",
  "nargin", "nargout", "eta_s_in", "Rs", "Rst" };

/* Function Declarations */
static void initialize_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);
static void initialize_params_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance);
static void enable_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);
static void disable_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance);
static void set_sim_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance, const mxArray *c14_st);
static void finalize_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);
static void sf_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);
static void initSimStructsc14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance);
static void registerMessagesc14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_Rst, const char_T *c14_identifier, real_T
  c14_y[9]);
static void c14_b_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_c_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_d_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3]);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_e_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_f_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_HIL_model_error, const
  char_T *c14_identifier);
static uint8_T c14_g_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void init_dsm_address_info(SFc14_HIL_model_errorInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_HIL_model_error = 0U;
}

static void initialize_params_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance)
{
}

static void enable_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  int32_T c14_i0;
  real_T c14_u[9];
  const mxArray *c14_b_y = NULL;
  int32_T c14_i1;
  real_T c14_b_u[9];
  const mxArray *c14_c_y = NULL;
  uint8_T c14_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  real_T (*c14_Rst)[9];
  real_T (*c14_Rs)[9];
  c14_Rst = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_Rs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(3), FALSE);
  for (c14_i0 = 0; c14_i0 < 9; c14_i0++) {
    c14_u[c14_i0] = (*c14_Rs)[c14_i0];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  for (c14_i1 = 0; c14_i1 < 9; c14_i1++) {
    c14_b_u[c14_i1] = (*c14_Rst)[c14_i1];
  }

  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_hoistedGlobal = chartInstance->c14_is_active_c14_HIL_model_error;
  c14_c_u = c14_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  sf_mex_assign(&c14_st, c14_y, FALSE);
  return c14_st;
}

static void set_sim_state_c14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[9];
  int32_T c14_i2;
  real_T c14_dv1[9];
  int32_T c14_i3;
  real_T (*c14_Rs)[9];
  real_T (*c14_Rst)[9];
  c14_Rst = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_Rs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)), "Rs",
                       c14_dv0);
  for (c14_i2 = 0; c14_i2 < 9; c14_i2++) {
    (*c14_Rs)[c14_i2] = c14_dv0[c14_i2];
  }

  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
                       "Rst", c14_dv1);
  for (c14_i3 = 0; c14_i3 < 9; c14_i3++) {
    (*c14_Rst)[c14_i3] = c14_dv1[c14_i3];
  }

  chartInstance->c14_is_active_c14_HIL_model_error = c14_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
     "is_active_c14_HIL_model_error");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_HIL_model_error(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
}

static void sf_c14_HIL_model_error(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_i7;
  real_T c14_eta_s_in[3];
  uint32_T c14_debug_family_var_map[9];
  real_T c14_eta_s[3];
  real_T c14_psi;
  real_T c14_c;
  real_T c14_s;
  real_T c14_nargin = 1.0;
  real_T c14_nargout = 2.0;
  real_T c14_Rs[9];
  real_T c14_Rst[9];
  int32_T c14_i8;
  real_T c14_x;
  real_T c14_b_x;
  real_T c14_c_x;
  real_T c14_d_x;
  int32_T c14_i9;
  int32_T c14_i10;
  static real_T c14_dv2[3] = { 0.0, 0.0, 1.0 };

  int32_T c14_i11;
  int32_T c14_i12;
  int32_T c14_i13;
  int32_T c14_i14;
  int32_T c14_i15;
  int32_T c14_i16;
  real_T (*c14_b_Rs)[9];
  real_T (*c14_b_Rst)[9];
  real_T (*c14_b_eta_s_in)[3];
  c14_b_Rst = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_Rs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_b_eta_s_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i4 = 0; c14_i4 < 3; c14_i4++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_eta_s_in)[c14_i4], 0U);
  }

  for (c14_i5 = 0; c14_i5 < 9; c14_i5++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_Rs)[c14_i5], 1U);
  }

  for (c14_i6 = 0; c14_i6 < 9; c14_i6++) {
    _SFD_DATA_RANGE_CHECK((*c14_b_Rst)[c14_i6], 2U);
  }

  chartInstance->c14_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i7 = 0; c14_i7 < 3; c14_i7++) {
    c14_eta_s_in[c14_i7] = (*c14_b_eta_s_in)[c14_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_eta_s, 0U, c14_b_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_psi, 1U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_c, 2U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_s, 3U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 4U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 5U, c14_c_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_eta_s_in, 6U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_Rs, 7U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_Rst, 8U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 3);
  CV_EML_IF(0, 1, 0, TRUE);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  for (c14_i8 = 0; c14_i8 < 3; c14_i8++) {
    c14_eta_s[c14_i8] = c14_eta_s_in[c14_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 9);
  c14_psi = c14_eta_s[2];
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 11);
  c14_x = c14_psi;
  c14_c = c14_x;
  c14_b_x = c14_c;
  c14_c = c14_b_x;
  c14_c = muDoubleScalarCos(c14_c);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 12);
  c14_c_x = c14_psi;
  c14_s = c14_c_x;
  c14_d_x = c14_s;
  c14_s = c14_d_x;
  c14_s = muDoubleScalarSin(c14_s);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 14);
  c14_Rs[0] = c14_c;
  c14_Rs[3] = -c14_s;
  c14_Rs[6] = 0.0;
  c14_Rs[1] = c14_s;
  c14_Rs[4] = c14_c;
  c14_Rs[7] = 0.0;
  c14_i9 = 0;
  for (c14_i10 = 0; c14_i10 < 3; c14_i10++) {
    c14_Rs[c14_i9 + 2] = c14_dv2[c14_i10];
    c14_i9 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 17);
  c14_i11 = 0;
  for (c14_i12 = 0; c14_i12 < 3; c14_i12++) {
    c14_i13 = 0;
    for (c14_i14 = 0; c14_i14 < 3; c14_i14++) {
      c14_Rst[c14_i14 + c14_i11] = c14_Rs[c14_i13 + c14_i12];
      c14_i13 += 3;
    }

    c14_i11 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -17);
  _SFD_SYMBOL_SCOPE_POP();
  for (c14_i15 = 0; c14_i15 < 9; c14_i15++) {
    (*c14_b_Rs)[c14_i15] = c14_Rs[c14_i15];
  }

  for (c14_i16 = 0; c14_i16 < 9; c14_i16++) {
    (*c14_b_Rst)[c14_i16] = c14_Rst[c14_i16];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_HIL_model_errorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance)
{
}

static void registerMessagesc14_HIL_model_error
  (SFc14_HIL_model_errorInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  real_T c14_b_inData[9];
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  real_T c14_u[9];
  const mxArray *c14_y = NULL;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i17 = 0;
  for (c14_i18 = 0; c14_i18 < 3; c14_i18++) {
    for (c14_i19 = 0; c14_i19 < 3; c14_i19++) {
      c14_b_inData[c14_i19 + c14_i17] = (*(real_T (*)[9])c14_inData)[c14_i19 +
        c14_i17];
    }

    c14_i17 += 3;
  }

  c14_i20 = 0;
  for (c14_i21 = 0; c14_i21 < 3; c14_i21++) {
    for (c14_i22 = 0; c14_i22 < 3; c14_i22++) {
      c14_u[c14_i22 + c14_i20] = c14_b_inData[c14_i22 + c14_i20];
    }

    c14_i20 += 3;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_Rst, const char_T *c14_identifier, real_T
  c14_y[9])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Rst), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Rst);
}

static void c14_b_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[9])
{
  real_T c14_dv3[9];
  int32_T c14_i23;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv3, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c14_i23 = 0; c14_i23 < 9; c14_i23++) {
    c14_y[c14_i23] = c14_dv3[c14_i23];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_Rst;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[9];
  int32_T c14_i24;
  int32_T c14_i25;
  int32_T c14_i26;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_Rst = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_Rst), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_Rst);
  c14_i24 = 0;
  for (c14_i25 = 0; c14_i25 < 3; c14_i25++) {
    for (c14_i26 = 0; c14_i26 < 3; c14_i26++) {
      (*(real_T (*)[9])c14_outData)[c14_i26 + c14_i24] = c14_y[c14_i26 + c14_i24];
    }

    c14_i24 += 3;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i27;
  real_T c14_b_inData[3];
  int32_T c14_i28;
  real_T c14_u[3];
  const mxArray *c14_y = NULL;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i27 = 0; c14_i27 < 3; c14_i27++) {
    c14_b_inData[c14_i27] = (*(real_T (*)[3])c14_inData)[c14_i27];
  }

  for (c14_i28 = 0; c14_i28 < 3; c14_i28++) {
    c14_u[c14_i28] = c14_b_inData[c14_i28];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static real_T c14_c_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static void c14_d_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[3])
{
  real_T c14_dv4[3];
  int32_T c14_i29;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c14_i29 = 0; c14_i29 < 3; c14_i29++) {
    c14_y[c14_i29] = c14_dv4[c14_i29];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_eta_s;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[3];
  int32_T c14_i30;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_eta_s = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_eta_s), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_eta_s);
  for (c14_i30 = 0; c14_i30 < 3; c14_i30++) {
    (*(real_T (*)[3])c14_outData)[c14_i30] = c14_y[c14_i30];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_HIL_model_error_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo;
  c14_ResolvedFunctionInfo c14_info[5];
  c14_ResolvedFunctionInfo (*c14_b_info)[5];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i31;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  c14_b_info = (c14_ResolvedFunctionInfo (*)[5])c14_info;
  (*c14_b_info)[0].context = "";
  (*c14_b_info)[0].name = "length";
  (*c14_b_info)[0].dominantType = "double";
  (*c14_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c14_b_info)[0].fileTimeLo = 1303146206U;
  (*c14_b_info)[0].fileTimeHi = 0U;
  (*c14_b_info)[0].mFileTimeLo = 0U;
  (*c14_b_info)[0].mFileTimeHi = 0U;
  (*c14_b_info)[1].context = "";
  (*c14_b_info)[1].name = "cos";
  (*c14_b_info)[1].dominantType = "double";
  (*c14_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c14_b_info)[1].fileTimeLo = 1343830372U;
  (*c14_b_info)[1].fileTimeHi = 0U;
  (*c14_b_info)[1].mFileTimeLo = 0U;
  (*c14_b_info)[1].mFileTimeHi = 0U;
  (*c14_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c14_b_info)[2].name = "eml_scalar_cos";
  (*c14_b_info)[2].dominantType = "double";
  (*c14_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c14_b_info)[2].fileTimeLo = 1286818722U;
  (*c14_b_info)[2].fileTimeHi = 0U;
  (*c14_b_info)[2].mFileTimeLo = 0U;
  (*c14_b_info)[2].mFileTimeHi = 0U;
  (*c14_b_info)[3].context = "";
  (*c14_b_info)[3].name = "sin";
  (*c14_b_info)[3].dominantType = "double";
  (*c14_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c14_b_info)[3].fileTimeLo = 1343830386U;
  (*c14_b_info)[3].fileTimeHi = 0U;
  (*c14_b_info)[3].mFileTimeLo = 0U;
  (*c14_b_info)[3].mFileTimeHi = 0U;
  (*c14_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c14_b_info)[4].name = "eml_scalar_sin";
  (*c14_b_info)[4].dominantType = "double";
  (*c14_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c14_b_info)[4].fileTimeLo = 1286818736U;
  (*c14_b_info)[4].fileTimeHi = 0U;
  (*c14_b_info)[4].mFileTimeLo = 0U;
  (*c14_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c14_i31 = 0; c14_i31 < 5; c14_i31++) {
    c14_r0 = &c14_info[c14_i31];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context", "nameCaptureInfo",
                    c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name", "nameCaptureInfo",
                    c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)), "resolved",
                    "nameCaptureInfo", c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c14_i31);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      &c14_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c14_i31);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static int32_T c14_e_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i32;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i32, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i32;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_f_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_HIL_model_error, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_HIL_model_error), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_HIL_model_error);
  return c14_y;
}

static uint8_T c14_g_emlrt_marshallIn(SFc14_HIL_model_errorInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void init_dsm_address_info(SFc14_HIL_model_errorInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c14_HIL_model_error_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4289391406U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(382120235U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(836338695U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3307314979U);
}

mxArray *sf_c14_HIL_model_error_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("H08gUXOQ4cGie6wRMFqGLH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c14_HIL_model_error_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c14_HIL_model_error(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Rs\",},{M[1],M[6],T\"Rst\",},{M[8],M[0],T\"is_active_c14_HIL_model_error\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_HIL_model_error_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_HIL_model_errorInstanceStruct *chartInstance;
    chartInstance = (SFc14_HIL_model_errorInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _HIL_model_errorMachineNumber_,
           14,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_HIL_model_errorMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_HIL_model_errorMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _HIL_model_errorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"eta_s_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Rs");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Rst");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,222);
        _SFD_CV_INIT_EML_IF(0,1,0,36,59,82,113);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        {
          real_T (*c14_eta_s_in)[3];
          real_T (*c14_Rs)[9];
          real_T (*c14_Rst)[9];
          c14_Rst = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c14_Rs = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c14_eta_s_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_eta_s_in);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_Rs);
          _SFD_SET_DATA_VALUE_PTR(2U, *c14_Rst);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _HIL_model_errorMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "aE4uNmGkbqfeM8ew8jZHyB";
}

static void sf_opaque_initialize_c14_HIL_model_error(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar);
  initialize_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_HIL_model_error(void *chartInstanceVar)
{
  enable_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_HIL_model_error(void *chartInstanceVar)
{
  disable_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_HIL_model_error(void *chartInstanceVar)
{
  sf_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_HIL_model_error(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_HIL_model_error
    ((SFc14_HIL_model_errorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_HIL_model_error();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c14_HIL_model_error(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_HIL_model_error();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_HIL_model_error(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_HIL_model_error(S);
}

static void sf_opaque_set_sim_state_c14_HIL_model_error(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_HIL_model_error(S, st);
}

static void sf_opaque_terminate_c14_HIL_model_error(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_HIL_model_errorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_HIL_model_error_optimization_info();
    }

    finalize_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_HIL_model_error(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_HIL_model_error((SFc14_HIL_model_errorInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_HIL_model_error(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_HIL_model_error_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,14,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1273352058U));
  ssSetChecksum1(S,(1709361536U));
  ssSetChecksum2(S,(1818388815U));
  ssSetChecksum3(S,(3593189603U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_HIL_model_error(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_HIL_model_error(SimStruct *S)
{
  SFc14_HIL_model_errorInstanceStruct *chartInstance;
  chartInstance = (SFc14_HIL_model_errorInstanceStruct *)utMalloc(sizeof
    (SFc14_HIL_model_errorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_HIL_model_errorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_HIL_model_error;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_HIL_model_error;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_HIL_model_error;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_HIL_model_error;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_HIL_model_error;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_HIL_model_error;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_HIL_model_error;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_HIL_model_error;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_HIL_model_error;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_HIL_model_error;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_HIL_model_error;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c14_HIL_model_error_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_HIL_model_error(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_HIL_model_error(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_HIL_model_error(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_HIL_model_error_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}