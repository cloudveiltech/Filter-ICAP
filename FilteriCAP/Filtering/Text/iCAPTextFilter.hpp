/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef FILTERING_TEXT_ICAPTEXTFILTER_HPP_
#define FILTERING_TEXT_ICAPTEXTFILTER_HPP_

#include <memory>

namespace Citadel
{
	namespace Filtering
	{
		namespace Text
		{

			class iCAPTextFilter
			{
				public:
					iCAPTextFilter();
					virtual ~iCAPTextFilter();
			};

			using UniqueTextFilter = std::unique_ptr<iCAPTextFilter>;

		} /* namespace Text */
	} /* namespace Filtering */
} /* namespace Citadel */

#endif /* FILTERING_TEXT_ICAPTEXTFILTER_HPP_ */
