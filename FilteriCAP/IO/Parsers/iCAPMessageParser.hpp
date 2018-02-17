/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef PARSERS_ICAPMESSAGEPARSER_HPP_
#define PARSERS_ICAPMESSAGEPARSER_HPP_

#include "../../../contrib/http_parser/http_parser.h"
#include "../../Net/Sockets/iCAPSocketTypes.hpp"

namespace Citadel
{

	class iCAPMessageParser
	{
		public:

			iCAPMessageParser();
			virtual ~iCAPMessageParser();

		private:

			// Aside from an extra header at the start of the message,
			// iCAP messages are just chunked HTTP 1.1 messages.
			http_parser m_parser;

	};

} /* namespace Citadel */

#endif /* PARSERS_ICAPMESSAGEPARSER_HPP_ */
