/**
 * @file ipps.hpp
 * @Brief 
 * @author Red Li
 * @version 
 * @date 2014-12-19
 */

#ifndef IPPPLUS_IPPS_HPP
#define IPPPLUS_IPPS_HPP

#include <ipps.h>

#include "ippcore.h"
#include "ipptype.hpp"
#include "ippcore.hpp"
#include "detail/ipps.hpp"

namespace ipp{

/**
 * defgroup VectorInitFuncTop This chapter describes the Intel® IPP functions that initialize vectors with either constants, the contents of other vectors, or the generated signals. 
 */

/**
 * @defgroup VectorInitFunc Vector Initialization Functions
 * @ingroup VectorInitFuncTop
 * @{
 */


/* --------------------------------------------------------------------------*/
/**
 * @brief copies the contents of one vector into another 
 *
 * @tparam T 
 * @param src
 * @param dst
 * @param len
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus copy(const T* src, T* dst, int len)
{
    return detail::copy<
        T, type_cat_index<T>::value, sizeof(T)>::do_copy(src, dst, len);
}


/* --------------------------------------------------------------------------*/
/**
 * @brief moves the contents of one vector to another vector
 *
 * @tparam T
 * @param src
 * @param dst
 * @param len
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus move(const T* src, T* dst, int len)
{
    return detail::move<
        T, type_cat_index<T>::value, sizeof(T)>::do_move(src, dst, len);
}



/* --------------------------------------------------------------------------*/
/**
 * @brief Initializes vector elements to a specified common value.
 *
 * @tparam T
 * @param val
 * @param dst
 * @param len
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus set(T val, T *dst, int len)
{
    typedef get<T>::type itype;
    return detail::set<itype>::do_set(
            *((itype*)&val), (itype*)dst, len);
}


/* --------------------------------------------------------------------------*/
/**
 * @brief Initializes a vector to zero.
 *
 * @tparam T
 * @param dst
 * @param len
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus zero(T *dst, int len)
{
    typedef get<T>::type itype;
    return detail::zero<itype>::do_zero(
            (itype*)dst, len);
};


/**@}*/

/**
 * @defgroup SampleGenFunc
 * @ingroup VectorInitFuncTop
 * @{
 */


/* --------------------------------------------------------------------------*/
/**
 * @brief Generates the pseudo-random samples with a uniform distribution.
 *
 * @tparam T
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
class rand_uniform
{
    void *state_;

    rand_uniform(const rand_uniform &);   
    rand_uniform &operator=(const rand_uniform &);
public:
    typedef typename get<T>::type itype;

    rand_uniform(T low, T high, unsigned int seed)
    {
        int pRandUniStateSize = 0;
        detail::do_rand_uniform_get_size<itype>(&pRandUniStateSize);
        state_ = malloc<char>(pRandUniStateSize); 
        
        detail::do_rand_uniform_init<itype>(
                state_, (itype)low, (itype)high, seed); 
    }
    ~rand_uniform()
    {
        free(state_);
    }

    IppStatus generate(T *dst, int len)
    {
        return detail::do_rand_uniform((itype*)dst, len, state_);
    }
};


/* --------------------------------------------------------------------------*/
/**
 * @brief This section describes the function that generates pseudo-random samples with Gaussian distribution.
 *
 * @tparam T
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
class rand_gauss
{
    void *state_;

    rand_gauss(const rand_gauss &);   
    rand_gauss &operator=(const rand_gauss &);
public:
    typedef typename get<T>::type itype;

    rand_gauss(T mean, T std_dev, unsigned int seed)
    {
        int pRandGaussStateSize = 0;
        detail::do_rand_gauss_get_size<itype>(&pRandGaussStateSize);
        state_ = malloc<char>(pRandGaussStateSize); 
        
        detail::do_rand_gauss_init<itype>(
                state_, (itype)mean, (itype)std_dev, seed); 
    }
    ~rand_gauss()
    {
        free(state_);
    }

    inline IppStatus generate(T *dst, int len)
    {
        return detail::do_rand_gauss((itype*)dst, len, state_);
    }
};


/* --------------------------------------------------------------------------*/
/**
 * @brief Creates a Jaehne vector.
 * pDst[n] = magn * sin ((0.5πn2)/len), 0 <= n < len 
 *
 * @tparam T 
 * @param dst
 * @param len
 * @param magn
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus vector_jaehne(T *dst, int len, T magn)
{
    typedef get<T>::type itype;
    return detail::vector_jaehne<itype>::do_vector_jaehne(
            (itype*)dst, len, magn);
}


/* --------------------------------------------------------------------------*/
/**
 * @brief Creates a slope vector.
 * pDst[n] = offset + slope*n, 0 <= n < len.
 *
 * @tparam T
 * @param dst
 * @param len
 * @param offset
 * @param slope
 *
 * @returns   
 */
/* ----------------------------------------------------------------------------*/
template<typename T>
static inline IppStatus vector_slope(
        T *dst, int len, double offset, double slope)
{
    typedef get<T>::type itype;
    return detail::vector_slope<itype>::do_vector_slope(
            (itype*)dst, len, offset, slope);
}

/**@}*/





}

#endif
