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
 * $Id: IGXMLScanner.hpp,v 1.1 2020/03/20 19:52:53 kurt Exp $
 */

#if !defined(XERCESC_INCLUDE_GUARD_IGXMLSCANNER_HPP)
#define XERCESC_INCLUDE_GUARD_IGXMLSCANNER_HPP

#include <xercesc/internal/XMLScanner.hpp>
#include <xercesc/util/KVStringPair.hpp>
#include <xercesc/util/NameIdPool.hpp>
#include <xercesc/util/RefHash2KeysTableOf.hpp>
#include <xercesc/util/RefHash3KeysIdPool.hpp>
#include <xercesc/util/Hash2KeysSetOf.hpp>
#include <xercesc/validators/common/Grammar.hpp>
#include <xercesc/validators/schema/SchemaInfo.hpp>
#include <xercesc/validators/schema/SchemaElementDecl.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class DTDElementDecl;
class DTDGrammar;
class DTDValidator;
class SchemaValidator;
class IdentityConstraintHandler;
class IdentityConstraint;
class ContentLeafNameTypeVector;
class SchemaAttDef;
class XMLContentModel;
class XSModel;
class PSVIAttributeList;
class PSVIElement;

//  This is an integrated scanner class, which does DTD/XML Schema grammar
//  processing.
class XMLPARSER_EXPORT IGXMLScanner : public XMLScanner
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    IGXMLScanner
    (
        XMLValidator* const valToAdopt
        , GrammarResolver* const grammarResolver
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    IGXMLScanner
    (
          XMLDocumentHandler* const docHandler
        , DocTypeHandler* const     docTypeHandler
        , XMLEntityHandler* const   entityHandler
        , XMLErrorReporter* const   errReporter
        , XMLValidator* const       valToAdopt
        , GrammarResolver* const    grammarResolver
        , MemoryManager* const      manager = XMLPlatformUtils::fgMemoryManager
    );
    virtual ~IGXMLScanner();

    // -----------------------------------------------------------------------
    //  XMLScanner public virtual methods
    // -----------------------------------------------------------------------
    virtual const XMLCh* getName() const;
    virtual NameIdPool<DTDEntityDecl>* getEntityDeclPool();
    virtual const NameIdPool<DTDEntityDecl>* getEntityDeclPool() const;
    virtual void scanDocument
    (
        const   InputSource&    src
    );
    virtual bool scanNext(XMLPScanToken& toFill);
    virtual Grammar* loadGrammar
    (
        const   InputSource&    src
        , const short           grammarType
        , const bool            toCache = false
    );

    virtual void resetCachedGrammar ();
    virtual Grammar::GrammarType getCurrentGrammarType() const;

private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    IGXMLScanner();
    IGXMLScanner(const IGXMLScanner&);
    IGXMLScanner& operator=(const IGXMLScanner&);

    // -----------------------------------------------------------------------
    //  XMLScanner virtual methods
    // -----------------------------------------------------------------------
    virtual void scanCDSection();
    virtual void scanCharData(XMLBuffer& toToUse);
    virtual EntityExpRes scanEntityRef
    (
        const   bool    inAttVal
        ,       XMLCh&  firstCh
        ,       XMLCh&  secondCh
        ,       bool&   escaped
    );
    virtual void scanDocTypeDecl();
    virtual void scanReset(const InputSource& src);
    virtual void sendCharData(XMLBuffer& toSend);
    virtual InputSource* resolveSystemId(const XMLCh* const sysId
                                        ,const XMLCh* const pubId);

    // -----------------------------------------------------------------------
    //  Private helper methods
    // -----------------------------------------------------------------------
    void commonInit();
    void cleanUp();

    XMLSize_t buildAttList
    (
        const   RefVectorOf<KVStringPair>&  providedAttrs
        , const XMLSize_t                   attCount
        ,       XMLElementDecl*             elemDecl
        ,       RefVectorOf<XMLAttr>&       toFill
    );
    bool normalizeAttValue
    (
        const   XMLAttDef* const    attDef
        , const XMLCh* const       name
        , const XMLCh* const        value
        ,       XMLBuffer&          toFill
    );
    bool normalizeAttRawValue
    (
        const   XMLCh* const        attrName
        , const XMLCh* const        value
        ,       XMLBuffer&          toFill
    );
    void updateNSMap
    (
        const   XMLCh* const    attrName
        , const XMLCh* const    attrValue
    );
    void updateNSMap
    (
        const   XMLCh* const    attrName
        , const XMLCh* const    attrValue
        , const int             colonPosition
    );
    void scanRawAttrListforNameSpaces(XMLSize_t attCount);
    void parseSchemaLocation(const XMLCh* const schemaLocationStr, bool ignoreLoadSchema = false);
    void resolveSchemaGrammar(const XMLCh* const loc, const XMLCh* const uri, bool ignoreLoadSchema = false);
    bool switchGrammar(const XMLCh* const newGrammarNameSpace);
    bool laxElementValidation(QName* element, ContentLeafNameTypeVector* cv,
                              const XMLContentModel* const cm,
                              const XMLSize_t parentElemDepth);
    bool anyAttributeValidation(SchemaAttDef* attWildCard,
                                unsigned int uriId,
                                bool& skipThisOne,
                                bool& laxThisOne);
    void resizeElemState();
    void processSchemaLocation(XMLCh* const schemaLoc);

    void resizeRawAttrColonList();

    // -----------------------------------------------------------------------
    //  Private scanning methods
    // -----------------------------------------------------------------------
    bool basicAttrValueScan
    (
        const   XMLCh* const    attrName
        ,       XMLBuffer&      toFill
    );
    XMLSize_t rawAttrScan
    (
        const   XMLCh* const                elemName
        ,       RefVectorOf<KVStringPair>&  toFill
        ,       bool&                       isEmpty
    );
    bool scanAttValue
    (
        const   XMLAttDef* const    attDef
        , const   XMLCh* const      attrName
        ,       XMLBuffer&          toFill
    );
    bool scanContent();
    void scanEndTag(bool& gotData);
    bool scanStartTag(bool& gotData);
    bool scanStartTagNS(bool& gotData);

    // -----------------------------------------------------------------------
    //  IdentityConstraints Activation methods
    // -----------------------------------------------------------------------
    inline bool toCheckIdentityConstraint()  const;

    // -----------------------------------------------------------------------
    //  Grammar preparsing methods
    // -----------------------------------------------------------------------
    Grammar* loadXMLSchemaGrammar(const InputSource& src, const bool toCache = false);
    Grammar* loadDTDGrammar(const InputSource& src, const bool toCache = false);

    // -----------------------------------------------------------------------
    //  PSVI handling methods
    // -----------------------------------------------------------------------
    void endElementPSVI(SchemaElementDecl* const elemDecl,
                        DatatypeValidator* const memberDV);
    void resetPSVIElemContext();

    // -----------------------------------------------------------------------
    //  Data members
    //
    //  fRawAttrList
    //      During the initial scan of the attributes we can only do a raw
    //      scan for key/value pairs. So this vector is used to store them
    //      until they can be processed (and put into fAttrList.)
    //
    //  fDTDValidator
    //      The DTD validator instance.
    //
    //  fSchemaValidator
    //      The Schema validator instance.
    //
    //  fSeeXsi
    //      This flag indicates a schema has been seen.
    //
    //  fElemState
    //  fElemLoopState
    //  fElemStateSize
    //      Stores an element next state from DFA content model - used for
    //      wildcard validation
    //
    // fDTDElemNonDeclPool
    //      registry of "faulted-in" DTD element decls
    // fSchemaElemNonDeclPool
    //      registry for elements without decls in the grammar
    // fElemCount
    //      count of the number of start tags seen so far (starts at 1).
    //      Used for duplicate attribute detection/processing of required/defaulted attributes
    // fAttDefRegistry
    //      mapping from XMLAttDef instances to the count of the last
    //      start tag where they were utilized.
    // fUndeclaredAttrRegistry
    //      set of attr QNames to detect duplicates
    // fPSVIAttrList
    //      PSVI attribute list implementation that needs to be
    //      filled when a PSVIHandler is registered
    // fSchemaInfoList
    //      Transient schema info list that is passed to TraverseSchema instances.
    // fCachedSchemaInfoList
    //      Cached Schema info list that is passed to TraverseSchema instances.
    //
    // -----------------------------------------------------------------------
    bool                                    fSeeXsi;
    Grammar::GrammarType                    fGrammarType;
    unsigned int                            fElemStateSize;
    unsigned int*                           fElemState;
    unsigned int*                           fElemLoopState;
    XMLBuffer                               fContent;
    RefVectorOf<KVStringPair>*              fRawAttrList;
    unsigned int                            fRawAttrColonListSize;
    int*                                    fRawAttrColonList;
    DTDValidator*                           fDTDValidator;
    SchemaValidator*                        fSchemaValidator;
    DTDGrammar*                             fDTDGrammar;
    IdentityConstraintHandler*              fICHandler;
    ValueVectorOf<XMLCh*>*                  fLocationPairs;
    NameIdPool<DTDElementDecl>*             fDTDElemNonDeclPool;
    RefHash3KeysIdPool<SchemaElementDecl>*  fSchemaElemNonDeclPool;
    unsigned int                            fElemCount;
    RefHashTableOf<unsigned int, PtrHasher>*fAttDefRegistry;
    Hash2KeysSetOf<StringHasher>*           fUndeclaredAttrRegistry;
    PSVIAttributeList *                     fPSVIAttrList;
    XSModel*                                fModel;
    PSVIElement*                            fPSVIElement;
    ValueStackOf<bool>*                     fErrorStack;
    PSVIElemContext                         fPSVIElemContext;
    RefHash2KeysTableOf<SchemaInfo>*        fSchemaInfoList;
    RefHash2KeysTableOf<SchemaInfo>*        fCachedSchemaInfoList;
};

inline const XMLCh* IGXMLScanner::getName() const
{
    return XMLUni::fgIGXMLScanner;
}

inline bool IGXMLScanner::toCheckIdentityConstraint()  const
{
    return fValidate && fIdentityConstraintChecking && fICHandler;
}

inline Grammar::GrammarType IGXMLScanner::getCurrentGrammarType() const
{
    return fGrammarType;
}

XERCES_CPP_NAMESPACE_END

#endif
