/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Model_justmodel_sfun.h"
#include "c4_Model_justmodel.h"
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
static const char * c4_debug_family_names[18] = { "theSize", "u", "psi", "uMax",
  "vMax", "psiMax", "xVel", "yVel", "r", "surge", "sway", "yaw", "nargin",
  "nargout", "in", "velMax", "eta_ship", "y" };

/* Function Declarations */
static void initialize_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance);
static void initialize_params_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance);
static void enable_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance);
static void disable_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance);
static void set_sim_state_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct *
  chartInstance, const mxArray *c4_st);
static void finalize_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance);
static void sf_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance);
static void initSimStructsc4_Model_justmodel(SFc4_Model_justmodelInstanceStruct *
  chartInstance);
static void registerMessagesc4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_y, const char_T *c4_identifier, real_T
  c4_b_y[3]);
static void c4_b_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Model_justmodel, const char_T
  *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Model_justmodelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Model_justmodel = 0U;
}

static void initialize_params_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance)
{
}

static void enable_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[3];
  const mxArray *c4_b_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T (*c4_d_y)[3];
  c4_d_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  for (c4_i0 = 0; c4_i0 < 3; c4_i0++) {
    c4_u[c4_i0] = (*c4_d_y)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_Model_justmodel;
  c4_b_u = c4_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct *
  chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[3];
  int32_T c4_i1;
  real_T (*c4_y)[3];
  c4_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "y",
                      c4_dv0);
  for (c4_i1 = 0; c4_i1 < 3; c4_i1++) {
    (*c4_y)[c4_i1] = c4_dv0[c4_i1];
  }

  chartInstance->c4_is_active_c4_Model_justmodel = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_Model_justmodel");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Model_justmodel(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance)
{
}

