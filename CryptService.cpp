// ************************************************************************ //
// Implementation class for interface ICryptService
// ************************************************************************ //
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop

#if !defined(__CryptService_h__)
#include "CryptService.h"
#endif

// ************************************************************************ //
//  TCryptServiceImpl implements interface ICryptService
// ************************************************************************ //
class TCryptServiceImpl : public TInvokableClass, public ICryptService
{
private:
  TCryptographicLibrary *CryptographicLibrary1 = new TCryptographicLibrary(NULL);
  TCodec *Codec1 = new TCodec(NULL);
public:
  __fastcall TCryptServiceImpl()  {
  	Codec1->CryptoLibrary = CryptographicLibrary1;
  	Codec1->StreamCipherId = "native.StreamToBlock";
  	Codec1->BlockCipherId = "native.AES-256";
  	Codec1->ChainModeId = "native.CBC";
  	Codec1->Password = "lozinka";
  }

  UnicodeString encrypt(UnicodeString string) {
  	String encrypted;
  	Codec1->EncryptString(string, encrypted, TEncoding::UTF8);

    return encrypted;
  }

  UnicodeString decrypt(UnicodeString string) {
  	String decrypted;
  	Codec1->DecryptString(decrypted, string, TEncoding::UTF8);

    return decrypted;
  }

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInvokableClass::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release() { return TInvokableClass::_Release();  }
};


static void __fastcall CryptServiceFactory(System::TObject* &obj)
{
  static _di_ICryptService iInstance;
  static TCryptServiceImpl *instance = 0;
  if (!instance)
  {
    instance = new TCryptServiceImpl();
    instance->GetInterface(iInstance);
  }
  obj = instance;
}

// ************************************************************************ //
//  The following routine registers the interface and implementation class
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__delphirtti(ICryptService));
  InvRegistry()->RegisterInvokableClass(__classid(TCryptServiceImpl), CryptServiceFactory);
}
#pragma startup RegTypes 32

