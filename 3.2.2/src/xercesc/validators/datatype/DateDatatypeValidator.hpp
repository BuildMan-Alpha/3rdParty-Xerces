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
 * $Id: DateDatatypeValidator.hpp,v 1.1 2020/03/20 19:53:01 kurt Exp $
 */

#if !defined(XERCESC_INCLUDE_GUARD_DATE_DATATYPE_VALIDATOR_HPP)
#define XERCESC_INCLUDE_GUARD_DATE_DATATYPE_VALIDATOR_HPP

#include <xercesc/validators/datatype/DateTimeValidator.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class VALIDATORS_EXPORT DateDatatypeValidator : public DateTimeValidator
{
public:

    // -----------------------------------------------------------------------
    //  Public ctor/dtor
    // -----------------------------------------------------------------------
	/** @name Constructors and Destructor */
    //@{

    DateDatatypeValidator
    (
        MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    DateDatatypeValidator
    (
        DatatypeValidator* const baseValidator
        , RefHashTableOf<KVStringPair>* const facets
        , RefArrayVectorOf<XMLCh>* const enums
        , const int finalSet
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    ~DateDatatypeValidator();

	//@}

    /**
      * Returns an instance of the base datatype validator class
	  * Used by the DatatypeValidatorFactory.
      */
    virtual DatatypeValidator* newInstance
    (
        RefHashTableOf<KVStringPair>* const facets
        , RefArrayVectorOf<XMLCh>* const enums
        , const int finalSet
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );

    virtual const XMLCh* getCanonicalRepresentation
                        (
                          const XMLCh*         const rawData
                        ,       MemoryManager* const memMgr = 0
                        ,       bool                 toValidate = false
                        ) const;
    /***
     * Support for Serialization/De-serialization
     ***/
    DECL_XSERIALIZABLE(DateDatatypeValidator)

protected:

    // -----------------------------------------------------------------------
    //  implementation of (DateTimeValidator's) virtual interface
    // -----------------------------------------------------------------------
    virtual XMLDateTime*          parse(const XMLCh* const, MemoryManager* const manager);
    virtual void                  parse(XMLDateTime* const);

private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    DateDatatypeValidator(const DateDatatypeValidator&);
    DateDatatypeValidator& operator=(const DateDatatypeValidator&);
};

XERCES_CPP_NAMESPACE_END

#endif

/**
  * End of file DateDatatypeValidator.hpp
  */
