
// ----------------------------------------------------------------------------
// Type conversion functions between Algorithmic datatypes and Matlab/Simulink
// ----------------------------------------------------------------------------

#ifndef __INCLUDED_MATLAB_TYPECONV_H__
#define __INCLUDED_MATLAB_TYPECONV_H__

#include <ac_complex.h>

// ----------------------------------------------------------------------------
// Required header for Matlab Simulink data structures
#include "simstruc.h"
#include "fixedpoint.h"

// Type conversion functions (specialized for ac_int and ac_fixed)
#if defined(__AC_INT_H)
template<int Twidth, bool Tsigned>
void simtype_to_origtype(SimStruct *S, int loc, const void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, ac_int<Twidth,Tsigned> &target, bool is_fxp)
{
   switch(dt) {
      case SS_BOOLEAN: {
         if (Tsigned) ssSetErrorStatus(S,"Assignment of SS_BOOLEAN to signed AC datatype");
         const boolean_T *typed_p = static_cast<const boolean_T *>(untyped_vp);
         target = typed_p[loc];
         break;
      }
      default: {
         switch(sc) {
            case FXP_STORAGE_UINT8: {
               // AC datatype width must be atleast 8 bits and be unsigned
               const uint8_T *typed_p = static_cast<const uint8_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT8: {
               // AC datatype width must be atleast 8 bits and be unsigned
               const int8_T *typed_p = static_cast<const int8_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UINT16: {
               // AC datatype width must be atleast 16 bits and be unsigned
               const uint16_T *typed_p = static_cast<const uint16_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT16: {
               // AC datatype width must be atleast 16 bits and be unsigned
               const int16_T *typed_p = static_cast<const int16_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UINT32: {
               // AC datatype width must be atleast 32 bits and be unsigned
               const uint32_T *typed_p = static_cast<const uint32_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT32: {
               // AC datatype width must be atleast 32 bits and be unsigned
               const int32_T *typed_p = static_cast<const int32_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UNKNOWN: {
               ssSetErrorStatus(S,"FXP_STORAGE_UNKNOWN not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_DOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_DOUBLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_SINGLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SINGLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_CHUNKARRAY: {
               ssSetErrorStatus(S,"FXP_STORAGE_CHUNKARRAY not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_SCALEDDOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SCALEDDOUBLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_OTHER_SINGLE_WORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_OTHER_SINGLE_WORD not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_MULTIWORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_MULTIWORD not supported in simtype_to_origtype");
               break;
            }
            default: {
               ssSetErrorStatus(S,"Unimplemented case in simtype_to_origtype");
               break;
            }
         }
         break;
      }
   }
}

template<int Twidth, bool Tsigned>
void origtype_to_simtype(SimStruct *S, int loc, void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, const ac_int<Twidth,Tsigned> &src, bool is_fxp)
{
   switch(dt) {
      case SS_BOOLEAN: {
         boolean_T *typed_p = static_cast<boolean_T*>(untyped_vp);
         typed_p[loc] = src.to_int();
         break;
      }
      default: {
         switch(sc) {
            case FXP_STORAGE_UINT8: {
               uint8_T *typed_p = static_cast<uint8_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_INT8: {
               int8_T *typed_p = static_cast<int8_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_UINT16: {
               uint16_T *typed_p = static_cast<uint16_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_INT16: {
               int16_T *typed_p = static_cast<int16_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_UINT32: {
               uint32_T *typed_p = static_cast<uint32_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_INT32: {
               int32_T *typed_p = static_cast<int32_T*>(untyped_vp);
               typed_p[loc] = src.to_int();
               break;
            }
            case FXP_STORAGE_UNKNOWN: {
               ssSetErrorStatus(S,"FXP_STORAGE_UNKNOWN not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_DOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_DOUBLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_SINGLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SINGLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_CHUNKARRAY: {
               ssSetErrorStatus(S,"FXP_STORAGE_CHUNKARRAY not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_SCALEDDOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SCALEDDOUBLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_OTHER_SINGLE_WORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_OTHER_SINGLE_WORD not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_MULTIWORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_MULTIWORD not supported in origtype_to_simtype");
               break;
            }
            default: {
               ssSetErrorStatus(S,"Unimplemented default case in origtype_to_simtype");
               break;
            }
         }
      }
   }
}
#endif

#if defined(__AC_FIXED_H)
template<int Twidth, int Ibits, bool Signed, ac_q_mode Qmode, ac_o_mode Omode>
void simtype_to_origtype(SimStruct *S, int loc, const void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, ac_fixed<Twidth,Ibits,Signed,Qmode,Omode> &target, bool is_fxp)
{
   if (ssGetDataTypeFxpWordLength(S,dt) != Twidth) {
      ssSetErrorStatus(S,"Assignment of fixed point value to ac_fixed of different word length");
      return;
   }
   if (ssGetDataTypeFractionLength(S,dt) != Twidth-Ibits) {
      ssSetErrorStatus(S,"Assignment of fixed point value to ac_fixed of different fraction length");
      return;
   }
   if (( (bool)ssGetDataTypeFxpIsSigned(S,dt) ) != Signed ) {
      ssSetErrorStatus(S,"Assignment of fixed point value to ac_fixed with different sign bits");
      return;
   }
   ac_int<Twidth,Signed> temp;
   simtype_to_origtype(S,loc,untyped_vp,dt,sc,temp,true);
   target.set_slc(0,temp);
}

template<int Twidth, int Ibits, bool Signed, ac_q_mode Qmode, ac_o_mode Omode>
void origtype_to_simtype(SimStruct *S, int loc, void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, const ac_fixed<Twidth,Ibits,Signed,Qmode,Omode> &src, bool is_fxp)
{
   if (ssGetDataTypeFxpWordLength(S,dt) != Twidth) {
      ssSetErrorStatus(S,"Assignment of ac_fixed to a fixed point value of different word length");
      return;
   }
   if (ssGetDataTypeFractionLength(S,dt) != Twidth-Ibits) {
      ssSetErrorStatus(S,"Assignment of ac_fixed to a fixed point value of different fraction length");
      return;
   }
   if (( (bool)ssGetDataTypeFxpIsSigned(S,dt) ) != Signed ) {
      ssSetErrorStatus(S,"Assignment of ac_fixed to a fixed point value with different sign bits");
      return;
   }
   ac_int<Twidth,Signed> temp = src.template slc<Twidth>(0);
   origtype_to_simtype(S,loc,untyped_vp,dt,sc,temp,true);
}
#endif

// Catch-all conversion
template <class Tclass>
void simtype_to_origtype(SimStruct *S, int loc, const void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, Tclass &target, bool is_fxp)
{
   switch(dt) {
      case SS_BOOLEAN: {
         const boolean_T *typed_p = static_cast<const boolean_T *>(untyped_vp);
         target = typed_p[loc];
         break;
      }
      default: {
         switch(sc) {
            case FXP_STORAGE_UINT8: {
               // AC datatype width must be atleast 8 bits and be unsigned
               const uint8_T *typed_p = static_cast<const uint8_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT8: {
               // AC datatype width must be atleast 8 bits and be unsigned
               const int8_T *typed_p = static_cast<const int8_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UINT16: {
               // AC datatype width must be atleast 16 bits and be unsigned
               const uint16_T *typed_p = static_cast<const uint16_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT16: {
               // AC datatype width must be atleast 16 bits and be unsigned
               const int16_T *typed_p = static_cast<const int16_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UINT32: {
               // AC datatype width must be atleast 32 bits and be unsigned
               const uint32_T *typed_p = static_cast<const uint32_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_INT32: {
               // AC datatype width must be atleast 32 bits and be unsigned
               const int32_T *typed_p = static_cast<const int32_T*>(untyped_vp);
               target = typed_p[loc];
               break;
            }
            case FXP_STORAGE_UNKNOWN: {
               ssSetErrorStatus(S,"FXP_STORAGE_UNKNOWN not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_DOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_DOUBLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_SINGLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SINGLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_CHUNKARRAY: {
               ssSetErrorStatus(S,"FXP_STORAGE_CHUNKARRAY not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_SCALEDDOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SCALEDDOUBLE not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_OTHER_SINGLE_WORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_OTHER_SINGLE_WORD not supported in simtype_to_origtype");
               break;
            }
            case FXP_STORAGE_MULTIWORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_MULTIWORD not supported in simtype_to_origtype");
               break;
            }
            default: {
               ssSetErrorStatus(S,"Unimplemented case in simtype_to_origtype");
               break;
            }
         }
         break;
      }
   }

}

template <class Tclass>
void origtype_to_simtype(SimStruct *S, int loc, void *untyped_vp, const DTypeId dt, const fxpStorageContainerCategory sc, const Tclass &src, bool is_fxp)
{
   switch(dt) {
      case SS_BOOLEAN: {
         boolean_T *typed_p = static_cast<boolean_T*>(untyped_vp);
         typed_p[loc] = src;
         break;
      }
      default: {
         switch(sc) {
            case FXP_STORAGE_UINT8: {
               uint8_T *typed_p = static_cast<uint8_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_INT8: {
               int8_T *typed_p = static_cast<int8_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_UINT16: {
               uint16_T *typed_p = static_cast<uint16_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_INT16: {
               int16_T *typed_p = static_cast<int16_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_UINT32: {
               uint32_T *typed_p = static_cast<uint32_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_INT32: {
               int32_T *typed_p = static_cast<int32_T*>(untyped_vp);
               typed_p[loc] = src;
               break;
            }
            case FXP_STORAGE_UNKNOWN: {
               ssSetErrorStatus(S,"FXP_STORAGE_UNKNOWN not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_DOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_DOUBLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_SINGLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SINGLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_CHUNKARRAY: {
               ssSetErrorStatus(S,"FXP_STORAGE_CHUNKARRAY not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_SCALEDDOUBLE: {
               ssSetErrorStatus(S,"FXP_STORAGE_SCALEDDOUBLE not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_OTHER_SINGLE_WORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_OTHER_SINGLE_WORD not supported in origtype_to_simtype");
               break;
            }
            case FXP_STORAGE_MULTIWORD: {
               ssSetErrorStatus(S,"FXP_STORAGE_MULTIWORD not supported in origtype_to_simtype");
               break;
            }
            default: {
               ssSetErrorStatus(S,"Unimplemented default case in origtype_to_simtype");
               break;
            }
         }
      }
   }
}

template<class Tclass>
void convert_input(
   SimStruct *S,
   int loc,
   int PortIdx,
   Tclass &target)
{
   // Create untyped void ptr to input data port
   const void *untyped_vp = ssGetInputPortSignal  (S, PortIdx);
   // get input data port type
   DTypeId input_dt = ssGetInputPortDataType  (S, PortIdx);
   // get input data storage category
   fxpStorageContainerCategory input_sc = ssGetDataTypeStorageContainCat (S, input_dt);
   // now copy data
   simtype_to_origtype(S,loc,untyped_vp, input_dt, input_sc, target, false);
}

template<typename Ttype>
void convert_input(
   SimStruct *S,
   int loc,
   int PortIdx,
   ac_complex<Ttype> &target)
{
   // Verify that port is COMPLEX
   if (ssGetInputPortComplexSignal(S,PortIdx) != COMPLEX_YES) {
      ssPrintf("Input port %d was not marked COMPLEX_YES\n", PortIdx);
      return;
   }
   const void *untyped_vp = ssGetInputPortSignal  (S, PortIdx);
   // get input data port type
   DTypeId input_dt = ssGetInputPortDataType  (S, PortIdx);
   // get input data storage category
   fxpStorageContainerCategory input_sc = ssGetDataTypeStorageContainCat (S, input_dt);

   // now copy REAL data
   Ttype tmp_real;
   simtype_to_origtype(S,loc,untyped_vp, input_dt, input_sc, tmp_real, false);
   target.set_r(tmp_real);
   // now copy IMAG data
   Ttype tmp_imag;
   simtype_to_origtype(S,loc+1,untyped_vp, input_dt, input_sc, tmp_imag, false);
   target.set_i(tmp_imag);
}

template<class Tclass>
void convert_output(
   SimStruct *S,
   int loc,
   int PortIdx,
   Tclass &target)
{
   // Create untyped void ptr to output data port
   void *untyped_vp = ssGetOutputPortSignal  (S, PortIdx);
   // get output data port type
   DTypeId output_dt = ssGetOutputPortDataType  (S, PortIdx);
   // get output data storage category
   fxpStorageContainerCategory output_sc = ssGetDataTypeStorageContainCat (S, output_dt);
   // now copy data
   origtype_to_simtype(S,loc,untyped_vp, output_dt, output_sc, target, false);
}

template<typename Ttype>
void convert_output(
   SimStruct *S,
   int loc,
   int PortIdx,
   ac_complex<Ttype> &target)
{
   // Verify that port is COMPLEX
   if (ssGetOutputPortComplexSignal(S,PortIdx) != COMPLEX_YES) {
      ssPrintf("Output port %d was not marked COMPLEX_YES\n", PortIdx);
      return;
   }
   // Create untyped void ptr to output data port
   void *untyped_vp = ssGetOutputPortSignal  (S, PortIdx);
   // get output data port type
   DTypeId output_dt = ssGetOutputPortDataType  (S, PortIdx);
   // get output data storage category
   fxpStorageContainerCategory output_sc = ssGetDataTypeStorageContainCat (S, output_dt);

   // now copy REAL data
   Ttype tmp_real = target.r();
   origtype_to_simtype(S,loc,untyped_vp, output_dt, output_sc, tmp_real, false);
   // now copy IMAG data
   Ttype tmp_imag = target.i();
   origtype_to_simtype(S,loc+1,untyped_vp, output_dt, output_sc, tmp_imag, false);
}

#endif

