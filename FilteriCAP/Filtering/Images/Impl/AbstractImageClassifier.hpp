/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef FILTERING_IMAGES_IMPL_ABSTRACTIMAGECLASSIFIER_HPP_
#define FILTERING_IMAGES_IMPL_ABSTRACTIMAGECLASSIFIER_HPP_

#include <vector>
#include <cstdint>

namespace Citadel
{
	namespace Filtering
	{
		namespace Images
		{
			namespace Impl
			{

				/**
				 * The AbstractImageClassifier class serves to provide an interface for various
				 * implementations of image classifiers.
				 */
				class AbstractImageClassifier
				{
					public:

						/**
						 * Default ctor.
						 */
						AbstractImageClassifier() noexcept;

						/**
						 * Default dtor.
						 */
						virtual ~AbstractImageClassifier() noexcept;

						/**
						 * Classifies the binary image data input.
						 * @param data The binary image input to classify.
						 * @return Returns true if the supplied image was successfully decoded
						 * and determined to contain pornographic visuals, false otherwise.
						 */
						virtual const bool Classify(const std::vector<uint8_t>& data) noexcept = 0;
				};

			} /* namespace Impl */
		} /* namespace Images */
	} /* namespace Filtering */
} /* namespace Citadel */

#endif /* FILTERING_IMAGES_IMPL_ABSTRACTIMAGECLASSIFIER_HPP_ */
