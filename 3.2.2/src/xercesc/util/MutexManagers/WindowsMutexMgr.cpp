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
 * $Id: WindowsMutexMgr.cpp,v 1.1 2020/03/20 19:52:58 kurt Exp $
 */

#include <windows.h>

#include <xercesc/util/MutexManagers/WindowsMutexMgr.hpp>
#include <xercesc/framework/MemoryManager.hpp>

XERCES_CPP_NAMESPACE_BEGIN

WindowsMutexMgr::WindowsMutexMgr()
{
}


WindowsMutexMgr::~WindowsMutexMgr()
{
}


XMLMutexHandle
WindowsMutexMgr::create(MemoryManager* const manager)
{
    CRITICAL_SECTION* newCS=(CRITICAL_SECTION*)manager->allocate(sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(newCS);
    return newCS;
}


void
WindowsMutexMgr::destroy(XMLMutexHandle mtx, MemoryManager* const manager)
{
    ::DeleteCriticalSection((LPCRITICAL_SECTION)mtx);
    manager->deallocate(mtx);
}


void
WindowsMutexMgr::lock(XMLMutexHandle mtx)
{
    ::EnterCriticalSection((LPCRITICAL_SECTION)mtx);
}


void
WindowsMutexMgr::unlock(XMLMutexHandle mtx)
{
    ::LeaveCriticalSection((LPCRITICAL_SECTION)mtx);
}


XERCES_CPP_NAMESPACE_END

