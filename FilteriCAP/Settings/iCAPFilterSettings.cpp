/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "iCAPFilterSettings.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <fstream>
#include <vector>

#include "../Models/FilteringPlainTextListModel.hpp"

using namespace boost::property_tree::json_parser;
using boost::property_tree::ptree;

namespace CitadeliCAP
{

	namespace Settings
	{

		const std::unordered_map<std::string, Models::PlainTextFilteringListType, Util::Hash::iCaseHash, Util::Hash::iCaseEquality> iCAPFilterSettings::s_listTypeMap {
		    { u8"Blacklist", Models::PlainTextFilteringListType::Blacklist},
			{ u8"Bypasslist", Models::PlainTextFilteringListType::Bypasslist},
			{ u8"TextTrigger", Models::PlainTextFilteringListType::TextTrigger},
			{ u8"Whitelist", Models::PlainTextFilteringListType::Whitelist}
		};

		const iCAPFilterSettings iCAPFilterSettings::LoadFromSettingsFile(const std::string& filePath) noexcept
		{
			// use boost::property_tree to read the json
			// https://stackoverflow.com/questions/15206705/reading-json-file-with-boost
			std::ifstream inFile(filePath, std::ios::in | std::ios::binary);

			bool filtersUrls = false;
			bool filtersImages = false;
			bool filtersText = false;

			if (inFile.good())
			{
				inFile.close();

				ptree root;
				read_json(filePath, root);

				std::vector<Models::FilteringPlainTextListModel> listModels;

				for (ptree::value_type& list : root.get_child("ConfiguredLists"))
				{
					auto listTypeStr = list.second.get<std::string>("ListType");
					auto relListPathStr = list.second.get<std::string>("RelativeListPath");

					auto typeit = s_listTypeMap.find(listTypeStr);

					if (typeit != s_listTypeMap.end())
					{
						switch (typeit->second)
						{
							case Models::PlainTextFilteringListType::Blacklist:
							case Models::PlainTextFilteringListType::Whitelist:
							case Models::PlainTextFilteringListType::Bypasslist:
							{
								filtersUrls = true;
							}
							break;

							case Models::PlainTextFilteringListType::TextTrigger:
							{
								filtersText = true;
							}
							break;
						}

						listModels.emplace_back(Models::FilteringPlainTextListModel { typeit->second, relListPathStr });
					}
				}

				auto updateFrequency = root.get<int>(u8"UpdateFrequency");
				auto maxTextTriggerScanningSize = root.get<int>(u8"MaxTextTriggerScanningSize");
			}

			// Just return an empty config if we failed to find/load/parse
			// a valid config file.
			return { false, false, false};
		}

		const bool iCAPFilterSettings::IsEmpty() const noexcept
		{
			return !m_filterImages && !m_filterText && !m_filterUrls;
		}

		const bool iCAPFilterSettings::HasUrlFiltering() const noexcept
		{
			return m_filterUrls;
		}

		const bool iCAPFilterSettings::HasImageFiltering() const noexcept
		{
			return m_filterImages;
		}

		const bool iCAPFilterSettings::HasTextFiltering() const noexcept
		{
			return m_filterText;
		}

		iCAPFilterSettings::iCAPFilterSettings(const bool filterUrls, const bool filterImages, const bool filterText)
				: m_filterUrls(filterUrls), m_filterImages(filterImages), m_filterText(filterText)
		{
			// TODO Auto-generated constructor stub

		}

		iCAPFilterSettings::~iCAPFilterSettings()
		{
			// TODO Auto-generated destructor stub
		}
	}

} /* namespace Citadel */
