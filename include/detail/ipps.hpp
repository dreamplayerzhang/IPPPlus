/**
 * @file ipps.hpp
 * @Brief 
 * @author Red Li
 * @version 
 * @date 2014-12-26
 */


#ifndef IPPPLUS_DETAIL_IPPS_HPP
#define IPPPLUS_DETAIL_IPPS_HPP


namespace ipp{
namespace detail{

//
template<typename T, int Tid, size_t Size>
struct copy;


template<typename T>
struct copy<T, TYPE_CAT_INT, 1>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_8u((const Ipp8u*)src, (Ipp8u*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_INT, 2>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_16s((const Ipp16s*)src, (Ipp16s*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_INT, 4>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_32s((const Ipp32s*)src, (Ipp32s*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_INT, 8>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_64s((const Ipp64s*)src, (Ipp64s*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_FLOAT, 4>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_32f((const Ipp32f*)src, (Ipp32f*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_FLOAT, 8>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_64f((const Ipp64f*)src, (Ipp64f*)dst, len);
    };
};


template<typename T>
struct copy<T, TYPE_CAT_COMPLEX, 8>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_32fc((const Ipp32fc*)src, (Ipp32fc*)dst, len);
    };
};

template<typename T>
struct copy<T, TYPE_CAT_COMPLEX, 16>
{
    static inline IppStatus do_copy(const T* src, T *dst, int len)
    {
        return ippsCopy_64fc((const Ipp64fc*)src, (Ipp64fc*)dst, len);
    };
};


template<typename T, int Tid, size_t Size>
struct move;


template<typename T>
struct move<T, TYPE_CAT_INT, 1>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_8u((const Ipp8u*)src, (Ipp8u*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_INT, 2>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_16s((const Ipp16s*)src, (Ipp16s*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_INT, 4>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_32s((const Ipp32s*)src, (Ipp32s*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_INT, 8>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_64s((const Ipp64s*)src, (Ipp64s*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_FLOAT, 4>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_32f((const Ipp32f*)src, (Ipp32f*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_FLOAT, 8>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_64f((const Ipp64f*)src, (Ipp64f*)dst, len);
    };
};


template<typename T>
struct move<T, TYPE_CAT_COMPLEX, 8>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_32fc((const Ipp32fc*)src, (Ipp32fc*)dst, len);
    };
};

template<typename T>
struct move<T, TYPE_CAT_COMPLEX, 16>
{
    static inline IppStatus do_move(const T* src, T *dst, int len)
    {
        return ippsMove_64fc((const Ipp64fc*)src, (Ipp64fc*)dst, len);
    };
};


//set
template<typename IT>
struct set;

#define SET_ASM(Suffix)\
template<>\
struct set<Ipp##Suffix>\
{\
    typedef Ipp##Suffix itype;\
    static inline IppStatus do_set(itype val, itype *dst, int len)\
    {\
        return ippsSet_##Suffix(val, dst, len);\
    }\
}

template<>
struct set<Ipp8s>
{
    typedef Ipp8s itype;
    static inline IppStatus do_set(itype val, itype *dst, int len)
    {
        return ippsSet_8u(*(Ipp8u*)&val, (Ipp8u*)dst, len);
    }
};

template<>
struct set<Ipp16u>
{
    typedef Ipp16u itype;
    static inline IppStatus do_set(itype val, itype *dst, int len)
    {
        return ippsSet_16s(*(Ipp16s*)&val, (Ipp16s*)dst, len);
    }
};

template<>
struct set<Ipp32u>
{
    typedef Ipp32u itype;
    static inline IppStatus do_set(itype val, itype *dst, int len)
    {
        return ippsSet_32s(*(Ipp32s*)&val, (Ipp32s*)dst, len);
    }
};

template<>
struct set<Ipp64u>
{
    typedef Ipp64u itype;
    static inline IppStatus do_set(itype val, itype *dst, int len)
    {
        return ippsSet_64s(*(Ipp64s*)&val, (Ipp64s*)dst, len);
    }
};

SET_ASM(8u);
SET_ASM(16s);
SET_ASM(32s);
SET_ASM(64s);
SET_ASM(32f);
SET_ASM(64f);
SET_ASM(32fc);
SET_ASM(64fc);

#undef SET_ASM

//zero
template<typename IT>
struct zero;

#define ZERO_ASM(Suffix)\
template<>\
struct zero<Ipp##Suffix>\
{\
    typedef Ipp##Suffix itype;\
    static inline IppStatus do_zero(itype *dst, int len)\
    {\
        return ippsZero_##Suffix(dst, len);\
    }\
}

template<>
struct zero<Ipp8s>
{
    typedef Ipp8s itype;
    static inline IppStatus do_zero(itype *dst, int len)
    {
        return ippsZero_8u((Ipp8u*)dst, len);
    }
};

template<>
struct zero<Ipp16u>
{
    typedef Ipp16u itype;
    static inline IppStatus do_zero(itype *dst, int len)
    {
        return ippsZero_16s((Ipp16s*)dst, len);
    }
};

template<>
struct zero<Ipp32u>
{
    typedef Ipp32u itype;
    static inline IppStatus do_zero(itype *dst, int len)
    {
        return ippsZero_32s((Ipp32s*)dst, len);
    }
};

template<>
struct zero<Ipp64u>
{
    typedef Ipp64u itype;
    static inline IppStatus do_zero(itype *dst, int len)
    {
        return ippsZero_64s((Ipp64s*)dst, len);
    }
};

ZERO_ASM(8u);
ZERO_ASM(16s);
ZERO_ASM(32s);
ZERO_ASM(64s);
ZERO_ASM(32f);
ZERO_ASM(64f);
ZERO_ASM(32fc);
ZERO_ASM(64fc);

#undef ZERO_ASM


template<typename T>
static inline IppStatus do_rand_uniform_get_size(int *pRandUniStateSize);

template<>
static inline IppStatus do_rand_uniform_get_size<Ipp8u>(int *pRandUniStateSize)
{
    return ippsRandUniformGetSize_8u(pRandUniStateSize);
}
template<>
static inline IppStatus do_rand_uniform_get_size<Ipp16s>(int *pRandUniStateSize)
{
    return ippsRandUniformGetSize_16s(pRandUniStateSize);
}
template<>
static inline IppStatus do_rand_uniform_get_size<Ipp32f>(int *pRandUniStateSize)
{
    return ippsRandUniformGetSize_32f(pRandUniStateSize);
}


template<typename T>
static inline IppStatus do_rand_uniform_init(
        void *state, T low, T high, unsigned int seed); 


template<>
static inline IppStatus do_rand_uniform_init<Ipp8u>(
        void *state, Ipp8u low, Ipp8u high, unsigned int seed)
{
    return ippsRandUniformInit_8u(
            (IppsRandUniState_8u*)state, low, high, seed);
}
template<>
static inline IppStatus do_rand_uniform_init<Ipp16s>(
        void *state, Ipp16s low, Ipp16s high, unsigned int seed)
{
    return ippsRandUniformInit_16s(
            (IppsRandUniState_16s*)state, low, high, seed);
}
template<>
static inline IppStatus do_rand_uniform_init<Ipp32f>(
        void *state, Ipp32f low, Ipp32f high, unsigned int seed)
{
    return ippsRandUniformInit_32f(
            (IppsRandUniState_32f*)state, low, high, seed);
}


template<typename T>
static inline IppStatus do_rand_uniform(
        T *dst, int len, void *state);

template<>
static inline IppStatus do_rand_uniform<Ipp8u>(
        Ipp8u *dst, int len, void *state)
{
    return ippsRandUniform_8u(
            dst, len, (IppsRandUniState_8u*)state);
}
template<>
static inline IppStatus do_rand_uniform<Ipp16s>(
        Ipp16s *dst, int len, void *state)
{
    return ippsRandUniform_16s(
            dst, len, (IppsRandUniState_16s*)state);
}
template<>
static inline IppStatus do_rand_uniform<Ipp32f>(
        Ipp32f *dst, int len, void *state)
{
    return ippsRandUniform_32f(
            dst, len, (IppsRandUniState_32f*)state);
}


////
template<typename T>
static inline IppStatus do_rand_gauss_get_size(int *pRandGaussStateSize);

template<>
static inline IppStatus do_rand_gauss_get_size<Ipp8u>(int *pRandGaussStateSize)
{
    return ippsRandGaussGetSize_8u(pRandGaussStateSize);
}
template<>
static inline IppStatus do_rand_gauss_get_size<Ipp16s>(int *pRandGaussStateSize)
{
    return ippsRandGaussGetSize_16s(pRandGaussStateSize);
}
template<>
static inline IppStatus do_rand_gauss_get_size<Ipp32f>(int *pRandGaussStateSize)
{
    return ippsRandGaussGetSize_32f(pRandGaussStateSize);
}


template<typename T>
static inline IppStatus do_rand_gauss_init(
        void *state, T mean, T std_dev, unsigned int seed); 


template<>
static inline IppStatus do_rand_gauss_init<Ipp8u>(
        void *state, Ipp8u mean, Ipp8u std_dev, unsigned int seed)
{
    return ippsRandGaussInit_8u(
            (IppsRandGaussState_8u*)state, mean, std_dev, seed);
}
template<>
static inline IppStatus do_rand_gauss_init<Ipp16s>(
        void *state, Ipp16s mean, Ipp16s std_dev, unsigned int seed)
{
    return ippsRandGaussInit_16s(
            (IppsRandGaussState_16s*)state, mean, std_dev, seed);
}
template<>
static inline IppStatus do_rand_gauss_init<Ipp32f>(
        void *state, Ipp32f mean, Ipp32f std_dev, unsigned int seed)
{
    return ippsRandGaussInit_32f(
            (IppsRandGaussState_32f*)state, mean, std_dev, seed);
}


template<typename T>
static inline IppStatus do_rand_gauss(
        T *dst, int len, void *state);

template<>
static inline IppStatus do_rand_gauss<Ipp8u>(
        Ipp8u *dst, int len, void *state)
{
    return ippsRandGauss_8u(
            dst, len, (IppsRandGaussState_8u*)state);
}
template<>
static inline IppStatus do_rand_gauss<Ipp16s>(
        Ipp16s *dst, int len, void *state)
{
    return ippsRandGauss_16s(
            dst, len, (IppsRandGaussState_16s*)state);
}
template<>
static inline IppStatus do_rand_gauss<Ipp32f>(
        Ipp32f *dst, int len, void *state)
{
    return ippsRandGauss_32f(
            dst, len, (IppsRandGaussState_32f*)state);
}



///////
template<typename IT>
struct vector_jaehne;

#define VECTOR_JAEHNE_ASM(Suffix)\
template<>\
struct vector_jaehne<Ipp##Suffix>\
{\
    typedef Ipp##Suffix itype;\
    static inline IppStatus do_vector_jaehne(\
            itype *dst, int len, itype magn)\
    {\
        return ippsVectorJaehne_##Suffix(dst, len, magn);\
    }\
}

VECTOR_JAEHNE_ASM(8u);
VECTOR_JAEHNE_ASM(16u);
VECTOR_JAEHNE_ASM(16s);
VECTOR_JAEHNE_ASM(32s);
VECTOR_JAEHNE_ASM(32f);
VECTOR_JAEHNE_ASM(64f);

#undef VECTOR_JAEHNE_ASM

template<typename IT>
struct vector_slope;

#define VECTOR_SLOPE_ASM(Suffix)\
template<>\
struct vector_slope<Ipp##Suffix>\
{\
    typedef Ipp##Suffix itype;\
    static inline IppStatus do_vector_slope(\
            itype *dst, int len, double offset, double slope)\
    {\
        return ippsVectorSlope_##Suffix(\
                dst, len, (Ipp32f)offset, (Ipp32f)slope);\
    }\
}

#define VECTOR_SLOPE_ASM_D(Suffix)\
template<>\
struct vector_slope<Ipp##Suffix>\
{\
    typedef Ipp##Suffix itype;\
    static inline IppStatus do_vector_slope(\
            itype *dst, int len, double offset, double slope)\
    {\
        return ippsVectorSlope_##Suffix(\
                dst, len, (Ipp64f)offset, (Ipp64f)slope);\
    }\
}

VECTOR_SLOPE_ASM(8u);
VECTOR_SLOPE_ASM(16u);
VECTOR_SLOPE_ASM(16s);
VECTOR_SLOPE_ASM_D(32u);
VECTOR_SLOPE_ASM_D(32s);
VECTOR_SLOPE_ASM(32f);
VECTOR_SLOPE_ASM_D(64f);

#undef VECTOR_SLOPE_ASM_D
#undef VECTOR_SLOPE_ASM

///// and const /////////
template<typename T>
static inline IppStatus and_const(const T*, T, T*, int);

#define AND_CONST_ASM(Suffix)\
template<>\
static inline IppStatus and_const<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  Ipp##Suffix val,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsAndC_##Suffix##_I(val, dst, len)\
                      : ippsAndC_##Suffix(src, val, dst, len);\
}

AND_CONST_ASM(8u);
AND_CONST_ASM(16u);
AND_CONST_ASM(32u);


#undef AND_CONST_ASM


///// or const /////////
template<typename T>
static inline IppStatus or_const(const T*, T, T*, int);

#define OR_CONST_ASM(Suffix)\
template<>\
static inline IppStatus or_const<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  Ipp##Suffix val,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsOrC_##Suffix##_I(val, dst, len)\
                      : ippsOrC_##Suffix(src, val, dst, len);\
}

OR_CONST_ASM(8u);
OR_CONST_ASM(16u);
OR_CONST_ASM(32u);


#undef OR_CONST_ASM



///// xor const /////////

template<typename T>
static inline IppStatus xor_const(const T*, T, T*, int);

#define XOR_CONST_ASM(Suffix)\
template<>\
static inline IppStatus xor_const<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  Ipp##Suffix val,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsXorC_##Suffix##_I(val, dst, len)\
                      : ippsXorC_##Suffix(src, val, dst, len);\
}

XOR_CONST_ASM(8u);
XOR_CONST_ASM(16u);
XOR_CONST_ASM(32u);


#undef XOR_CONST_ASM


///// and /////////

template<typename T>
static inline IppStatus and(const T*, const T*, T*, int);

#define AND_ASM(Suffix)\
template<>\
static inline IppStatus and<Ipp##Suffix>(const Ipp##Suffix *src1, \
                            const Ipp##Suffix *src2,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src1 == dst ? ippsAnd_##Suffix##_I(src2, dst, len)\
                       : (src2 == dst ? ippsAnd_##Suffix##_I(src1, dst, len)\
                         : ippsAnd_##Suffix(src1, src2, dst, len));\
}

AND_ASM(8u);
AND_ASM(16u);
AND_ASM(32u);

#undef AND_ASM


///// or /////////

template<typename T>
static inline IppStatus or(const T*, const T*, T*, int);

#define OR_ASM(Suffix)\
template<>\
static inline IppStatus or<Ipp##Suffix>(const Ipp##Suffix *src1, \
                            const Ipp##Suffix *src2,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src1 == dst ? ippsOr_##Suffix##_I(src2, dst, len)\
                       : (src2 == dst ? ippsOr_##Suffix##_I(src1, dst, len)\
                         : ippsOr_##Suffix(src1, src2, dst, len));\
}

OR_ASM(8u);
OR_ASM(16u);
OR_ASM(32u);

#undef OR_ASM

///// xor /////////

template<typename T>
static inline IppStatus xor(const T*, const T*, T*, int);

#define XOR_ASM(Suffix)\
template<>\
static inline IppStatus xor<Ipp##Suffix>(const Ipp##Suffix *src1, \
                            const Ipp##Suffix *src2,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src1 == dst ? ippsXor_##Suffix##_I(src2, dst, len)\
                       : (src2 == dst ? ippsXor_##Suffix##_I(src1, dst, len)\
                         : ippsXor_##Suffix(src1, src2, dst, len));\
}

XOR_ASM(8u);
XOR_ASM(16u);
XOR_ASM(32u);

#undef XOR_ASM

///// not /////////

template<typename T>
static inline IppStatus not(const T*, T*, int);

#define NOT_ASM(Suffix)\
template<>\
static inline IppStatus not<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsNot_##Suffix##_I(dst, len)\
                      : ippsNot_##Suffix(src, dst, len);\
}

NOT_ASM(8u);
NOT_ASM(16u);
NOT_ASM(32u);

#undef NOT_ASM


///// lshift /////////

template<typename T>
static inline IppStatus lshift_const(const T*, int, T*, int);

#define LSHIFT_ASM(Suffix)\
template<>\
static inline IppStatus lshift_const<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  int val,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsLShiftC_##Suffix##_I(val, dst, len)\
                      : ippsLShiftC_##Suffix(src, val, dst, len);\
}

LSHIFT_ASM(8u);
LSHIFT_ASM(16u);
LSHIFT_ASM(16s);
LSHIFT_ASM(32s);

#undef LSHIFT_ASM

///// rshift /////////

template<typename T>
static inline IppStatus rshift_const(const T*, int, T*, int);

#define RSHIFT_ASM(Suffix)\
template<>\
static inline IppStatus rshift_const<Ipp##Suffix>(const Ipp##Suffix *src, \
                                  int val,\
                                  Ipp##Suffix* dst,\
                                  int len)\
{\
    return src == dst ? ippsRShiftC_##Suffix##_I(val, dst, len)\
                      : ippsRShiftC_##Suffix(src, val, dst, len);\
}

RSHIFT_ASM(8u);
RSHIFT_ASM(16u);
RSHIFT_ASM(16s);
RSHIFT_ASM(32s);

#undef RSHIFT_ASM


/////// add_const /////////
template<typename T>
static inline IppStatus add_const(const T *, T, T *, int, int);


#define ADD_CONST_ASM(Suffix)\
template<>\
static inline IppStatus add_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src == dst ? ippsAddC_##Suffix##_I(val, dst, len)\
                      : ippsAddC_##Suffix(src, val, dst, len);\
}


#define ADD_CONST_SFS_ASM(Suffix)\
template<>\
static inline IppStatus add_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src == dst ? ippsAddC_##Suffix##_ISfs(val, dst, len, scale)\
                      : ippsAddC_##Suffix##_Sfs(src, val, dst, len, scale);\
}


ADD_CONST_ASM(32f);
ADD_CONST_ASM(64f);
ADD_CONST_ASM(32fc);
ADD_CONST_ASM(64fc);

ADD_CONST_SFS_ASM(8u);
ADD_CONST_SFS_ASM(16u);
ADD_CONST_SFS_ASM(16s);
ADD_CONST_SFS_ASM(32s);
ADD_CONST_SFS_ASM(16sc);
ADD_CONST_SFS_ASM(32sc);

#undef ADD_CONST_ASM
#undef ADD_CONST_SFS_ASM


template<typename T>
static inline IppStatus add_product_const(
        const T*, T, T *, int);


template<>
static inline IppStatus add_product_const<Ipp32f>(
        const Ipp32f *src, Ipp32f val, Ipp32f *dst, int len)
{
    return ippsAddProductC_32f(src, val, dst, len);
}


/////// mul_const /////////
template<typename T>
static inline IppStatus mul_const(const T *, T, T *, int, int);


#define MUL_CONST_ASM(Suffix)\
template<>\
static inline IppStatus mul_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src == dst ? ippsMulC_##Suffix##_I(val, dst, len)\
                      : ippsMulC_##Suffix(src, val, dst, len);\
}


#define MUL_CONST_SFS_ASM(Suffix)\
template<>\
static inline IppStatus mul_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src == dst ? ippsMulC_##Suffix##_ISfs(val, dst, len, scale)\
                      : ippsMulC_##Suffix##_Sfs(src, val, dst, len, scale);\
}


MUL_CONST_ASM(32f);
MUL_CONST_ASM(64f);
MUL_CONST_ASM(32fc);
MUL_CONST_ASM(64fc);

MUL_CONST_SFS_ASM(8u);
MUL_CONST_SFS_ASM(16u);
MUL_CONST_SFS_ASM(16s);
MUL_CONST_SFS_ASM(32s);
MUL_CONST_SFS_ASM(16sc);
MUL_CONST_SFS_ASM(32sc);

#undef MUL_CONST_ASM
#undef MUL_CONST_SFS_ASM

/////// sub_const /////////
template<typename T>
static inline IppStatus sub_const(const T *, T, T *, int, int);


#define SUB_CONST_ASM(Suffix)\
template<>\
static inline IppStatus sub_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src == dst ? ippsSubC_##Suffix##_I(val, dst, len)\
                      : ippsSubC_##Suffix(src, val, dst, len);\
}


#define SUB_CONST_SFS_ASM(Suffix)\
template<>\
static inline IppStatus sub_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src == dst ? ippsSubC_##Suffix##_ISfs(val, dst, len, scale)\
                      : ippsSubC_##Suffix##_Sfs(src, val, dst, len, scale);\
}


