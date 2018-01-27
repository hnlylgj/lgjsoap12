// CloudConApp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "soapH.h"
#include "USCORECloudServiceProxy.h"
#include "USCORECloudService.h"


int main()
{
	//----CSWCF-----
	const char* soap_endpoint = "http://121.201.28.118:8000/SmartCarCloud/PrimeAccount";	
	const char* soap_action="http://www.vispect.com/PrimeAccountCloudService/RegisterAccount";

	const char* soap_endpoint2 = "http://121.201.28.118:8000/SmartCarCloud/SmartDevice";
	const char* soap_action2 = "http://www.vispect.com/SmartDeviceCloudService/BindingDevice";

	//----JAXWS-------
	const char* jaxsoap_endpoint = "http://121.201.28.118:8080/smartcarcloudservice/SmartCarCloud";
	const char* jaxsoap_action = "http://jaxws2.vispectcloud.com/SmartCarCloudService/RegisterAccountRequest";


	BasicHttpBinding_USCOREPrimeAccountCloudServiceProxy MyCloudServiceProxy(SOAP_C_UTFSTRING,SOAP_C_UTFSTRING);
	_ns1__RegisterAccount MyRequest;
	MyRequest.LoginName =_T( "一代天骄");
	MyRequest.PassWord = _T("123456");
	MyRequest.AccountID = _T("123456789012347");
	_ns1__RegisterAccountResponse MyResponse;
	
	int ResultFalg= MyCloudServiceProxy.RegisterAccount(soap_endpoint, soap_action,&MyRequest, MyResponse);
	if (ResultFalg == SOAP_OK)
	{
		printf("Success ...\n");
		printf("AccountID:%ws\n", MyResponse.AccountID);
		printf("RegisterAccountResult:%d\n", *(MyResponse.RegisterAccountResult));
		printf("ResultFalg:%d\n", ResultFalg);

		
		
		printf("Start Bind...\n");
		
		//123456710003
		_ns1__BindingDevice MyBindingDevice;
		_ns1__BindingDeviceResponse MyBindingDeviceResponse;

		MyBindingDevice.AccountID= _T("123456710003");
		MyBindingDevice.DeviceID= _T("ABCDEF123456-粤A78993");
		ResultFalg = MyCloudServiceProxy.BindingDevice(soap_endpoint2, soap_action2, &MyBindingDevice, MyBindingDeviceResponse);

		printf("BindingDeviceResponse:%d\n", *(MyBindingDeviceResponse.BindingDeviceResult));
		printf("ResultFalg:%d\n", ResultFalg);
		

		MyCloudServiceProxy.destroy();
	}
	else
	{
		printf("Fail...\n");
		printf("ResultFalg:%d", ResultFalg);
		MyCloudServiceProxy.destroy();
	}
	

    return 0;


}

