#pragma once
#include "IRuntimeModule.hpp"
#include "GfxConfiguration.hpp"

namespace My {
    Interface IApplication : implements IRuntimeModule
    {
    public:
        int Initialize() override = 0;
        void Finalize() override = 0;
        // One cycle of the main loop
        void Tick() override = 0;

        virtual void SetCommandLineParameters(int argc, char** argv) = 0;
        virtual int  GetCommandLineArgumentsCount() const = 0;
        virtual const char* GetCommandLineArgument(int index) const = 0;

        virtual bool IsQuit() const = 0;
        virtual void RequestQuit() = 0;

        virtual void CreateMainWindow() = 0;
        virtual void* GetMainWindowHandler() = 0;

        virtual const GfxConfiguration& GetConfiguration() const = 0;
    };

	extern IApplication*    g_pApp;
}