SUB_CONST_ASM(32f);
SUB_CONST_ASM(64f);
SUB_CONST_ASM(32fc);
SUB_CONST_ASM(64fc);

SUB_CONST_SFS_ASM(8u);
SUB_CONST_SFS_ASM(16u);
SUB_CONST_SFS_ASM(16s);
SUB_CONST_SFS_ASM(32s);
SUB_CONST_SFS_ASM(16sc);
SUB_CONST_SFS_ASM(32sc);

#undef SUB_CONST_ASM
#undef SUB_CONST_SFS_ASM

/////// sub_const_rev /////////
template<typename T>
static inline IppStatus sub_const_rev(const T *, T, T *, int, int);


#define SUB_CONST_REV_ASM(Suffix)\
template<>\
static inline IppStatus sub_const_rev<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src == dst ? ippsSubCRev_##Suffix##_I(val, dst, len)\
                      : ippsSubCRev_##Suffix(src, val, dst, len);\
}


#define SUB_CONST_REV_SFS_ASM(Suffix)\
template<>\
static inline IppStatus sub_const_rev<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src == dst ? ippsSubCRev_##Suffix##_ISfs(val, dst, len, scale)\
                      : ippsSubCRev_##Suffix##_Sfs(src, val, dst, len, scale);\
}


