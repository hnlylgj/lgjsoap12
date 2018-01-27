
#include "soapH.h"
SOAP_NMAC struct Namespace namespaces[] = {
	   { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", NULL, NULL },
	   { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", NULL, NULL },
	   { "xsi", "http://www.w3.org/2001/XMLSchema-instance", NULL, NULL },
	   { "xsd", "http://www.w3.org/2001/XMLSchema", NULL, NULL },
		{"ns2", "http://www.vispect.com/SmartCarBaseLib/", NULL, NULL},
        {"arr", "http://schemas.microsoft.com/2003/10/Serialization/Arrays", NULL, NULL},
        {"ns1", "http://www.vispect.com/", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
