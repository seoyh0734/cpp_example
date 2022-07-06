#include <iostream>

#include "dyLib.h"
#include "../stLib/stLib2.h"

void callFirstFuncOnDyLib()
{
  std::cout << "callFirstFuncOnDyLib" << std::endl;
  secondFunc();
}
