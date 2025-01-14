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
 * $Id: XSTypeDefinition.cpp,v 1.1 2020/03/20 19:52:53 kurt Exp $
 */

#include <xercesc/framework/psvi/XSTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/util/XMLString.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  XSTypeDefinition: Constructors and Destructor
// ---------------------------------------------------------------------------
XSTypeDefinition::XSTypeDefinition(TYPE_CATEGORY           typeCategory,
                                   XSTypeDefinition* const xsBaseType,
                                   XSModel* const          xsModel,
                                   MemoryManager* const    manager)
    : XSObject(XSConstants::TYPE_DEFINITION, xsModel, manager)
    , fTypeCategory(typeCategory)
    , fFinal(0)
    , fBaseType(xsBaseType)    
{
}

XSTypeDefinition::~XSTypeDefinition()
{
}

// ---------------------------------------------------------------------------
//  XSTypeDefinition: access methods
// ---------------------------------------------------------------------------
bool XSTypeDefinition::isFinal(short toTest)
{
    if (fFinal & toTest)
        return true;

    return false;

}

bool XSTypeDefinition::derivedFrom(const XMLCh *typeNamespace, 
                                   const XMLCh *name)
{    
    if (!name)
        return false;

    XSTypeDefinition* type = fXSModel->getTypeDefinition(name, typeNamespace);
    
    if (!type)
        return false;

    return derivedFromType(type);
}

XERCES_CPP_NAMESPACE_END


