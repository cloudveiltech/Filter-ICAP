/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ICAPCLIENTCONNECTION_HPP_
#define ICAPCLIENTCONNECTION_HPP_

#include <memory>

#include "../../../IO/Parsers/iCAPMessageParser.hpp"
#include "../iCAPSocketTypes.hpp"
#include "../../../Logging/LoggerUtil.hpp"

#include <boost/asio.hpp>

namespace Citadel
{
	// The iCAPClientConnection class handles one, or multiple, sequential iCAP requests
	// from an inbound client connection.
	//
	// This class governs its own life cycle via the shared_from_this class,
	// self-incrementing its own reference count at each asynchronous
	// IO operation via callback parameter binding.
	class iCAPClientConnection: public std::enable_shared_from_this<iCAPClientConnection>
	{
			// Lets be best buddies with the listener class, so it can directly
			// access our socket(s).
			friend class iCAPListener;

		public:

			iCAPClientConnection(boost::asio::io_service* service) noexcept;
			virtual ~iCAPClientConnection() noexcept;

		private:

			const void Start() noexcept;

			const void SetStreamTimeout(const boost::posix_time::time_duration& expiry) noexcept;

			const void OnStreamTimeout(const boost::system::error_code& error) noexcept;

			const void Terminate() noexcept;

			TcpSocket m_clientSocket;

			boost::asio::deadline_timer m_streamTimer;

			// Used to parse incoming iCAP messages.
			std::unique_ptr<iCAPMessageParser> m_msgParser;

	};

	using SharedClient = std::shared_ptr<iCAPClientConnection>;

} /* namespace Citadel */

#endif /* ICAPCLIENTCONNECTION_HPP_ */
