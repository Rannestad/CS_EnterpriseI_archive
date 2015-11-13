/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model_justmodel_sfun.h"
#include "c7_Model_justmodel.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Model_justmodel_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[17] = { "psi_d", "psi_s", "cd", "sd",
  "Rd", "cs", "ss", "Rs", "Rst", "nargin", "nargout", "Kp", "z1", "nu_d",
  "eta_s", "eta_d", "alpha_1" };

/* Function Declarations */
static void initialize_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void initialize_params_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance);
static void enable_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void disable_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance);
static void set_sim_state_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct *
  chartInstance, const mxArray *c7_st);
static void finalize_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void sf_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void c7_chartstep_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance);
static void initSimStructsc7_Model_justmodel(SFc7_Model_justmodelInstanceStruct *
  chartInstance);
static void registerMessagesc7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_alpha_1, const char_T *c7_identifier, real_T
  c7_y[3]);
static void c7_b_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[3]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_d_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[9]);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[14]);
static void c7_eml_scalar_eg(SFc7_Model_justmodelInstanceStruct *chartInstance);
static void c7_b_eml_scalar_eg(SFc7_Model_justmodelInstanceStruct *chartInstance);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_e_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_f_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Model_justmodel, const char_T
  *c7_identifier);
static uint8_T c7_g_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_Model_justmodelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_Model_justmodel = 0U;
}

static void initialize_params_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance)
{
}

static void enable_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[3];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T (*c7_alpha_1)[3];
  c7_alpha_1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_u[c7_i0] = (*c7_alpha_1)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_Model_justmodel;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct *
  chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[3];
  int32_T c7_i1;
  real_T (*c7_alpha_1)[3];
  c7_alpha_1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
                      "alpha_1", c7_dv0);
  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    (*c7_alpha_1)[c7_i1] = c7_dv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_Model_justmodel = c7_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_Model_justmodel");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Model_justmodel(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
}

