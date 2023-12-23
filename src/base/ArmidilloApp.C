#include "ArmidilloApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ArmidilloApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

ArmidilloApp::ArmidilloApp(InputParameters parameters) : MooseApp(parameters)
{
  ArmidilloApp::registerAll(_factory, _action_factory, _syntax);
}

ArmidilloApp::~ArmidilloApp() {}

void 
ArmidilloApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<ArmidilloApp>(f, af, s);
  Registry::registerObjectsTo(f, {"ArmidilloApp"});
  Registry::registerActionsTo(af, {"ArmidilloApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ArmidilloApp::registerApps()
{
  registerApp(ArmidilloApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ArmidilloApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ArmidilloApp::registerAll(f, af, s);
}
extern "C" void
ArmidilloApp__registerApps()
{
  ArmidilloApp::registerApps();
}