SUB_CONST_REV_ASM(32f);
SUB_CONST_REV_ASM(64f);
SUB_CONST_REV_ASM(32fc);
SUB_CONST_REV_ASM(64fc);

SUB_CONST_REV_SFS_ASM(8u);
SUB_CONST_REV_SFS_ASM(16u);
SUB_CONST_REV_SFS_ASM(16s);
SUB_CONST_REV_SFS_ASM(32s);
SUB_CONST_REV_SFS_ASM(16sc);
SUB_CONST_REV_SFS_ASM(32sc);

#undef SUB_CONST_REV_ASM
#undef SUB_CONST_REV_SFS_ASM


/////// div_const /////////
template<typename T>
static inline IppStatus div_const(const T *, T, T *, int, int);


#define DIV_CONST_ASM(Suffix)\
template<>\
static inline IppStatus div_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src == dst ? ippsDivC_##Suffix##_I(val, dst, len)\
                      : ippsDivC_##Suffix(src, val, dst, len);\
}


#define DIV_CONST_SFS_ASM(Suffix)\
template<>\
static inline IppStatus div_const<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src == dst ? ippsDivC_##Suffix##_ISfs(val, dst, len, scale)\
                      : ippsDivC_##Suffix##_Sfs(src, val, dst, len, scale);\
}


