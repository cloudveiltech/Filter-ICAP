/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef FILTERING_URLS_ICAPURLFILTER_HPP_
#define FILTERING_URLS_ICAPURLFILTER_HPP_

#include <memory>

namespace Citadel
{
	namespace Filtering
	{
		namespace Urls
		{

			class iCAPUrlFilter
			{
				public:
					iCAPUrlFilter();
					virtual ~iCAPUrlFilter();
			};

			using UniqueUrlFilter = std::unique_ptr<iCAPUrlFilter>;

		} /* namespace Urls */
	} /* namespace Filtering */
} /* namespace Citadel */

#endif /* FILTERING_URLS_ICAPURLFILTER_HPP_ */