static void sf_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_i7;
  real_T (*c7_eta_d)[3];
  real_T (*c7_eta_s)[3];
  real_T (*c7_nu_d)[3];
  real_T (*c7_z1)[3];
  real_T (*c7_alpha_1)[3];
  real_T (*c7_Kp)[9];
  c7_eta_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c7_eta_s = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c7_nu_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c7_z1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c7_alpha_1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_Kp = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 9; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((*c7_Kp)[c7_i2], 0U);
  }

  for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*c7_alpha_1)[c7_i3], 1U);
  }

  for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*c7_z1)[c7_i4], 2U);
  }

  for (c7_i5 = 0; c7_i5 < 3; c7_i5++) {
    _SFD_DATA_RANGE_CHECK((*c7_nu_d)[c7_i5], 3U);
  }

  for (c7_i6 = 0; c7_i6 < 3; c7_i6++) {
    _SFD_DATA_RANGE_CHECK((*c7_eta_s)[c7_i6], 4U);
  }

  for (c7_i7 = 0; c7_i7 < 3; c7_i7++) {
    _SFD_DATA_RANGE_CHECK((*c7_eta_d)[c7_i7], 5U);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_Model_justmodel(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model_justmodelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_chartstep_c7_Model_justmodel(SFc7_Model_justmodelInstanceStruct
  *chartInstance)
{
  int32_T c7_i8;
  real_T c7_Kp[9];
  int32_T c7_i9;
  real_T c7_z1[3];
  int32_T c7_i10;
  real_T c7_nu_d[3];
  int32_T c7_i11;
  real_T c7_eta_s[3];
  int32_T c7_i12;
  real_T c7_eta_d[3];
  uint32_T c7_debug_family_var_map[17];
  real_T c7_psi_d;
  real_T c7_psi_s;
  real_T c7_cd;
  real_T c7_sd;
  real_T c7_Rd[9];
  real_T c7_cs;
  real_T c7_ss;
  real_T c7_Rs[9];
  real_T c7_Rst[9];
  real_T c7_nargin = 5.0;
  real_T c7_nargout = 1.0;
  real_T c7_alpha_1[3];
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_d_x;
  int32_T c7_i13;
  int32_T c7_i14;
  static real_T c7_dv1[3] = { 0.0, 0.0, 1.0 };

  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_g_x;
  real_T c7_h_x;
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i20;
  int32_T c7_i21;
  real_T c7_a[9];
  int32_T c7_i22;
  real_T c7_b[3];
  int32_T c7_i23;
  real_T c7_y[3];
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  int32_T c7_i27;
  real_T c7_b_b[9];
  int32_T c7_i28;
  int32_T c7_i29;
  int32_T c7_i30;
  real_T c7_b_y[9];
  int32_T c7_i31;
  int32_T c7_i32;
  int32_T c7_i33;
  int32_T c7_i34;
  real_T c7_c_y[3];
  int32_T c7_i35;
  int32_T c7_i36;
  int32_T c7_i37;
  int32_T c7_i38;
  real_T (*c7_b_alpha_1)[3];
  real_T (*c7_b_eta_d)[3];
  real_T (*c7_b_eta_s)[3];
  real_T (*c7_b_nu_d)[3];
  real_T (*c7_b_z1)[3];
  real_T (*c7_b_Kp)[9];
  c7_b_eta_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c7_b_eta_s = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_nu_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_z1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_alpha_1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_Kp = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i8 = 0; c7_i8 < 9; c7_i8++) {
    c7_Kp[c7_i8] = (*c7_b_Kp)[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    c7_z1[c7_i9] = (*c7_b_z1)[c7_i9];
  }

  for (c7_i10 = 0; c7_i10 < 3; c7_i10++) {
    c7_nu_d[c7_i10] = (*c7_b_nu_d)[c7_i10];
  }

  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    c7_eta_s[c7_i11] = (*c7_b_eta_s)[c7_i11];
  }

  for (c7_i12 = 0; c7_i12 < 3; c7_i12++) {
    c7_eta_d[c7_i12] = (*c7_b_eta_d)[c7_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_psi_d, 0U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_psi_s, 1U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_cd, 2U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_sd, 3U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_Rd, 4U, c7_b_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_cs, 5U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_ss, 6U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_Rs, 7U, c7_b_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_Rst, 8U, c7_b_sf_marshallOut,
    c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 9U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 10U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_Kp, 11U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_z1, 12U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_nu_d, 13U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_eta_s, 14U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_eta_d, 15U, c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_alpha_1, 16U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 5);
  CV_EML_IF(0, 1, 0, TRUE);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 6);
  c7_psi_d = c7_eta_d[2];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 10);
  CV_EML_IF(0, 1, 1, TRUE);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 11);
  c7_psi_s = c7_eta_s[2];
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  c7_x = c7_psi_d;
  c7_cd = c7_x;
  c7_b_x = c7_cd;
  c7_cd = c7_b_x;
  c7_cd = muDoubleScalarCos(c7_cd);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 17);
  c7_c_x = c7_psi_d;
  c7_sd = c7_c_x;
  c7_d_x = c7_sd;
  c7_sd = c7_d_x;
  c7_sd = muDoubleScalarSin(c7_sd);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
  c7_Rd[0] = c7_cd;
  c7_Rd[3] = -c7_sd;
  c7_Rd[6] = 0.0;
  c7_Rd[1] = c7_sd;
  c7_Rd[4] = c7_cd;
  c7_Rd[7] = 0.0;
  c7_i13 = 0;
  for (c7_i14 = 0; c7_i14 < 3; c7_i14++) {
    c7_Rd[c7_i13 + 2] = c7_dv1[c7_i14];
    c7_i13 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
  c7_e_x = c7_psi_s;
  c7_cs = c7_e_x;
  c7_f_x = c7_cs;
  c7_cs = c7_f_x;
  c7_cs = muDoubleScalarCos(c7_cs);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 23);
  c7_g_x = c7_psi_s;
  c7_ss = c7_g_x;
  c7_h_x = c7_ss;
  c7_ss = c7_h_x;
  c7_ss = muDoubleScalarSin(c7_ss);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 24);
  c7_Rs[0] = c7_cs;
  c7_Rs[3] = -c7_ss;
  c7_Rs[6] = 0.0;
  c7_Rs[1] = c7_ss;
  c7_Rs[4] = c7_cs;
  c7_Rs[7] = 0.0;
  c7_i15 = 0;
  for (c7_i16 = 0; c7_i16 < 3; c7_i16++) {
    c7_Rs[c7_i15 + 2] = c7_dv1[c7_i16];
    c7_i15 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  c7_i17 = 0;
  for (c7_i18 = 0; c7_i18 < 3; c7_i18++) {
    c7_i19 = 0;
    for (c7_i20 = 0; c7_i20 < 3; c7_i20++) {
      c7_Rst[c7_i20 + c7_i17] = c7_Rs[c7_i19 + c7_i18];
      c7_i19 += 3;
    }

    c7_i17 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 29);
  for (c7_i21 = 0; c7_i21 < 9; c7_i21++) {
    c7_a[c7_i21] = -c7_Kp[c7_i21];
  }

  for (c7_i22 = 0; c7_i22 < 3; c7_i22++) {
    c7_b[c7_i22] = c7_z1[c7_i22];
  }

  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  for (c7_i23 = 0; c7_i23 < 3; c7_i23++) {
    c7_y[c7_i23] = 0.0;
    c7_i24 = 0;
    for (c7_i25 = 0; c7_i25 < 3; c7_i25++) {
      c7_y[c7_i23] += c7_a[c7_i24 + c7_i23] * c7_b[c7_i25];
      c7_i24 += 3;
    }
  }

  for (c7_i26 = 0; c7_i26 < 9; c7_i26++) {
    c7_a[c7_i26] = c7_Rst[c7_i26];
  }

  for (c7_i27 = 0; c7_i27 < 9; c7_i27++) {
    c7_b_b[c7_i27] = c7_Rd[c7_i27];
  }

  c7_b_eml_scalar_eg(chartInstance);
  c7_b_eml_scalar_eg(chartInstance);
  for (c7_i28 = 0; c7_i28 < 3; c7_i28++) {
    c7_i29 = 0;
    for (c7_i30 = 0; c7_i30 < 3; c7_i30++) {
      c7_b_y[c7_i29 + c7_i28] = 0.0;
      c7_i31 = 0;
      for (c7_i32 = 0; c7_i32 < 3; c7_i32++) {
        c7_b_y[c7_i29 + c7_i28] += c7_a[c7_i31 + c7_i28] * c7_b_b[c7_i32 +
          c7_i29];
        c7_i31 += 3;
      }

      c7_i29 += 3;
    }
  }

  for (c7_i33 = 0; c7_i33 < 3; c7_i33++) {
    c7_b[c7_i33] = c7_nu_d[c7_i33];
  }

  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  for (c7_i34 = 0; c7_i34 < 3; c7_i34++) {
    c7_c_y[c7_i34] = 0.0;
    c7_i35 = 0;
    for (c7_i36 = 0; c7_i36 < 3; c7_i36++) {
      c7_c_y[c7_i34] += c7_b_y[c7_i35 + c7_i34] * c7_b[c7_i36];
      c7_i35 += 3;
    }
  }

  for (c7_i37 = 0; c7_i37 < 3; c7_i37++) {
    c7_alpha_1[c7_i37] = c7_y[c7_i37] + c7_c_y[c7_i37];
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  for (c7_i38 = 0; c7_i38 < 3; c7_i38++) {
    (*c7_b_alpha_1)[c7_i38] = c7_alpha_1[c7_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_Model_justmodel(SFc7_Model_justmodelInstanceStruct *
  chartInstance)
{
}

static void registerMessagesc7_Model_justmodel
  (SFc7_Model_justmodelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i39;
  real_T c7_b_inData[3];
  int32_T c7_i40;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i39 = 0; c7_i39 < 3; c7_i39++) {
    c7_b_inData[c7_i39] = (*(real_T (*)[3])c7_inData)[c7_i39];
  }

  for (c7_i40 = 0; c7_i40 < 3; c7_i40++) {
    c7_u[c7_i40] = c7_b_inData[c7_i40];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_alpha_1, const char_T *c7_identifier, real_T
  c7_y[3])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_alpha_1), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_alpha_1);
}

static void c7_b_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[3])
{
  real_T c7_dv2[3];
  int32_T c7_i41;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv2, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i41 = 0; c7_i41 < 3; c7_i41++) {
    c7_y[c7_i41] = c7_dv2[c7_i41];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_alpha_1;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i42;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_alpha_1 = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_alpha_1), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_alpha_1);
  for (c7_i42 = 0; c7_i42 < 3; c7_i42++) {
    (*(real_T (*)[3])c7_outData)[c7_i42] = c7_y[c7_i42];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i43;
  int32_T c7_i44;
  int32_T c7_i45;
  real_T c7_b_inData[9];
  int32_T c7_i46;
  int32_T c7_i47;
  int32_T c7_i48;
  real_T c7_u[9];
  const mxArray *c7_y = NULL;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i43 = 0;
  for (c7_i44 = 0; c7_i44 < 3; c7_i44++) {
    for (c7_i45 = 0; c7_i45 < 3; c7_i45++) {
      c7_b_inData[c7_i45 + c7_i43] = (*(real_T (*)[9])c7_inData)[c7_i45 + c7_i43];
    }

    c7_i43 += 3;
  }

  c7_i46 = 0;
  for (c7_i47 = 0; c7_i47 < 3; c7_i47++) {
    for (c7_i48 = 0; c7_i48 < 3; c7_i48++) {
      c7_u[c7_i48 + c7_i46] = c7_b_inData[c7_i48 + c7_i46];
    }

    c7_i46 += 3;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static void c7_d_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[9])
{
  real_T c7_dv3[9];
  int32_T c7_i49;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv3, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c7_i49 = 0; c7_i49 < 9; c7_i49++) {
    c7_y[c7_i49] = c7_dv3[c7_i49];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Rst;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[9];
  int32_T c7_i50;
  int32_T c7_i51;
  int32_T c7_i52;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_Rst = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Rst), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_Rst);
  c7_i50 = 0;
  for (c7_i51 = 0; c7_i51 < 3; c7_i51++) {
    for (c7_i52 = 0; c7_i52 < 3; c7_i52++) {
      (*(real_T (*)[9])c7_outData)[c7_i52 + c7_i50] = c7_y[c7_i52 + c7_i50];
    }

    c7_i50 += 3;
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Model_justmodel_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[14];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i53;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c7_i53 = 0; c7_i53 < 14; c7_i53++) {
    c7_r0 = &c7_info[c7_i53];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i53);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i53);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[14])
{
  c7_info[0].context = "";
  c7_info[0].name = "length";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c7_info[0].fileTimeLo = 1303146206U;
  c7_info[0].fileTimeHi = 0U;
  c7_info[0].mFileTimeLo = 0U;
  c7_info[0].mFileTimeHi = 0U;
  c7_info[1].context = "";
  c7_info[1].name = "cos";
  c7_info[1].dominantType = "double";
  c7_info[1].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[1].fileTimeLo = 1343830372U;
  c7_info[1].fileTimeHi = 0U;
  c7_info[1].mFileTimeLo = 0U;
  c7_info[1].mFileTimeHi = 0U;
  c7_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[2].name = "eml_scalar_cos";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c7_info[2].fileTimeLo = 1286818722U;
  c7_info[2].fileTimeHi = 0U;
  c7_info[2].mFileTimeLo = 0U;
  c7_info[2].mFileTimeHi = 0U;
  c7_info[3].context = "";
  c7_info[3].name = "sin";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[3].fileTimeLo = 1343830386U;
  c7_info[3].fileTimeHi = 0U;
  c7_info[3].mFileTimeLo = 0U;
  c7_info[3].mFileTimeHi = 0U;
  c7_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[4].name = "eml_scalar_sin";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c7_info[4].fileTimeLo = 1286818736U;
  c7_info[4].fileTimeHi = 0U;
  c7_info[4].mFileTimeLo = 0U;
  c7_info[4].mFileTimeHi = 0U;
  c7_info[5].context = "";
  c7_info[5].name = "mtimes";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[5].fileTimeLo = 1289519692U;
  c7_info[5].fileTimeHi = 0U;
  c7_info[5].mFileTimeLo = 0U;
  c7_info[5].mFileTimeHi = 0U;
  c7_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[6].name = "eml_index_class";
  c7_info[6].dominantType = "";
  c7_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[6].fileTimeLo = 1323170578U;
  c7_info[6].fileTimeHi = 0U;
  c7_info[6].mFileTimeLo = 0U;
  c7_info[6].mFileTimeHi = 0U;
  c7_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[7].name = "eml_scalar_eg";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[7].fileTimeLo = 1286818796U;
  c7_info[7].fileTimeHi = 0U;
  c7_info[7].mFileTimeLo = 0U;
  c7_info[7].mFileTimeHi = 0U;
  c7_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[8].name = "eml_xgemm";
  c7_info[8].dominantType = "char";
  c7_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[8].fileTimeLo = 1299076772U;
  c7_info[8].fileTimeHi = 0U;
  c7_info[8].mFileTimeLo = 0U;
  c7_info[8].mFileTimeHi = 0U;
  c7_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c7_info[9].name = "eml_blas_inline";
  c7_info[9].dominantType = "";
  c7_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c7_info[9].fileTimeLo = 1299076768U;
  c7_info[9].fileTimeHi = 0U;
  c7_info[9].mFileTimeLo = 0U;
  c7_info[9].mFileTimeHi = 0U;
  c7_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c7_info[10].name = "mtimes";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[10].fileTimeLo = 1289519692U;
  c7_info[10].fileTimeHi = 0U;
  c7_info[10].mFileTimeLo = 0U;
  c7_info[10].mFileTimeHi = 0U;
  c7_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[11].name = "eml_index_class";
  c7_info[11].dominantType = "";
  c7_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[11].fileTimeLo = 1323170578U;
  c7_info[11].fileTimeHi = 0U;
  c7_info[11].mFileTimeLo = 0U;
  c7_info[11].mFileTimeHi = 0U;
  c7_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[12].name = "eml_scalar_eg";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[12].fileTimeLo = 1286818796U;
  c7_info[12].fileTimeHi = 0U;
  c7_info[12].mFileTimeLo = 0U;
  c7_info[12].mFileTimeHi = 0U;
  c7_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c7_info[13].name = "eml_refblas_xgemm";
  c7_info[13].dominantType = "char";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c7_info[13].fileTimeLo = 1299076774U;
  c7_info[13].fileTimeHi = 0U;
  c7_info[13].mFileTimeLo = 0U;
  c7_info[13].mFileTimeHi = 0U;
}

