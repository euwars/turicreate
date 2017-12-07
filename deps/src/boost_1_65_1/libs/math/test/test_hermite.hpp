// Copyright John Maddock 2006.
// Copyright Paul A. Bristow 2007, 2009
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifdef _MSC_VER
#  pragma warning(disable : 4127) // conditional expression is constant
#  pragma warning(disable : 4512) // assignment operator could not be generated
#  pragma warning(disable : 4756) // overflow in constant arithmetic
// Constants are too big for float case, but this doesn't matter for test.
#endif

#include <boost/math/concepts/real_concept.hpp>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/math/special_functions/math_fwd.hpp>
#include <boost/math/constants/constants.hpp>
#include <boost/array.hpp>
#include "functor.hpp"

#include "handle_test_result.hpp"
#include "table_type.hpp"

#ifndef SC_
#define SC_(x) static_cast<typename table_type<T>::type>(BOOST_JOIN(x, L))
#endif

template <class Real, class T>
void do_test_hermite(const T& data, const char* type_name, const char* test_name)
{
#if !(defined(ERROR_REPORTING_MODE) && !defined(HERMITE_FUNCTION_TO_TEST))
   typedef Real                   value_type;

   typedef value_type (*pg)(unsigned, value_type);
#ifdef HERMITE_FUNCTION_TO_TEST
   pg funcp = HERMITE_FUNCTION_TO_TEST;
#elif defined(BOOST_MATH_NO_DEDUCED_FUNCTION_POINTERS)
   pg funcp = boost::math::hermite<value_type>;
#else
   pg funcp = boost::math::hermite;
#endif

   boost::math::tools::test_result<value_type> result;

   std::cout << "Testing " << test_name << " with type " << type_name
      << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

   //
   // test hermite against data:
   //
   result = boost::math::tools::test_hetero<Real>(
      data,
      bind_func_int1<Real>(funcp, 0, 1),
      extract_result<Real>(2));
   handle_test_result(result, data[result.worst()], result.worst(), type_name, "hermite", test_name);

   std::cout << std::endl;
#endif
}

template <class T>
void test_hermite(T, const char* name)
{
   //
   // The actual test data is rather verbose, so it's in a separate file
   //
   // The contents are as follows, each row of data contains
   // three items, input value a, input value b and erf(a, b):
   //
#  include "hermite.ipp"

   do_test_hermite<T>(hermite, name, "Hermite Polynomials");
}

template <class T>
void test_spots(T, const char* t)
{
   std::cout << "Testing basic sanity checks for type " << t << std::endl;
   //
   // basic sanity checks, tolerance is 100 epsilon:
   // These spots were generated by MathCAD, precision is
   // 14-16 digits.
   //
   T tolerance = (std::max)(boost::math::tools::epsilon<T>() * 100, static_cast<T>(1e-14));
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(0, static_cast<T>(1)), static_cast<T>(1.L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(1)), static_cast<T>(2.L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(2)), static_cast<T>(4.L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(10)), static_cast<T>(20), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(100)), static_cast<T>(200), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(1e6)), static_cast<T>(2e6), tolerance);
   if(std::numeric_limits<T>::max_exponent >= std::numeric_limits<double>::max_exponent)
   {
      BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(1, static_cast<T>(1e307)), static_cast<T>(2e307), tolerance);
      BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(99, static_cast<T>(100)), static_cast<T>(4.967223743011310E+227L), tolerance);
   }
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(10, static_cast<T>(30)), static_cast<T>(5.896624628001300E+17L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(10, static_cast<T>(1000)), static_cast<T>(1.023976960161280E+33L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(10, static_cast<T>(10)), static_cast<T>(8.093278209760000E+12L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(10, static_cast<T>(-10)), static_cast<T>(8.093278209760000E+12L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(3, static_cast<T>(-10)), static_cast<T>(-7.880000000000000E+3L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(3, static_cast<T>(-1000)), static_cast<T>(-7.999988000000000E+9L), tolerance);
   BOOST_CHECK_CLOSE_FRACTION(::boost::math::hermite(3, static_cast<T>(-1000000)), static_cast<T>(-7.999999999988000E+18L), tolerance);
}
