/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SETTINGS_ICAPFILTERSETTINGS_HPP_
#define SETTINGS_ICAPFILTERSETTINGS_HPP_

#include <memory>
#include <string>
#include <unordered_map>
#include "../Util/Hash/iCaseHash.hpp"

namespace CitadeliCAP
{

	namespace Models
	{
		enum class PlainTextFilteringListType : int;
	}

	namespace Settings
	{

		/**
		 * Serves as the configuration settings for the lifetime of the application
		 * execution. The only way to construct an instance through this class is
		 * through the static interface where you are expected to supply a path
		 * to a JSON-based application configuration file.
		 */
		class iCAPFilterSettings : std::enable_shared_from_this<iCAPFilterSettings>
		{

			public:

				/**
				 * Default dtor.
				 */
				virtual ~iCAPFilterSettings();

				/**
				 * Creates a new iCAPFilterSettings instance from the JSON configuration file
				 * at the supplied path.
				 * @param filePath
				 * @return An iCAPFilterSettings instance created from the supplied JSON configuration
				 * file. If there was any error loading or parsing the supplied file, the return instance
				 * will be empty.
				 */
				static const iCAPFilterSettings LoadFromSettingsFile(const std::string& filePath) noexcept;

				/**
				 * Gets whether or not any settings were loaded from the source configuration file.
				 * @return True if one or more settings were successfully loaded from the source
				 * configuration file, false otherwise.
				 */
				const bool IsEmpty() const noexcept;

				/**
				 * Gets whether or not the source configuration provided any URL filtering files.
				 * @return True if URL filtering rules were provided, false otherwise.
				 */
				const bool HasUrlFiltering() const noexcept;

				/**
				 * Gets whether or not the source configuration provided any image filtering rules.
				 * @return True if image filtering rules were provided, false otherwise.
				 */
				const bool HasImageFiltering() const noexcept;

				/**
				 * Gets whether or not the source configuration provided any text filtering rules.
				 * @return True if text filtering rules were provided, false otherwise.
				 */
				const bool HasTextFiltering() const noexcept;

			private:

				iCAPFilterSettings(const bool filterUrls, const bool filterImages, const bool filterText);

				const bool m_filterUrls;

				const bool m_filterImages;

				const bool m_filterText;

				int m_updateFrequencyInMinutes = 5;

				static const std::unordered_map<std::string, Models::PlainTextFilteringListType, Util::Hash::iCaseHash, Util::Hash::iCaseEquality> s_listTypeMap;
		};

		using SharedFilterSettings = std::shared_ptr<iCAPFilterSettings>;
	}

} /* namespace Citadel */

#endif /* SETTINGS_ICAPFILTERSETTINGS_HPP_ */
