// Copyright (c) 2014-2018 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAO_PEGTL_UTF8_HPP
#define TAO_PEGTL_UTF8_HPP

#include "config.hpp"

#include "internal/peek_utf8.hpp"
#include "internal/result_on_found.hpp"
#include "internal/rules.hpp"

namespace tao
{
   namespace TAO_PEGTL_NAMESPACE
   {
      namespace utf8
      {
         // clang-format off
         struct any : internal::any< internal::peek_utf8 > {};
         struct bom : internal::one< internal::result_on_found::SUCCESS, internal::peek_utf8, 0xfeff > {};
         template< char32_t... Cs > struct not_one : internal::one< internal::result_on_found::FAILURE, internal::peek_utf8, Cs... > {};
         template< char32_t Lo, char32_t Hi > struct not_range : internal::range< internal::result_on_found::FAILURE, internal::peek_utf8, Lo, Hi > {};
         template< char32_t... Cs > struct one : internal::one< internal::result_on_found::SUCCESS, internal::peek_utf8, Cs... > {};
         template< char32_t Lo, char32_t Hi > struct range : internal::range< internal::result_on_found::SUCCESS, internal::peek_utf8, Lo, Hi > {};
         template< char32_t... Cs > struct ranges : internal::ranges< internal::peek_utf8, Cs... > {};
         template< char32_t... Cs > struct string : internal::seq< internal::one< internal::result_on_found::SUCCESS, internal::peek_utf8, Cs >... > {};
         // clang-format on

      }  // namespace utf8

   }  // namespace TAO_PEGTL_NAMESPACE

}  // namespace tao

#endif
