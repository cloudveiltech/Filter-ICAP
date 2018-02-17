/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ICAPLISTENER_HPP_
#define ICAPLISTENER_HPP_

#include <cstdint>

#include "iCAPSocketTypes.hpp"
#include "Client/iCAPClientConnection.hpp"

namespace Citadel
{

	class iCAPListener
	{

		public:

			// Constructs a new instance of the iCAPListener class.
			iCAPListener(boost::asio::io_service* service, const uint16_t listenerPort = 0) noexcept;

			// Gets the bound listener port.
			const uint16_t GetListenerPort() const;

			// Stars the acceptor. Non-blocking.
			const bool AcceptConnections() noexcept;

			// Stop the acceptor. Non-blocking.
			const void Stop() noexcept;

			// Default dtor.
			virtual ~iCAPListener() noexcept;

		private:

			// Pointer to the service driving the acceptor.
			boost::asio::io_service* m_service = nullptr;

			// The underlying TCP acceptor itself.
			boost::asio::ip::tcp::acceptor m_acceptor;

			// The preferred port passed to the constructor.
			uint16_t m_preferredPort;

			const void HandleAccept(const boost::system::error_code& error, SharedClient client);
	};

} /* namespace Citadel */

#endif /* ICAPLISTENER_HPP_ */
