/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "iCAPListener.hpp"

#include <memory>

#include "Client/iCAPClientConnection.hpp"
#include "../../Logging/LoggerUtil.hpp"

namespace Citadel
{
	using namespace Citadel::Logging;

	iCAPListener::iCAPListener(boost::asio::io_service* service, const uint16_t listenerPort) noexcept :
	m_service(service),
	m_acceptor(*service),
	m_preferredPort(listenerPort)
	{
		boost::asio::ip::tcp::endpoint listenerEndpoint(boost::asio::ip::tcp::v6(), m_preferredPort);
		m_acceptor.open(listenerEndpoint.protocol());

		// Clear the V6 only flag so we get a dual-mode socket. Should work most places we care about.
		boost::asio::ip::v6_only v6OnlyOption(false);
		m_acceptor.set_option(v6OnlyOption);

		boost::system::error_code reuseAddrEc;
		m_acceptor.set_option(boost::asio::socket_base::reuse_address(true), reuseAddrEc);

		m_acceptor.bind(listenerEndpoint);
		m_acceptor.listen();

	}

	iCAPListener::~iCAPListener() noexcept
	{

	}

	const uint16_t iCAPListener::GetListenerPort() const
	{
		return m_acceptor.local_endpoint().port();
	}

	const bool iCAPListener::AcceptConnections() noexcept
	{
		if (m_service != nullptr)
		{
			try
			{
				SharedClient session = std::make_shared<iCAPClientConnection>(m_service);

				if (session == nullptr)
				{
					LoggerUtil::ReportError(std::string(u8"In iCAPListener::Start() - Failed to allocate new session!"));
					return false;
				}

				m_acceptor.async_accept(session->m_clientSocket,
				        std::bind(&iCAPListener::HandleAccept, this, std::placeholders::_1, session));
				return true;
			}
			catch (std::exception& e)
			{
				std::string errMessage(u8"In iCAPListener::Start()- Got error:\t");
				errMessage.append(e.what());
				LoggerUtil::ReportError(errMessage);
			}
		}

		return false;
	}

	const void iCAPListener::Stop() noexcept
	{
		boost::system::error_code e;
		m_acceptor.cancel(e);

		if (e)
		{
			std::string errMessage(u8"In iCAPListener::Stop() - Got error:\t");
			errMessage.append(e.message());
		}
	}

	const void iCAPListener::HandleAccept(const boost::system::error_code& error, SharedClient client)
	{
		if (!error && client.get() != nullptr)
		{
			client->Start();

			if (!AcceptConnections())
			{
				LoggerUtil::ReportError(std::string(u8"In iCAPListener::HandleAccept(...) - Failed to reinitiate accept."));
			}
		}
		else
		{
			if (error)
			{
				std::string errMessage(u8"In iCAPListener::HandleAccept(...) - Got error:\t");
				errMessage.append(error.message());
			}
			else
			{
				LoggerUtil::ReportError(std::string(u8"In iCAPListener::HandleAccept(...) - Session is nullptr!"));
			}
		}
	}

} /* namespace Citadel */

