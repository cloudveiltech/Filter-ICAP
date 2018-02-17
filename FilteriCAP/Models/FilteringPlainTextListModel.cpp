/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "FilteringPlainTextListModel.hpp"

namespace CitadeliCAP
{
	namespace Models
	{

		FilteringPlainTextListModel::FilteringPlainTextListModel(const PlainTextFilteringListType type, const std::string& relativeListPath) noexcept
				:
						m_type(type),
						m_relativeListPath(relativeListPath)
		{

		}

		FilteringPlainTextListModel::~FilteringPlainTextListModel() noexcept
		{

		}

		const PlainTextFilteringListType FilteringPlainTextListModel::GetListType() const noexcept
		{
			return m_type;
		}

		const std::string& FilteringPlainTextListModel::GetListRelativePath() const noexcept
		{
			return m_relativeListPath;
		}

	} /* namespace Models */
} /* namespace CitadeliCAP */
