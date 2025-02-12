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
 * $Id: FlagJanitor.c,v 1.1 2020/03/20 19:52:55 kurt Exp $
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#if defined(XERCES_TMPLSINC)
#include <xercesc/util/FlagJanitor.hpp>
#endif

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  Constructors and Destructor
// ---------------------------------------------------------------------------
template <class T> FlagJanitor<T>::FlagJanitor(T* const valPtr, const T newVal)
:   fValPtr(valPtr)
{
    // Store the pointer, save the org value, and store the new value    
    if (fValPtr)
    {
        fOldVal = *fValPtr;
        *fValPtr = newVal;
    }
}

template <class T> FlagJanitor<T>::~FlagJanitor()
{
    // Restore the old value
    if (fValPtr)
        *fValPtr = fOldVal;
}


// ---------------------------------------------------------------------------
//  Value management methods
// ---------------------------------------------------------------------------
template <class T> void FlagJanitor<T>::release()
{
    fValPtr = 0;
}

XERCES_CPP_NAMESPACE_END
