/**
* @license Apache-2.0
*
* Copyright (c) 2020 The Stdlib Authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef STDLIB_MATH_BASE_NAPI_UNARY_H
#define STDLIB_MATH_BASE_NAPI_UNARY_H

#include <node_api.h>
#include <assert.h>
#include <stdint.h>

/**
* Macro for registering an N-API module exporting an interface invoking a unary function accepting and returning double-precision floating-point numbers.
*
* @param fcn   unary function
*
* @example
* static double scale( const double x ) {
*     return x * 10.0;
* }
*
* // ...
*
* // Register an N-API module:
* STDLIB_MATH_BASE_NAPI_MODULE_D_D( scale );
*/
#define STDLIB_MATH_BASE_NAPI_MODULE_D_D( fcn )                                \
	static napi_value stdlib_math_base_napi_d_d_wrapper(                       \
		napi_env env,                                                          \
		napi_callback_info info                                                \
	) {                                                                        \
		return stdlib_math_base_napi_d_d( env, info, fcn );                    \
	};                                                                         \
	static napi_value stdlib_math_base_napi_d_d_init(                          \
		napi_env env,                                                          \
		napi_value exports                                                     \
	) {                                                                        \
		napi_value fcn;                                                        \
		napi_status status = napi_create_function(                             \
			env,                                                               \
			"exports",                                                         \
			NAPI_AUTO_LENGTH,                                                  \
			stdlib_math_base_napi_d_d_wrapper,                                 \
			NULL,                                                              \
			&fcn                                                               \
		);                                                                     \
		assert( status == napi_ok );                                           \
		return fcn;                                                            \
	};                                                                         \
	NAPI_MODULE( NODE_GYP_MODULE_NAME, stdlib_math_base_napi_d_d_init )

/**
* Macro for registering an N-API module exporting an interface invoking a unary function accepting and returning single-precision floating-point numbers.
*
* @param fcn   unary function
*
* @example
* static float scale( const float x ) {
*     return x * 10.0f;
* }
*
* // ...
*
* // Register an N-API module:
* STDLIB_MATH_BASE_NAPI_MODULE_F_F( scale );
*/
#define STDLIB_MATH_BASE_NAPI_MODULE_F_F( fcn )                                \
	static napi_value stdlib_math_base_napi_f_f_wrapper(                       \
		napi_env env,                                                          \
		napi_callback_info info                                                \
	) {                                                                        \
		return stdlib_math_base_napi_f_f( env, info, fcn );                    \
	};                                                                         \
	static napi_value stdlib_math_base_napi_f_f_init(                          \
		napi_env env,                                                          \
		napi_value exports                                                     \
	) {                                                                        \
		napi_value fcn;                                                        \
		napi_status status = napi_create_function(                             \
			env,                                                               \
			"exports",                                                         \
			NAPI_AUTO_LENGTH,                                                  \
			stdlib_math_base_napi_f_f_wrapper,                                 \
			NULL,                                                              \
			&fcn                                                               \
		);                                                                     \
		assert( status == napi_ok );                                           \
		return fcn;                                                            \
	};                                                                         \
	NAPI_MODULE( NODE_GYP_MODULE_NAME, stdlib_math_base_napi_f_f_init )

/**
* Macro for registering an N-API module exporting an interface invoking a unary function accepting and returning 32-bit signed integers.
*
* @param fcn   unary function
*
* @example
* #include <stdint.h>
*
* static int32_t scale( const int32_t x ) {
*     return x * 10;
* }
*
* // ...
*
* // Register an N-API module:
* STDLIB_MATH_BASE_NAPI_MODULE_I_I( scale );
*/
#define STDLIB_MATH_BASE_NAPI_MODULE_I_I( fcn )                                \
	static napi_value stdlib_math_base_napi_i_i_wrapper(                       \
		napi_env env,                                                          \
		napi_callback_info info                                                \
	) {                                                                        \
		return stdlib_math_base_napi_i_i( env, info, fcn );                    \
	};                                                                         \
	static napi_value stdlib_math_base_napi_i_i_init(                          \
		napi_env env,                                                          \
		napi_value exports                                                     \
	) {                                                                        \
		napi_value fcn;                                                        \
		napi_status status = napi_create_function(                             \
			env,                                                               \
			"exports",                                                         \
			NAPI_AUTO_LENGTH,                                                  \
			stdlib_math_base_napi_i_i_wrapper,                                 \
			NULL,                                                              \
			&fcn                                                               \
		);                                                                     \
		assert( status == napi_ok );                                           \
		return fcn;                                                            \
	};                                                                         \
	NAPI_MODULE( NODE_GYP_MODULE_NAME, stdlib_math_base_napi_i_i_init )

/*
* If C++, prevent name mangling so that the compiler emits a binary file having undecorated names, thus mirroring the behavior of a C compiler.
*/
#ifdef __cplusplus
extern "C" {
#endif

/**
* Invokes a unary function accepting and returning double-precision floating-point numbers.
*/
napi_value stdlib_math_base_napi_d_d( napi_env env, napi_callback_info info, double (*fcn)( double ) );

/**
* Invokes a unary function accepting and returning single-precision floating-point numbers.
*/
napi_value stdlib_math_base_napi_f_f( napi_env env, napi_callback_info info, float (*fcn)( float ) );

/**
* Invokes a unary function accepting and returning 32-bit signed integers.
*/
napi_value stdlib_math_base_napi_i_i( napi_env env, napi_callback_info info, int32_t (*fcn)( int32_t ) );

#ifdef __cplusplus
}
#endif

#endif // !STDLIB_MATH_BASE_NAPI_UNARY_H