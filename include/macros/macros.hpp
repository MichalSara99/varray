#pragma once
#if !defined(_MACROS_HPP_)
#define _MACROS_HPP_

#define VERIFY(cond, mesg)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        if (cond)                                                                                                      \
        { /* contextually convertible to bool paranoia */                                                              \
        }                                                                                                              \
        else                                                                                                           \
        {                                                                                                              \
            _STL_REPORT_ERROR(mesg);                                                                                   \
        }                                                                                                              \
                                                                                                                       \
        _Analysis_assume_(cond);                                                                                       \
    } while (false)

#endif //_MACROS_HPP_
