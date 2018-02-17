/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef UTIL_HASH_ICASEHASH_HPP_
#define UTIL_HASH_ICASEHASH_HPP_

#include <string>

namespace CitadeliCAP
{
	namespace Util
	{
		namespace Hash
		{

			struct iCaseHash
			{
				size_t operator()(const std::string& strRef) const noexcept;
			};

			struct iCaseEquality
			{
				bool operator()(const std::string& lhs, const std::string& rhs) const noexcept;
			};

		} /* namespace Hash */
	} /* namespace Util */
} /* namespace CitadeliCAP */

#endif /* UTIL_HASH_ICASEHASH_HPP_ */