DIV_CONST_ASM(32f);
DIV_CONST_ASM(64f);
DIV_CONST_ASM(32fc);
DIV_CONST_ASM(64fc);

DIV_CONST_SFS_ASM(8u);
DIV_CONST_SFS_ASM(16u);
DIV_CONST_SFS_ASM(16s);
DIV_CONST_SFS_ASM(16sc);

#undef DIV_CONST_ASM
#undef DIV_CONST_SFS_ASM


/////// div_const_rev /////////
template<typename T>
static inline IppStatus div_const_rev(const T *, T, T *, int);


#define DIV_CONST_REV_ASM(Suffix)\
template<>\
static inline IppStatus div_const_rev<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len)\
{\
    return src == dst ? ippsDivCRev_##Suffix##_I(val, dst, len)\
                      : ippsDivCRev_##Suffix(src, val, dst, len);\
}


#define DIV_CONST_REV_SFS_ASM(Suffix)\
template<>\
static inline IppStatus div_const_rev<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix val,\
                                  Ipp##Suffix *dst,\
                                  int len)\
{\
    return src == dst ? ippsDivCRev_##Suffix##_I(val, dst, len)\
                      : ippsDivCRev_##Suffix##(src, val, dst, len);\
}


DIV_CONST_REV_ASM(32f);

DIV_CONST_REV_SFS_ASM(16u);

#undef DIV_CONST_REV_ASM
#undef DIV_CONST_REV_SFS_ASM


/////// add /////////
template<typename T>
static inline IppStatus add(const T *, const T*, T *, int, int);


#define ADD_ASM(Suffix)\
template<>\
static inline IppStatus add<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src1 == dst ? ippsAdd_##Suffix##_I(src2, dst, len)\
                      : (src2 == dst ? ippsAdd_##Suffix##_I(src1, dst, len)\
                                     : ippsAdd_##Suffix(src1, src2, dst, len));\
}


#define ADD_SFS_ASM(Suffix)\
template<>\
static inline IppStatus add<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src1 == dst ? ippsAdd_##Suffix##_ISfs(src2, dst, len, scale)\
                      : (src2 == dst ? ippsAdd_##Suffix##_ISfs(src1, dst, len, scale)\
                                     : ippsAdd_##Suffix##_Sfs(src1, src2, dst, len, scale));\
}


ADD_ASM(32f);
ADD_ASM(64f);
ADD_ASM(32fc);
ADD_ASM(64fc);

ADD_SFS_ASM(8u);
ADD_SFS_ASM(16u);
ADD_SFS_ASM(16s);
ADD_SFS_ASM(32s);
ADD_SFS_ASM(16sc);
ADD_SFS_ASM(32sc);

#undef ADD_ASM
#undef ADD_SFS_ASM


/////// add product /////////
template<typename T>
static inline IppStatus add_product(const T *, const T*, T *, int, int);


#define ADD_PRODUCT_ASM(Suffix)\
template<>\
static inline IppStatus add_product<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return ippsAddProduct_##Suffix##(src1, src2, dst, len);\
}


