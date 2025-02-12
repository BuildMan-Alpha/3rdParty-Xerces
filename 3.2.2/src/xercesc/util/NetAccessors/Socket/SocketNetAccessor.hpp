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
 * $Id: SocketNetAccessor.hpp,v 1.1 2020/03/20 19:52:58 kurt Exp $
 */

#if !defined(XERCESC_INCLUDE_GUARD_SOCKETNETACCESSOR_HPP)
#define XERCESC_INCLUDE_GUARD_SOCKETNETACCESSOR_HPP


#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLURL.hpp>
#include <xercesc/util/BinInputStream.hpp>
#include <xercesc/util/XMLNetAccessor.hpp>

XERCES_CPP_NAMESPACE_BEGIN

//
// This class is the wrapper for the socket based code which
// provides the ability to fetch a resource specified using
// a HTTP or FTP URL.
//

class XMLUTIL_EXPORT SocketNetAccessor : public XMLNetAccessor
{
public :
    SocketNetAccessor();
    ~SocketNetAccessor();

    virtual BinInputStream* makeNew(const XMLURL&  urlSource, const XMLNetHTTPInfo* httpInfo=0);
    virtual const XMLCh* getId() const;

private :
    static const XMLCh fgMyName[];

    SocketNetAccessor(const SocketNetAccessor&);
    SocketNetAccessor& operator=(const SocketNetAccessor&);

}; // SocketNetAccessor

inline const XMLCh* SocketNetAccessor::getId() const
{
    return fgMyName;
}


XERCES_CPP_NAMESPACE_END

#endif // SOCKETNETACCESSOR_HPP
