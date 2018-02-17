/*
 * Copyright © 2018 Cloudveil Technology Inc.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef ICAPSERVER_H_
#define ICAPSERVER_H_

#include <memory>

#include "Sockets/iCAPListener.hpp"

namespace Citadel
{

	/**
	 *  The iCAPServer class hosts the complete function of this filtering server
	 *  in a single class. All that's required is to instantiate this.
	 */
	class iCAPServer
	{
		public:

			/**
			 * Creates a new instance of the iCAP server.
			 */
			iCAPServer();

			/**
			 * Default dtor.
			 */
			virtual ~iCAPServer();

			/**
			 * Stars running the server. This is a blocking call.
			 */
			const void Run();

		private:

			/**
			 * Unique ptr to the connection listener.
			 */
			std::unique_ptr<iCAPListener> m_listener;

	};

} /* namespace Citadel */

#endif /* ICAPSERVER_H_ */
