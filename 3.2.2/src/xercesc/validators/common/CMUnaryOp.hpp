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
 * $Id: CMUnaryOp.hpp,v 1.1 2020/03/20 19:53:00 kurt Exp $
 */

#if !defined(XERCESC_INCLUDE_GUARD_CMUNARYOP_HPP)
#define XERCESC_INCLUDE_GUARD_CMUNARYOP_HPP

#include <xercesc/validators/common/CMNode.hpp>


XERCES_CPP_NAMESPACE_BEGIN

class CMStateSet;

class CMUnaryOp : public CMNode
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    CMUnaryOp
    (
          ContentSpecNode::NodeTypes    type
        , CMNode* const                 nodeToAdopt
        , unsigned int                  maxStates
        , MemoryManager* const          manager = XMLPlatformUtils::fgMemoryManager
    );
    ~CMUnaryOp();


    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    const CMNode* getChild() const;
    CMNode* getChild();


    // -----------------------------------------------------------------------
    //  Implementation of the public CMNode virtual interface
    // -----------------------------------------------------------------------
    virtual void orphanChild();


protected :
    // -----------------------------------------------------------------------
    //  Implementation of the protected CMNode virtual interface
    // -----------------------------------------------------------------------
    void calcFirstPos(CMStateSet& toSet) const;
    void calcLastPos(CMStateSet& toSet) const;


private :
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fChild
    //      This is the reference to the one child that we have for this
    //      unary operation. We own it.
    // -----------------------------------------------------------------------
    CMNode*     fChild;

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    CMUnaryOp(const CMUnaryOp&);
    CMUnaryOp& operator=(const CMUnaryOp&);
};

XERCES_CPP_NAMESPACE_END

#endif