static void c7_eml_scalar_eg(SFc7_Model_justmodelInstanceStruct *chartInstance)
{
}

static void c7_b_eml_scalar_eg(SFc7_Model_justmodelInstanceStruct *chartInstance)
{
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_e_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i54;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i54, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i54;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Model_justmodel, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Model_justmodel), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Model_justmodel);
  return c7_y;
}

static uint8_T c7_g_emlrt_marshallIn(SFc7_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_Model_justmodelInstanceStruct
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

void sf_c7_Model_justmodel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3091581888U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1545513829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2278389821U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1468613333U);
}

mxArray *sf_c7_Model_justmodel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("s3Z21eWbdMKukxXIrWcsq");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_Model_justmodel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c7_Model_justmodel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"alpha_1\",},{M[8],M[0],T\"is_active_c7_Model_justmodel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Model_justmodel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Model_justmodelInstanceStruct *chartInstance;
    chartInstance = (SFc7_Model_justmodelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model_justmodelMachineNumber_,
           7,
           1,
           1,
           6,
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
          init_script_number_translation(_Model_justmodelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Model_justmodelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Model_justmodelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Kp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"alpha_1");
          _SFD_SET_DATA_PROPS(2,1,1,0,"z1");
          _SFD_SET_DATA_PROPS(3,1,1,0,"nu_d");
          _SFD_SET_DATA_PROPS(4,1,1,0,"eta_s");
          _SFD_SET_DATA_PROPS(5,1,1,0,"eta_d");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,414);
        _SFD_CV_INIT_EML_IF(0,1,0,63,83,106,129);
        _SFD_CV_INIT_EML_IF(0,1,1,130,150,173,196);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c7_Kp)[9];
          real_T (*c7_alpha_1)[3];
          real_T (*c7_z1)[3];
          real_T (*c7_nu_d)[3];
          real_T (*c7_eta_s)[3];
          real_T (*c7_eta_d)[3];
          c7_eta_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c7_eta_s = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c7_nu_d = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c7_z1 = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c7_alpha_1 = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_Kp = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_Kp);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_alpha_1);
          _SFD_SET_DATA_VALUE_PTR(2U, *c7_z1);
          _SFD_SET_DATA_VALUE_PTR(3U, *c7_nu_d);
          _SFD_SET_DATA_VALUE_PTR(4U, *c7_eta_s);
          _SFD_SET_DATA_VALUE_PTR(5U, *c7_eta_d);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Model_justmodelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "wLIU1FNcGVbOKxcd4UcwXB";
}

