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
 * $Id: RedirectHandlers.hpp,v 1.1 2020/03/20 19:52:47 kurt Exp $
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLEntityResolver.hpp>

XERCES_CPP_NAMESPACE_USE

XERCES_CPP_NAMESPACE_BEGIN
class AttributeList;
XERCES_CPP_NAMESPACE_END


class RedirectHandlers : public HandlerBase, public XMLEntityResolver
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    RedirectHandlers();
    ~RedirectHandlers();


    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    XMLSize_t getElementCount()
    {
        return fElementCount;
    }

    XMLSize_t getAttrCount()
    {
        return fAttrCount;
    }

    XMLSize_t getCharacterCount()
    {
        return fCharacterCount;
    }

    XMLSize_t getSpaceCount()
    {
        return fSpaceCount;
    }


    // -----------------------------------------------------------------------
    //  Handlers for the SAX DocumentHandler interface
    // -----------------------------------------------------------------------
    void startElement(const XMLCh* const name, AttributeList& attributes);
    void characters(const XMLCh* const chars, const XMLSize_t length);
    void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length);
    void resetDocument();


    // -----------------------------------------------------------------------
    //  Handlers for the SAX ErrorHandler interface
    // -----------------------------------------------------------------------
    void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);


    // This is the SAX2 resolveEntity interface.  This is inherited from
    // EntityResolver.
    // -----------------------------------------------------------------------
    //  Handlers for the SAX EntityResolver interface
    // -----------------------------------------------------------------------
    InputSource* resolveEntity
    (
        const   XMLCh* const    publicId
        , const XMLCh* const    systemId
    );

    // -----------------------------------------------------------------------
    //  Handlers for the XMLEntityResolver interface
    // -----------------------------------------------------------------------
    InputSource* resolveEntity
    (
        XMLResourceIdentifier* resourceIdentifier
    );

private:
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fAttrCount
    //  fCharacterCount
    //  fElementCount
    //  fSpaceCount
    //      These are just counters that are run upwards based on the input
    //      from the document handlers.
    // -----------------------------------------------------------------------
    XMLSize_t       fAttrCount;
    XMLSize_t       fCharacterCount;
    XMLSize_t       fElementCount;
    XMLSize_t       fSpaceCount;
};