static void sf_c4_Model_justmodel(SFc4_Model_justmodelInstanceStruct
  *chartInstance)
{
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  real_T c4_in[3];
  int32_T c4_i7;
  real_T c4_velMax[3];
  int32_T c4_i8;
  real_T c4_eta_ship[3];
  uint32_T c4_debug_family_var_map[18];
  real_T c4_theSize;
  real_T c4_u[3];
  real_T c4_psi;
  real_T c4_uMax;
  real_T c4_vMax;
  real_T c4_psiMax;
  real_T c4_xVel;
  real_T c4_yVel;
  real_T c4_r;
  real_T c4_surge;
  real_T c4_sway;
  real_T c4_yaw;
  real_T c4_nargin = 3.0;
  real_T c4_nargout = 1.0;
  real_T c4_y[3];
  int32_T c4_i9;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_a;
  real_T c4_b;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_y;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_d_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_e_y;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_f_y;
  real_T c4_k_x;
  real_T c4_l_x;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T c4_m_x;
  real_T c4_n_x;
  real_T c4_g_y;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_f_a;
  real_T c4_f_b;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_h_y;
  real_T c4_s_x;
  real_T c4_t_x;
  real_T c4_g_a;
  real_T c4_g_b;
  int32_T c4_i10;
  real_T c4_u_x;
  real_T c4_v_x;
  real_T c4_h_a;
  real_T c4_h_b;
  real_T c4_i_y;
  real_T c4_w_x;
  real_T c4_x_x;
  real_T c4_i_a;
  real_T c4_i_b;
  real_T c4_j_y;
  real_T c4_y_x;
  real_T c4_ab_x;
  real_T c4_j_a;
  real_T c4_j_b;
  real_T c4_k_y;
  real_T c4_bb_x;
  real_T c4_cb_x;
  real_T c4_k_a;
  real_T c4_k_b;
  real_T c4_l_y;
  int32_T c4_i11;
  real_T (*c4_m_y)[3];
  real_T (*c4_b_eta_ship)[3];
  real_T (*c4_b_velMax)[3];
  real_T (*c4_b_in)[3];
  c4_b_eta_ship = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
  c4_m_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_velMax = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_in)[c4_i2], 0U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_velMax)[c4_i3], 1U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_m_y)[c4_i4], 2U);
  }

  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    _SFD_DATA_RANGE_CHECK((*c4_b_eta_ship)[c4_i5], 3U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_in[c4_i6] = (*c4_b_in)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    c4_velMax[c4_i7] = (*c4_b_velMax)[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    c4_eta_ship[c4_i8] = (*c4_b_eta_ship)[c4_i8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_theSize, 0U, c4_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_u, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_psi, 2U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_uMax, 3U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_vMax, 4U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_psiMax, 5U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_xVel, 6U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_yVel, 7U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_r, 8U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_surge, 9U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sway, 10U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_yaw, 11U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 12U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 13U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_in, 14U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_velMax, 15U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_eta_ship, 16U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_y, 17U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_theSize = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  CV_EML_IF(0, 1, 0, c4_theSize < 3.0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_u[c4_i9] = c4_in[c4_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_psi = c4_eta_ship[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_uMax = c4_velMax[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_vMax = c4_velMax[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
  c4_psiMax = c4_velMax[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
  c4_xVel = c4_u[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
  c4_yVel = c4_u[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
  c4_r = c4_u[2];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
  c4_x = c4_psi;
  c4_b_x = c4_x;
  c4_b_x = muDoubleScalarCos(c4_b_x);
  c4_a = c4_xVel;
  c4_b = c4_b_x;
  c4_b_y = c4_a * c4_b;
  c4_c_x = c4_psi;
  c4_d_x = c4_c_x;
  c4_d_x = muDoubleScalarSin(c4_d_x);
  c4_b_a = c4_yVel;
  c4_b_b = c4_d_x;
  c4_c_y = c4_b_a * c4_b_b;
  c4_surge = c4_b_y + c4_c_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
  c4_e_x = c4_psi;
  c4_f_x = c4_e_x;
  c4_f_x = muDoubleScalarSin(c4_f_x);
  c4_c_a = -c4_xVel;
  c4_c_b = c4_f_x;
  c4_d_y = c4_c_a * c4_c_b;
  c4_g_x = c4_psi;
  c4_h_x = c4_g_x;
  c4_h_x = muDoubleScalarCos(c4_h_x);
  c4_d_a = c4_yVel;
  c4_d_b = c4_h_x;
  c4_e_y = c4_d_a * c4_d_b;
  c4_sway = c4_d_y + c4_e_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
  c4_yaw = c4_r;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 25);
  c4_i_x = c4_surge;
  c4_j_x = c4_i_x;
  c4_f_y = muDoubleScalarAbs(c4_j_x);
  if (CV_EML_IF(0, 1, 1, c4_f_y > c4_uMax)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
    c4_k_x = c4_surge;
    c4_l_x = c4_k_x;
    c4_l_x = muDoubleScalarSign(c4_l_x);
    c4_e_a = c4_l_x;
    c4_e_b = c4_uMax;
    c4_surge = c4_e_a * c4_e_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
  c4_m_x = c4_sway;
  c4_n_x = c4_m_x;
  c4_g_y = muDoubleScalarAbs(c4_n_x);
  if (CV_EML_IF(0, 1, 2, c4_g_y > c4_vMax)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
    c4_o_x = c4_sway;
    c4_p_x = c4_o_x;
    c4_p_x = muDoubleScalarSign(c4_p_x);
    c4_f_a = c4_p_x;
    c4_f_b = c4_vMax;
    c4_sway = c4_f_a * c4_f_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 31);
  c4_q_x = c4_yaw;
  c4_r_x = c4_q_x;
  c4_h_y = muDoubleScalarAbs(c4_r_x);
  if (CV_EML_IF(0, 1, 3, c4_h_y > c4_psiMax)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
    c4_s_x = c4_yaw;
    c4_t_x = c4_s_x;
    c4_t_x = muDoubleScalarSign(c4_t_x);
    c4_g_a = c4_t_x;
    c4_g_b = c4_psiMax;
    c4_yaw = c4_g_a * c4_g_b;
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
  for (c4_i10 = 0; c4_i10 < 3; c4_i10++) {
    c4_y[c4_i10] = c4_u[c4_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
  c4_u_x = c4_psi;
  c4_v_x = c4_u_x;
  c4_v_x = muDoubleScalarCos(c4_v_x);
  c4_h_a = c4_v_x;
  c4_h_b = c4_surge;
  c4_i_y = c4_h_a * c4_h_b;
  c4_w_x = c4_psi;
  c4_x_x = c4_w_x;
  c4_x_x = muDoubleScalarSin(c4_x_x);
  c4_i_a = c4_x_x;
  c4_i_b = c4_sway;
  c4_j_y = c4_i_a * c4_i_b;
  c4_y[0] = c4_i_y - c4_j_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
  c4_y_x = c4_psi;
  c4_ab_x = c4_y_x;
  c4_ab_x = muDoubleScalarSin(c4_ab_x);
  c4_j_a = c4_ab_x;
  c4_j_b = c4_surge;
  c4_k_y = c4_j_a * c4_j_b;
  c4_bb_x = c4_psi;
  c4_cb_x = c4_bb_x;
  c4_cb_x = muDoubleScalarCos(c4_cb_x);
  c4_k_a = c4_cb_x;
  c4_k_b = c4_sway;
  c4_l_y = c4_k_a * c4_k_b;
  c4_y[1] = c4_k_y + c4_l_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
  c4_y[2] = c4_yaw;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i11 = 0; c4_i11 < 3; c4_i11++) {
    (*c4_m_y)[c4_i11] = c4_y[c4_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Model_justmodelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_Model_justmodel(SFc4_Model_justmodelInstanceStruct *
  chartInstance)
{
}

static void registerMessagesc4_Model_justmodel
  (SFc4_Model_justmodelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  real_T c4_b_inData[3];
  int32_T c4_i13;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_b_inData[c4_i12] = (*(real_T (*)[3])c4_inData)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_u[c4_i13] = c4_b_inData[c4_i13];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_y, const char_T *c4_identifier, real_T
  c4_b_y[3])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
}

static void c4_b_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[3])
{
  real_T c4_dv1[3];
  int32_T c4_i14;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c4_i14 = 0; c4_i14 < 3; c4_i14++) {
    c4_y[c4_i14] = c4_dv1[c4_i14];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_y;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_b_y[3];
  int32_T c4_i15;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_y = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_y), &c4_thisId, c4_b_y);
  sf_mex_destroy(&c4_y);
  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    (*(real_T (*)[3])c4_outData)[c4_i15] = c4_b_y[c4_i15];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i16;
  real_T c4_b_inData[3];
  int32_T c4_i17;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_b_inData[c4_i16] = (*(real_T (*)[3])c4_inData)[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 3; c4_i17++) {
    c4_u[c4_i17] = c4_b_inData[c4_i17];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Model_justmodel_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[10];
  c4_ResolvedFunctionInfo (*c4_b_info)[10];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i18;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[10])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "length";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c4_b_info)[0].fileTimeLo = 1303146206U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "cos";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[1].fileTimeLo = 1343830372U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c4_b_info)[2].name = "eml_scalar_cos";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c4_b_info)[2].fileTimeLo = 1286818722U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context = "";
  (*c4_b_info)[3].name = "mtimes";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[3].fileTimeLo = 1289519692U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "sin";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[4].fileTimeLo = 1343830386U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c4_b_info)[5].name = "eml_scalar_sin";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c4_b_info)[5].fileTimeLo = 1286818736U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 0U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context = "";
  (*c4_b_info)[6].name = "abs";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c4_b_info)[6].fileTimeLo = 1343830366U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  (*c4_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c4_b_info)[7].name = "eml_scalar_abs";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c4_b_info)[7].fileTimeLo = 1286818712U;
  (*c4_b_info)[7].fileTimeHi = 0U;
  (*c4_b_info)[7].mFileTimeLo = 0U;
  (*c4_b_info)[7].mFileTimeHi = 0U;
  (*c4_b_info)[8].context = "";
  (*c4_b_info)[8].name = "sign";
  (*c4_b_info)[8].dominantType = "double";
  (*c4_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  (*c4_b_info)[8].fileTimeLo = 1354368064U;
  (*c4_b_info)[8].fileTimeHi = 0U;
  (*c4_b_info)[8].mFileTimeLo = 0U;
  (*c4_b_info)[8].mFileTimeHi = 0U;
  (*c4_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m";
  (*c4_b_info)[9].name = "eml_scalar_sign";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  (*c4_b_info)[9].fileTimeLo = 1354368064U;
  (*c4_b_info)[9].fileTimeHi = 0U;
  (*c4_b_info)[9].mFileTimeLo = 0U;
  (*c4_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c4_i18 = 0; c4_i18 < 10; c4_i18++) {
    c4_r0 = &c4_info[c4_i18];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i18);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i18);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i19;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i19, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i19;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Model_justmodel, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Model_justmodel), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Model_justmodel);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_Model_justmodelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_Model_justmodelInstanceStruct
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

void sf_c4_Model_justmodel_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(595520732U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1332140903U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(143591051U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2174478615U);
}

mxArray *sf_c4_Model_justmodel_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ASu1O1s8cmc6pjtKKrL18F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

mxArray *sf_c4_Model_justmodel_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_Model_justmodel(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c4_Model_justmodel\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Model_justmodel_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Model_justmodelInstanceStruct *chartInstance;
    chartInstance = (SFc4_Model_justmodelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Model_justmodelMachineNumber_,
           4,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"in");
          _SFD_SET_DATA_PROPS(1,1,1,0,"velMax");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"eta_ship");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,614);
        _SFD_CV_INIT_EML_IF(0,1,0,90,104,125,145);
        _SFD_CV_INIT_EML_IF(0,1,1,357,377,-1,411);
        _SFD_CV_INIT_EML_IF(0,1,2,412,431,-1,463);
        _SFD_CV_INIT_EML_IF(0,1,3,464,484,-1,516);
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
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c4_in)[3];
          real_T (*c4_velMax)[3];
          real_T (*c4_y)[3];
          real_T (*c4_eta_ship)[3];
          c4_eta_ship = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 2);
          c4_y = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c4_velMax = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c4_in = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c4_in);
          _SFD_SET_DATA_VALUE_PTR(1U, *c4_velMax);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_y);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_eta_ship);
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
  return "8FMnQhU6Uzl3cGuIyQtDkH";
}