static void sf_opaque_initialize_c7_Model_justmodel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar);
  initialize_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_Model_justmodel(void *chartInstanceVar)
{
  enable_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_Model_justmodel(void *chartInstanceVar)
{
  disable_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_Model_justmodel(void *chartInstanceVar)
{
  sf_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_Model_justmodel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_Model_justmodel
    ((SFc7_Model_justmodelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Model_justmodel();/* state var info */
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

extern void sf_internal_set_sim_state_c7_Model_justmodel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_Model_justmodel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_Model_justmodel(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_Model_justmodel(S);
}

static void sf_opaque_set_sim_state_c7_Model_justmodel(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_Model_justmodel(S, st);
}

static void sf_opaque_terminate_c7_Model_justmodel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Model_justmodelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model_justmodel_optimization_info();
    }

    finalize_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Model_justmodel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Model_justmodel((SFc7_Model_justmodelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_Model_justmodel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Model_justmodel_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1015268603U));
  ssSetChecksum1(S,(3253929054U));
  ssSetChecksum2(S,(1933022004U));
  ssSetChecksum3(S,(974226328U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Model_justmodel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Model_justmodel(SimStruct *S)
{
  SFc7_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc7_Model_justmodelInstanceStruct *)utMalloc(sizeof
    (SFc7_Model_justmodelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_Model_justmodelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Model_justmodel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_Model_justmodel;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_Model_justmodel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_Model_justmodel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_Model_justmodel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Model_justmodel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Model_justmodel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Model_justmodel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Model_justmodel;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Model_justmodel;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Model_justmodel;
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

void c7_Model_justmodel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Model_justmodel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Model_justmodel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Model_justmodel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Model_justmodel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}