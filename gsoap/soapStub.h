/* soapStub.h
   Generated by gSOAP 2.8.103 for lacuisine.h

gSOAP XML Web services tools
Copyright (C) 2000-2020, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include <vector>
#define SOAP_NAMESPACE_OF_ns1	"http://truetechsystems.com.br/lacuisine/hmi/v1/"
#define SOAP_NAMESPACE_OF_ns2	"http://truetechsystems.com.br/lacuisine/common/v1/"

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 208103
# error "GSOAP VERSION 208103 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumeration Types                                                          *
 *                                                                            *
\******************************************************************************/


/* lacuisine.h:193 */
#ifndef SOAP_TYPE_ns2__ProfileEnum
#define SOAP_TYPE_ns2__ProfileEnum (12)
/* ns2:ProfileEnum */
enum ns2__ProfileEnum {
	ns2__ProfileEnum__ProfileMaster = 0,
	ns2__ProfileEnum__ProfileAdministrador = 1,
	ns2__ProfileEnum__ProfileCheckout = 2,
	ns2__ProfileEnum__ProfileKitchen = 3,
	ns2__ProfileEnum__ProfileUser = 4,
	ns2__ProfileEnum__ProfileUnknown = 5
};
#endif

/* lacuisine.h:206 */
#ifndef SOAP_TYPE_ns2__SessionEnum
#define SOAP_TYPE_ns2__SessionEnum (13)
/* ns2:SessionEnum */
enum ns2__SessionEnum {
	ns2__SessionEnum__SessionOk = 0,
	ns2__SessionEnum__SessionIsOpened = 1,
	ns2__SessionEnum__SessionCannotBeOpened = 2,
	ns2__SessionEnum__SessionIsSuccessfullyClosed = 3,
	ns2__SessionEnum__SessionUnauthorizedUser = 4,
	ns2__SessionEnum__SessionNotFound = 5
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs and Unions                                                *
 *                                                                            *
\******************************************************************************/

class ns1__DataUserSessionType;	/* lacuisine.h:165 */
class ns1__OpenUserSessionResponseType;	/* lacuisine.h:167 */
class ns1__CloseUserSessionResponseType;	/* lacuisine.h:169 */
class ns2__UserDataSession;	/* lacuisine.h:171 */
struct __ns1__OpenUserSession;	/* lacuisine.h:510 */
struct __ns1__CloseUserSession;	/* lacuisine.h:580 */

/* lacuisine.h:165 */
#ifndef SOAP_TYPE_ns1__DataUserSessionType
#define SOAP_TYPE_ns1__DataUserSessionType (8)
/* complex XML schema type 'ns1:DataUserSessionType': */
class SOAP_CMAC ns1__DataUserSessionType {
      public:
        /// Required element 'userName' of XML schema type 'xsd:string'
        std::string userName;
        /// Required element 'passwd' of XML schema type 'xsd:string'
        std::string passwd;
        /// Required element 'deviceId' of XML schema type 'xsd:string'
        std::string deviceId;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__DataUserSessionType
        virtual long soap_type(void) const { return SOAP_TYPE_ns1__DataUserSessionType; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__DataUserSessionType, default initialized and not managed by a soap context
        virtual ns1__DataUserSessionType *soap_alloc(void) const { return SOAP_NEW_UNMANAGED(ns1__DataUserSessionType); }
      public:
        /// Constructor with default initializations
        ns1__DataUserSessionType() : userName(), passwd(), deviceId(), soap() { }
        virtual ~ns1__DataUserSessionType() { }
        /// Friend allocator used by soap_new_ns1__DataUserSessionType(struct soap*, int)
        friend SOAP_FMAC1 ns1__DataUserSessionType * SOAP_FMAC2 soap_instantiate_ns1__DataUserSessionType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:167 */
#ifndef SOAP_TYPE_ns1__OpenUserSessionResponseType
#define SOAP_TYPE_ns1__OpenUserSessionResponseType (9)
/* complex XML schema type 'ns1:OpenUserSessionResponseType': */
class SOAP_CMAC ns1__OpenUserSessionResponseType {
      public:
        /// Required element 'userDataSession' of XML schema type 'ns2:UserDataSession'
        ns2__UserDataSession *userDataSession;
        /// Required element 'response' of XML schema type 'ns2:SessionEnum'
        enum ns2__SessionEnum response;
        /// Required element 'success' of XML schema type 'xsd:boolean'
        bool success;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__OpenUserSessionResponseType
        virtual long soap_type(void) const { return SOAP_TYPE_ns1__OpenUserSessionResponseType; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__OpenUserSessionResponseType, default initialized and not managed by a soap context
        virtual ns1__OpenUserSessionResponseType *soap_alloc(void) const { return SOAP_NEW_UNMANAGED(ns1__OpenUserSessionResponseType); }
      public:
        /// Constructor with default initializations
        ns1__OpenUserSessionResponseType() : userDataSession(), response(), success(), soap() { }
        virtual ~ns1__OpenUserSessionResponseType() { }
        /// Friend allocator used by soap_new_ns1__OpenUserSessionResponseType(struct soap*, int)
        friend SOAP_FMAC1 ns1__OpenUserSessionResponseType * SOAP_FMAC2 soap_instantiate_ns1__OpenUserSessionResponseType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:169 */
#ifndef SOAP_TYPE_ns1__CloseUserSessionResponseType
#define SOAP_TYPE_ns1__CloseUserSessionResponseType (10)
/* complex XML schema type 'ns1:CloseUserSessionResponseType': */
class SOAP_CMAC ns1__CloseUserSessionResponseType {
      public:
        /// Required element 'response' of XML schema type 'ns2:SessionEnum'
        enum ns2__SessionEnum response;
        /// Required element 'success' of XML schema type 'xsd:boolean'
        bool success;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns1__CloseUserSessionResponseType
        virtual long soap_type(void) const { return SOAP_TYPE_ns1__CloseUserSessionResponseType; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns1__CloseUserSessionResponseType, default initialized and not managed by a soap context
        virtual ns1__CloseUserSessionResponseType *soap_alloc(void) const { return SOAP_NEW_UNMANAGED(ns1__CloseUserSessionResponseType); }
      public:
        /// Constructor with default initializations
        ns1__CloseUserSessionResponseType() : response(), success(), soap() { }
        virtual ~ns1__CloseUserSessionResponseType() { }
        /// Friend allocator used by soap_new_ns1__CloseUserSessionResponseType(struct soap*, int)
        friend SOAP_FMAC1 ns1__CloseUserSessionResponseType * SOAP_FMAC2 soap_instantiate_ns1__CloseUserSessionResponseType(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:171 */
#ifndef SOAP_TYPE_ns2__UserDataSession
#define SOAP_TYPE_ns2__UserDataSession (11)
/* complex XML schema type 'ns2:UserDataSession': */
class SOAP_CMAC ns2__UserDataSession {
      public:
        /// Required element 'ns2:fullName' of XML schema type 'xsd:string'
        std::string fullName;
        /// Required element 'ns2:challenge' of XML schema type 'xsd:int'
        int challenge;
        /// Required element 'ns2:profileType' of XML schema type 'ns2:ProfileEnum'
        enum ns2__ProfileEnum profileType;
        /// Context that manages this object
        struct soap *soap;
      public:
        /// Return unique type id SOAP_TYPE_ns2__UserDataSession
        virtual long soap_type(void) const { return SOAP_TYPE_ns2__UserDataSession; }
        /// (Re)set members to default values
        virtual void soap_default(struct soap*);
        /// Serialize object to prepare for SOAP 1.1/1.2 encoded output (or with SOAP_XML_GRAPH) by analyzing its (cyclic) structures
        virtual void soap_serialize(struct soap*) const;
        /// Output object in XML, compliant with SOAP 1.1 encoding style, return error code or SOAP_OK
        virtual int soap_put(struct soap*, const char *tag, const char *type) const;
        /// Output object in XML, with tag and optional id attribute and xsi:type, return error code or SOAP_OK
        virtual int soap_out(struct soap*, const char *tag, int id, const char *type) const;
        /// Get object from XML, compliant with SOAP 1.1 encoding style, return pointer to object or NULL on error
        virtual void *soap_get(struct soap*, const char *tag, const char *type);
        /// Get object from XML, with matching tag and type (NULL matches any tag and type), return pointer to object or NULL on error
        virtual void *soap_in(struct soap*, const char *tag, const char *type);
        /// Return a new object of type ns2__UserDataSession, default initialized and not managed by a soap context
        virtual ns2__UserDataSession *soap_alloc(void) const { return SOAP_NEW_UNMANAGED(ns2__UserDataSession); }
      public:
        /// Constructor with default initializations
        ns2__UserDataSession() : fullName(), challenge(), profileType(), soap() { }
        virtual ~ns2__UserDataSession() { }
        /// Friend allocator used by soap_new_ns2__UserDataSession(struct soap*, int)
        friend SOAP_FMAC1 ns2__UserDataSession * SOAP_FMAC2 soap_instantiate_ns2__UserDataSession(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:510 */
#ifndef SOAP_TYPE___ns1__OpenUserSession
#define SOAP_TYPE___ns1__OpenUserSession (21)
/* Wrapper: */
struct SOAP_CMAC __ns1__OpenUserSession {
      public:
        /** Optional element 'ns1:DataUserSessionRequest' of XML schema type 'ns1:DataUserSessionType' */
        ns1__DataUserSessionType *ns1__DataUserSessionRequest;
      public:
        /** Return unique type id SOAP_TYPE___ns1__OpenUserSession */
        long soap_type() const { return SOAP_TYPE___ns1__OpenUserSession; }
        /** Constructor with member initializations */
        __ns1__OpenUserSession() : ns1__DataUserSessionRequest() { }
        /** Friend allocator */
        friend SOAP_FMAC1 __ns1__OpenUserSession * SOAP_FMAC2 soap_instantiate___ns1__OpenUserSession(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:580 */
#ifndef SOAP_TYPE___ns1__CloseUserSession
#define SOAP_TYPE___ns1__CloseUserSession (24)
/* Wrapper: */
struct SOAP_CMAC __ns1__CloseUserSession {
      public:
        /** Optional element 'ns1:DataUserSessionRequest' of XML schema type 'ns1:DataUserSessionType' */
        ns1__DataUserSessionType *ns1__DataUserSessionRequest;
      public:
        /** Return unique type id SOAP_TYPE___ns1__CloseUserSession */
        long soap_type() const { return SOAP_TYPE___ns1__CloseUserSession; }
        /** Constructor with member initializations */
        __ns1__CloseUserSession() : ns1__DataUserSessionRequest() { }
        /** Friend allocator */
        friend SOAP_FMAC1 __ns1__CloseUserSession * SOAP_FMAC2 soap_instantiate___ns1__CloseUserSession(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* lacuisine.h:653 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
/* SOAP_ENV__Header: */
struct SOAP_CMAC SOAP_ENV__Header {
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Header */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Header; }
        /** Constructor with member initializations */
        SOAP_ENV__Header() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Header * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* lacuisine.h:653 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
/* Type SOAP_ENV__Code is a recursive data type, (in)directly referencing itself through its (base or derived class) members */
/* SOAP_ENV__Code: */
struct SOAP_CMAC SOAP_ENV__Code {
      public:
        /** Optional element 'SOAP-ENV:Value' of XML schema type 'xsd:QName' */
        char *SOAP_ENV__Value;
        /** Optional element 'SOAP-ENV:Subcode' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Subcode;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Code */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Code; }
        /** Constructor with member initializations */
        SOAP_ENV__Code() : SOAP_ENV__Value(), SOAP_ENV__Subcode() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Code * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* lacuisine.h:653 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
/* SOAP_ENV__Detail: */
struct SOAP_CMAC SOAP_ENV__Detail {
      public:
        char *__any;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_<typename> assigned to __type */
        /** Do not create a cyclic data structure through this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Detail */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Detail; }
        /** Constructor with member initializations */
        SOAP_ENV__Detail() : __any(), __type(), fault() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Detail * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* lacuisine.h:653 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (31)
/* SOAP_ENV__Reason: */
struct SOAP_CMAC SOAP_ENV__Reason {
      public:
        /** Optional element 'SOAP-ENV:Text' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Text;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Reason */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Reason; }
        /** Constructor with member initializations */
        SOAP_ENV__Reason() : SOAP_ENV__Text() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Reason * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* lacuisine.h:653 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (32)
/* SOAP_ENV__Fault: */
struct SOAP_CMAC SOAP_ENV__Fault {
      public:
        /** Optional element 'faultcode' of XML schema type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XML schema type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XML schema type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XML schema type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
      public:
        /** Return unique type id SOAP_TYPE_SOAP_ENV__Fault */
        long soap_type() const { return SOAP_TYPE_SOAP_ENV__Fault; }
        /** Constructor with member initializations */
        SOAP_ENV__Fault() : faultcode(), faultstring(), faultactor(), detail(), SOAP_ENV__Code(), SOAP_ENV__Reason(), SOAP_ENV__Node(), SOAP_ENV__Role(), SOAP_ENV__Detail() { }
        /** Friend allocator */
        friend SOAP_FMAC1 SOAP_ENV__Fault * SOAP_FMAC2 soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* (built-in):0 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
typedef char *_XML;
#endif

/* (built-in):0 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
typedef char *_QName;
#endif

/******************************************************************************\
 *                                                                            *
 * Serializable Types                                                         *
 *                                                                            *
\******************************************************************************/


/* char has binding name 'byte' for type 'xsd:byte' */
#ifndef SOAP_TYPE_byte
#define SOAP_TYPE_byte (3)
#endif

/* int has binding name 'int' for type 'xsd:int' */
#ifndef SOAP_TYPE_int
#define SOAP_TYPE_int (1)
#endif

/* bool has binding name 'bool' for type 'xsd:boolean' */
#ifndef SOAP_TYPE_bool
#define SOAP_TYPE_bool (17)
#endif

/* enum ns2__SessionEnum has binding name 'ns2__SessionEnum' for type 'ns2:SessionEnum' */
#ifndef SOAP_TYPE_ns2__SessionEnum
#define SOAP_TYPE_ns2__SessionEnum (13)
#endif

/* enum ns2__ProfileEnum has binding name 'ns2__ProfileEnum' for type 'ns2:ProfileEnum' */
#ifndef SOAP_TYPE_ns2__ProfileEnum
#define SOAP_TYPE_ns2__ProfileEnum (12)
#endif

/* std::string has binding name 'std__string' for type 'xsd:string' */
#ifndef SOAP_TYPE_std__string
#define SOAP_TYPE_std__string (14)
#endif

/* ns2__UserDataSession has binding name 'ns2__UserDataSession' for type 'ns2:UserDataSession' */
#ifndef SOAP_TYPE_ns2__UserDataSession
#define SOAP_TYPE_ns2__UserDataSession (11)
#endif

/* ns1__CloseUserSessionResponseType has binding name 'ns1__CloseUserSessionResponseType' for type 'ns1:CloseUserSessionResponseType' */
#ifndef SOAP_TYPE_ns1__CloseUserSessionResponseType
#define SOAP_TYPE_ns1__CloseUserSessionResponseType (10)
#endif

/* ns1__OpenUserSessionResponseType has binding name 'ns1__OpenUserSessionResponseType' for type 'ns1:OpenUserSessionResponseType' */
#ifndef SOAP_TYPE_ns1__OpenUserSessionResponseType
#define SOAP_TYPE_ns1__OpenUserSessionResponseType (9)
#endif

/* ns1__DataUserSessionType has binding name 'ns1__DataUserSessionType' for type 'ns1:DataUserSessionType' */
#ifndef SOAP_TYPE_ns1__DataUserSessionType
#define SOAP_TYPE_ns1__DataUserSessionType (8)
#endif

/* struct SOAP_ENV__Fault has binding name 'SOAP_ENV__Fault' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (32)
#endif

/* struct SOAP_ENV__Reason has binding name 'SOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (31)
#endif

/* struct SOAP_ENV__Detail has binding name 'SOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
#endif

/* struct SOAP_ENV__Code has binding name 'SOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
#endif

/* struct SOAP_ENV__Header has binding name 'SOAP_ENV__Header' for type '' */
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
#endif

/* struct SOAP_ENV__Reason * has binding name 'PointerToSOAP_ENV__Reason' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Reason
#define SOAP_TYPE_PointerToSOAP_ENV__Reason (34)
#endif

/* struct SOAP_ENV__Detail * has binding name 'PointerToSOAP_ENV__Detail' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Detail
#define SOAP_TYPE_PointerToSOAP_ENV__Detail (33)
#endif

/* struct SOAP_ENV__Code * has binding name 'PointerToSOAP_ENV__Code' for type '' */
#ifndef SOAP_TYPE_PointerToSOAP_ENV__Code
#define SOAP_TYPE_PointerToSOAP_ENV__Code (27)
#endif

/* ns1__DataUserSessionType * has binding name 'PointerTons1__DataUserSessionType' for type 'ns1:DataUserSessionType' */
#ifndef SOAP_TYPE_PointerTons1__DataUserSessionType
#define SOAP_TYPE_PointerTons1__DataUserSessionType (18)
#endif

/* ns2__UserDataSession * has binding name 'PointerTons2__UserDataSession' for type 'ns2:UserDataSession' */
#ifndef SOAP_TYPE_PointerTons2__UserDataSession
#define SOAP_TYPE_PointerTons2__UserDataSession (16)
#endif

/* _QName has binding name '_QName' for type 'xsd:QName' */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (6)
#endif

/* _XML has binding name '_XML' for type '' */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (5)
#endif

/* char * has binding name 'string' for type 'xsd:string' */
#ifndef SOAP_TYPE_string
#define SOAP_TYPE_string (4)
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