#define ADD_PRODUCT_SFS_ASM(Suffix)\
template<>\
static inline IppStatus add_product<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return ippsAddProduct_##Suffix##_Sfs(src1, src2, dst, len, scale);\
}


ADD_PRODUCT_ASM(32f);
ADD_PRODUCT_ASM(64f);
ADD_PRODUCT_ASM(32fc);
ADD_PRODUCT_ASM(64fc);

ADD_PRODUCT_SFS_ASM(16s);
ADD_PRODUCT_SFS_ASM(32s);

#undef ADD_PRODUCT_ASM
#undef ADD_PRODUCT_SFS_ASM



/////// mul /////////
template<typename T>
static inline IppStatus mul(const T *, const T*, T *, int, int);


#define MUL_ASM(Suffix)\
template<>\
static inline IppStatus mul<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src1 == dst ? ippsMul_##Suffix##_I(src2, dst, len)\
                      : (src2 == dst ? ippsMul_##Suffix##_I(src1, dst, len)\
                                     : ippsMul_##Suffix(src1, src2, dst, len));\
}


#define MUL_SFS_ASM(Suffix)\
template<>\
static inline IppStatus mul<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src1 == dst ? ippsMul_##Suffix##_ISfs(src2, dst, len, scale)\
                      : (src2 == dst ? ippsMul_##Suffix##_ISfs(src1, dst, len, scale)\
                                     : ippsMul_##Suffix##_Sfs(src1, src2, dst, len, scale));\
}


MUL_ASM(32f);
MUL_ASM(64f);
MUL_ASM(32fc);
MUL_ASM(64fc);

MUL_SFS_ASM(8u);
MUL_SFS_ASM(16u);
MUL_SFS_ASM(16s);
MUL_SFS_ASM(32s);
MUL_SFS_ASM(16sc);
MUL_SFS_ASM(32sc);

#undef MUL_ASM
#undef MUL_SFS_ASM

/////// sub /////////
template<typename T>
static inline IppStatus sub(const T *, const T*, T *, int, int);


#define SUB_ASM(Suffix)\
template<>\
static inline IppStatus sub<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src1 == dst ? ippsSub_##Suffix##_I(src2, dst, len)\
                      : (src2 == dst ? ippsSub_##Suffix##_I(src1, dst, len)\
                                     : ippsSub_##Suffix(src1, src2, dst, len));\
}


#define SUB_SFS_ASM(Suffix)\
template<>\
static inline IppStatus sub<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src1 == dst ? ippsSub_##Suffix##_ISfs(src2, dst, len, scale)\
                      : (src2 == dst ? ippsSub_##Suffix##_ISfs(src1, dst, len, scale)\
                                     : ippsSub_##Suffix##_Sfs(src1, src2, dst, len, scale));\
}


SUB_ASM(32f);
SUB_ASM(64f);
SUB_ASM(32fc);
SUB_ASM(64fc);

SUB_SFS_ASM(8u);
SUB_SFS_ASM(16u);
SUB_SFS_ASM(16s);
SUB_SFS_ASM(32s);
SUB_SFS_ASM(16sc);
SUB_SFS_ASM(32sc);

#undef SUB_ASM
#undef SUB_SFS_ASM


/////// div /////////
template<typename T>
static inline IppStatus div(const T *, const T*, T *, int, int);


#define DIV_ASM(Suffix)\
template<>\
static inline IppStatus div<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int )\
{\
    return src1 == dst ? ippsDiv_##Suffix##_I(src2, dst, len)\
                      : (src2 == dst ? ippsDiv_##Suffix##_I(src1, dst, len)\
                                     : ippsDiv_##Suffix(src1, src2, dst, len));\
}


#define DIV_SFS_ASM(Suffix)\
template<>\
static inline IppStatus div<Ipp##Suffix>(\
                                  const Ipp##Suffix *src1,\
                                  const Ipp##Suffix *src2,\
                                  Ipp##Suffix *dst,\
                                  int len,\
                                  int scale)\
{\
    return src1 == dst ? ippsDiv_##Suffix##_ISfs(src2, dst, len, scale)\
                      : (src2 == dst ? ippsDiv_##Suffix##_ISfs(src1, dst, len, scale)\
                                     : ippsDiv_##Suffix##_Sfs(src1, src2, dst, len, scale));\
}


DIV_ASM(32f);
DIV_ASM(64f);
DIV_ASM(32fc);
DIV_ASM(64fc);

DIV_SFS_ASM(8u);
DIV_SFS_ASM(16u);
DIV_SFS_ASM(16s);
DIV_SFS_ASM(32s);
DIV_SFS_ASM(16sc);

#undef DIV_ASM
#undef DIV_SFS_ASM

/////// abs /////////
template<typename T>
static inline IppStatus abs(const T *, T *, int);


#define ABS_ASM(Suffix)\
template<>\
static inline IppStatus abs<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len)\
{\
    return src == dst ? ippsAbs_##Suffix##_I(dst, len)\
                      : ippsAbs_##Suffix(src, dst, len);\
}

ABS_ASM(16s);
ABS_ASM(32s);
ABS_ASM(32f);
ABS_ASM(64f);

#undef ABS_ASM


/////// sqr /////////
template<typename T>
static inline IppStatus sqr(const T *, T *, int, int);


#define SQR_ASM(Suffix)\
template<>\
static inline IppStatus sqr<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int)\
{\
    return src == dst ? ippsSqr_##Suffix##_I(dst, len)\
                      : ippsSqr_##Suffix(src, dst, len);\
}


#define SQR_SFS_ASM(Suffix)\
template<>\
static inline IppStatus sqr<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int scale)\
{\
    return src == dst ? ippsSqr_##Suffix##_ISfs(dst, len, scale)\
                      : ippsSqr_##Suffix##_Sfs(src, dst, len, scale);\
}

SQR_ASM(32f);
SQR_ASM(64f);
SQR_ASM(32fc);
SQR_ASM(64fc);

SQR_SFS_ASM(8u);
SQR_SFS_ASM(16u);
SQR_SFS_ASM(16s);
SQR_SFS_ASM(16sc);


#undef SQR_ASM
#undef SQR_SFS_ASM


/////// sqrt /////////
template<typename T>
static inline IppStatus sqrt(const T *, T *, int, int);


#define SQRT_ASM(Suffix)\
template<>\
static inline IppStatus sqrt<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int)\
{\
    return src == dst ? ippsSqrt_##Suffix##_I(dst, len)\
                      : ippsSqrt_##Suffix(src, dst, len);\
}


#define SQRT_SFS_ASM(Suffix)\
template<>\
static inline IppStatus sqrt<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int scale)\
{\
    return ippsSqrt_##Suffix##_Sfs(src, dst, len, scale);\
}

