/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id: NoThreadMutexMgr.cpp,v 1.1 2020/03/20 19:52:58 kurt Exp $
 */

#include <xercesc/util/MutexManagers/NoThreadMutexMgr.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/*
	The NoThread mutex manager is for use where no threading is used
	in an environment. Since no threading is used, mutexes are not
	needed, so the implementation does essentially nothing.
*/


NoThreadMutexMgr::NoThreadMutexMgr()
{
}


NoThreadMutexMgr::~NoThreadMutexMgr()
{
}


XMLMutexHandle
NoThreadMutexMgr::create(MemoryManager* const manager)
{
    return 0;
}


void
NoThreadMutexMgr::destroy(XMLMutexHandle mtx, MemoryManager* const manager)
{
}


void
NoThreadMutexMgr::lock(XMLMutexHandle mtx)
{
}


void
NoThreadMutexMgr::unlock(XMLMutexHandle mtx)
{
}


XERCES_CPP_NAMESPACE_END

