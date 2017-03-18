#include <Urho3D/Urho3D.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Physics/PhysicsWorld.h>
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Zone.h>
#include <Urho3D/Scene/Scene.h>

#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/RenderPath.h>
#include <Urho3D/Resource/ResourceCache.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/IO/FileSystem.h>
#include <Urho3D/Core/CoreEvents.h>

#include <Urho3D/UI/UI.h>

#include <Urho3D/AngelScript/ScriptFile.h>
#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/Core/Main.h>
#include <Urho3D/Resource/ResourceEvents.h>

//--------

#include "Main.h"

#include "iogram/Urho3D/UI/IogramWindow.h"

#include "iogram/Core/IoGraph.h"
#include "iogram/Core/IoSerialization.h"
#include "iogram/Core/ComponentRegistration.h"
#include "iogram/Components/RegisterCoreComponents.h"

#include "iogram/Components/Scene_GetNode.h"


#include <Urho3D/DebugNew.h>
#include <Urho3D/IO/Log.h>
#include <Urho3D/Engine/DebugHud.h>

URHO3D_DEFINE_APPLICATION_MAIN(Main)

Main::Main(Context* context) :
    ApplicationHandler(context)
{
	cfgFileName_ = "iogram.cfg";

	context->RegisterSubsystem(new IoGraph(context));

	IogramWindow::RegisterObject(context);
}

Main::~Main(){}

void Main::Start()
{
    // Execute base class startup
    ApplicationHandler::Start();

    ResourceCache* cache = GetSubsystem<ResourceCache>();

    //register core components
	RegisterCoreComponents(context_);

    engineParameters_["FullScreen"]=true;

    //are we loading the editor?
    scriptFileName_ = "/Scripts/CustomEditor.as";//force the editor
    bool scripted = LoadScriptFile();//load the script file (editor)

    ///IoGraph->AddNewComponent(new Input_Panel
    IoGraph* graph = GetSubsystem<IoGraph>();
	graph->scene = scene_;

	//UI* ui = GetSubsystem<UI>();
	//XMLFile* style = cache->GetResource<XMLFile>("UI/IogramDefaultStyle.xml");
	//ui->GetRoot()->SetDefaultStyle(style);

	//solve it
	
	SharedPtr<IoComponentBase> nodePtr(new Scene_GetNode(GetContext()) );

	graph->AddNewComponent(nodePtr);

	graph->TopoSolveGraph();
}


