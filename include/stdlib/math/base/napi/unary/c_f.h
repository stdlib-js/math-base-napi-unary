/**
* @license Apache-2.0
*
* Copyright (c) 2025 The Stdlib Authors.
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

#ifndef STDLIB_MATH_BASE_NAPI_UNARY_C_F_H
#define STDLIB_MATH_BASE_NAPI_UNARY_C_F_H

#include "stdlib/complex/float32/ctor.h"
#include <node_api.h>
#include <assert.h>

/**
* Macro for registering a Node-API module exporting an interface invoking a unary function accepting a single-precision complex floating-point number and returning a single-precision floating-point number.
*
* @param fcn   unary function
*
* @example
* #include "stdlib/complex/float32/ctor.h"
*
* static float fcn( const stdlib_complex64_t x ) {
*     // ...
* }
*
* // ...
*
* // Register a Node-API module:
* STDLIB_MATH_BASE_NAPI_MODULE_C_F( fcn );
*/
#define STDLIB_MATH_BASE_NAPI_MODULE_C_F( fcn )                                \
	static napi_value stdlib_math_base_napi_c_f_wrapper(                       \
		napi_env env,                                                          \
		napi_callback_info info                                                \
	) {                                                                        \
		return stdlib_math_base_napi_c_f( env, info, fcn );                    \
	};                                                                         \
	static napi_value stdlib_math_base_napi_c_f_init(                          \
		napi_env env,                                                          \
		napi_value exports                                                     \
	) {                                                                        \
		napi_value f;                                                          \
		napi_status status = napi_create_function(                             \
			env,                                                               \
			"exports",                                                         \
			NAPI_AUTO_LENGTH,                                                  \
			stdlib_math_base_napi_c_f_wrapper,                                 \
			NULL,                                                              \
			&f                                                                 \
		);                                                                     \
		assert( status == napi_ok );                                           \
		return f;                                                              \
	};                                                                         \
	NAPI_MODULE( NODE_GYP_MODULE_NAME, stdlib_math_base_napi_c_f_init )

/*
* If C++, prevent name mangling so that the compiler emits a binary file having undecorated names, thus mirroring the behavior of a C compiler.
*/
#ifdef __cplusplus
extern "C" {
#endif

/**
* Invokes a unary function accepting a single-precision complex floating-point number and returning a single-precision floating-point number.
*/
napi_value stdlib_math_base_napi_c_f( napi_env env, napi_callback_info info, float (*fcn)( stdlib_complex64_t ) );

#ifdef __cplusplus
}
#endif

#endif // !STDLIB_MATH_BASE_NAPI_UNARY_C_F_H
