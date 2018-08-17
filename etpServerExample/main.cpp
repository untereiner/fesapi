/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/

#include "etp/Server.h"
#include "MyOwnEtpServerSession.h"

using namespace ETP_NS;

int main(int argc, char **argv)
{
	const std::string ipAddress = "127.0.0.1";
	const unsigned short port = 8080;
	const int threadCount = 2;

	Server<MyOwnEtpServerSession> etpServer;
	std::cout << "Start listening on " << ipAddress << ":" << port << " with " << threadCount << " threads..." << std::endl;
	etpServer.listen(ipAddress, port, threadCount);

#ifdef _WIN32
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
