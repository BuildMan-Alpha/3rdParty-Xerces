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
 * $Id: ClosureToken.cpp,v 1.1 2020/03/20 19:52:59 kurt Exp $
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/regx/ClosureToken.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  ClosureToken: Constructors and Destructors
// ---------------------------------------------------------------------------
ClosureToken::ClosureToken(const Token::tokType tkType, Token* const tok, MemoryManager* const manager)
    : Token(tkType, manager)
    , fMin(-1)    
    , fMax(-1)
    , fChild(tok)
{

}


ClosureToken::~ClosureToken() {

}

XERCES_CPP_NAMESPACE_END

/**
  *    End of file ClosureToken.cpp
  */
