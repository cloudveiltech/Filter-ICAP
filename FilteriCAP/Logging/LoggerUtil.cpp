/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "LoggerUtil.hpp"

namespace Citadel
{
	namespace Logging
	{
		MessageCallback LoggerUtil::s_msgCb = nullptr;

		MessageCallback LoggerUtil::s_warnCb = nullptr;

		MessageCallback LoggerUtil::s_errCb = nullptr;

		const void LoggerUtil::SetMessageCallback(MessageCallback cb) noexcept
		{
			s_msgCb = cb;
		}

		const void LoggerUtil::SetWarningCallback(MessageCallback cb) noexcept
		{
			s_warnCb = cb;
		}

		const void LoggerUtil::SetErrorCallback(MessageCallback cb) noexcept
		{
			s_errCb = cb;
		}

		const void LoggerUtil::ReportMessage(const std::string& message) noexcept
		{
			if (s_msgCb != nullptr)
			{
				s_msgCb(message);
			}
		}

		const void LoggerUtil::ReportWarning(const std::string& message) noexcept
		{
			if (s_warnCb != nullptr)
			{
				s_warnCb(message);
			}
		}

		const void LoggerUtil::ReportError(const std::string& message) noexcept
		{
			if (s_errCb != nullptr)
			{
				s_errCb(message);
			}
		}

		LoggerUtil::LoggerUtil() noexcept
		{
			// TODO Auto-generated constructor stub

		}

		LoggerUtil::~LoggerUtil() noexcept
		{
			// TODO Auto-generated destructor stub
		}
	}

} /* namespace Citadel */