SQRT_ASM(32f);
SQRT_ASM(64f);
SQRT_ASM(32fc);
SQRT_ASM(64fc);

SQRT_SFS_ASM(8u);
SQRT_SFS_ASM(16u);
SQRT_SFS_ASM(16s);
SQRT_SFS_ASM(16sc);


#undef SQRT_ASM
#undef SQRT_SFS_ASM

///// cubrt ////
template<typename T>
static inline IppStatus cubrt(const T*, T*, int);

template<>
static inline IppStatus cubrt<Ipp32f>(
        const Ipp32f *src, Ipp32f *dst, int len)
{
    return ippsCubrt_32f(src, dst, len);
}


///// exp ////
template<typename T>
static inline IppStatus exp(const T*, T*, int);

template<>
static inline IppStatus exp<Ipp32f>(
        const Ipp32f *src, Ipp32f *dst, int len)
{
    return ippsExp_32f(src, dst, len);
}

template<>
static inline IppStatus exp<Ipp64f>(
        const Ipp64f *src, Ipp64f *dst, int len)
{
    return ippsExp_64f(src, dst, len);
}

///// ln ///////
template<typename T>
static inline IppStatus ln(const T *, T *, int, int);


#define LN_ASM(Suffix)\
template<>\
static inline IppStatus ln<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int)\
{\
    return src == dst ? ippsLn_##Suffix##_I(dst, len)\
                      : ippsLn_##Suffix(src, dst, len);\
}


#define LN_SFS_ASM(Suffix)\
template<>\
static inline IppStatus ln<Ipp##Suffix>(\
                                  const Ipp##Suffix *src,\
                                  Ipp##Suffix *dst,\
                                  int len, int scale)\
{\
    return src == dst ? ippsLn_##Suffix##_ISfs(dst, len, scale)\
                      : ippsLn_##Suffix##_Sfs(src, dst, len, scale);\
}

LN_ASM(32f);
LN_ASM(64f);

LN_SFS_ASM(16s);
LN_SFS_ASM(32s);


#undef LN_ASM
#undef LN_SFS_ASM

///// arctan /////////////
template<typename T>
static inline IppStatus arctan(const T*, T*, int);

template<>
static inline IppStatus arctan<Ipp32f>(
        const Ipp32f *src, Ipp32f *dst, int len)
{
    return ippsArctan_32f(src, dst, len);
}

template<>
static inline IppStatus arctan<Ipp64f>(
        const Ipp64f *src, Ipp64f *dst, int len)
{
    return ippsArctan_64f(src, dst, len);
}



//////// normalize /////////
template<typename T1, typename T2>
static inline IppStatus normalize(
        const T1*, T1*, int, T1, T2, int);

#define NORMALIZE_ASM(Suffix1, Suffix2)\
template<>\
static inline IppStatus normalize<Ipp##Suffix1, Ipp##Suffix2>(\
                                  const Ipp##Suffix1 *src,\
                                  Ipp##Suffix1 *dst,\
                                  int len, Ipp##Suffix1 sub,\
                                  Ipp##Suffix2 div, int)\
{\
    return ippsNormalize_##Suffix1(src, dst, len, sub, div);\
}



NORMALIZE_ASM(32f, 32f);
NORMALIZE_ASM(64f, 64f);
NORMALIZE_ASM(32fc, 32f);
NORMALIZE_ASM(64fc, 64f);

#undef NORMALIZE_ASM




//////////sort_ascend /////////
template<typename T>
static inline IppStatus sort_ascend(T *, int);

#define SORT_ASCEND(Suffix)\
template<>\
static inline IppStatus sort_ascend<Ipp##Suffix>(\
        Ipp##Suffix *buf, int len)\
{\
    return ippsSortAscend_##Suffix##_I(buf, len);\
}

SORT_ASCEND(8u);
SORT_ASCEND(16u);
SORT_ASCEND(16s);
SORT_ASCEND(32s);
SORT_ASCEND(32f);
SORT_ASCEND(64f);


#undef SORT_ASCEND



//////////sort_descend /////////
template<typename T>
static inline IppStatus sort_descend(T *, int);

#define SORT_DESCEND(Suffix)\
template<>\
static inline IppStatus sort_descend<Ipp##Suffix>(\
        Ipp##Suffix *buf, int len)\
{\
    return ippsSortDescend_##Suffix##_I(buf, len);\
}

SORT_DESCEND(8u);
SORT_DESCEND(16u);
SORT_DESCEND(16s);
SORT_DESCEND(32s);
SORT_DESCEND(32f);
SORT_DESCEND(64f);

#undef SORT_DESCEND



//////////sort_index_descend /////////
template<typename T>
static inline IppStatus sort_index_ascend(T *, int*, int);

#define SORT_INDEX_ASCEND(Suffix)\
template<>\
static inline IppStatus sort_index_ascend<Ipp##Suffix>(\
        Ipp##Suffix *buf, int *idxs, int len)\
{\
    return ippsSortIndexAscend_##Suffix##_I(buf, idxs, len);\
}

SORT_INDEX_ASCEND(8u);
SORT_INDEX_ASCEND(16u);
SORT_INDEX_ASCEND(16s);
SORT_INDEX_ASCEND(32s);
SORT_INDEX_ASCEND(32f);
SORT_INDEX_ASCEND(64f);


#undef SORT_INDEX_ASCEND


//////////sort_index_descend /////////
template<typename T>
static inline IppStatus sort_index_descend(T *, int*, int);

#define SORT_INDEX_DESCEND(Suffix)\
template<>\
static inline IppStatus sort_index_descend<Ipp##Suffix>(\
        Ipp##Suffix *buf, int *idxs, int len)\
{\
    return ippsSortIndexDescend_##Suffix##_I(buf, idxs, len);\
}

SORT_INDEX_DESCEND(8u);
SORT_INDEX_DESCEND(16u);
SORT_INDEX_DESCEND(16s);
SORT_INDEX_DESCEND(32s);
SORT_INDEX_DESCEND(32f);
SORT_INDEX_DESCEND(64f);

#undef SORT_INDEX_DESCEND


//////////sort_radix_ascend /////////
template<typename T>
static inline IppStatus sort_radix_ascend(T *, T*, Ipp32s);

#define SORT_RADIX_ASCEND(Suffix)\
template<>\
static inline IppStatus sort_radix_ascend<Ipp##Suffix>(\
        Ipp##Suffix *buf, Ipp##Suffix *tmp, Ipp32s len)\
{\
    return ippsSortRadixAscend_##Suffix##_I(buf, tmp, len);\
}

SORT_RADIX_ASCEND(8u);
SORT_RADIX_ASCEND(16u);
SORT_RADIX_ASCEND(16s);
SORT_RADIX_ASCEND(32s);
SORT_RADIX_ASCEND(32u);
SORT_RADIX_ASCEND(32f);
SORT_RADIX_ASCEND(64f);

