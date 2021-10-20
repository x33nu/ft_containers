#pragma once

namespace ft {

    template<class T, T v>
    struct integral_constant {
        static const T value = v;
        typedef T value_type;
        typedef integral_constant<T, v> type;
        operator value_type() const { return value; }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template<class T>
    struct remove_cv {
        typedef T type;
    };

    template<class T>
    struct remove_cv<const T> {
        typedef T type;
    };

    template<class T>
    struct remove_cv<volatile T> {
        typedef T type;
    };

    template<class T>
    struct remove_cv<const volatile T> {
        typedef T type;
    };

    template<class>
    struct is_integral_helper : public false_type {};

    template<>
    struct is_integral_helper<bool> : public true_type {};

    template<>
    struct is_integral_helper<char> : public true_type {};

    template<>
    struct is_integral_helper<signed char> : public true_type {};

    template<>
    struct is_integral_helper<unsigned char> : public true_type {};

    template<>
    struct is_integral_helper<wchar_t> : public true_type {};

    template<>
    struct is_integral_helper<short> : public true_type {};

    template<>
    struct is_integral_helper<unsigned short> : public true_type {};

    template<>
    struct is_integral_helper<int> : public true_type {};

    template<>
    struct is_integral_helper<unsigned int> : public true_type {};

    template<>
    struct is_integral_helper<long> : public true_type {};

    template<>
    struct is_integral_helper<unsigned long> : public true_type {};

    template<>
    struct is_integral_helper<long long> : public true_type {};

    template<>
    struct is_integral_helper<unsigned long long> : public true_type {};

    template<>
    struct is_integral_helper<__int128_t> : public true_type {};

    template<>
    struct is_integral_helper<__uint128_t> : public true_type {};

    template<class T>
    struct is_integral : public is_integral_helper<typename remove_cv<T>::type>::type {};

    template<bool, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> {
        typedef T type;
    };

}
