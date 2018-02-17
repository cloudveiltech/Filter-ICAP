/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "iCAPClientConnection.hpp"

namespace Citadel
{

	iCAPClientConnection::iCAPClientConnection(boost::asio::io_service* service) noexcept :
	m_clientSocket(*service),
	m_streamTimer(*service)
	{

		// Init our message parser.
		m_msgParser = std::make_unique<iCAPMessageParser>();

	}

	iCAPClientConnection::~iCAPClientConnection() noexcept
	{
		// TODO Auto-generated destructor stub
	}

	const void iCAPClientConnection::Start() noexcept
	{

	}

	const void iCAPClientConnection::SetStreamTimeout(const boost::posix_time::time_duration& expiry) noexcept
	{
		m_streamTimer.cancel();

		m_streamTimer.expires_from_now(expiry);

		m_streamTimer.async_wait(
		        std::bind(&iCAPClientConnection::OnStreamTimeout, shared_from_this(), std::placeholders::_1));
	}

	const void iCAPClientConnection::OnStreamTimeout(const boost::system::error_code& error) noexcept
	{
		if (error)
		{
			if (error == boost::asio::error::operation_aborted)
			{
				// Aborts are normal, as pending async_waits are cancelled every time that
				// the timeout is reset. Therefore, we safely ignore them.
				return;
			}
			else
			{
				std::string errMessage(u8"In iCAPClientConnection::OnStreamTimeout(...) - Got error:\t");
				errMessage.append(error.message());
				Logging::LoggerUtil::ReportError(errMessage);
			}
		}

		Terminate();
	}

	const void iCAPClientConnection::Terminate() noexcept
	{

	}

}
/* namespace Citadel */