#undef SORT_RADIX_ASCEND

//////////sort_radix_descend /////////
template<typename T>
static inline IppStatus sort_radix_descend(T *, T*, Ipp32s);

#define SORT_RADIX_DESCEND(Suffix)\
template<>\
static inline IppStatus sort_radix_descend<Ipp##Suffix>(\
        Ipp##Suffix *buf, Ipp##Suffix *tmp, Ipp32s len)\
{\
    return ippsSortRadixDescend_##Suffix##_I(buf, tmp, len);\
}

SORT_RADIX_DESCEND(8u);
SORT_RADIX_DESCEND(16u);
SORT_RADIX_DESCEND(16s);
SORT_RADIX_DESCEND(32s);
SORT_RADIX_DESCEND(32u);
SORT_RADIX_DESCEND(32f);
SORT_RADIX_DESCEND(64f);

#undef SORT_RADIX_DESCEND


//////////sort_radix_index_ascend /////////
template<typename T>
static inline IppStatus sort_radix_index_ascend(const T * const,
                                                 Ipp32s, Ipp32s*,
                                                 Ipp32s*, Ipp32s);

#define SORT_RADIX_INDEX_ASCEND(Suffix)\
template<>\
static inline IppStatus sort_radix_index_ascend<Ipp##Suffix>(\
        const Ipp##Suffix * const buf, Ipp32s stride, Ipp32s *idxs,\
        Ipp32s *tmp_idxs, Ipp32s len)\
{\
    return ippsSortRadixIndexAscend_##Suffix(\
            buf, stride, idxs, tmp_idxs, len);\
}

SORT_RADIX_INDEX_ASCEND(8u);
SORT_RADIX_INDEX_ASCEND(16u);
SORT_RADIX_INDEX_ASCEND(16s);
SORT_RADIX_INDEX_ASCEND(32s);
SORT_RADIX_INDEX_ASCEND(32u);
SORT_RADIX_INDEX_ASCEND(32f);

#undef SORT_RADIX_INDEX_ASCEND


//////////sort_radix_index_descend /////////
template<typename T>
static inline IppStatus sort_radix_index_descend(const T * const,
                                                 Ipp32s, Ipp32s*,
                                                 Ipp32s*, Ipp32s);
#define SORT_RADIX_INDEX_DESCEND(Suffix)\
template<>\
static inline IppStatus sort_radix_index_descend<Ipp##Suffix>(\
        const Ipp##Suffix * const buf, Ipp32s stride, Ipp32s *idxs,\
        Ipp32s *tmp_idxs, Ipp32s len)\
{\
    return ippsSortRadixIndexDescend_##Suffix(\
            buf, stride, idxs, tmp_idxs, len);\
}

SORT_RADIX_INDEX_DESCEND(8u);
SORT_RADIX_INDEX_DESCEND(16u);
SORT_RADIX_INDEX_DESCEND(16s);
SORT_RADIX_INDEX_DESCEND(32s);
SORT_RADIX_INDEX_DESCEND(32u);
SORT_RADIX_INDEX_DESCEND(32f);

#undef SORT_RADIX_INDEX_DESCEND


//////////swap_bytes/////////
template<typename T>
static inline IppStatus swap_bytes(const T *,
                                   T *, int);

#define SWAP_BYTES(Suffix)\
template<>\
static inline IppStatus swap_bytes<Ipp##Suffix>(\
        const Ipp##Suffix *src, Ipp##Suffix *dst, int len)\
{\
    return src == dst ? ippsSwapBytes_##Suffix##_I(dst, len)\
                      : ippsSwapBytes_##Suffix(src, dst, len);\
}

template<>
static inline IppStatus swap_bytes<Ipp8u>(
        const Ipp8u *src, Ipp8u *dst, int len)
{
    return src == dst ? ippsSwapBytes_24u_I(dst, len)
                      : ippsSwapBytes_24u(src, dst, len);
}


SWAP_BYTES(16u);
SWAP_BYTES(32u);
SWAP_BYTES(64u);

#undef SWAP_BYTES


//////////swap_bytes/////////
template<typename T1, typename T2>
static inline IppStatus convert(const T1 *,
                                   T2 *, int);

#define CONVERT(Suffix1, Suffix2)\
template<>\
static inline IppStatus convert<Ipp##Suffix1, Ipp##Suffix2>(\
        const Ipp##Suffix1 *src, Ipp##Suffix2 *dst, int len)\
{\
    return ippsConvert_##Suffix1##Suffix2(src, dst, len);\
}


template<typename T1, typename T2>
static inline IppStatus convert_sfs(const T1 *,
                                   T2 *, int, int);

#define CONVERT_SFS(Suffix1, Suffix2)\
template<>\
static inline IppStatus convert_sfs<Ipp##Suffix1, Ipp##Suffix2>(\
        const Ipp##Suffix1 *src, Ipp##Suffix2 *dst, int len, int scale)\
{\
    return ippsConvert_##Suffix1##Suffix2##_Sfs(src, dst, len, scale);\
}

template<typename T1, typename T2>
static inline IppStatus convert_sfs(const T1 *,
                                   T2 *, int,  IppRoundMode, int);

#define CONVERT_SFS_RND(Suffix1, Suffix2)\
template<>\
static inline IppStatus convert_sfs<Ipp##Suffix1, Ipp##Suffix2>(\
        const Ipp##Suffix1 *src, Ipp##Suffix2 *dst, int len, IppRoundMode rnd, int scale)\
{\
    return ippsConvert_##Suffix1##Suffix2##_Sfs(src, dst, len, rnd, scale);\
}


CONVERT(8s, 16s);
CONVERT(8s, 32f);
CONVERT(8u, 32f);
CONVERT(16s, 32s);
CONVERT(16s, 32f);
CONVERT(16u, 32f);
CONVERT(32s, 16s);
CONVERT(32s, 32f);
CONVERT(32s, 64f);
CONVERT(32f, 64f);
CONVERT(64s, 64f);
CONVERT(64f, 32f);


CONVERT_SFS_RND(16s, 8s);
CONVERT_SFS(16s, 32f);
CONVERT_SFS(16s, 64f);
CONVERT_SFS(32s, 16s);
CONVERT_SFS(32s, 32f);
CONVERT_SFS(32s, 64f);
CONVERT_SFS_RND(32f, 8s);
CONVERT_SFS_RND(32f, 8u);
CONVERT_SFS_RND(32f, 16s);
CONVERT_SFS_RND(32f, 16u);
CONVERT_SFS_RND(32f, 32s);
CONVERT_SFS_RND(64s, 32s);
CONVERT_SFS_RND(64f, 16s);
CONVERT_SFS_RND(64f, 32s);
CONVERT_SFS_RND(64f, 64s);

