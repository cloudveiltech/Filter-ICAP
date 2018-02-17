/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef NET_SOCKETS_ICAPSOCKETTYPES_HPP_
#define NET_SOCKETS_ICAPSOCKETTYPES_HPP_

#include <boost/asio.hpp>

namespace Citadel
{
	using TcpSocket = boost::asio::ip::tcp::socket;
}

#endif /* NET_SOCKETS_ICAPSOCKETTYPES_HPP_ */
