//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ArmidilloTestApp.h"
#include "ArmidilloApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
ArmidilloTestApp::validParams()
{
  InputParameters params = ArmidilloApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

ArmidilloTestApp::ArmidilloTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ArmidilloTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ArmidilloTestApp::~ArmidilloTestApp() {}

void
ArmidilloTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ArmidilloApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ArmidilloTestApp"});
    Registry::registerActionsTo(af, {"ArmidilloTestApp"});
  }
}

void
ArmidilloTestApp::registerApps()
{
  registerApp(ArmidilloApp);
  registerApp(ArmidilloTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ArmidilloTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ArmidilloTestApp::registerAll(f, af, s);
}
extern "C" void
ArmidilloTestApp__registerApps()
{
  ArmidilloTestApp::registerApps();
}