static void sf_opaque_initialize_c4_Model_justmodel(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar);
  initialize_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_Model_justmodel(void *chartInstanceVar)
{
  enable_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_Model_justmodel(void *chartInstanceVar)
{
  disable_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_Model_justmodel(void *chartInstanceVar)
{
  sf_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Model_justmodel(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Model_justmodel
    ((SFc4_Model_justmodelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Model_justmodel();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Model_justmodel(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Model_justmodel();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Model_justmodel(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_Model_justmodel(S);
}

static void sf_opaque_set_sim_state_c4_Model_justmodel(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_Model_justmodel(S, st);
}

static void sf_opaque_terminate_c4_Model_justmodel(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Model_justmodelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Model_justmodel_optimization_info();
    }

    finalize_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Model_justmodel(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Model_justmodel((SFc4_Model_justmodelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Model_justmodel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Model_justmodel_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3317654908U));
  ssSetChecksum1(S,(1802814276U));
  ssSetChecksum2(S,(3371498805U));
  ssSetChecksum3(S,(1726282385U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Model_justmodel(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Model_justmodel(SimStruct *S)
{
  SFc4_Model_justmodelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Model_justmodelInstanceStruct *)utMalloc(sizeof
    (SFc4_Model_justmodelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Model_justmodelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Model_justmodel;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Model_justmodel;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Model_justmodel;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_Model_justmodel;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_Model_justmodel;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Model_justmodel;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Model_justmodel;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Model_justmodel;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Model_justmodel;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Model_justmodel;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Model_justmodel;
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

void c4_Model_justmodel_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Model_justmodel(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Model_justmodel(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Model_justmodel(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Model_justmodel_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
