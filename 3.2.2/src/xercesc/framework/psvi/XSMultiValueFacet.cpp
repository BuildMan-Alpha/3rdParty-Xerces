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
 * $Id: XSMultiValueFacet.cpp,v 1.1 2020/03/20 19:52:52 kurt Exp $
 */

#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
#include <xercesc/framework/psvi/XSAnnotation.hpp>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  XSMultiValueFacet: Constructors and Destructors
// ---------------------------------------------------------------------------
XSMultiValueFacet::XSMultiValueFacet(XSSimpleTypeDefinition::FACET facetKind,
                                     StringList*                   lexicalValues,
                                     bool                          isFixed,
                                     XSAnnotation* const           headAnnot,
                                     XSModel* const                xsModel,
                                     MemoryManager* const          manager)
    : XSObject(XSConstants::MULTIVALUE_FACET, xsModel, manager)
    , fFacetKind(facetKind)
    , fIsFixed(isFixed)
    , fLexicalValues(lexicalValues)
    , fXSAnnotationList(0)
{
    if (headAnnot)
    {        
        fXSAnnotationList = new (manager) RefVectorOf<XSAnnotation>(1, false, manager);
  
        XSAnnotation* annot = headAnnot;
        do 
        {
            fXSAnnotationList->addElement(annot);
            annot = annot->getNext();
        } while (annot);
    }
}

XSMultiValueFacet::~XSMultiValueFacet()
{
    if (fXSAnnotationList)
        delete fXSAnnotationList;
}


XERCES_CPP_NAMESPACE_END


