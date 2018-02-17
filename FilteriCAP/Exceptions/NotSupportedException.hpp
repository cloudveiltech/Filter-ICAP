/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef EXCEPTIONS_NOTSUPPORTEDEXCEPTION_HPP_
#define EXCEPTIONS_NOTSUPPORTEDEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace CitadeliCAP
{
	namespace Exceptions
	{

		class NotSupportedException : public std::exception
		{
			public:
				NotSupportedException(const std::string& message);
				virtual ~NotSupportedException();
		};

	} /* namespace Exceptions */
} /* namespace CitadeliCAP */

#endif /* EXCEPTIONS_NOTSUPPORTEDEXCEPTION_HPP_ */
