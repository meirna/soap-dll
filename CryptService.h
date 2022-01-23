// ************************************************************************ //
// Invokable interface declaration header for CryptService
// ************************************************************************ //
#ifndef   CryptServiceH
#define   CryptServiceH

#include <System.hpp>
#include <Soap.InvokeRegistry.hpp>
#include <Soap.XSBuiltIns.hpp>
#include <System.Types.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"


// ************************************************************************ //
//  Invokable interfaces must derive from IInvokable
//  The methods of the interface will be exposed via SOAP
// ************************************************************************ //
__interface INTERFACE_UUID("{AA8FB7B6-93A2-4206-9416-C08C647B6B6F}") ICryptService : public IInvokable
{
public:
	virtual UnicodeString encrypt(UnicodeString string) = 0;
	virtual UnicodeString decrypt(UnicodeString string) = 0;
};
typedef DelphiInterface<ICryptService> _di_ICryptService;


#endif // CryptServiceH
//---------------------------------------------------------------------------


