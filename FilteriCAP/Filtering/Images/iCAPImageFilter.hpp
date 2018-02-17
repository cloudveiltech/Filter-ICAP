/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef FILTERING_IMAGES_ICAPIMAGEFILTER_HPP_
#define FILTERING_IMAGES_ICAPIMAGEFILTER_HPP_

#include <memory>
#include <vector>

#include "../../Exceptions/NotSupportedException.hpp"

/*
 * Forward decl abstract classifier.
 */
namespace Citadel
{
	namespace Filtering
	{
		namespace Images
		{
			namespace Impl
			{
				class AbstractImageClassifier;
			}
		}
	}
}

namespace Citadel
{
	namespace Filtering
	{
		namespace Images
		{

			/**
			 * Indicates the result of an image classification attempt.
			 */
			enum ImageClassifierResult
			{
				/**
				 * The classification result was negative
				 */
				Allow, //!< Allow

				/**
				 * The classification result was positive.
				 */
				Block, //!< Block

				/**
				 * There was an error while attempting to classify.
				 */
				Error //!< Error
			};

			/**
			 * Specifies the type of classifier back end to use for image
			 * classification.
			 */
			enum ClassifierType
			{
				/**
				 * Use the Yahoo NSFW Resetnet model powered by
				 * Caffe CPU.
				 */
				ResnetCPUCaffe,     //!< ResnetCPUCaffe

				/**
				 * Use the Yahoo NSFW Resetnet model powered by
				 * OpenCV DNN CPU.
				 */
				ResnetCPUOpenCV,    //!< ResnetCPUOpenCV

				/**
				 * Use the Yahoo NSFW Resetnet model powered by
				 * Caffe CPU.
				 */
				ResnetGPUCaffe,     //!< ResnetGPUCaffe

				/**
				 * Use the Squeezenet NSFW model powered by
				 * Caffe CPU.
				 */
				SqueezenetCPUCaffe, //!< SqueezenetCPUCaffe

				/**
				 * Use the Squeezenet NSFW model powered by
				 * OpenCV DNN CPU.
				 */
				SqueezenetCPUOpenCV, //!< SqueezenetCPUOpenCV

				/**
				 * Use the Squeezenet NSFW model powered by
				 * Caffe GPU.
				 */
				SqueezenetGPUCaffe, //!< SqueezenetGPUCaffe
			};

			class iCAPImageFilter
			{
				public:

					/**
					 * Constructs a new iCAPImageFilter instance with the given underlying
					 * classifier type.
					 * @param type The type of classifier back end to use.
					 * @throws NotSupportedException. Will throw if the supplied classifier
					 * type is not supported either by the system or by compilation options.
					 */
					iCAPImageFilter(const ClassifierType type);

					virtual ~iCAPImageFilter() noexcept;

					const ImageClassifierResult Classify(const std::vector<uint8_t>& imageData) noexcept;

					const ClassifierType GetType() const noexcept;

				private:

					const ClassifierType m_type;

					// The actual classifier.
					std::unique_ptr<Impl::AbstractImageClassifier> m_classifier;
			};

			using UniqueImageFilter = std::unique_ptr<iCAPImageFilter>;

		} /* namespace Images */
	} /* namespace Filtering */
} /* namespace Citadel */

#endif /* FILTERING_IMAGES_ICAPIMAGEFILTER_HPP_ */
