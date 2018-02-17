/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "iCaseHash.hpp"

#include <boost/functional/hash.hpp>
#include <boost/utility/string_ref.hpp>
#include <boost/algorithm/string.hpp>

namespace CitadeliCAP
{
	namespace Util
	{
		namespace Hash
		{

			size_t iCaseHash::operator ()(const std::string& str) const
			{
				size_t h;
				for(const auto& c : str)
				{
					boost::hash_combine(h, c & 0xdf);
				}

				return h;
			}

			bool iCaseEquality::operator ()(const std::string& lhs, const std::string& rhs) const
			{
				auto sz = lhs.length();
				if(sz == rhs.length())
				{
					for(auto i = 0; i < sz; ++i)
					{
						if(lhs[i] & 0xdf != rhs[i] & 0xdf)
						{
							return false;
						}
					}

					return true;
				}

				return false;
			}

		} /* namespace Hash */
	} /* namespace Util */
} /* namespace CitadeliCAP */
