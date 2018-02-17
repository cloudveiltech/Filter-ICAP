/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "iCAPImageFilter.hpp"
#include "../../Logging/LoggerUtil.hpp"
#include "Impl/AbstractImageClassifier.hpp"

namespace Citadel
{
	namespace Filtering
	{
		namespace Images
		{

			iCAPImageFilter::iCAPImageFilter(const ClassifierType type) : m_type(type)
			{

			}

			const ImageClassifierResult iCAPImageFilter::Classify(const std::vector<uint8_t>& imageData) noexcept
			{
				auto result = ImageClassifierResult::Allow;

				try
				{

				}
				catch(std::exception& e)
				{
					result = ImageClassifierResult::Error;

					std::string err {
						u8"While classifying image, encountered error: "
					};
					err.append(e.what());
					Logging::LoggerUtil::ReportError(err);
				}

				return result;
			}

			iCAPImageFilter::~iCAPImageFilter() noexcept
			{
				// TODO Auto-generated destructor stub
			}

			const ClassifierType iCAPImageFilter::GetType() const noexcept
			{
				return m_type;
			}

		} /* namespace Images */
	} /* namespace Filtering */
} /* namespace Citadel */
