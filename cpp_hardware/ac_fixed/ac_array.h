////////////////////////////////////////////////////////////////////////////////
// Catapult Synthesis
//
// Copyright (c) 2003-2015 Mentor Graphics Corp.
//       All Rights Reserved
// 
////////////////////////////////////////////////////////////////////////////////

#ifndef AC_ARRAY_H
#define AC_ARRAY_H

#ifdef AC_ARRAY_ASSERT
#include <ac_assert.h>
#define AC_A_ASSERT(cond) ac::ac_assert(__FILE__, __LINE__, #cond, cond)
#else // !AC_ARRAY_ASSERT
#define AC_A_ASSERT(cond) 
#endif // AC_ARRAY_ASSERT


template <typename T, unsigned D1, unsigned D2, unsigned D3> class ac_array;

////////////////////////////////////////////////////////////////////////////////
//  Type:         ac_array
//  Description:  Container class for multi-dimensional arrays, simplifies copy
////////////////////////////////////////////////////////////////////////////////

template <typename T, typename Td, unsigned D>
class ac_array_b
{
public:
    T d[D]; // data

public:

    typedef T ElemType;

    ac_array_b() {}
    virtual ~ac_array_b() {}

    T &operator [] (unsigned i) {
        AC_A_ASSERT(i < D);
        return d[i];
    }
    const T &operator [] (unsigned i) const {
        AC_A_ASSERT(i < D);
        return d[i];
    }

    unsigned size() const { return D; }

    void set(const Td &ival) {
        for ( unsigned i = 0; i < D; ++i )
            set(i, ival);
    }

    void set(unsigned i, const Td &ival) {
        AC_A_ASSERT(i < D);
        d[i] = ival;
    }

    void clearAll(bool dc=false) {
        for ( unsigned i = 0; i < D; ++i )
            clear(i, dc);
    }

    void clear(unsigned i, bool dc=false) {
        AC_A_ASSERT(i < D);
        if ( !dc ) {
            d[i] = 0;
        } else {
            Td v;
            d[i] = v;
        }
    }

};

////////////////////////////////////////////////////////////////////////////////
//  Multi-dimension
template <typename T, unsigned D1, unsigned D2=0, unsigned D3=0>
class ac_array : public ac_array_b< ac_array<T,D2,D3>, T, D1>
{
    typedef ac_array_b< ac_array<T,D2,D3>, T, D1> Base;
public:

    ac_array() {}
    ac_array(const T &ival) { Base::set(ival); }
    virtual ~ac_array() {}

    ac_array &operator = (const T &v) { Base::set(v); return *this; }

};

////////////////////////////////////////////////////////////////////////////////
//  Single-dimension  (rows)
template <typename T, unsigned D1>
class ac_array<T,D1,0,0> : public ac_array_b<T,T,D1>
{
    typedef ac_array_b<T,T,D1> Base;
public:
    ac_array() {}
    ac_array(const T &ival) { Base::set(ival); }
    virtual ~ac_array() {}

    ac_array &operator = (const T &v) { Base::set(v); return *this; }

};

template <typename T>
class ac_array<T,0,0,0> : public ac_array_b<T,T,1>
{
    typedef ac_array_b<T,T,1> Base;
public:
    ac_array() {}
    ac_array(const T &ival) { Base::set(ival); }
    virtual ~ac_array() {}

    ac_array &operator = (const T &v) { Base::set(v); return *this; }
};

#endif // AC_ARRAY_H