#undef CONVERT
#undef CONVERT_SFS
#undef CONVERT_SFS_RND


//////////conj/////////
template<typename T>
static inline IppStatus conj(const T *,
                                   T *, int);

#define CONJ(Suffix)\
template<>\
static inline IppStatus conj<Ipp##Suffix>(\
        const Ipp##Suffix *src, Ipp##Suffix *dst, int len)\
{\
    return src == dst ? ippsConj_##Suffix##_I(dst, len)\
                      : ippsConj_##Suffix(src, dst, len);\
}

CONJ(16sc);
CONJ(32fc);
CONJ(64fc);

#undef CONJ


//////////magnitude/////////
template<typename T>
static inline IppStatus magnitude(const T *, const T*,
                                   T *, int, int);

template<>
static inline IppStatus magnitude<Ipp32f>(const Ipp32f *re, 
                                          const Ipp32f *im,
										  Ipp32f *dst,
                                          int len,
                                          int)
{
    return ippsMagnitude_32f(re, im, dst, len);
}

template<>
static inline IppStatus magnitude<Ipp64f>(const Ipp64f *re, 
                                          const Ipp64f *im,
                                          Ipp64f *dst,
                                          int len,
                                          int)
{
    return ippsMagnitude_64f(re, im, dst, len);
}

template<>
static inline IppStatus magnitude<Ipp16s>(const Ipp16s *re, 
                                          const Ipp16s *im,
                                          Ipp16s *dst,
                                          int len,
                                          int scale)
{
    return ippsMagnitude_16s_Sfs(re, im, dst, len, scale);
}

//
template<typename T1, typename T2>
static inline IppStatus magnitude(const T1 *, const T1*,
                                   T2 *, int, int);

template<>
static inline IppStatus magnitude<Ipp16s, Ipp32f>(const Ipp16s *re, const Ipp16s* im,
                                   Ipp32f *dst, int len, int)
{
    return ippsMagnitude_16s32f(re, im, dst, len);
}

//
template<typename T1, typename T2>
static inline IppStatus magnitude(const T1 *,
                                   T2 *, int, int);

template<>
static inline IppStatus magnitude<Ipp32fc, Ipp32f>(const Ipp32fc *src,
                                   Ipp32f *dst, int len, int)
{
    return ippsMagnitude_32fc(src, dst, len);
}

template<>
static inline IppStatus magnitude<Ipp64fc, Ipp64f>(const Ipp64fc *src,
                                   Ipp64f *dst, int len, int)
{
    return ippsMagnitude_64fc(src, dst, len);
}

template<>
static inline IppStatus magnitude<Ipp16sc, Ipp32f>(const Ipp16sc *src,
                                   Ipp32f *dst, int len, int)
{
    return ippsMagnitude_16sc32f(src, dst, len);
}

template<>
static inline IppStatus magnitude<Ipp16sc, Ipp16s>(const Ipp16sc *src,
                                   Ipp16s *dst, int len, int scale)
{
    return ippsMagnitude_16sc_Sfs(src, dst, len, scale);
}

template<>
static inline IppStatus magnitude<Ipp32sc, Ipp32s>(const Ipp32sc *src,
                                   Ipp32s *dst, int len, int scale)
{
    return ippsMagnitude_32sc_Sfs(src, dst, len, scale);
}



//////////phase/////////
template<typename T1, typename T2>
static inline IppStatus phase(const T1 *, T2*, int);

template<>
static inline IppStatus phase<Ipp64fc, Ipp64f>(
        const Ipp64fc *src, Ipp64f *dst, int len)
{
    return ippsPhase_64fc(src, dst, len);
}

template<>
static inline IppStatus phase<Ipp32fc, Ipp32f>(
        const Ipp32fc *src, Ipp32f *dst, int len)
{
    return ippsPhase_32fc(src, dst, len);
}

template<>
static inline IppStatus phase<Ipp16sc, Ipp32f>(
        const Ipp16sc *src, Ipp32f *dst, int len)
{
    return ippsPhase_16sc32f(src, dst, len);
}


template<typename T1, typename T2>
static inline IppStatus phase(const T1 *, const T1*, T2*, int);


template<>
static inline IppStatus phase<Ipp64f, Ipp64f>(
        const Ipp64f *re, const Ipp64f *im, Ipp64f *dst, int len)
{
    return ippsPhase_64f(re, im, dst, len);
}

template<>
static inline IppStatus phase<Ipp32f, Ipp32f>(
        const Ipp32f *re, const Ipp32f *im, Ipp32f *dst, int len)
{
    return ippsPhase_32f(re, im, dst, len);
}

template<>
static inline IppStatus phase<Ipp16s, Ipp32f>(
        const Ipp16s *re, const Ipp16s *im, Ipp32f *dst, int len)
{
    return ippsPhase_16s32f(re, im, dst, len);
}


//////////power_spectr/////////
template<typename T1, typename T2>
static inline IppStatus power_spectr(const T1 *, T2*, int, int);

template<>
static inline IppStatus power_spectr<Ipp64fc, Ipp64f>(
        const  Ipp64fc* src, Ipp64f* dst, int len, int)
{
    return ippsPowerSpectr_64fc(src, dst, len);
}

template<>
static inline IppStatus power_spectr<Ipp32fc, Ipp32f>(
        const  Ipp32fc* src, Ipp32f* dst, int len, int)
{
    return ippsPowerSpectr_32fc(src, dst, len);
}

template<>
static inline IppStatus power_spectr<Ipp16sc, Ipp16s>(
        const  Ipp16sc* src, Ipp16s* dst, int len, int scale)
{
    return ippsPowerSpectr_16sc_Sfs(src, dst, len, scale);
}


template<typename T1, typename T2>
static inline IppStatus power_spectr(const T1 *, const T1*, T2*, int, int);


template<>
static inline IppStatus power_spectr<Ipp64f, Ipp64f>(
        const  Ipp64f* re, const Ipp64f *im, Ipp64f* dst, int len, int)
{
    return ippsPowerSpectr_64f(re, im, dst, len);
}

template<>
static inline IppStatus power_spectr<Ipp32f, Ipp32f>(
        const  Ipp32f* re, const Ipp32f *im, Ipp32f* dst, int len, int)
{
    return ippsPowerSpectr_32f(re, im, dst, len);
}

template<>
static inline IppStatus power_spectr<Ipp16s, Ipp16s>(
        const  Ipp16s* re, const Ipp16s *im, Ipp16s* dst, int len, int scale)
{
    return ippsPowerSpectr_16s_Sfs(re, im, dst, len, scale);
}



}}

#endif

