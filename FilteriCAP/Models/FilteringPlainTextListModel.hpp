/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef MODELS_FILTERINGPLAINTEXTLISTMODEL_HPP_
#define MODELS_FILTERINGPLAINTEXTLISTMODEL_HPP_

#include <string>

namespace CitadeliCAP
{
	namespace Models
	{
		enum class PlainTextFilteringListType : int
		{
			/**
			 * A plain text file where each line contains a domain or URL that should be blacklisted.
			 */
			Blacklist,

			/**
			 * A plain text file where each line contains a domain or URL that should be whitelisted.
			 */
			Whitelist,

			/**
			 * A plain text file where each line contains a domain or URL that should be blacklisted,
			 * but also should also be capable of being transformed on-demand into a whitelist.
			 */
			Bypasslist,

			/**
			 * A plain text file where each line contains arbitrary text that, if detected within a HTML
			 * text payload, should trigger a block action.
			 */
			TextTrigger
		};

		/**
		 * The FilteringPlainTextListModel represents, as generically as possible, a plain text data
		 * file that is intended to be used for content filtering. This plain text file may be a list of
		 * domains, urls, text triggers, or something else.
		 *
		 * This model contains a relative path to the plain text file within a parent zip container. It
		 * also gives an enumeration indicating the type or intent of the text data within the file.
		 */
		class FilteringPlainTextListModel
		{
			public:

				/**
				 * Constructs a new FilteringPlainTextListModel instance.
				 * @param type The type of list this model represents.
				 * @param relativeListPath The relative path within the payload archive where
				 * this list can be located.
				 */
				FilteringPlainTextListModel(const PlainTextFilteringListType type, const std::string& relativeListPath) noexcept;

				/**
				 * Default dtor.
				 */
				virtual ~FilteringPlainTextListModel() noexcept;

				/**
				 * Gets the list type.
				 * @return The list type.
				 */
				const PlainTextFilteringListType GetListType() const noexcept;

				/**
				 * Gets the relative list path.
				 * @return The relative path to the list within the payload archive.
				 */
				const std::string&  GetListRelativePath() const noexcept;

			private:

				/**
				 * The list type.
				 */
				const PlainTextFilteringListType m_type;

				/**
				 * The relative list path.
				 */
				const std::string m_relativeListPath;
		};

	} /* namespace Models */
} /* namespace CitadeliCAP */

#endif /* MODELS_FILTERINGPLAINTEXTLISTMODEL_HPP_ */
