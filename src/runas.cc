/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Microsoft Corporation. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/

#include "nan.h"
using namespace v8;

void Runas(const Nan::FunctionCallbackInfo<Value> &args)
{
    auto isolate = args.GetIsolate();

    SHELLEXECUTEINFO shExInfo = {sizeof(shExInfo)};
    shExInfo.fMask = SEE_MASK_NOASYNC | SEE_MASK_NOCLOSEPROCESS;
    shExInfo.lpVerb = "runas";
    shExInfo.lpFile = std::string(*String::Utf8Value(args[0])).c_str();
    shExInfo.nShow = SW_NORMAL; // TODO SW_HIDE;

    if (ShellExecuteEx(&shExInfo))
    {
        WaitForSingleObject(shExInfo.hProcess, INFINITE);
        CloseHandle(shExInfo.hProcess);

        auto cb = Local<Function>::Cast(args[0]);
        cb->Call(Null(isolate), 0, {});
    }
}

void Init(Local<Object> exports)
{
    exports->Set(Nan::New("runas").ToLocalChecked(), Nan::New<FunctionTemplate>(Runas)->GetFunction());
}

NODE_MODULE(hello, Init)