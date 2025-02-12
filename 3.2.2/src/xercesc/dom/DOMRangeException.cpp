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
 * $Id: DOMRangeException.cpp,v 1.1 2020/03/20 19:52:49 kurt Exp $
 */

#include "DOMRangeException.hpp"
#include <xercesc/util/XMLDOMMsg.hpp>

XERCES_CPP_NAMESPACE_BEGIN


DOMRangeException::DOMRangeException()
: DOMException()
{
}


DOMRangeException::DOMRangeException(short exCode,
                                     short messageCode,
                                     MemoryManager* const  memoryManager)
: DOMException(exCode, messageCode?messageCode:XMLDOMMsg::DOMRANGEEXCEPTION_ERRX+exCode-DOMRangeException::BAD_BOUNDARYPOINTS_ERR+1, memoryManager)
{
}


DOMRangeException::DOMRangeException(const DOMRangeException &other)
: DOMException(other)
{
}


DOMRangeException::~DOMRangeException()
{
}

XERCES_CPP_NAMESPACE_END
